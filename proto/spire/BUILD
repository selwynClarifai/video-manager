# Description:
#   Spire protos

load("//bazel:cf_build_systems.bzl", "cf_proto_library")
load("//bazel:cf_python.bzl", "cf_autogen_py_library", "cf_py_binary", "cf_py_library")

package(
    default_visibility = [
        "//conf/spire:__pkg__",
        "//proto:protos",
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

cf_proto_library(
    name = "spire_cc_proto",
    srcs = ["spire.proto"],
    deps = [
        "//proto/utils:checkpoint_cc_proto",
        "//proto/utils:data_provider_cc_proto",
        "//proto/utils:databatch_cc_proto",
        "//proto/utils:request_meta_cc_proto",
        "//proto/utils:tag_cc_proto",
        "//proto/utils:vocab_cc_proto",
    ],
)

cf_proto_library(
    name = "spire_service_cc_proto",
    srcs = ["spire_service.proto"],
    has_services = 1,
    cc_grpc_version = 1,
    deps = [
        ":spire_cc_proto",
    ],
)

cf_autogen_py_library(
    name = "py",
    srcs = glob(
        ["**/*.py"],
    ),
    deps = [
        "//proto/utils:py",
    ],
)
