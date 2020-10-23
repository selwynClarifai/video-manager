# Description:
#   Clarifai API status code protobufs

load("//bazel:cf_build_systems.bzl", "cf_proto_library")
load("//bazel:cf_python.bzl", "cf_autogen_py_library")

package(
    default_visibility = [
        "//proto:protos",
        "//py/svc/config_runner:__pkg__",
        "//py/svc/models:__pkg__",
    ],
)

cf_proto_library(
    name = "status_code_cc_proto",
    srcs = ["status_code.proto"],
)

cf_proto_library(
    name = "status_cc_proto",
    srcs = ["status.proto"],
    deps = [
        ":status_code_cc_proto",
    ],
)

cf_autogen_py_library(
    name = "py",
    srcs = glob(["*.py"]),
)
