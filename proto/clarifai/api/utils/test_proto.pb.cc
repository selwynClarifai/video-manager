// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/clarifai/api/utils/test_proto.proto

#include "proto/clarifai/api/utils/test_proto.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_TestProto2_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto;
namespace clarifai {
namespace api {
namespace utils {
class TestProtoDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<TestProto> _instance;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr string_oneof_;
  bool bool_oneof_;
  const ::clarifai::api::utils::TestProto2* message_oneof_;
} _TestProto_default_instance_;
class TestProto2DefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<TestProto2> _instance;
} _TestProto2_default_instance_;
}  // namespace utils
}  // namespace api
}  // namespace clarifai
static void InitDefaultsscc_info_TestProto_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::clarifai::api::utils::_TestProto_default_instance_;
    new (ptr) ::clarifai::api::utils::TestProto();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::clarifai::api::utils::TestProto::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_TestProto_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_TestProto_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto}, {
      &scc_info_TestProto2_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto.base,}};

static void InitDefaultsscc_info_TestProto2_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::clarifai::api::utils::_TestProto2_default_instance_;
    new (ptr) ::clarifai::api::utils::TestProto2();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::clarifai::api::utils::TestProto2::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_TestProto2_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_TestProto2_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::clarifai::api::utils::TestProto, _internal_metadata_),
  ~0u,  // no _extensions_
  PROTOBUF_FIELD_OFFSET(::clarifai::api::utils::TestProto, _oneof_case_[0]),
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::clarifai::api::utils::TestProto, id_),
  PROTOBUF_FIELD_OFFSET(::clarifai::api::utils::TestProto, message_),
  PROTOBUF_FIELD_OFFSET(::clarifai::api::utils::TestProto, value_),
  PROTOBUF_FIELD_OFFSET(::clarifai::api::utils::TestProto, image_bytes_),
  offsetof(::clarifai::api::utils::TestProtoDefaultTypeInternal, string_oneof_),
  offsetof(::clarifai::api::utils::TestProtoDefaultTypeInternal, bool_oneof_),
  offsetof(::clarifai::api::utils::TestProtoDefaultTypeInternal, message_oneof_),
  PROTOBUF_FIELD_OFFSET(::clarifai::api::utils::TestProto, one_of_field_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::clarifai::api::utils::TestProto2, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::clarifai::api::utils::TestProto2, id_),
  PROTOBUF_FIELD_OFFSET(::clarifai::api::utils::TestProto2, flip_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::clarifai::api::utils::TestProto)},
  { 13, -1, sizeof(::clarifai::api::utils::TestProto2)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::clarifai::api::utils::_TestProto_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::clarifai::api::utils::_TestProto2_default_instance_),
};

const char descriptor_table_protodef_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n)proto/clarifai/api/utils/test_proto.pr"
  "oto\022\022clarifai.api.utils\032)proto/clarifai/"
  "api/utils/extensions.proto\"\345\001\n\tTestProto"
  "\022\n\n\002id\030\001 \001(\t\022(\n\007message\030\002 \001(\tB\027\200\265\030\001\212\265\030\017p"
  "rotos are cool\022\026\n\005value\030\003 \001(\001B\007\325\265\030\000\000\200\?\022\023"
  "\n\013image_bytes\030\004 \001(\014\022\026\n\014string_oneof\030\005 \001("
  "\tH\000\022\024\n\nbool_oneof\030\006 \001(\010H\000\0227\n\rmessage_one"
  "of\030\007 \001(\0132\036.clarifai.api.utils.TestProto2"
  "H\000B\016\n\014one_of_field\"&\n\nTestProto2\022\n\n\002id\030\001"
  " \001(\t\022\014\n\004flip\030\002 \001(\010B(\n\026com.clarifai.api.u"
  "tilsP\001Z\005utils\242\002\004CAIPb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto_deps[1] = {
  &::descriptor_table_proto_2fclarifai_2fapi_2futils_2fextensions_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto_sccs[2] = {
  &scc_info_TestProto_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto.base,
  &scc_info_TestProto2_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto = {
  false, false, descriptor_table_protodef_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto, "proto/clarifai/api/utils/test_proto.proto", 428,
  &descriptor_table_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto_once, descriptor_table_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto_sccs, descriptor_table_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto_deps, 2, 1,
  schemas, file_default_instances, TableStruct_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto::offsets,
  file_level_metadata_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto, 2, file_level_enum_descriptors_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto, file_level_service_descriptors_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto)), true);
