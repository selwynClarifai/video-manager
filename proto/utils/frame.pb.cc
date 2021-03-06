// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/utils/frame.proto

#include "proto/utils/frame.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_proto_2futils_2fimage_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_Image_proto_2futils_2fimage_2eproto;
class FrameDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Frame> _instance;
} _Frame_default_instance_;
static void InitDefaultsscc_info_Frame_proto_2futils_2fframe_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_Frame_default_instance_;
    new (ptr) ::Frame();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Frame::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_Frame_proto_2futils_2fframe_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_Frame_proto_2futils_2fframe_2eproto}, {
      &scc_info_Image_proto_2futils_2fimage_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_proto_2futils_2fframe_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_proto_2futils_2fframe_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_proto_2futils_2fframe_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_proto_2futils_2fframe_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Frame, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Frame, name_),
  PROTOBUF_FIELD_OFFSET(::Frame, image_),
  PROTOBUF_FIELD_OFFSET(::Frame, timestamp_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::Frame)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_Frame_default_instance_),
};

const char descriptor_table_protodef_proto_2futils_2fframe_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\027proto/utils/frame.proto\032\027proto/utils/i"
  "mage.proto\"@\n\005Frame\022\014\n\004name\030\001 \001(\t\022\025\n\005ima"
  "ge\030\002 \001(\0132\006.Image\022\022\n\ttimestamp\030\350\007 \001(\005B\016\n\005"
  "utilsZ\005utilsb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_proto_2futils_2fframe_2eproto_deps[1] = {
  &::descriptor_table_proto_2futils_2fimage_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_proto_2futils_2fframe_2eproto_sccs[1] = {
  &scc_info_Frame_proto_2futils_2fframe_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_proto_2futils_2fframe_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2futils_2fframe_2eproto = {
  false, false, descriptor_table_protodef_proto_2futils_2fframe_2eproto, "proto/utils/frame.proto", 140,
  &descriptor_table_proto_2futils_2fframe_2eproto_once, descriptor_table_proto_2futils_2fframe_2eproto_sccs, descriptor_table_proto_2futils_2fframe_2eproto_deps, 1, 1,
  schemas, file_default_instances, TableStruct_proto_2futils_2fframe_2eproto::offsets,
  file_level_metadata_proto_2futils_2fframe_2eproto, 1, file_level_enum_descriptors_proto_2futils_2fframe_2eproto, file_level_service_descriptors_proto_2futils_2fframe_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_proto_2futils_2fframe_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_proto_2futils_2fframe_2eproto)), true);

// ===================================================================

void Frame::InitAsDefaultInstance() {
  ::_Frame_default_instance_._instance.get_mutable()->image_ = const_cast< ::Image*>(
      ::Image::internal_default_instance());
}
class Frame::_Internal {
 public:
  static const ::Image& image(const Frame* msg);
};

const ::Image&
Frame::_Internal::image(const Frame* msg) {
  return *msg->image_;
}
void Frame::clear_image() {
  if (GetArena() == nullptr && image_ != nullptr) {
    delete image_;
  }
  image_ = nullptr;
}
Frame::Frame(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:Frame)
}
Frame::Frame(const Frame& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_name().empty()) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_name(),
      GetArena());
  }
  if (from._internal_has_image()) {
    image_ = new ::Image(*from.image_);
  } else {
    image_ = nullptr;
  }
  timestamp_ = from.timestamp_;
  // @@protoc_insertion_point(copy_constructor:Frame)
}

void Frame::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Frame_proto_2futils_2fframe_2eproto.base);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&image_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&timestamp_) -
      reinterpret_cast<char*>(&image_)) + sizeof(timestamp_));
}

Frame::~Frame() {
  // @@protoc_insertion_point(destructor:Frame)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Frame::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete image_;
}

void Frame::ArenaDtor(void* object) {
  Frame* _this = reinterpret_cast< Frame* >(object);
  (void)_this;
}
void Frame::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Frame::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Frame& Frame::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Frame_proto_2futils_2fframe_2eproto.base);
  return *internal_default_instance();
}


void Frame::Clear() {
// @@protoc_insertion_point(message_clear_start:Frame)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  if (GetArena() == nullptr && image_ != nullptr) {
    delete image_;
  }
  image_ = nullptr;
  timestamp_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Frame::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Frame.name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .Image image = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_image(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 timestamp = 1000;
      case 1000:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 64)) {
          timestamp_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* Frame::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Frame)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (this->name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Frame.name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_name(), target);
  }

  // .Image image = 2;
  if (this->has_image()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        2, _Internal::image(this), target, stream);
  }

  // int32 timestamp = 1000;
  if (this->timestamp() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1000, this->_internal_timestamp(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Frame)
  return target;
}

size_t Frame::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Frame)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string name = 1;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // .Image image = 2;
  if (this->has_image()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *image_);
  }

  // int32 timestamp = 1000;
  if (this->timestamp() != 0) {
    total_size += 2 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_timestamp());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Frame::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Frame)
  GOOGLE_DCHECK_NE(&from, this);
  const Frame* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Frame>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Frame)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Frame)
    MergeFrom(*source);
  }
}

void Frame::MergeFrom(const Frame& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Frame)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.name().size() > 0) {
    _internal_set_name(from._internal_name());
  }
  if (from.has_image()) {
    _internal_mutable_image()->::Image::MergeFrom(from._internal_image());
  }
  if (from.timestamp() != 0) {
    _internal_set_timestamp(from._internal_timestamp());
  }
}

void Frame::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Frame)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Frame::CopyFrom(const Frame& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Frame)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Frame::IsInitialized() const {
  return true;
}

void Frame::InternalSwap(Frame* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  name_.Swap(&other->name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Frame, timestamp_)
      + sizeof(Frame::timestamp_)
      - PROTOBUF_FIELD_OFFSET(Frame, image_)>(
          reinterpret_cast<char*>(&image_),
          reinterpret_cast<char*>(&other->image_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Frame::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Frame* Arena::CreateMaybeMessage< ::Frame >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Frame >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
