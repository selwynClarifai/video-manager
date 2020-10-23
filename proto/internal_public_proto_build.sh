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


readonly SOURCEDIR=$CLARIFAI_ROOT #$(dirname "${CLARIFAI_ROOT}")
readonly PROTO_CLIENTS_DIR="${CLARIFAI_ROOT}/public_clients"
readonly SWAGGERSOURCEDIR="${PROTO_CLIENTS_DIR}/swagger"
readonly GOSOURCEDIR="${PROTO_CLIENTS_DIR}/go"
readonly PYSOURCEDIR="${PROTO_CLIENTS_DIR}/py"
readonly CPPSOURCEDIR="${PROTO_CLIENTS_DIR}/cpp"
readonly CSHARPSOURCEDIR="${PROTO_CLIENTS_DIR}/csharp"
readonly PHPSOURCEDIR="${PROTO_CLIENTS_DIR}/php"
readonly JSSOURCEDIR="${PROTO_CLIENTS_DIR}/js"
readonly OBJCSOURCEDIR="${PROTO_CLIENTS_DIR}/objc"
readonly JAVASOURCEDIR="${PROTO_CLIENTS_DIR}/java"
readonly SWIFT_SOURCE_DIR="${PROTO_CLIENTS_DIR}/swift"

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

echo "Removing existing folder: $PROTO_CLIENTS_DIR"
rm -rf $PROTO_CLIENTS_DIR

mkdir -p \
      "$JSSOURCEDIR" \
      "$OBJCSOURCEDIR" \
      "$JAVASOURCEDIR" \
      "$PYSOURCEDIR" \
      "$SWAGGERSOURCEDIR" \
      "$GOSOURCEDIR" \
      "$CPPSOURCEDIR" \
      "$SWIFT_SOURCE_DIR" \
      "$CSHARPSOURCEDIR" \
      "$PHPSOURCEDIR"