namespace clarifai {
namespace api {
namespace utils {

// ===================================================================

void TestProto::InitAsDefaultInstance() {
  ::clarifai::api::utils::_TestProto_default_instance_.string_oneof_.UnsafeSetDefault(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::clarifai::api::utils::_TestProto_default_instance_.bool_oneof_ = false;
  ::clarifai::api::utils::_TestProto_default_instance_.message_oneof_ = const_cast< ::clarifai::api::utils::TestProto2*>(
      ::clarifai::api::utils::TestProto2::internal_default_instance());
}
class TestProto::_Internal {
 public:
  static const ::clarifai::api::utils::TestProto2& message_oneof(const TestProto* msg);
};

const ::clarifai::api::utils::TestProto2&
TestProto::_Internal::message_oneof(const TestProto* msg) {
  return *msg->one_of_field_.message_oneof_;
}
void TestProto::set_allocated_message_oneof(::clarifai::api::utils::TestProto2* message_oneof) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  clear_one_of_field();
  if (message_oneof) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(message_oneof);
    if (message_arena != submessage_arena) {
      message_oneof = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, message_oneof, submessage_arena);
    }
    set_has_message_oneof();
    one_of_field_.message_oneof_ = message_oneof;
  }
  // @@protoc_insertion_point(field_set_allocated:clarifai.api.utils.TestProto.message_oneof)
}
TestProto::TestProto(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:clarifai.api.utils.TestProto)
}
TestProto::TestProto(const TestProto& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_id().empty()) {
    id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_id(),
      GetArena());
  }
  message_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_message().empty()) {
    message_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_message(),
      GetArena());
  }
  image_bytes_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_image_bytes().empty()) {
    image_bytes_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_image_bytes(),
      GetArena());
  }
  value_ = from.value_;
  clear_has_one_of_field();
  switch (from.one_of_field_case()) {
    case kStringOneof: {
      _internal_set_string_oneof(from._internal_string_oneof());
      break;
    }
    case kBoolOneof: {
      _internal_set_bool_oneof(from._internal_bool_oneof());
      break;
    }
    case kMessageOneof: {
      _internal_mutable_message_oneof()->::clarifai::api::utils::TestProto2::MergeFrom(from._internal_message_oneof());
      break;
    }
    case ONE_OF_FIELD_NOT_SET: {
      break;
    }
  }
  // @@protoc_insertion_point(copy_constructor:clarifai.api.utils.TestProto)
}

void TestProto::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_TestProto_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto.base);
  id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  message_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  image_bytes_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  value_ = 0;
  clear_has_one_of_field();
}

TestProto::~TestProto() {
  // @@protoc_insertion_point(destructor:clarifai.api.utils.TestProto)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void TestProto::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  message_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  image_bytes_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (has_one_of_field()) {
    clear_one_of_field();
  }
}

void TestProto::ArenaDtor(void* object) {
  TestProto* _this = reinterpret_cast< TestProto* >(object);
  (void)_this;
}
void TestProto::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void TestProto::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const TestProto& TestProto::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_TestProto_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto.base);
  return *internal_default_instance();
}


