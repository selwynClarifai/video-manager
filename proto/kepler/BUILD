# Description:
#   Kepler protos

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
    name = "kepler_cc_proto",
    srcs = ["kepler.proto"],
)

cf_proto_library(
    name = "kepler_service_cc_proto",
    srcs = ["kepler_service.proto"],
    has_services = 1,
    cc_grpc_version = 1,
    deps = [
        ":kepler_cc_proto",
    ],
)