function compile {
    FILE=$1
    PROTODIR=$(dirname "${FILE}")

    echo "$(tput setaf ${COLOR_BLUE})----------------------------------------------$(tput sgr0)"

    # Only build for other languages the client code (not the internal
    # protos).
    cd $CLARIFAI_ROOT
    # For grpc:
    # Look at these tutorials for how to generate the code:
    # http://www.grpc.io/docs/tutorials/
    # java you use the protoc build plugin to Gradel or Maven
    # node.js you use npm install.
    # js in browsers needs the grpc-web standard instead
    # objc you can use cocoa pods to set things up.

    echo "Building $(tput setaf ${COLOR_CYAN})$FILE$(tput sgr0) for $(tput setaf ${COLOR_GREEN})C++$(tput sgr0)"
    protoc -I $SOURCEDIR \
           -I $ANNOTATIONS_PATH \
           --proto_path=$GOPATH/src/vendor \
           --cpp_out=$CPPSOURCEDIR \
           --grpc_out=$CPPSOURCEDIR \
           --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` \
          ${PROTODIR}/*.proto

    echo "Building $(tput setaf ${COLOR_CYAN})$FILE$(tput sgr0) for $(tput setaf ${COLOR_GREEN})PHP$(tput sgr0)"
    protoc -I $SOURCEDIR \
           -I $ANNOTATIONS_PATH \
           --proto_path=$GOPATH/src/vendor \
           --php_out=$PHPSOURCEDIR \
           --grpc_out=$PHPSOURCEDIR \
           --plugin=protoc-gen-grpc=`which grpc_php_plugin` \
          ${PROTODIR}/*.proto

    echo "Building $(tput setaf ${COLOR_CYAN})$FILE$(tput sgr0) for $(tput setaf ${COLOR_GREEN})C#$(tput sgr0)"
    protoc -I $SOURCEDIR \
           -I $ANNOTATIONS_PATH \
           --proto_path=$GOPATH/src/vendor \
           --csharp_out=$CSHARPSOURCEDIR \
           --grpc_out=$CSHARPSOURCEDIR \
           --plugin=protoc-gen-grpc=`which grpc_csharp_plugin` \
          ${PROTODIR}/*.proto

    echo "Building $(tput setaf ${COLOR_CYAN})$FILE$(tput sgr0) for $(tput setaf ${COLOR_GREEN})Python$(tput sgr0)"
    python -m grpc.tools.protoc \
        -I $SOURCEDIR \
        -I $ANNOTATIONS_PATH \
        --proto_path=$GOPATH/src/vendor \
        --python_out=$PYSOURCEDIR \
        --grpc_python_out=grpc_2_0:$PYSOURCEDIR \
        ${PROTODIR}/*.proto

    echo "Building $(tput setaf ${COLOR_CYAN})$FILE$(tput sgr0) for $(tput setaf ${COLOR_GREEN})Java$(tput sgr0)"
    PLUGIN_PROTOC_GEN_GRPC_JAVA=/usr/bin/protoc-gen-grpc-java.exe
    protoc \
        -I $SOURCEDIR \
        -I $ANNOTATIONS_PATH \
        --proto_path=$GOPATH/src/vendor \
        --plugin=protoc-gen-grpc-java=$PLUGIN_PROTOC_GEN_GRPC_JAVA \
        --grpc-java_out=$JAVASOURCEDIR \
        --java_out=$JAVASOURCEDIR \
        ${PROTODIR}/*.proto

    echo "Building $(tput setaf ${COLOR_CYAN})$FILE$(tput sgr0) for $(tput setaf ${COLOR_GREEN}) Go$(tput sgr0)"
    protoc \
        -I $SOURCEDIR \
        -I $ANNOTATIONS_PATH \
        --proto_path=$GOPATH/src/vendor \
        --gogofast_out=plugins=grpc,protoc-gen-grpc="$( which protoc-gen-gogofast )",$IMPORT_TYPE_REMAPPER:$GOSOURCEDIR \
        ${PROTODIR}/*.proto

    echo "Building $(tput setaf ${COLOR_CYAN})$FILE$(tput sgr0) for $(tput setaf ${COLOR_GREEN}) JS$(tput sgr0)"
    protoc \
        -I $SOURCEDIR \
        -I $ANNOTATIONS_PATH \
        --proto_path=$GOPATH/src/vendor \
        --js_out=import_style=commonjs:$JSSOURCEDIR \
        --grpc-web_out=import_style=commonjs,mode=grpcwebtext:$JSSOURCEDIR \
        ${PROTODIR}/*.proto

    # echo "Building $(tput setaf ${COLOR_CYAN})$FILE$(tput sgr0) for $(tput setaf ${COLOR_GREEN}) Obj-C$(tput sgr0)"
    # protoc \
    #     -I $SOURCEDIR \
    #     -I $ANNOTATIONS_PATH \
    #     --proto_path=$GOPATH/src/vendor \
    #     --objc_out=$OBJCSOURCEDIR \
    #     --objcgrpc_out=$OBJCSOURCEDIR \
    #     --plugin=protoc-gen-grpc=`which grpc_objc_plugin` \
    #     ${PROTODIR}/*.proto

    # echo "Building $(tput setaf ${COLOR_CYAN})$FILE$(tput sgr0) for $(tput setaf ${COLOR_GREEN}) Swift$(tput sgr0)"
    # protoc \
    #     -I $SOURCEDIR \
    #     -I $ANNOTATIONS_PATH \
    #     --proto_path=$GOPATH/src/vendor \
    #     --swift_out="$SWIFT_SOURCE_DIR" \
    #     --swiftgrpc_out=Client=true,Server=false:"$SWIFT_SOURCE_DIR" \
    #     --plugin=protoc-gen-grpc=`which grpc_swift_plugin` \
    #     ${PROTODIR}/*.proto

    # echo "Building $(tput setaf ${COLOR_CYAN})$FILE$(tput sgr0) for $(tput setaf ${COLOR_GREEN}) Ruby$(tput sgr0)"
    # protoc \
    #     -I $SOURCEDIR \
    #     -I $ANNOTATIONS_PATH \
    #     --proto_path=$GOPATH/src/vendor \
    #     --ruby_out="$RUBY_SOURCE_DIR" \
    #     --grpc_out="$RUBY_SOURCE_DIR" \
    #     --plugin=protoc-gen-grpc=`which grpc_ruby_plugin` \
    #     ${PROTODIR}/*.proto

    # Only generate the swagger file for the service.proto
    # file.
    # Note: we use ls to check here so that *.proto FILE paths will expand.
    service_proto="proto/clarifai/api/service.proto"
    if ls $FILE | grep -q "^${CLARIFAI_ROOT}/${service_proto}$"; then
        echo "Building $(tput setaf ${COLOR_CYAN})$FILE$(tput sgr0) for $(tput setaf ${COLOR_GREEN})Swagger$(tput sgr0)"
        cd $CLARIFAI_ROOT
        python -m grpc.tools.protoc \
            -I $SOURCEDIR \
            -I $ANNOTATIONS_PATH \
            --proto_path=$GOPATH/src/vendor \
            --swagger_out=allow_delete_body=true,logtostderr=true:$SWAGGERSOURCEDIR \
            ${PROTODIR}/*.proto
        # translate from "proto/clarifai/api/service.proto" -> ".*/proto/clarifai/api/service\.swagger\.json"
        swagger_regex=".*/${service_proto%.proto}\\.swagger\\.json"
        # Clean up the other swagger.json files other than services.swagger.json
        find "$SWAGGERSOURCEDIR/proto/clarifai/api" -name "*.swagger.json" ! -regex ".*/${swagger_regex}" -print -exec rm {} \;
    fi

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
getDeps $CLARIFAI_ROOT/proto/clarifai/api
getDeps $CLARIFAI_ROOT/proto/clarifai/auth

declare -a paths=("${CLARIFAI_ROOT}/proto/clarifai/api" "${CLARIFAI_ROOT}/proto/clarifai/auth")

for path in "${paths[@]}"; do
    echo "$path"
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
