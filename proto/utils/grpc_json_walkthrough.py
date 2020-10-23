#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
This is an example of using the Python grpc client for v2 APIs. It requires you to run the
go server locally in order to use it. The remote APIs at api-dev, api-staging and api.clarifai.com
won't work just yet until we have an HTTP/2 load balancer because grpc talks HTTP/2 (and requires
HTTP/2 trailers which AWS's LBs don't support unfortunately). If we don't use this channel then the
whole V2Stub needs to be implemented. That involves:
1) using a request library for HTTP 1.1
2) hard coding all the endpoints into that new client
3) serialize / deserialize to/from json for each object before using the request library.
"""
from __future__ import absolute_import, division, print_function, unicode_literals
from future import standard_library

import os
import time
from builtins import range, str

# from proto.clarifai.api.resources_pb2 import Input, PostModelOutputsRequest
from proto.clarifai.api.resources_pb2 import (Concept, Data, Image, Input, Model, OutputInfo,
                                              Workflow, WorkflowNode)
from proto.clarifai.api.service_pb2 import (
    _V2, DeleteModelRequest, GetConceptRequest, GetModelRequest, GetModelVersionRequest,
    GetWorkflowRequest, ListConceptsRequest, ListInputsRequest, PostConceptsRequest,
    PostInputsRequest, PostModelOutputsRequest, PostModelsRequest, PostModelVersionsRequest,
    PostWorkflowsRequest)
from proto.clarifai.api.service_pb2_grpc import V2Stub
from proto.clarifai.api.status.status_code_pb2 import MODEL_TRAINED, SUCCESS
from proto.utils.grpc_json_channel import GRPCJSONChannel, ParseDict

standard_library.install_aliases()

# Create a json channel.
channel = GRPCJSONChannel(
    key=os.environ['CLARIFAI_API_KEY'],
    base_url=os.environ['CLARIFAI_API_BASE'],
    service_descriptor=_V2)

# We make the connection. We might need to use a secure_channel instead for production because the
# load balancer that works with HTTP/2 would also host the SSL certificate.
#channel = grpc.insecure_channel('%s:%s' % (host, port))

stub = V2Stub(channel)

# Ok now let's start making calls. Here we'll create a new concept, checking first
# if the concept with that id exists.
# Note: you need to set value=1 for positive and value=0 for negative. There are no defaults when
# using the grpc fields in the future. This will still work for now using the json field default
# because the server will have defaults for JSONs but we want to educate users to use the grpc
# client the right way and not make bad behaviors.
dog = Concept(id="doggy_concept_id", name="doggy", value=1)
veil = Concept(id="veil_concept_id", name="veil", value=1)
notdog = Concept(id="doggy_concept_id", name="doggy", value=0)
notveil = Concept(id="veil_concept_id", name="veil", value=0)

res = stub.ListConcepts(ListConceptsRequest())

# res = stub.GetConcept(GetConceptRequest(concept_id=cid), metadata=mdata)
res = stub.GetConcept(GetConceptRequest(concept_id=dog.id))
res2 = stub.GetConcept(GetConceptRequest(concept_id=veil.id))
if res.status.code == SUCCESS and res2.status.code == SUCCESS:
  print('Concept already created')
  # You can use this in future requests and it has even more info!
  createdConcepts = [res.concept, res2.concept]
else:
  print('Concept not created')
  # POST /concepts
  res = stub.PostConcepts(PostConceptsRequest(concepts=[dog, veil]))

  # You can use this in future requests and it has even more info!
  createdConcepts = res.concepts

print(createdConcepts)

# Build a new model for custom training using that one concept.
# We won't train it because we haven't added any data in this example yet b
# but that isn't to hard.
mid = u"my_model人"  # use unicode character to make sure we encode properly.
res = stub.DeleteModel(DeleteModelRequest(model_id=mid))

m = Model(id=mid, output_info=OutputInfo(data=Data(concepts=createdConcepts)))

res = stub.GetModel(GetModelRequest(model_id=mid))
print(res)
if res.status.code == SUCCESS:
  print('Model already created')
  # You can use this in future requests and it has even more info!
  createdModel = res.model
else:
  # POST /concepts to create a new custom model.
  res = stub.PostModels(PostModelsRequest(models=[m]))

# Create an input labelled with our concept.
inputs = [
    Input(data=Data(
        image=Image(url="https://samples.clarifai.com/metro-north.jpg"), concepts=[dog, notveil])),
    Input(data=Data(
        image=Image(url="https://samples.clarifai.com/wedding.jpg"), concepts=[veil, notdog])),
    Input(data=Data(image=Image(url="https://samples.clarifai.com/gun.jpg"), concepts=[dog])),
    Input(data=Data(image=Image(url="https://samples.clarifai.com/logo.jpg"), concepts=[veil])),
]
# Add some metadata to the first one:
ParseDict({
    'saved_outputs_eid': 123,
    'ex.id': "abcd",
    'dataset_name': "hello world",
    'bool': True,
}, inputs[0].data.metadata)

res = stub.PostInputs(PostInputsRequest(inputs=inputs))
res = stub.ListInputs(ListInputsRequest())

# Let's train the model.
res = stub.PostModelVersions(PostModelVersionsRequest(model_id=mid))
version_id = res.model.model_version.id
for i in range(60):
  res = stub.GetModelVersion(GetModelVersionRequest(model_id=mid, version_id=version_id))
  if res.model_version.status.code == MODEL_TRAINED:
    break
  print('Waiting on training to complete, status is: \n%s' % str(res.model_version.status))
  time.sleep(1)

# This is how you can get the general model.
# It's the same object in requests and responses so you can immediately passs it
# back in to the next request!!!
# This is the general model
res = stub.GetModel(GetModelRequest(model_id="aaa03c23b3724a16a56b629203edc62c"))
generalModel = res.model
print('general model:')
print(generalModel)

res = stub.GetModel(GetModelRequest(model_id=mid))
createdModel = res.model
print('trained model:')
print(createdModel)

# Finally let's make a new workflow with general model and my new custom model
wid = "my-workflow"
res = stub.GetWorkflow(GetWorkflowRequest(workflow_id=wid))
print(res)
if res.status.code == SUCCESS:
  print('Workflow already created')
  # You can use this in future requests and it has even more info!
  createdWorkflow = res.workflow
else:
  w = Workflow(
      id=wid,
      nodes=[
          WorkflowNode(id="1", model=createdModel),
          WorkflowNode(id="2", model=generalModel),
      ])
  res = stub.PostWorkflows(PostWorkflowsRequest(workflows=[w]))
  createdWorkflow = res.workflows[0]

print('created model:')
print(createdWorkflow)

################################
# Predict with the general model

# Create an input using a url.
iny = Input(data=Data(image=Image(url="https://samples.clarifai.com/metro-north.jpg")))

# Model predict!
res = stub.PostModelOutputs(
    PostModelOutputsRequest(
        model_id=generalModel.id, version_id=generalModel.model_version.id, inputs=[iny]))

print(res)

# CLIENT: if we wanted to send bytes we just load the file and send them.
# Note: the naming is funky but left over from json days to indicate that this field will actually
# base64 itself from this client when this proto bytes field converts to json.
iny = Input(data=Data(image=Image(base64=open("/Users/zeiler/metro-north.jpg"))))

# Model predict!
res = stub.PostModelOutputs(
    PostModelOutputsRequest(
        model_id=generalModel.id, version_id=generalModel.model_version.id, inputs=[iny]))

print(res)
