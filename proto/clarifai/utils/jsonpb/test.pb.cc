// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/clarifai/utils/jsonpb/test.proto

#include "proto/clarifai/utils/jsonpb/test.pb.h"

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
namespace jsonpb {
class BoolFloatTestMessageDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<BoolFloatTestMessage> _instance;
} _BoolFloatTestMessage_default_instance_;
}  // namespace jsonpb
static void InitDefaultsscc_info_BoolFloatTestMessage_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::jsonpb::_BoolFloatTestMessage_default_instance_;
    new (ptr) ::jsonpb::BoolFloatTestMessage();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::jsonpb::BoolFloatTestMessage::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_BoolFloatTestMessage_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_BoolFloatTestMessage_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::jsonpb::BoolFloatTestMessage, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::jsonpb::BoolFloatTestMessage, uint_32_),
  PROTOBUF_FIELD_OFFSET(::jsonpb::BoolFloatTestMessage, uint_64_),
  PROTOBUF_FIELD_OFFSET(::jsonpb::BoolFloatTestMessage, int_32_),
  PROTOBUF_FIELD_OFFSET(::jsonpb::BoolFloatTestMessage, int_64_),
  PROTOBUF_FIELD_OFFSET(::jsonpb::BoolFloatTestMessage, f_32_),
  PROTOBUF_FIELD_OFFSET(::jsonpb::BoolFloatTestMessage, f_64_),
  PROTOBUF_FIELD_OFFSET(::jsonpb::BoolFloatTestMessage, b_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::jsonpb::BoolFloatTestMessage)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::jsonpb::_BoolFloatTestMessage_default_instance_),
};

const char descriptor_table_protodef_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n&proto/clarifai/utils/jsonpb/test.proto"
  "\022\006jsonpb\"\177\n\024BoolFloatTestMessage\022\017\n\007uint"
  "_32\030\004 \001(\r\022\017\n\007uint_64\030\005 \001(\004\022\016\n\006int_32\030\006 \001"
  "(\005\022\016\n\006int_64\030\007 \001(\003\022\014\n\004f_32\030\010 \001(\002\022\014\n\004f_64"
  "\030\t \001(\001\022\t\n\001b\030\n \001(\010B\035\n\031com.clarifai.utils."
  "jsonpbP\001b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto_sccs[1] = {
  &scc_info_BoolFloatTestMessage_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto = {
  false, false, descriptor_table_protodef_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto, "proto/clarifai/utils/jsonpb/test.proto", 216,
  &descriptor_table_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto_once, descriptor_table_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto_sccs, descriptor_table_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto::offsets,
  file_level_metadata_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto, 1, file_level_enum_descriptors_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto, file_level_service_descriptors_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto)), true);
namespace jsonpb {

// ===================================================================

void BoolFloatTestMessage::InitAsDefaultInstance() {
}
class BoolFloatTestMessage::_Internal {
 public:
};

BoolFloatTestMessage::BoolFloatTestMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:jsonpb.BoolFloatTestMessage)
}
BoolFloatTestMessage::BoolFloatTestMessage(const BoolFloatTestMessage& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&uint_64_, &from.uint_64_,
    static_cast<size_t>(reinterpret_cast<char*>(&b_) -
    reinterpret_cast<char*>(&uint_64_)) + sizeof(b_));
  // @@protoc_insertion_point(copy_constructor:jsonpb.BoolFloatTestMessage)
}

void BoolFloatTestMessage::SharedCtor() {
  ::memset(&uint_64_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&b_) -
      reinterpret_cast<char*>(&uint_64_)) + sizeof(b_));
}

BoolFloatTestMessage::~BoolFloatTestMessage() {
  // @@protoc_insertion_point(destructor:jsonpb.BoolFloatTestMessage)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void BoolFloatTestMessage::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void BoolFloatTestMessage::ArenaDtor(void* object) {
  BoolFloatTestMessage* _this = reinterpret_cast< BoolFloatTestMessage* >(object);
  (void)_this;
}
void BoolFloatTestMessage::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void BoolFloatTestMessage::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const BoolFloatTestMessage& BoolFloatTestMessage::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_BoolFloatTestMessage_proto_2fclarifai_2futils_2fjsonpb_2ftest_2eproto.base);
  return *internal_default_instance();
}


void BoolFloatTestMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:jsonpb.BoolFloatTestMessage)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&uint_64_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&b_) -
      reinterpret_cast<char*>(&uint_64_)) + sizeof(b_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* BoolFloatTestMessage::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // uint32 uint_32 = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          uint_32_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint64 uint_64 = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 40)) {
          uint_64_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 int_32 = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 48)) {
          int_32_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int64 int_64 = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 56)) {
          int_64_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // float f_32 = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 69)) {
          f_32_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // double f_64 = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 73)) {
          f_64_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // bool b = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 80)) {
          b_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* BoolFloatTestMessage::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:jsonpb.BoolFloatTestMessage)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 uint_32 = 4;
  if (this->uint_32() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(4, this->_internal_uint_32(), target);
  }

  // uint64 uint_64 = 5;
  if (this->uint_64() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(5, this->_internal_uint_64(), target);
  }

  // int32 int_32 = 6;
  if (this->int_32() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(6, this->_internal_int_32(), target);
  }

  // int64 int_64 = 7;
  if (this->int_64() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(7, this->_internal_int_64(), target);
  }

  // float f_32 = 8;
  if (!(this->f_32() <= 0 && this->f_32() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(8, this->_internal_f_32(), target);
  }

  // double f_64 = 9;
  if (!(this->f_64() <= 0 && this->f_64() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(9, this->_internal_f_64(), target);
  }

  // bool b = 10;
  if (this->b() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(10, this->_internal_b(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:jsonpb.BoolFloatTestMessage)
  return target;
}

size_t BoolFloatTestMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:jsonpb.BoolFloatTestMessage)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // uint64 uint_64 = 5;
  if (this->uint_64() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_uint_64());
  }

  // uint32 uint_32 = 4;
  if (this->uint_32() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_uint_32());
  }

  // int32 int_32 = 6;
  if (this->int_32() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_int_32());
  }

  // int64 int_64 = 7;
  if (this->int_64() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
        this->_internal_int_64());
  }

  // double f_64 = 9;
  if (!(this->f_64() <= 0 && this->f_64() >= 0)) {
    total_size += 1 + 8;
  }

  // float f_32 = 8;
  if (!(this->f_32() <= 0 && this->f_32() >= 0)) {
    total_size += 1 + 4;
  }

  // bool b = 10;
  if (this->b() != 0) {
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

void BoolFloatTestMessage::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:jsonpb.BoolFloatTestMessage)
  GOOGLE_DCHECK_NE(&from, this);
  const BoolFloatTestMessage* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<BoolFloatTestMessage>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:jsonpb.BoolFloatTestMessage)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:jsonpb.BoolFloatTestMessage)
    MergeFrom(*source);
  }
}

void BoolFloatTestMessage::MergeFrom(const BoolFloatTestMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:jsonpb.BoolFloatTestMessage)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.uint_64() != 0) {
    _internal_set_uint_64(from._internal_uint_64());
  }
  if (from.uint_32() != 0) {
    _internal_set_uint_32(from._internal_uint_32());
  }
  if (from.int_32() != 0) {
    _internal_set_int_32(from._internal_int_32());
  }
  if (from.int_64() != 0) {
    _internal_set_int_64(from._internal_int_64());
  }
  if (!(from.f_64() <= 0 && from.f_64() >= 0)) {
    _internal_set_f_64(from._internal_f_64());
  }
  if (!(from.f_32() <= 0 && from.f_32() >= 0)) {
    _internal_set_f_32(from._internal_f_32());
  }
  if (from.b() != 0) {
    _internal_set_b(from._internal_b());
  }
}

void BoolFloatTestMessage::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:jsonpb.BoolFloatTestMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BoolFloatTestMessage::CopyFrom(const BoolFloatTestMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:jsonpb.BoolFloatTestMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BoolFloatTestMessage::IsInitialized() const {
  return true;
}

void BoolFloatTestMessage::InternalSwap(BoolFloatTestMessage* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(BoolFloatTestMessage, b_)
      + sizeof(BoolFloatTestMessage::b_)
      - PROTOBUF_FIELD_OFFSET(BoolFloatTestMessage, uint_64_)>(
          reinterpret_cast<char*>(&uint_64_),
          reinterpret_cast<char*>(&other->uint_64_));
}

::PROTOBUF_NAMESPACE_ID::Metadata BoolFloatTestMessage::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace jsonpb
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::jsonpb::BoolFloatTestMessage* Arena::CreateMaybeMessage< ::jsonpb::BoolFloatTestMessage >(Arena* arena) {
  return Arena::CreateMessageInternal< ::jsonpb::BoolFloatTestMessage >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
