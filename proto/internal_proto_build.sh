#!/usr/bin/env bash
#
# Builds the python and go proto files so that you can commit them to the repo afterwards.
#
# If you want to build the client libraries (outside of golang) then
# you need to set the flag BUILD_CLIENTS=true at the top of this file.
#
# DO NOT RUN FROM TERMINAL DIRECTLY, use run_proto_build.sh instead which will make sure this is run
# from within a docker container that has all the right dependencies for building.
set -e

# Colors
readonly COLOR_BLACK=0
readonly COLOR_RED=1
readonly COLOR_GREEN=2
readonly COLOR_YELLOW=3
readonly COLOR_BLUE=4
readonly COLOR_MAGENTA=5
readonly COLOR_CYAN=6
readonly COLOR_WHITE=7

if [ `uname` = "Darwin" ]; then
    echo "$(tput setaf ${COLOR_RED})Do not use this file on macOS. $(tput sgr0)Use: $(tput setaf ${COLOR_CYAN})./proto/run_proto_build.sh $(tput sgr0)instead, which uses a docker Linux image."
    exit 1
fi

readonly BUILD_CPP_CLIENT=false
readonly BUILD_PYTHON_CLIENT=false # we now use this internally!
readonly BUILD_OTHER_CLIENTS=false  # java, js, obj-c

readonly PACKAGE_ROOT=/packages
readonly SOURCEDIR=$CLARIFAI_ROOT #$(dirname "${CLARIFAI_ROOT}")
readonly GOSOURCEDIR=$CLARIFAI_ROOT/go/src/clarifai
readonly PROTO_CLIENTS_DIR="proto_clients"
readonly CPPSOURCEDIR="${PROTO_CLIENTS_DIR}/cpp"
readonly JSSOURCEDIR="${PROTO_CLIENTS_DIR}/js"
readonly OBJCSOURCEDIR="${PROTO_CLIENTS_DIR}/objc"
readonly JAVASOURCEDIR="${PROTO_CLIENTS_DIR}/java"
# readonly SWIFT_SOURCE_DIR="${PROTO_CLIENTS_DIR}/swift"

IMPORT_TYPE_REMAPPER="Mgoogle/protobuf/any.proto=github.com/gogo/protobuf/types,"\
"Mgoogle/protobuf/timestamp.proto=github.com/gogo/protobuf/types,"\
"Mgoogle/protobuf/duration.proto=github.com/gogo/protobuf/types,"\
"Mgoogle/protobuf/struct.proto=github.com/gogo/protobuf/types,"\
"Mgoogle/protobuf/wrappers.proto=github.com/gogo/protobuf/types,"\
"Mgoogle/protobuf/descriptor.proto=github.com/gogo/protobuf/protoc-gen-gogo/descriptor,"\
"Mgoogle.golang.org/grpc=clarifai/vendor/,"\
"Mgoogle/api/annotations.proto=google.golang.org/genproto/googleapis/api/annotations"

# "Mgoogle/api/annotations.proto=github.com/gogo/googleapis/api/annotations"

# Path for the annotations.proto from google/api.
# In the Dockerfile we wget from the https://github.com/googleapis/googleapis/tree/master/google/api
# repo into the PACKAGE_ROTO. So we can use them from there rather than have old versions checked
# into our rep. Then above in IMPORT_TYPE_REMAPPER we confer that google/api/annotations.proto
# import to point to what we have in gopkg installs for the our server.
readonly ANNOTATIONS_PATH=$PACKAGE_ROOT/proto