void TestProto::clear_one_of_field() {
// @@protoc_insertion_point(one_of_clear_start:clarifai.api.utils.TestProto)
  switch (one_of_field_case()) {
    case kStringOneof: {
      one_of_field_.string_oneof_.Destroy(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
      break;
    }
    case kBoolOneof: {
      // No need to clear
      break;
    }
    case kMessageOneof: {
      if (GetArena() == nullptr) {
        delete one_of_field_.message_oneof_;
      }
      break;
    }
    case ONE_OF_FIELD_NOT_SET: {
      break;
    }
  }
  _oneof_case_[0] = ONE_OF_FIELD_NOT_SET;
}


void TestProto::Clear() {
// @@protoc_insertion_point(message_clear_start:clarifai.api.utils.TestProto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  id_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  message_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  image_bytes_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  value_ = 0;
  clear_one_of_field();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* TestProto::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_id();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "clarifai.api.utils.TestProto.id"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string message = 2 [(.clarifai.api.utils.cl_show_if_empty) = true, (.clarifai.api.utils.cl_moretags) = "protos are cool"];
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_message();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "clarifai.api.utils.TestProto.message"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // double value = 3 [(.clarifai.api.utils.cl_default_float) = 1];
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 25)) {
          value_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // bytes image_bytes = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          auto str = _internal_mutable_image_bytes();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string string_oneof = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          auto str = _internal_mutable_string_oneof();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "clarifai.api.utils.TestProto.string_oneof"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bool bool_oneof = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 48)) {
          _internal_set_bool_oneof(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .clarifai.api.utils.TestProto2 message_oneof = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 58)) {
          ptr = ctx->ParseMessage(_internal_mutable_message_oneof(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* TestProto::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:clarifai.api.utils.TestProto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string id = 1;
  if (this->id().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_id().data(), static_cast<int>(this->_internal_id().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "clarifai.api.utils.TestProto.id");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_id(), target);
  }

  // string message = 2 [(.clarifai.api.utils.cl_show_if_empty) = true, (.clarifai.api.utils.cl_moretags) = "protos are cool"];
  if (this->message().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_message().data(), static_cast<int>(this->_internal_message().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "clarifai.api.utils.TestProto.message");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_message(), target);
  }

  // double value = 3 [(.clarifai.api.utils.cl_default_float) = 1];
  if (!(this->value() <= 0 && this->value() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(3, this->_internal_value(), target);
  }

  // bytes image_bytes = 4;
  if (this->image_bytes().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        4, this->_internal_image_bytes(), target);
  }

  // string string_oneof = 5;
  if (_internal_has_string_oneof()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_string_oneof().data(), static_cast<int>(this->_internal_string_oneof().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "clarifai.api.utils.TestProto.string_oneof");
    target = stream->WriteStringMaybeAliased(
        5, this->_internal_string_oneof(), target);
  }

  // bool bool_oneof = 6;
  if (_internal_has_bool_oneof()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(6, this->_internal_bool_oneof(), target);
  }

  // .clarifai.api.utils.TestProto2 message_oneof = 7;
  if (_internal_has_message_oneof()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        7, _Internal::message_oneof(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:clarifai.api.utils.TestProto)
  return target;
}

size_t TestProto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:clarifai.api.utils.TestProto)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string id = 1;
  if (this->id().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_id());
  }

  // string message = 2 [(.clarifai.api.utils.cl_show_if_empty) = true, (.clarifai.api.utils.cl_moretags) = "protos are cool"];
  if (this->message().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_message());
  }

  // bytes image_bytes = 4;
  if (this->image_bytes().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_image_bytes());
  }

  // double value = 3 [(.clarifai.api.utils.cl_default_float) = 1];
  if (!(this->value() <= 0 && this->value() >= 0)) {
    total_size += 1 + 8;
  }

  switch (one_of_field_case()) {
    // string string_oneof = 5;
    case kStringOneof: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_string_oneof());
      break;
    }
    // bool bool_oneof = 6;
    case kBoolOneof: {
      total_size += 1 + 1;
      break;
    }
    // .clarifai.api.utils.TestProto2 message_oneof = 7;
    case kMessageOneof: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *one_of_field_.message_oneof_);
      break;
    }
    case ONE_OF_FIELD_NOT_SET: {
      break;
    }
  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void TestProto::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:clarifai.api.utils.TestProto)
  GOOGLE_DCHECK_NE(&from, this);
  const TestProto* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<TestProto>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:clarifai.api.utils.TestProto)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:clarifai.api.utils.TestProto)
    MergeFrom(*source);
  }
}

void TestProto::MergeFrom(const TestProto& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:clarifai.api.utils.TestProto)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.id().size() > 0) {
    _internal_set_id(from._internal_id());
  }
  if (from.message().size() > 0) {
    _internal_set_message(from._internal_message());
  }
  if (from.image_bytes().size() > 0) {
    _internal_set_image_bytes(from._internal_image_bytes());
  }
  if (!(from.value() <= 0 && from.value() >= 0)) {
    _internal_set_value(from._internal_value());
  }
  switch (from.one_of_field_case()) {
    case kStringOneof: {
      _internal_set_string_oneof(from._internal_string_oneof());
      break;
    }
    case kBoolOneof: {
      _internal_set_bool_oneof(from._internal_bool_oneof());
      break;
    }
    case kMessageOneof: {
      _internal_mutable_message_oneof()->::clarifai::api::utils::TestProto2::MergeFrom(from._internal_message_oneof());
      break;
    }
    case ONE_OF_FIELD_NOT_SET: {
      break;
    }
  }
}

