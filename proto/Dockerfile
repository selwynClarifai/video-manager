# Docker file to compile the protobuf files.
# Whenever you change this file, before merging to master, push the image to the registry.
# Usage in accompanying run_proto_build.sh script
FROM ubuntu:16.04

ENV CPUS 4
ENV GRPC_VERSION 1.23.0
ENV PROTOBUF_VERSION 3.9.1
ENV LATEST_PROTO $PROTOBUF_VERSION
ENV PACKAGE_ROOT "/packages"
ENV GO_VERSION 1.9.1
ENV CLARIFAI_ROOT "/work/clarifai"
ENV SWIFT_PLATFORM ubuntu16.04
ENV SWIFT_BRANCH swift-3.1.1-release
ENV SWIFT_VERSION swift-3.1.1-RELEASE
ENV SWIFT_PROTOBUF_TAG 0.9.902
ENV CLANG_VERSION 3.8
ENV GOOGLEAPIS_COMMON_PROTOS_VERSION 1.6.0

########################################
# prebuild_proto_cpp() {
# Step 1: for protoc and cpp/python install. Only once per release/OS combo.
# If you want to build from source and build cpp version which makes python faster!
# This is NOT required to get proto's working from Python. However the cpp impelmentation can be
# much faster.
# After this builds a new tar for s3 then you can call setup_proto_python to use it.
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        automake \
        autoconf \
        build-essential \
        curl \
        g++ \
        git \
        libssl-dev \
        libtool \
        make \
        openssl \
        pkg-config \
        python \
        python-dev \
        python-pip \
        wget \
        zlib1g-dev \
        libc6-dev \
        clang-$CLANG_VERSION \
        libedit-dev \
        libtinfo-dev \
        libicu-dev \
        libxml2 \
        libcurl4-openssl-dev \
        cmake \
        pkg-config && \
    update-alternatives --quiet --install /usr/bin/clang clang /usr/bin/clang-$CLANG_VERSION 100 && \
    update-alternatives --quiet --install /usr/bin/clang++ clang++ /usr/bin/clang++-$CLANG_VERSION 100 && \
    rm -rf /var/lib/apt/lists/*

########################################

#RUN echo "Pip install cython, protobuf and grpc" && \
RUN python -m pip install --upgrade pip && \
    python -m pip install setuptools && \
    python -m pip install --install-option="--no-cython-compile" Cython==0.27.3 && \
    python -m pip install protobuf==$LATEST_PROTO && \
    python -m pip install grpcio==$GRPC_VERSION grpcio-tools==$GRPC_VERSION && \
    python -m pip install awscli==1.12.1 && \
    python -m pip install future==0.17.1 && \
    python -m pip install googleapis-common-protos==$GOOGLEAPIS_COMMON_PROTOS_VERSION

########################################

# Download and install Swift
RUN SWIFT_URL=https://swift.org/builds/$SWIFT_BRANCH/$(echo "$SWIFT_PLATFORM" | tr -d .)/$SWIFT_VERSION/$SWIFT_VERSION-$SWIFT_PLATFORM.tar.gz && \
    curl -fSsL $SWIFT_URL -o swift.tar.gz && \
    curl -fSsL $SWIFT_URL.sig -o swift.tar.gz.sig && \
    export GNUPGHOME="$(mktemp -d)" && \
    set -e; \
        for key in \
          # pub   4096R/412B37AD 2015-11-19 [expires: 2017-11-18]
          #       Key fingerprint = 7463 A81A 4B2E EA1B 551F  FBCF D441 C977 412B 37AD
          # uid                  Swift Automatic Signing Key #1 <swift-infrastructure@swift.org>
          7463A81A4B2EEA1B551FFBCFD441C977412B37AD \
          # pub   4096R/21A56D5F 2015-11-28 [expires: 2017-11-27]
          #       Key fingerprint = 1BE1 E29A 084C B305 F397  D62A 9F59 7F4D 21A5 6D5F
          # uid                  Swift 2.2 Release Signing Key <swift-infrastructure@swift.org>
          1BE1E29A084CB305F397D62A9F597F4D21A56D5F \
          # pub   4096R/91D306C6 2016-05-31 [expires: 2018-05-31]
          #       Key fingerprint = A3BA FD35 56A5 9079 C068  94BD 63BC 1CFE 91D3 06C6
          # uid                  Swift 3.x Release Signing Key <swift-infrastructure@swift.org>
          A3BAFD3556A59079C06894BD63BC1CFE91D306C6 \
        ; do \
            gpg --quiet --keyserver ha.pool.sks-keyservers.net --recv-keys "$key"; \
        done && \
    gpg --batch --verify --quiet swift.tar.gz.sig swift.tar.gz && \
    tar -xzf swift.tar.gz --directory / --strip-components=1 && \
    rm -r "$GNUPGHOME" swift.tar.gz.sig swift.tar.gz

########################################

ENV UNPACKED_DIR protobuf-$LATEST_PROTO

RUN echo "Building protobuf cpp" && \
    set -eux && \
    mkdir -p $PACKAGE_ROOT && \
    cd $PACKAGE_ROOT && \
    # Get the latest beta-1 that comes with alot of the build tools already.
    wget -nv -O out.tar.gz https://github.com/google/protobuf/releases/download/v$LATEST_PROTO/protobuf-cpp-$LATEST_PROTO.tar.gz  && \
    tar -xf out.tar.gz && \
    rm out.tar.gz && \

    cd $UNPACKED_DIR && \

    ./configure && \
    make -j $CPUS && \
    make check -j $CPUS && \
    # This installs to /usr/local/lib which is fine inside docker container.
    make install -j $CPUS && \
    make clean

ENV LD_LIBRARY_PATH "/usr/local/lib"

# Build the Swift plugin for protobuf
RUN echo "Building the Swift plugin for protobuf" && \
    set -eux && \
    git clone https://github.com/apple/swift-protobuf.git && \
    cd swift-protobuf && \
    git checkout tags/$SWIFT_PROTOBUF_TAG && \
    swift build && \
    mv .build/debug/protoc-gen-swift /usr/bin && \
    cd .. && \
    rm -rf swift-protobuf

########################################
# setup_proto_go() {

ENV GOPATH "/work/go"
ENV GOROOT "/usr/local/go"
ENV PATH "$GOROOT/bin:$GOPATH/bin:$PATH"

RUN echo "Install protoc for go" && \
    echo $GOROOT && \
    mkdir -p $GOROOT/.. && \
    cd $GOROOT/.. && \
    wget -nv -O go.tar.gz https://storage.googleapis.com/golang/go${GO_VERSION}.linux-amd64.tar.gz && \
    tar -C /usr/local -xzf go.tar.gz && \
    rm go.tar.gz

RUN mkdir -p $GOPATH/src/clarifai && \
    go get github.com/Masterminds/glide && \
    go get github.com/Azure/azure-storage-blob-go/azblob && \
    go get github.com/cenkalti/backoff && \
    cd $GOPATH/src/clarifai && \
    echo 'package: clarifai\n\
import: \n\
- package: github.com/golang/protobuf \n\
  version: 925541529c1fa6821df4e44ce2723319eb2be768 \n\
  subpackages: \n\
  - jsonpb \n\
  - proto \n\
  - protoc-gen-go/descriptor \n\
  - ptypes \n\
  - ptypes/any \n\
  - ptypes/duration \n\
  - ptypes/struct \n\
  - ptypes/timestamp \n\
- package: github.com/gogo/protobuf \n\
  version: 1adfc126b41513cc696b209667c8656ea7aac67c \n\
  subpackages: \n\
  - gogoproto \n\
  - jsonpb \n\
  - proto \n\
  - protoc-gen-gogo \n\
  - protoc-gen-gogo/descriptor \n\
  - protoc-gen-gogofast \n\
  - sortkeys \n\
  - types \n\
- package: github.com/golang/glog \n\
  version: 23def4e6c14b4da8ac2ed8007337bc5eb5007998 \n\
- package: google.golang.org/genproto \n\
  version: de9f5e90fe9b278809363f08c2072d2f2a429de7 \n\
  subpackages: \n\
  - googleapis/api/annotations \n\
- package: github.com/grpc-ecosystem/grpc-gateway \n\
  version: 597c8c358cb7475bc9fc495af32f94065aa6b6e1 \n\
  subpackages: \n\
  - protoc-gen-swagger \n\
  - protoc-gen-grpc-gateway \n\
  - third_party/googleapis \n\
- package: github.com/golang/mock/mockgen \n\
  version: c34cdb4725f4c3844d095133c6e40e448b86589b \n\
    ' > glide.yaml && \
    glide install && \
    glide rebuild && \
    glide cache-clear && \
    rm -rf $GOPATH/pkg && \
    mv $GOPATH/src/clarifai/vendor $GOPATH/src && \
    rm -rf $GOPATH/src/clarifai

########################################

# get specific version of needed packages
RUN go get github.com/golang/mock/gomock && \
    cd $GOPATH/src/github.com/golang/mock/gomock && \
    git checkout v1.1.1 && \
    cd - && \
    go get github.com/Jeffail/gabs && \
    cd $GOPATH/src/github.com/Jeffail/gabs && \
    git checkout v1.2.0 && \
    cd -

RUN git clone -b v$GRPC_VERSION https://github.com/grpc/grpc && \
    cd grpc && \
    git submodule update --init && \
    make -j $CPUS && \
    make install

# Get the java protoc compiler.
RUN wget http://central.maven.org/maven2/io/grpc/protoc-gen-grpc-java/${GRPC_VERSION}/protoc-gen-grpc-java-${GRPC_VERSION}-linux-x86_64.exe \
   -O /usr/bin/protoc-gen-grpc-java.exe && \
   chmod a+x /usr/bin/protoc-gen-grpc-java.exe

# Get the grpc-web protoc compiler
RUN wget https://github.com/grpc/grpc-web/releases/download/1.0.6/protoc-gen-grpc-web-1.0.6-linux-x86_64 \
  -O /usr/bin/protoc-gen-grpc-web && \
  chmod a+x /usr/bin/protoc-gen-grpc-web

# We need to get the googleapis protos from here https://github.com/googleapis/api-common-protos
RUN mkdir -p $PACKAGE_ROOT/proto/google/api && \
  wget -O $PACKAGE_ROOT/proto/google/api/annotations.proto https://raw.githubusercontent.com/googleapis/api-common-protos/master/google/api/annotations.proto && \
  wget -O $PACKAGE_ROOT/proto/google/api/http.proto https://raw.githubusercontent.com/googleapis/api-common-protos/master/google/api/http.proto


RUN echo "Check final versions" && \
    bash -c "set -eux && \
    echo '[go version]' && go version && \
    echo '[python -m grpc.tools.protoc --version]' && python -m grpc.tools.protoc --version && \
    echo '[protoc --version]' && protoc --version && \
    echo '[which grpc_cpp_plugin]' && which grpc_cpp_plugin && \
    echo '[pip freeze | grep grpc]' && pip freeze | grep grpc && \
    echo '[glide: --version]' && glide --version && \
    2>&1 " | tee /versions.txt

########################################

VOLUME $CLARIFAI_ROOT
