# Description:
#   Clarifai Protobufs

package(
    default_visibility = ["//visibility:public"],
)

load("//bazel:cf_python.bzl", "cf_py_library", "cf_py_test", "req")

package_group(
    name = "protos",
    packages = [
        "//proto/...",
    ],
)

filegroup(
    name = "all_files",
    srcs = glob(
        ["**/*"],
        exclude = [
            "**/METADATA",
            "**/OWNERS",
        ],
    ),
)

cc_library(
    name = "kepler_service_protos",
    deps = [
        "//proto/kepler:kepler_service_cc_proto",
    ],
)

cc_library(
    name = "endpoint_service_protos",
    deps = [
        "//proto/clarifai/api:endpoint_service_cc_proto",
    ],
)

cc_library(
    name = "sdk_protos",
    deps = [
        "//proto/clarifai/api/status:status_code_cc_proto",
        "//proto/spire:spire_cc_proto",
        "//proto/utils:proto_utils_all",
    ],
)

cc_library(
    name = "spire_service_protos",
    deps = [
        "//proto/spire:spire_service_cc_proto",
    ],
)

cc_library(
    name = "media_processor_service_protos",
    deps = [
        "//proto/media_processor:media_processor_service_cc_proto",
    ],
)

# Python libraries

# Nothing in here for now.
cf_py_library(
    name = "lib",
    srcs = ["__init__.py"],
    deps = [req("protobuf")],
)

# The generic gRPC server
cf_py_library(
    name = "grpc_server",
    srcs = ["grpc_server.py"],
    deps = [
        ":lib",
        "//proto/health_check:py",
        req("futures"),
        req("grpcio"),
    ],
)

cf_py_test(
    name = "test_embedding",
    srcs = ["test/test_embedding.py"],
    deps = [
        "//proto/utils:embedding",
        "//proto/utils:py",
    ],
)

cf_py_test(
    name = "test_grpc_json_channel",
    srcs = ["test/test_grpc_json_channel.py"],
    deps = [
        "//proto/clarifai/api:py",
        "//proto/clarifai/api/status:py",
        "//proto/clarifai/api/utils:py",
        "//proto/clarifai/utils/pagination:py",
        "//proto/utils:grpc_json_channel",
        "//proto/utils:py",
        "//utils:log",
    ],
)

cf_py_test(
    name = "test_grpc_server",
    srcs = ["test/test_grpc_server.py"],
    deps = [
        ":grpc_server",
        "//proto/clarifai/api/status:py",
        "//proto/utils:common",
        "//proto/utils:py",
        "//utils:lib",
        "//utils:log",
    ],
)

cf_py_test(
    name = "test_overwrite",
    srcs = ["test/test_overwrite.py"],
    deps = [
        "//proto/utils:common",
        "//utils:log",
    ],
)

cf_py_test(
    name = "test_image",
    srcs = ["test/test_image.py"],
    deps = [
        ":lib",
        "//proto/utils:py",
    ],
)
