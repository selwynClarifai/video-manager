#!/bin/bash
# Installs the protoc dependencies in a docker container, build anywhere
#
# To rebuild the docker image that is used to build the protos, run this script with the flags
# modified below such as BUILD_IMAGE_LOCALLY and PUSH_TO_REGISTRY. You should only have to do this
# when some dependency like protobuf or grpc version changes.
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

DOCKER_FILENAME="Dockerfile"
DOCKER_IMAGE_TAG=$(docker run --rm -v $CLARIFAI_ROOT/proto/$DOCKER_FILENAME:/tmp/$DOCKER_FILENAME:ro alpine sh -c "md5sum /tmp/$DOCKER_FILENAME | awk '{print \$1}'")
DOCKER_IMAGE_NAME="282244745782.dkr.ecr.us-east-1.amazonaws.com/clarifai/proto"
WORK_DIR=/work/clarifai
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# TODO: convert these to proper bash flags

# Set this flag to not build the image locally automatically when missing
DISABLE_AUTO_BUILD_IMAGE_LOCALLY=${DISABLE_AUTO_BUILD_IMAGE_LOCALLY:-false}
# Set this flag to not push the image to the docker image registry automatically when built
DISABLE_AUTO_PUSH_TO_REGISTRY=${DISABLE_AUTO_PUSH_TO_REGISTRY:-false}
# when developing, sometimes you don't want to build right away'
BUILD_PROTOS_IMMEDIATELY=${BUILD_PROTOS_IMMEDIATELY:-true}

# are one or more path argument specified?:
if [ $# -gt 0 ]; then
    paths=( "$@" )
    parsed_paths=()
    # for each one, check validity:
    for path in "${paths[@]}"; do
        # if $path doesn't start with '/' prefix with the current dir. OSX doesn't have
        # realpath -- nor do we want it, as a file's canonical path might not reveal that
        # it can be reached from $CLARIFAI_ROOT/proto/
        qualified_path=$([[ "$path" == /* ]] && echo "$path" || echo "$PWD/$path")
        pattern="${CLARIFAI_ROOT}/proto(/.*)?"
        if ! [[ "$qualified_path" =~ $pattern ]]; then
            echo "All paths must be in $CLARIFAI_ROOT/proto; received: $qualified_path" 1>&2
            exit 1
        fi
        # translate the path into a path valid inside of the docker container:
        parsed_paths+=( "${WORK_DIR}/${qualified_path#${CLARIFAI_ROOT}/}" )
    done
else
    parsed_paths=( "${WORK_DIR}/proto" )
fi

build_docker_image_locally () {
    if [ "${DISABLE_AUTO_BUILD_IMAGE_LOCALLY}" = true ]; then
        echo "Skipping docker build, flag not enabled"
    else
        # this is really expensive, can take 20-30 minutes to build
        NUM_CPU_CORES=$(docker run --rm alpine sh -c "cat /proc/cpuinfo | grep processor | wc -l")
        docker build -t ${DOCKER_IMAGE_NAME}:${DOCKER_IMAGE_TAG} -f ${SCRIPT_DIR}/${DOCKER_FILENAME} --cpuset-cpus 0-$((${NUM_CPU_CORES}-1)) .
        docker tag ${DOCKER_IMAGE_NAME}:${DOCKER_IMAGE_TAG} ${DOCKER_IMAGE_NAME}:latest
    fi
}

push_docker_image_to_registry () {
    if [ "${DISABLE_AUTO_PUSH_TO_REGISTRY}" = true ]; then
        echo "Skipping pushing to registry, flag not enabled"
    else
        # push to registry if the flag is set
        if docker inspect ${DOCKER_IMAGE_NAME}:${DOCKER_IMAGE_TAG}; then
            docker tag ${DOCKER_IMAGE_NAME}:${DOCKER_IMAGE_TAG} ${DOCKER_IMAGE_NAME}:latest
            docker push ${DOCKER_IMAGE_NAME}:${DOCKER_IMAGE_TAG}
            docker push ${DOCKER_IMAGE_NAME}:latest
        else
            echo "Skipping push to registry, missing local build"
        fi
    fi
}

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
            build_docker_image_locally
            push_docker_image_to_registry
        fi
    else
        echo "Docker image already exists locally"
    fi
}

echo "Beginning to check for docker image $DOCKER_IMAGE_NAME:$DOCKER_IMAGE_TAG"
pull_docker_image
echo "Complete dealing with for docker image $DOCKER_IMAGE_NAME:$DOCKER_IMAGE_TAG"

if [ "$BUILD_PROTOS_IMMEDIATELY" = true ]; then
    cd $CLARIFAI_ROOT/proto
    # runs the docker command
    echo ""
    echo "Generating protobufs"
    docker run --rm -it \
        -v $CLARIFAI_ROOT:$WORK_DIR \
        -w $WORK_DIR/proto \
        -u $(id -u):$(id -g) \
        $DOCKER_IMAGE_NAME:$DOCKER_IMAGE_TAG \
        /bin/bash internal_proto_build.sh "${parsed_paths[@]}"
fi