void TestProto::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:clarifai.api.utils.TestProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TestProto::CopyFrom(const TestProto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:clarifai.api.utils.TestProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TestProto::IsInitialized() const {
  return true;
}

void TestProto::InternalSwap(TestProto* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  id_.Swap(&other->id_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  message_.Swap(&other->message_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  image_bytes_.Swap(&other->image_bytes_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  swap(value_, other->value_);
  swap(one_of_field_, other->one_of_field_);
  swap(_oneof_case_[0], other->_oneof_case_[0]);
}

::PROTOBUF_NAMESPACE_ID::Metadata TestProto::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void TestProto2::InitAsDefaultInstance() {
}
class TestProto2::_Internal {
 public:
};

TestProto2::TestProto2(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:clarifai.api.utils.TestProto2)
}
TestProto2::TestProto2(const TestProto2& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_id().empty()) {
    id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_id(),
      GetArena());
  }
  flip_ = from.flip_;
  // @@protoc_insertion_point(copy_constructor:clarifai.api.utils.TestProto2)
}

void TestProto2::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_TestProto2_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto.base);
  id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  flip_ = false;
}

TestProto2::~TestProto2() {
  // @@protoc_insertion_point(destructor:clarifai.api.utils.TestProto2)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void TestProto2::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void TestProto2::ArenaDtor(void* object) {
  TestProto2* _this = reinterpret_cast< TestProto2* >(object);
  (void)_this;
}
void TestProto2::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void TestProto2::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const TestProto2& TestProto2::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_TestProto2_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto.base);
  return *internal_default_instance();
}


void TestProto2::Clear() {
// @@protoc_insertion_point(message_clear_start:clarifai.api.utils.TestProto2)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  id_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  flip_ = false;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* TestProto2::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_id();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "clarifai.api.utils.TestProto2.id"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bool flip = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          flip_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* TestProto2::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:clarifai.api.utils.TestProto2)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string id = 1;
  if (this->id().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_id().data(), static_cast<int>(this->_internal_id().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "clarifai.api.utils.TestProto2.id");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_id(), target);
  }

  // bool flip = 2;
  if (this->flip() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(2, this->_internal_flip(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:clarifai.api.utils.TestProto2)
  return target;
}

size_t TestProto2::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:clarifai.api.utils.TestProto2)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string id = 1;
  if (this->id().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_id());
  }

  // bool flip = 2;
  if (this->flip() != 0) {
    total_size += 1 + 1;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void TestProto2::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:clarifai.api.utils.TestProto2)
  GOOGLE_DCHECK_NE(&from, this);
  const TestProto2* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<TestProto2>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:clarifai.api.utils.TestProto2)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:clarifai.api.utils.TestProto2)
    MergeFrom(*source);
  }
}

void TestProto2::MergeFrom(const TestProto2& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:clarifai.api.utils.TestProto2)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.id().size() > 0) {
    _internal_set_id(from._internal_id());
  }
  if (from.flip() != 0) {
    _internal_set_flip(from._internal_flip());
  }
}

void TestProto2::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:clarifai.api.utils.TestProto2)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TestProto2::CopyFrom(const TestProto2& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:clarifai.api.utils.TestProto2)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TestProto2::IsInitialized() const {
  return true;
}

void TestProto2::InternalSwap(TestProto2* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  id_.Swap(&other->id_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  swap(flip_, other->flip_);
}

::PROTOBUF_NAMESPACE_ID::Metadata TestProto2::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace utils
}  // namespace api
}  // namespace clarifai
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::clarifai::api::utils::TestProto* Arena::CreateMaybeMessage< ::clarifai::api::utils::TestProto >(Arena* arena) {
  return Arena::CreateMessageInternal< ::clarifai::api::utils::TestProto >(arena);
}
template<> PROTOBUF_NOINLINE ::clarifai::api::utils::TestProto2* Arena::CreateMaybeMessage< ::clarifai::api::utils::TestProto2 >(Arena* arena) {
  return Arena::CreateMessageInternal< ::clarifai::api::utils::TestProto2 >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
