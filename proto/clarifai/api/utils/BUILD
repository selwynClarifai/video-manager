# Description:
#   Clarifai API status code protobufs

load("//bazel:cf_build_systems.bzl", "cf_proto_library")
load("//bazel:cf_python.bzl", "cf_autogen_py_library")

package(default_visibility = ["//visibility:public"])

cf_proto_library(
    name = "extensions_cc_proto",
    srcs = ["extensions.proto"],
    deps = [
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)

cf_autogen_py_library(
    name = "py",
    srcs = glob(["*.py"]),
)