function compile {
    FILE=$1
    PROTODIR=$(dirname "${FILE}")

    echo "$(tput setaf ${COLOR_BLUE})----------------------------------------------$(tput sgr0)"
    # For now until we need the other languages for the public
    # protos, let's skip building them so builds are faster and
    # dirs stay clean.
    # We only build the js/java/objc/c++ templates for protos that are public (ie, in
    # proto/clarfai/api) AND when BUILD_CLIENTS=true
    # Build C++ for internal tools always and optionally for clients.
    if (echo $FILE | grep -q "proto/clarifai/api" || \
        echo $FILE | grep -q "proto/clarifai/admin_api" || \
        echo $FILE | grep -q "proto/clarifai/analytics" || \
        echo $FILE | grep -q "proto/clarifai/commands" || \
        echo $FILE | grep -q "proto/clarifai/model_fetching" || \
        echo $FILE | grep -q "proto/clarifai/sdk_billing") && \
        ! echo $FILE | grep -q "proto/clarifai/api/status" && \
        [ "$BUILD_CPP_CLIENT" = false ]
    then
        echo "Skipping $(tput setaf ${COLOR_CYAN})$FILE$(tput sgr0) for $(tput setaf ${COLOR_GREEN})C++$(tput sgr0)"
    else
        # file is both a public proto (in proto/clarifai/api) and BUILD_CLIENTS=true
        echo "Building $(tput setaf ${COLOR_CYAN})$FILE$(tput sgr0) for $(tput setaf ${COLOR_GREEN})C++$(tput sgr0)"
        # cd $CLARIFAI_ROOT
        # # This builds the C++ protos and grpc client.
        mkdir -p $CPPSOURCEDIR
        protoc -I $SOURCEDIR \
            -I $ANNOTATIONS_PATH \
            --proto_path=$GOPATH/src/vendor \
            --cpp_out=$CPPSOURCEDIR \
            --grpc_out=$CPPSOURCEDIR \
            --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` \
            ${PROTODIR}/*.proto
    fi

    # For now until we need the other languages for the public
    # protos, let's skip building them so builds are faster and
    # dirs stay clean.
    # We only build the js/java/objc/c++ templates for protos that are public (ie, in
    # proto/clarfai/api) AND when BUILD_CLIENTS=true

    echo "Building $(tput setaf ${COLOR_CYAN})$FILE$(tput sgr0) for $(tput setaf ${COLOR_GREEN})Python$(tput sgr0)"
    cd $CLARIFAI_ROOT
    python -m grpc.tools.protoc \
        -I $SOURCEDIR \
        -I $ANNOTATIONS_PATH \
        --proto_path=$GOPATH/src/vendor \
        --python_out=$SOURCEDIR \
        --grpc_python_out=grpc_2_0:$SOURCEDIR \
        ${PROTODIR}/*.proto


    # Only build for other languages the client code (not the internal
    # protos).
    if (echo $FILE | grep -q "proto/clarifai/api" || \
        echo $FILE | grep -q "proto/clarifai/admin_api" || \
        echo $FILE | grep -q "proto/clarifai/utils" || \
        echo $FILE | grep -q "proto/clarifai/analytics" || \
        echo $FILE | grep -q "proto/clarifai/commands" || \
        echo $FILE | grep -q "proto/clarifai/sdk_billing" || \
        echo $FILE | grep -q "proto/utils") && \
        [ $BUILD_OTHER_CLIENTS = true ]
    then
        echo "Building $(tput setaf ${COLOR_CYAN})$FILE$(tput sgr0) for $(tput setaf ${COLOR_GREEN})Java, JS, and Obj-C$(tput sgr0)"
        cd $CLARIFAI_ROOT
        # For grpc:
        # Look at these tutorials for how to generate the code:
        # http://www.grpc.io/docs/tutorials/
        # java you use the protoc build plugin to Gradel or Maven
        # node.js you use npm install.
        # js in browsers needs the grpc-web standard instead
        # objc you can use cocoa pods to set things up.
        mkdir -p "$JSSOURCEDIR" "$OBJCSOURCEDIR" "$JAVASOURCEDIR"
        #"$SWIFT_SOURCE_DIR"
        protoc -I $SOURCEDIR \
            -I $ANNOTATIONS_PATH \
            --proto_path=$GOPATH/src/vendor \
            --js_out=$JSSOURCEDIR \
            --objc_out=$OBJCSOURCEDIR \
            --java_out=$JAVASOURCEDIR \
            ${PROTODIR}/*.proto
            # --objcgrpc_out=$OBJCSOURCEDIR \
            # --swift_out="$SWIFT_SOURCE_DIR" \
    else
        echo "Skipping $(tput setaf ${COLOR_CYAN})$FILE$(tput sgr0) for $(tput setaf ${COLOR_GREEN})Java, JS, and Obj-C$(tput sgr0)"
    fi

    # Only build for Go client code

    echo "Building $(tput setaf ${COLOR_CYAN})$FILE$(tput sgr0) for $(tput setaf ${COLOR_GREEN})Go$(tput sgr0)"
    cd $CLARIFAI_ROOT
    python -m grpc.tools.protoc \
            -I $SOURCEDIR  \
            -I $ANNOTATIONS_PATH \
            --proto_path=$GOPATH/src/vendor \
            --gogofast_out=plugins=grpc,protoc-gen-grpc="$( which protoc-gen-gogofast )",$IMPORT_TYPE_REMAPPER:$GOSOURCEDIR \
            ${PROTODIR}/*.proto

    # We don't need grpc-gateway for anything outside
    # api, admin_api and analytics folders
    # Note: we use ls to check here so that *.proto FILE paths will expand.
    if ls $FILE | grep -q "clarifai/api/service" || \
       ls $FILE | grep -q "clarifai/model_fetching/service" || \
       ls $FILE | grep -q "clarifai/admin_api/service" || \
       ls $FILE | grep -q "clarifai/analytics/service" || \
       ls $FILE | grep -q "clarifai/bulk_data_service/service" || \
       ls $FILE | grep -q "clarifai/sdk_billing/service"

    then
    	# For gprc-gateway service.
    	echo "Building $(tput setaf ${COLOR_CYAN})$FILE$(tput sgr0) for $(tput setaf ${COLOR_GREEN})Go grpc-gateway routes$(tput sgr0)"
    	cd $CLARIFAI_ROOT
    	python -m grpc.tools.protoc \
                -I $SOURCEDIR \
                -I $ANNOTATIONS_PATH \
                --proto_path=$GOPATH/src/vendor \
                --grpc-gateway_out=allow_delete_body=true,request_context=true,logtostderr=true,$IMPORT_TYPE_REMAPPER:$GOSOURCEDIR \
                ${PROTODIR}/*.proto
    fi

    # Update mock client when api/endpoint is updated
    # Use array to store the configs
    # may add more mock client in the future
    # package: go package, mocked_interface: go client to be mocked
    # destination: generated file path, proto_file: proto file path
    local MOCK_TARGETS
    MOCK_TARGETS+=("clarifai/proto/clarifai/api:V2Client:$CLARIFAI_ROOT/go/src/clarifai/mock/mock_api_client/mock_api_client.go:clarifai/api/service")
    for tuple in "${MOCK_TARGETS[@]}"
    do
        package=$(echo $tuple | cut -f1 -d:)
        mocked_interface=$(echo $tuple | cut -f2 -d:)
        destination=$(echo $tuple | cut -f3 -d:)
        proto_file=$(echo $tuple | cut -f4 -d:)
        if ls $FILE | grep -q $proto_file
        then

            echo "Generating mock client $(tput setaf ${COLOR_CYAN})$mocked_interface$(tput sgr0) for package $(tput setaf ${COLOR_GREEN})$package$(tput sgr0)"
            # NOTE(xinli): GOPATH of container and clarifai package are different
            # so change to /work/clarifai/go to run mockgen and change back after
            # Also update Dockerfile if there's a new dependent package
            GOPATH="$GOPATH:/work/clarifai/go" mockgen $package $mocked_interface > $destination
        fi
    done

}

function recurse {
    # Recurse over and over through the directories looking for proto files to build.
    if [[ -d "$1" ]]; then
	# Here we check if this current directory has .proto files and if so builds them
	# all together in one call to compile.
	if [[ $(ls $1/*.proto 2> /dev/null) ]]; then
	    echo "Compiling directory with protos:$(tput setaf ${COLOR_CYAN}) $1 $(tput sgr0)"
	    compile "$1/*.proto"
	fi
	# Then we go through any directories in this directory and recurse.
        for dir in $1/*; do
	    if [[ -d "$dir" ]]; then
		echo "Recursing down into directory:$(tput setaf ${COLOR_CYAN}) $dir $(tput sgr0)"
		recurse $dir
	    fi
        done
    elif [[ $1 == *.proto ]]; then
        # If we ever land on a single proto file (like the user passes it in) then we compile.
        echo "Compiling proto file:$(tput setaf ${COLOR_CYAN}) $1 $(tput sgr0)"
        compile $1
    fi
}

function getDeps {
    if [[ -d "$1" ]]; then
        for file in "$1"/*; do
            getDeps $file
        done
    elif [[ $1 == *.proto ]]; then
        # Example: proto/clarifai/api/concepts.proto
        CURR=${1#$CLARIFAI_ROOT/}
        # Example: clarifai/api/concepts.proto
        PROTOLESS=${CURR#proto/}
        # Example: clarifai/api
        DIR="$(dirname "${PROTOLESS}")"
        IMPORT_TYPE_REMAPPER="$IMPORT_TYPE_REMAPPER,M$CURR=clarifai/proto/$DIR"
    fi
}

# Always get dep for everything under $CLARIFAI_ROOT/proto since a proto file can directly
# or transitively depend on any other proto file
getDeps $CLARIFAI_ROOT/proto
echo $IMPORT_TYPE_REMAPPER

for path in "$@"; do
    pattern="${CLARIFAI_ROOT}/proto(/.*)?"
    if ! [[ "$path" =~ $pattern ]]; then
        echo "$(tput setaf ${COLOR_RED})All paths must be in $(tput setaf ${COLOR_CYAN})$CLARIFAI_ROOT/proto$(tput sgr0); received: $(tput setaf ${COLOR_CYAN})$qualified_path$(tput sgr0)" 1>&2
        exit 1
    fi
    echo "Building protos in $(tput setaf ${COLOR_CYAN})$path$(tput sgr0)"
    recurse $path
done

# NOTE(zeiler): this makes sure that the names of any fields used inside the .pb.go files match the
# json field names that the golang json project expects (jsonpb). This is required when
# you load a reference from the DB that itself has a proto (such as the Workflow struct which has
# the utils.WorkflowGraph in it). This is because the naming convention for the .pb.go file seems to
# screw up the `json` field (uses underscores) but not the `protobuf` field (uses camelCase as
# expected by jsonpb). When loading only one layer we use jsonpb so it works, but if we load the
# proto within another json then the json package is used and the names in the DB (camelCase) json
# no longer match those defined in the `json` field of the .pb.go
# file.

echo "Finishing up by cleaning the .pb.go files so their json support works with json package"
find "$GOSOURCEDIR/proto" -name "*.pb.go" -print -exec $CLARIFAI_ROOT/proto/go_proto_clean.py {} +

echo "🎉 $(tput setaf ${COLOR_GREEN})Success$(tput sgr0)"

exit 0
