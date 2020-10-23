# Description:
#   Utility protos that make up the DataExample and DataBatch

load("//bazel:cf_build_systems.bzl", "cf_proto_library")
load("//bazel:cf_python.bzl", "cf_autogen_py_library", "cf_py_library", "req")

package(default_visibility = ["//visibility:public"])

# package(
#     # TODO: keep? make public to all callers?
#     default_visibility = [
#         "//conf/logos:__pkg__",
#         "//datasets:__pkg__",
#         "//proto:protos",
#         "//py/svc/config_runner:__pkg__",
#         "//py/svc/models:__pkg__",
#         "//utils/storage:__pkg__",
#     ],
# )

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

PROTO_UTILS_DEPS = [
    ":audio_cc_proto",
    ":bbox_cc_proto",
    ":boundingbox_cc_proto",
    ":checkpoint_cc_proto",
    ":data_provider_cc_proto",
    ":face_cc_proto",
    ":ndarray_cc_proto",
    ":point_cc_proto",
    ":saved_output_cc_proto",
    ":video_cc_proto",
    ":blur_result_cc_proto",
    ":color_result_cc_proto",
    ":databatch_cc_proto",
    ":frame_cc_proto",
    ":image_cc_proto",
    ":tag_cc_proto",
    ":workflow_cc_proto",
    ":caption_cc_proto",
    ":data_example_cc_proto",
    ":embedding_cc_proto",
    ":geo_cc_proto",
    ":lopq_code_cc_proto",
    ":lopq_service_cc_proto",
    ":request_meta_cc_proto",
    ":train_config_cc_proto",
    ":vocab_cc_proto",
    "//proto/clarifai/api/utils:extensions_cc_proto",
]

cc_library(
    name = "proto_utils_all",
    visibility = ["//visibility:public"],
    deps = PROTO_UTILS_DEPS,
    alwayslink = 1,
)

cf_proto_library(
    name = "audio_cc_proto",
    srcs = ["audio.proto"],
    deps = [
        ":ndarray_cc_proto",
    ],
)

cf_proto_library(
    name = "bbox_cc_proto",
    srcs = ["bbox.proto"],
    deps = [
        "//proto/clarifai/api/utils:extensions_cc_proto",
    ],
)

cf_proto_library(
    name = "boundingbox_cc_proto",
    srcs = ["boundingbox.proto"],
    deps = [
        ":embedding_cc_proto",
        ":tag_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
    ],
)

cf_proto_library(
    name = "blur_result_cc_proto",
    srcs = ["blur_result.proto"],
    deps = [
        ":boundingbox_cc_proto",
        ":request_meta_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
    ],
)

cf_proto_library(
    name = "caption_cc_proto",
    srcs = ["caption.proto"],
    deps = [
        ":ndarray_cc_proto",
        ":tag_cc_proto",
    ],
)

cf_proto_library(
    name = "checkpoint_cc_proto",
    srcs = ["checkpoint.proto"],
)

cf_proto_library(
    name = "color_result_cc_proto",
    srcs = ["color_result.proto"],
    deps = [
        ":request_meta_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
    ],
)

