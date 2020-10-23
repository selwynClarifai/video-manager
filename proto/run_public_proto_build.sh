#!/bin/bash
# Installs the protoc dependencies in a docker container, build anywhere
#
# To rebuild the docker image that is used to build the protos, run this script with the flags
# modified below such as BUILD_IMAGE_LOCALLY and PUSH_TO_REGISTRY. You should only have to do this
# when some dependency like protobuf or grpc version changes.
#
# If you are working on the swagger file, you can use the instructions here to generate static
# html files locally: https://github.com/swagger-api/swagger-codegen/tree/master#generating-dynamic-html-api-documentation
#
# Usage:
#  # To build all the protos under proto/ dir.
#  ./proto/run_proto_build.sh
#
#  # To build a specific single proto:
#  ./proto/run_proto_build.sh proto/clarifai/api/auth.proto
#
#  # To build a specific directory of protos:
#  ./proto/run_proto_build.sh "proto/clarifai/api"
#
set -eux

{
    git diff-index --quiet HEAD
} || {
    echo "You cannot have any uncommited changes when running this script because we will modify files in place and then check them back out after we're done."
    exit 1
}

DOCKER_FILENAME="Dockerfile"
DOCKER_IMAGE_TAG=$(docker run --rm -v $CLARIFAI_ROOT/proto/$DOCKER_FILENAME:/tmp/$DOCKER_FILENAME:ro alpine sh -c "md5sum /tmp/$DOCKER_FILENAME | awk '{print \$1}'")
DOCKER_IMAGE_NAME="282244745782.dkr.ecr.us-east-1.amazonaws.com/clarifai/proto"
WORK_DIR=/work/clarifai
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

pull_docker_image () {
    # check if the docker image already exists
    if [ "$(docker image ls | grep ${DOCKER_IMAGE_NAME} | grep ${DOCKER_IMAGE_TAG} | wc -l)" -eq "0" ]; then
        # login to ECR
        # pull the image from ecr
        $( aws ecr get-login --no-include-email )
        docker pull ${DOCKER_IMAGE_NAME}:${DOCKER_IMAGE_TAG} || true

        if [ "$(docker image ls | grep ${DOCKER_IMAGE_NAME} | grep ${DOCKER_IMAGE_TAG} | wc -l)" -eq "1" ]; then
            echo "Successfully pulled image"
        else
            echo "Could not get the docker image. Please run 'run_proto_build.sh' to build it locally."
        fi
    else
        echo "Docker image already exists locally"
    fi
}

echo "Beginning to check for docker image $DOCKER_IMAGE_NAME:$DOCKER_IMAGE_TAG"
pull_docker_image
echo "Complete dealing with for docker image $DOCKER_IMAGE_NAME:$DOCKER_IMAGE_TAG"

function recheckout {
    echo "Checking out the proto dir again to get back to the previous state with non-stripped protos."
    cd $CLARIFAI_ROOT
    git checkout proto
}
trap recheckout EXIT

# Strip out the private protos before compiling.
python $CLARIFAI_ROOT/utils/strip_proto_private_rpcs.py proto

echo ""
echo "Generating protobufs for public clients"
docker run --rm -it \
    -v $CLARIFAI_ROOT:$WORK_DIR \
    -w $WORK_DIR/proto \
    -u $(id -u):$(id -g) \
    $DOCKER_IMAGE_NAME:$DOCKER_IMAGE_TAG \
    /bin/bash internal_public_proto_build.sh



# Here we copy over the swagger file that defines the endpoints in the
# API. We copy it into a golang file so that we don't care about it's
# location and it will be compiled into the binary.

# Note(zeiler): it's a pain in the ass to get aws credentials
# inside docker securely. So to avoid that we just leverage the
# native OS here to copy to s3 the swagger output and update the
# swagger.pb.go file.
SWAGGERSOURCEDIR=$CLARIFAI_ROOT/public_clients/swagger
GOSOURCEDIR=$CLARIFAI_ROOT/go/src/clarifai
# Get a unique hash for s3.
MHASH=$(docker run --rm -v $SWAGGERSOURCEDIR/proto/clarifai/api/service.swagger.json:/tmp/service.swagger.json:ro alpine sh -c "md5sum /tmp/service.swagger.json | awk '{print \$1}'")
LOCAL_SWAGGER_PATH=$SWAGGERSOURCEDIR/proto/clarifai/api/service.swagger.json
aws s3 cp $LOCAL_SWAGGER_PATH "s3://clarifai-deploy/swaggers/swagger_$MHASH.json" --acl public-read

URLNAME=https://s3.amazonaws.com/clarifai-deploy/swaggers/swagger_$MHASH.json

# Note(zeiler): this package name must match those in proto/clarifai/api/
echo "package api

const (
	swaggerURL = \"$URLNAME\"
)
" > $GOSOURCEDIR/proto/clarifai/api/swagger.pb.go
    go fmt $GOSOURCEDIR/proto/clarifai/api/swagger.pb.go
