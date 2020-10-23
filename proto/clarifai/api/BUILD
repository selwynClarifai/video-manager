# Description:
#   Spire protos

load("//bazel:cf_build_systems.bzl", "cf_proto_library")
load("//bazel:cf_python.bzl", "cf_autogen_py_library", "cf_py_library")

package(
    default_visibility = [
        "//datasets:__pkg__",
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
    name = "common_cc_proto",
    srcs = ["common.proto"],
)

cf_proto_library(
    name = "feedback_cc_proto",
    srcs = ["feedback.proto"],
)

cf_proto_library(
    name = "input_cc_proto",
    srcs = ["input.proto"],
    deps = [
        ":common_cc_proto",
        ":concept_cc_proto",
        ":data_cc_proto",
        ":feedback_cc_proto",
        ":model_cc_proto",
        "//proto/clarifai/api/status:status_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)

cf_proto_library(
    name = "app_cc_proto",
    srcs = ["app.proto"],
    deps = [
        ":common_cc_proto",
        ":input_cc_proto",
        "//proto/clarifai/api/status:status_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
    ],
)

cf_proto_library(
    name = "app_sharing_cc_proto",
    srcs = ["app_sharing.proto"],
    deps = [
        ":app_cc_proto",
        ":common_cc_proto",
        ":user_cc_proto",
        "//proto/clarifai/api/status:status_cc_proto",
    ],
)

cf_proto_library(
    name = "audio_cc_proto",
    srcs = ["audio.proto"],
)

cf_proto_library(
    name = "auth_cc_proto",
    srcs = ["auth.proto"],
    deps = [
        "//proto/clarifai/api/status:status_cc_proto",
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)

cf_proto_library(
    name = "code_cc_proto",
    srcs = ["code.proto"],
    deps = [
        "//proto/clarifai/api/status:status_cc_proto",
    ],
)

cf_proto_library(
    name = "concept_cc_proto",
    srcs = ["concept.proto"],
    deps = [
        ":common_cc_proto",
        "//proto/clarifai/api/status:status_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)

cf_proto_library(
    name = "concept_graph_cc_proto",
    srcs = ["concept_graph.proto"],
    deps = [
        ":common_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
    ],
)

cf_proto_library(
    name = "concept_language_cc_proto",
    srcs = ["concept_language.proto"],
    deps = [
        ":common_cc_proto",
        "//proto/clarifai/api/status:status_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
    ],
)

cf_proto_library(
    name = "concept_reference_cc_proto",
    srcs = ["concept_reference.proto"],
    deps = [
        ":common_cc_proto",
        "//proto/clarifai/api/status:status_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
    ],
)

cf_proto_library(
    name = "healthz_cc_proto",
    srcs = ["healthz.proto"],
    deps = [
        "//proto/clarifai/api/status:status_cc_proto",
    ],
)

cf_proto_library(
    name = "key_cc_proto",
    srcs = ["key.proto"],
    deps = [
        ":app_cc_proto",
        ":common_cc_proto",
        "//proto/clarifai/api/status:status_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)

cf_proto_library(
    name = "cluster_cc_proto",
    srcs = ["cluster.proto"],
)

cf_proto_library(
    name = "color_cc_proto",
    srcs = ["color.proto"],
    deps = [
        "//proto/clarifai/api/utils:extensions_cc_proto",
    ],
)

cf_proto_library(
    name = "embedding_cc_proto",
    srcs = ["embedding.proto"],
)

cf_proto_library(
    name = "face_cc_proto",
    srcs = ["face.proto"],
    deps = [
        ":concept_cc_proto",
    ],
)

cf_proto_library(
    name = "focus_cc_proto",
    srcs = ["focus.proto"],
    deps = [
        "//proto/clarifai/api/utils:extensions_cc_proto",
    ],
)

cf_proto_library(
    name = "geo_cc_proto",
    srcs = ["geo.proto"],
    deps = [
        "//proto/clarifai/api/utils:extensions_cc_proto",
    ],
)

cf_proto_library(
    name = "image_cc_proto",
    srcs = ["image.proto"],
)

cf_proto_library(
    name = "video_cc_proto",
    srcs = ["video.proto"],
)

cf_proto_library(
    name = "data_cc_proto",
    srcs = ["data.proto"],
    deps = [
        ":audio_cc_proto",
        ":cluster_cc_proto",
        ":color_cc_proto",
        ":common_cc_proto",
        ":concept_cc_proto",
        ":embedding_cc_proto",
        ":face_cc_proto",
        ":focus_cc_proto",
        ":geo_cc_proto",
        ":image_cc_proto",
        ":text_cc_proto",
        ":video_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)

cf_proto_library(
    name = "text_cc_proto",
    srcs = ["text.proto"],
    deps = [
        ":common_cc_proto",
        "//proto/clarifai/api/status:status_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)

cf_proto_library(
    name = "license_cc_proto",
    srcs = ["license.proto"],
    deps = [
        ":common_cc_proto",
        ":model_cc_proto",
        "//proto/clarifai/api/status:status_cc_proto",
    ],
)

cf_proto_library(
    name = "model_version_cc_proto",
    srcs = ["model_version.proto"],
    deps = [
        ":common_cc_proto",
        ":concept_cc_proto",
        "//proto/clarifai/api/status:status_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
        "//proto/utils:lopq_service_cc_proto",
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)

cf_proto_library(
    name = "model_cc_proto",
    srcs = ["model.proto"],
    deps = [
        ":common_cc_proto",
        ":concept_cc_proto",
        ":data_cc_proto",
        ":model_version_cc_proto",
        "//proto/clarifai/api/status:status_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)

cf_proto_library(
    name = "output_cc_proto",
    srcs = ["output.proto"],
    deps = [
        ":common_cc_proto",
        ":data_cc_proto",
        ":input_cc_proto",
        ":model_cc_proto",
        "//proto/clarifai/api/status:status_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)

cf_proto_library(
    name = "scope_cc_proto",
    srcs = ["scope.proto"],
    deps = [
        ":app_cc_proto",
        "//proto/clarifai/api/status:status_cc_proto",
    ],
)

cf_proto_library(
    name = "search_cc_proto",
    srcs = ["search.proto"],
    deps = [
        ":common_cc_proto",
        ":input_cc_proto",
        ":output_cc_proto",
        "//proto/clarifai/api/status:status_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
    ],
)

cf_proto_library(
    name = "subscription_cc_proto",
    srcs = ["subscription.proto"],
    deps = [
        "//proto/clarifai/api/status:status_cc_proto",
    ],
)

cf_proto_library(
    name = "usage_cc_proto",
    srcs = ["usage.proto"],
    deps = [
        ":auth_cc_proto",
        ":common_cc_proto",
        ":model_cc_proto",
        "//proto/clarifai/api/status:status_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)

cf_proto_library(
    name = "user_cc_proto",
    srcs = ["user.proto"],
    deps = [
        ":common_cc_proto",
        ":input_cc_proto",
        "//proto/clarifai/api/status:status_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)


cf_proto_library(
    name = "vocab_cc_proto",
    srcs = ["vocab.proto"],
    deps = [
        ":common_cc_proto",
        ":concept_cc_proto",
        "//proto/clarifai/api/status:status_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)

cf_proto_library(
    name = "worker_cc_proto",
    srcs = ["worker.proto"],
    deps = [
        ":common_cc_proto",
        "//proto/clarifai/api/status:status_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
    ],
)

cf_proto_library(
    name = "workflow_cc_proto",
    srcs = ["workflow.proto"],
    deps = [
        ":common_cc_proto",
        ":input_cc_proto",
        ":model_cc_proto",
        ":output_cc_proto",
        "//proto/clarifai/api/status:status_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)

cf_proto_library(
    name = "annotation_cc_proto",
    srcs = ["annotation.proto"],
    deps = [
        ":common_cc_proto",
        ":data_cc_proto",
        "//proto/clarifai/api/status:status_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)

cf_proto_library(
    name = "endpoint_service_cc_proto",
    srcs = ["endpoint.proto"],
    has_services = 1,
    cc_grpc_version = 1,
    deps = [
        ":annotation_cc_proto",
        ":app_cc_proto",
        ":app_sharing_cc_proto",
        ":auth_cc_proto",
        ":code_cc_proto",
        ":concept_cc_proto",
        ":concept_graph_cc_proto",
        ":concept_language_cc_proto",
        ":concept_reference_cc_proto",
        ":healthz_cc_proto",
        ":input_cc_proto",
        ":key_cc_proto",
        ":license_cc_proto",
        ":model_cc_proto",
        ":model_version_cc_proto",
        ":output_cc_proto",
        ":scope_cc_proto",
        ":search_cc_proto",
        ":subscription_cc_proto",
        ":usage_cc_proto",
        ":user_cc_proto",
        ":vocab_cc_proto",
        ":worker_cc_proto",
        ":workflow_cc_proto",
        "//proto/clarifai/api/status:status_cc_proto",
        "//proto/google/api:annotations_cc_proto",
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)

cf_autogen_py_library(
    name = "py",
    srcs = glob(
        ["*.py"],
    ),
    deps = [
        "//proto/clarifai/api/status:py",
        "//proto/google/api:py",
    ],
)
