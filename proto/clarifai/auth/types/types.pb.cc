// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/clarifai/auth/types/types.proto

#include "proto/clarifai/auth/types/types.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace clarifai {
namespace auth {
namespace types {
}  // namespace types
}  // namespace auth
}  // namespace clarifai
static constexpr ::PROTOBUF_NAMESPACE_ID::Metadata* file_level_metadata_proto_2fclarifai_2fauth_2ftypes_2ftypes_2eproto = nullptr;
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_proto_2fclarifai_2fauth_2ftypes_2ftypes_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_proto_2fclarifai_2fauth_2ftypes_2ftypes_2eproto = nullptr;
const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_proto_2fclarifai_2fauth_2ftypes_2ftypes_2eproto::offsets[1] = {};
static constexpr ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema* schemas = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::Message* const* file_default_instances = nullptr;

const char descriptor_table_protodef_proto_2fclarifai_2fauth_2ftypes_2ftypes_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n%proto/clarifai/auth/types/types.proto\022"
  "\023clarifai.auth.types*`\n\010AuthType\022\t\n\005unde"
  "f\020\000\022\n\n\006NoAuth\020\001\022\013\n\007KeyAuth\020\002\022\024\n\020SessionT"
  "okenAuth\020\003\022\r\n\tAdminAuth\020\004\022\013\n\007PATAuth\020\005B)"
  "\n\027com.clarifai.auth.typesP\001Z\005types\242\002\004CAI"
  "Pb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_proto_2fclarifai_2fauth_2ftypes_2ftypes_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_proto_2fclarifai_2fauth_2ftypes_2ftypes_2eproto_sccs[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_proto_2fclarifai_2fauth_2ftypes_2ftypes_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2fclarifai_2fauth_2ftypes_2ftypes_2eproto = {
  false, false, descriptor_table_protodef_proto_2fclarifai_2fauth_2ftypes_2ftypes_2eproto, "proto/clarifai/auth/types/types.proto", 209,
  &descriptor_table_proto_2fclarifai_2fauth_2ftypes_2ftypes_2eproto_once, descriptor_table_proto_2fclarifai_2fauth_2ftypes_2ftypes_2eproto_sccs, descriptor_table_proto_2fclarifai_2fauth_2ftypes_2ftypes_2eproto_deps, 0, 0,
  schemas, file_default_instances, TableStruct_proto_2fclarifai_2fauth_2ftypes_2ftypes_2eproto::offsets,
  file_level_metadata_proto_2fclarifai_2fauth_2ftypes_2ftypes_2eproto, 0, file_level_enum_descriptors_proto_2fclarifai_2fauth_2ftypes_2ftypes_2eproto, file_level_service_descriptors_proto_2fclarifai_2fauth_2ftypes_2ftypes_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_proto_2fclarifai_2fauth_2ftypes_2ftypes_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_proto_2fclarifai_2fauth_2ftypes_2ftypes_2eproto)), true);
namespace clarifai {
namespace auth {
namespace types {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* AuthType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_proto_2fclarifai_2fauth_2ftypes_2ftypes_2eproto);
  return file_level_enum_descriptors_proto_2fclarifai_2fauth_2ftypes_2ftypes_2eproto[0];
}
bool AuthType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace types
}  // namespace auth
}  // namespace clarifai
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>