cf_proto_library(
    name = "data_example_cc_proto",
    srcs = ["data_example.proto"],
    deps = [
        ":audio_cc_proto",
        ":bbox_cc_proto",
        ":boundingbox_cc_proto",
        ":blur_result_cc_proto",
        ":caption_cc_proto",
        ":color_result_cc_proto",
        ":embedding_cc_proto",
        ":face_cc_proto",
        ":geo_cc_proto",
        ":image_cc_proto",
        ":lopq_code_cc_proto",
        ":request_meta_cc_proto",
        ":point_cc_proto",
        ":saved_output_cc_proto",
        ":tag_cc_proto",
        ":text_cc_proto",
        ":video_cc_proto",
        "//proto/clarifai/api/utils:extensions_cc_proto",
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)

cf_proto_library(
    name = "data_provider_cc_proto",
    srcs = ["data_provider.proto"],
)

cf_proto_library(
    name = "databatch_cc_proto",
    srcs = ["databatch.proto"],
    deps = [
        ":data_example_cc_proto",
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)

cf_proto_library(
    name = "pasting_data_provider_cc_proto",
    srcs = ["pasting_data_provider.proto"],
    deps = [
        ":data_provider_cc_proto",
    ],
)

cf_proto_library(
    name = "databatch_generator_cc_proto",
    srcs = ["databatch_generator.proto"],
    deps = [
        ":data_provider_cc_proto",
        ":pasting_data_provider_cc_proto",
    ],
)

cf_proto_library(
    name = "embedding_cc_proto",
    srcs = ["embedding.proto"],
    deps = [
        ":bbox_cc_proto",
    ]
)

cf_proto_library(
    name = "face_cc_proto",
    srcs = ["face.proto"],
    deps = [
        ":boundingbox_cc_proto",
        ":embedding_cc_proto",
        ":tag_cc_proto",
    ],
)

cf_proto_library(
    name = "frame_cc_proto",
    srcs = ["frame.proto"],
    deps = [
        ":image_cc_proto",
    ],
)

cf_proto_library(
    name = "geo_cc_proto",
    srcs = ["geo.proto"],
    deps = [
        "//proto/clarifai/api/utils:extensions_cc_proto",
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)

cf_proto_library(
    name = "image_cc_proto",
    srcs = ["image.proto"],
    deps = [
        ":ndarray_cc_proto",
    ],
)

cf_proto_library(
    name = "lopq_code_cc_proto",
    srcs = ["lopq_code.proto"],
    deps = [
        "//proto/clarifai/api/utils:extensions_cc_proto",
    ],
)

cf_proto_library(
    name = "lopq_service_cc_proto",
    srcs = ["lopq_service.proto"],
    deps = [
        "//proto/clarifai/api/utils:extensions_cc_proto",
    ],
)

cf_proto_library(
    name = "ndarray_cc_proto",
    srcs = ["ndarray.proto"],
)

cf_proto_library(
    name = "point_cc_proto",
    srcs = ["point.proto"],
    deps = [
        "//proto/clarifai/api/utils:extensions_cc_proto",
    ],
)

cf_proto_library(
    name = "proto_test_cc_proto",
    srcs = ["proto_test.proto"],
    deps = [
        ":request_meta_cc_proto",
    ],
)

cf_proto_library(
    name = "request_meta_cc_proto",
    srcs = ["request_meta.proto"],
    deps = [
        "//proto/clarifai/api/status:status_code_cc_proto",
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)

cf_proto_library(
    name = "saved_output_cc_proto",
    srcs = ["saved_output.proto"],
    deps = [
        ":ndarray_cc_proto",
    ],
)

cf_proto_library(
    name = "tag_cc_proto",
    srcs = ["tag.proto"],
)

cf_proto_library(
    name = "text_cc_proto",
    srcs = ["text.proto"],
)

cf_proto_library(
    name = "train_config_cc_proto",
    srcs = ["train_config.proto"],
    deps = [
        ":checkpoint_cc_proto",
        ":data_provider_cc_proto",
        ":databatch_generator_cc_proto",
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)

cf_proto_library(
    name = "video_cc_proto",
    srcs = ["video.proto"],
    deps = [
        ":frame_cc_proto",
        "@com_google_protobuf_cf//:cc_wkt_protos",
    ],
)

cf_proto_library(
    name = "vocab_cc_proto",
    srcs = ["vocab.proto"],
    deps = [
        ":tag_cc_proto",
    ],
)

cf_proto_library(
    name = "workflow_cc_proto",
    srcs = ["workflow.proto"],
)

cf_py_library(
    name = "embedding",
    srcs = ["embedding.py"],
    deps = [req("numpy")],
)

cf_autogen_py_library(
    name = "py",
    srcs = glob([
        "__init__.py",
        "*_pb2.py",
        "*_pb2_grpc.py",
    ]),
    deps = [
        "//proto/clarifai/api/utils:py",
    ],
)

cf_py_library(
    name = "common",
    srcs = ["common.py"],
    deps = [
        ":embedding",
        "//proto/clarifai/api/status:py",
        "//proto/spire:py",
        "//utils/tracing:lib",
    ],
)

cf_py_library(
    name = "grpc_json_channel",
    srcs = ["grpc_json_channel.py"],
    deps = [
        "//proto:lib",
        req("requests"),
    ],
)

# TODO: figure what to do with these. Are they used?
# grpc_json_walkthrough.py
