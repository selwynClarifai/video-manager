# Proto Buffers for Data

Here is a guide to the protocol buffers used at Clarifai for data storage, RPCs, databatches, etc.

proto3 is the only proto used at Clarifai!!!

[Protobuf 3 Guide](https://developers.google.com/protocol-buffers/docs/proto3#oneof)


## Installation
If you are just running our code but not re-building proto-buffers, then all you need is the pip
install of protobuffers or the go get line which are in utils/requirements.txt or
go/src/clarifai/glide.yaml respectively.

To compile the protobufs you need protoc which is now included in utils/install.sh because the
requirements.txt file installs `pip install grpcio-tools` for you:
ones:
```
$INSTALL_ROOT/utils/install.sh
```

You also need the grpc plugin for Go which you can install. :
```
$INSTALL_ROOT/scripts/amazon/install_amazon.sh setup_go
$INSTALL_ROOT/scripts/amazon/install_amazon.sh setup_proto_go
```

## Upgrading Proto Versions
This turns out to be a multi-step process right now.

### Updating the files
You have to update the following files whereever there is a protobuf
version or grpcio or grpcio-tools version as well as any golang
dependencies which are versioned by git hash (pick a hash that is
later than the release date of the protobuf and grpc releases you are
updating to).

```
utils/requirements.txt
scripts/amazon/install_amazon.sh
proto/Dockerfile
go/src/clarifai/glide.yaml
go/src/clarifai/glide.lock
```

### Building cached versions on OSX and Colo Ubuntu
We cache the built protos because they take about 30 minutes to
compile. You can do that simply by running the following in your new
branch that you are updating the proto version in:

```
./utils/install.sh
```

### Building the production protobuf version
Right now we use Ubuntu 14.04 inside the docker images but 16.04 on
the colo machines. Therefore before we can deploy to production we
have to build the protos for 14.04. This can be done with the
following line. This is needed because docker builds by default don't
get credentials backed into them, so you have to mount your aws
credentials with an older prebuild 14.04 docker image and trigger the
docker build which will push the cached protos to s3.

Log on to colo q3 and run this in one line
```
export WORK_DIR=/home/ubuntu/work/clarifai; docker run --rm -it
--env HOME=/home/ubuntu -v /home/zeiler/.aws:/home/ubuntu/.aws
-v $CLARIFAI_ROOT:$WORK_DIR -w $WORK_DIR/scripts/amazon/ conf/spire:latest
/bin/bash install_amazon.sh prebuild_proto_cpp
```

## Setup Editor
### Emacs
```
M-x package-install
protobuf-mode
```

## Design Doc

https://docs.google.com/document/d/1Ft4C8YVL-c6qBUgb2Jk8QerPzfTdaXMy6St35_PuUUo/edit#

## Things that are missing in proto3 (but were in proto2)
- required fields do not exists. All are optional.
- you cannot set the default values for fields, they have standard defaults by type but nothing more
than that.
- Extensions do not exist in proto3
- proto3 is still alpha so some parts might be buggy from Python. Example, HasField() doesn't have write behaviour.
 - wrapping primitive types so that they work nicely with the "Any" functionality in proto3 can be
 done using these wrappers: https://github.com/google/protobuf/blob/master/src/google/protobuf/wrappers.proto

## Writing Protos
Create a directory for all your new protos. This directory will be the same for Python and Go

You can import one proto into another using the import statement:
```
import "proto/utils/image.proto"

message Data {
  Image image = 1;
}
```

When you write a new proto, if you want to be able to compile them using Bazel, you must also add a corresopnding entry to the package `BUILD` file. If the package does not have an existing `BUILD` file, you can just create one. Note that if a package does not have a `BUILD` file (even an empty one), Bazel will not look inside the folder.

For the example above for message Data, the corresponding entry in the `BUILD` file looks like this:
```
cf_proto_library(
    name = "data_cc_proto",
    srcs = ["data.proto"],
    deps = [
        ":image_cc_proto",
    ],
)
```

## Compiling

### Bazel
To compile all the protobufs using Bazel, use the following command:
```
bazel build //proto:all_files
```
Alternatively, you can also compile specific proto libraries such as the protos used in the SDK Core or Spire service.
```
bazel build //proto:sdk_protos
bazel build //proto:spire_service_protos
```

### build.sh
The `./proto/run_proto_build.sh` file will build all of the protos. It uses an Ubuntu docker image so that even if you
build on OSX you get consistent builds.

This will create files such as ./proto/utils/image_pb2.py. Yes both proto2 and proto3 use the pb2
extension currently. Notice that we changed dir to the root directory first then included ".". This
is done so that all the imports you do in .proto files can use the full path from root and others
can find the proper proto definitions. For example, always use improt "proto/utils/tag.proto" in
your new .proto file instead of just import "tag.proto".

For Go code this also copies the compile .pb.go files to go/src/clarifai/proto/.


## Using Proto Buffers in Practice
### Python
The message interface is defined here for python:

https://developers.google.com/protocol-buffers/docs/reference/python/google.protobuf.message.Message-class

https://developers.google.com/protocol-buffers/docs/reference/python-generated#singular-fields-proto3

#### Checking if a field exists:
 - cannot do it for a singular non-message field
 - use HasField('blah') to see if a singulage message field called 'blah' was set.
 - use len(proto.repeated_field) to see if a repeated field has been set.


#### Extending a repeated field.

You simply use the .add() on the field name which creates a new instance of the Message. If using
DataBatch for example, that should be the only import you every need to do to get all of it's sub
fields. For example:
```python
from proto.utils.common import DataBatch
db = DataBatch()
data_example = databatch.example.add()
# You can also set the nested message fields and that creates an Image() without having to import.
data_example.image.encoded_bytes = "kadfakdfjasfl"
for i in range(10):
  tag = data_example.tag.add()
  tag.label_num = i
assert len(data.example) == 1
assert len(data.example.tag) == 10
```
