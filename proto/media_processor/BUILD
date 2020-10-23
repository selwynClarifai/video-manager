# Description:
#   Media Processor Protos

load("//bazel:cf_build_systems.bzl", "cf_proto_library")

package(
    default_visibility = ["//proto:protos"],
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
    name = "media_cc_proto",
    srcs = ["media.proto"],
)

cf_proto_library(
    name = "media_processor_service_cc_proto",
    srcs = ["media_processor.proto"],
    has_services = 1,
    cc_grpc_version = 1,
    deps = [
        ":media_cc_proto",
        "//proto/utils:databatch_cc_proto",
        "//proto/utils:request_meta_cc_proto",
    ],
)
