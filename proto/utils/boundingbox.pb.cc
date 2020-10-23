// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/utils/boundingbox.proto

#include "proto/utils/boundingbox.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_proto_2futils_2fembedding_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_Embedding_proto_2futils_2fembedding_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_proto_2futils_2ftag_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Tag_proto_2futils_2ftag_2eproto;
class BoundingBoxDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<BoundingBox> _instance;
} _BoundingBox_default_instance_;
static void InitDefaultsscc_info_BoundingBox_proto_2futils_2fboundingbox_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_BoundingBox_default_instance_;
    new (ptr) ::BoundingBox();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::BoundingBox::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<2> scc_info_BoundingBox_proto_2futils_2fboundingbox_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 2, 0, InitDefaultsscc_info_BoundingBox_proto_2futils_2fboundingbox_2eproto}, {
      &scc_info_Tag_proto_2futils_2ftag_2eproto.base,
      &scc_info_Embedding_proto_2futils_2fembedding_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_proto_2futils_2fboundingbox_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_proto_2futils_2fboundingbox_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_proto_2futils_2fboundingbox_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_proto_2futils_2fboundingbox_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::BoundingBox, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::BoundingBox, tag_),
  PROTOBUF_FIELD_OFFSET(::BoundingBox, top_row_),
  PROTOBUF_FIELD_OFFSET(::BoundingBox, left_col_),
  PROTOBUF_FIELD_OFFSET(::BoundingBox, bottom_row_),
  PROTOBUF_FIELD_OFFSET(::BoundingBox, right_col_),
  PROTOBUF_FIELD_OFFSET(::BoundingBox, is_positive_),
  PROTOBUF_FIELD_OFFSET(::BoundingBox, embedding_),
  PROTOBUF_FIELD_OFFSET(::BoundingBox, track_id_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::BoundingBox)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_BoundingBox_default_instance_),
};

const char descriptor_table_protodef_proto_2futils_2fboundingbox_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\035proto/utils/boundingbox.proto\032\033proto/u"
  "tils/embedding.proto\032\025proto/utils/tag.pr"
  "oto\032)proto/clarifai/api/utils/extensions"
  ".proto\"\310\001\n\013BoundingBox\022\021\n\003tag\030\001 \003(\0132\004.Ta"
  "g\022\025\n\007top_row\030\003 \001(\002B\004\200\265\030\001\022\026\n\010left_col\030\004 \001"
  "(\002B\004\200\265\030\001\022\030\n\nbottom_row\030\005 \001(\002B\004\200\265\030\001\022\027\n\tri"
  "ght_col\030\006 \001(\002B\004\200\265\030\001\022\023\n\013is_positive\030\007 \001(\010"
  "\022\035\n\tembedding\030\010 \003(\0132\n.Embedding\022\020\n\010track"
  "_id\030\t \001(\005B\016\n\005utilsZ\005utilsb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_proto_2futils_2fboundingbox_2eproto_deps[3] = {
  &::descriptor_table_proto_2fclarifai_2fapi_2futils_2fextensions_2eproto,
  &::descriptor_table_proto_2futils_2fembedding_2eproto,
  &::descriptor_table_proto_2futils_2ftag_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_proto_2futils_2fboundingbox_2eproto_sccs[1] = {
  &scc_info_BoundingBox_proto_2futils_2fboundingbox_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_proto_2futils_2fboundingbox_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2futils_2fboundingbox_2eproto = {
  false, false, descriptor_table_protodef_proto_2futils_2fboundingbox_2eproto, "proto/utils/boundingbox.proto", 353,
  &descriptor_table_proto_2futils_2fboundingbox_2eproto_once, descriptor_table_proto_2futils_2fboundingbox_2eproto_sccs, descriptor_table_proto_2futils_2fboundingbox_2eproto_deps, 1, 3,
  schemas, file_default_instances, TableStruct_proto_2futils_2fboundingbox_2eproto::offsets,
  file_level_metadata_proto_2futils_2fboundingbox_2eproto, 1, file_level_enum_descriptors_proto_2futils_2fboundingbox_2eproto, file_level_service_descriptors_proto_2futils_2fboundingbox_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_proto_2futils_2fboundingbox_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_proto_2futils_2fboundingbox_2eproto)), true);

// ===================================================================

void BoundingBox::InitAsDefaultInstance() {
}
class BoundingBox::_Internal {
 public:
};

void BoundingBox::clear_tag() {
  tag_.Clear();
}
void BoundingBox::clear_embedding() {
  embedding_.Clear();
}
BoundingBox::BoundingBox(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  tag_(arena),
  embedding_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:BoundingBox)
}
BoundingBox::BoundingBox(const BoundingBox& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      tag_(from.tag_),
      embedding_(from.embedding_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&top_row_, &from.top_row_,
    static_cast<size_t>(reinterpret_cast<char*>(&track_id_) -
    reinterpret_cast<char*>(&top_row_)) + sizeof(track_id_));
  // @@protoc_insertion_point(copy_constructor:BoundingBox)
}

void BoundingBox::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_BoundingBox_proto_2futils_2fboundingbox_2eproto.base);
  ::memset(&top_row_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&track_id_) -
      reinterpret_cast<char*>(&top_row_)) + sizeof(track_id_));
}

BoundingBox::~BoundingBox() {
  // @@protoc_insertion_point(destructor:BoundingBox)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void BoundingBox::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void BoundingBox::ArenaDtor(void* object) {
  BoundingBox* _this = reinterpret_cast< BoundingBox* >(object);
  (void)_this;
}
void BoundingBox::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void BoundingBox::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const BoundingBox& BoundingBox::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_BoundingBox_proto_2futils_2fboundingbox_2eproto.base);
  return *internal_default_instance();
}


void BoundingBox::Clear() {
// @@protoc_insertion_point(message_clear_start:BoundingBox)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  tag_.Clear();
  embedding_.Clear();
  ::memset(&top_row_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&track_id_) -
      reinterpret_cast<char*>(&top_row_)) + sizeof(track_id_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* BoundingBox::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .Tag tag = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_tag(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else goto handle_unusual;
        continue;
      // float top_row = 3 [(.clarifai.api.utils.cl_show_if_empty) = true];
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 29)) {
          top_row_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float left_col = 4 [(.clarifai.api.utils.cl_show_if_empty) = true];
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 37)) {
          left_col_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float bottom_row = 5 [(.clarifai.api.utils.cl_show_if_empty) = true];
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 45)) {
          bottom_row_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float right_col = 6 [(.clarifai.api.utils.cl_show_if_empty) = true];
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 53)) {
          right_col_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // bool is_positive = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 56)) {
          is_positive_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .Embedding embedding = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 66)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_embedding(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<66>(ptr));
        } else goto handle_unusual;
        continue;
      // int32 track_id = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 72)) {
          track_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* BoundingBox::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:BoundingBox)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .Tag tag = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_tag_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_tag(i), target, stream);
  }

  // float top_row = 3 [(.clarifai.api.utils.cl_show_if_empty) = true];
  if (!(this->top_row() <= 0 && this->top_row() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(3, this->_internal_top_row(), target);
  }

  // float left_col = 4 [(.clarifai.api.utils.cl_show_if_empty) = true];
  if (!(this->left_col() <= 0 && this->left_col() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(4, this->_internal_left_col(), target);
  }

  // float bottom_row = 5 [(.clarifai.api.utils.cl_show_if_empty) = true];
  if (!(this->bottom_row() <= 0 && this->bottom_row() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(5, this->_internal_bottom_row(), target);
  }

  // float right_col = 6 [(.clarifai.api.utils.cl_show_if_empty) = true];
  if (!(this->right_col() <= 0 && this->right_col() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(6, this->_internal_right_col(), target);
  }

  // bool is_positive = 7;
  if (this->is_positive() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(7, this->_internal_is_positive(), target);
  }

  // repeated .Embedding embedding = 8;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_embedding_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(8, this->_internal_embedding(i), target, stream);
  }

  // int32 track_id = 9;
  if (this->track_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(9, this->_internal_track_id(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:BoundingBox)
  return target;
}

size_t BoundingBox::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:BoundingBox)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .Tag tag = 1;
  total_size += 1UL * this->_internal_tag_size();
  for (const auto& msg : this->tag_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .Embedding embedding = 8;
  total_size += 1UL * this->_internal_embedding_size();
  for (const auto& msg : this->embedding_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // float top_row = 3 [(.clarifai.api.utils.cl_show_if_empty) = true];
  if (!(this->top_row() <= 0 && this->top_row() >= 0)) {
    total_size += 1 + 4;
  }

  // float left_col = 4 [(.clarifai.api.utils.cl_show_if_empty) = true];
  if (!(this->left_col() <= 0 && this->left_col() >= 0)) {
    total_size += 1 + 4;
  }

  // float bottom_row = 5 [(.clarifai.api.utils.cl_show_if_empty) = true];
  if (!(this->bottom_row() <= 0 && this->bottom_row() >= 0)) {
    total_size += 1 + 4;
  }

  // float right_col = 6 [(.clarifai.api.utils.cl_show_if_empty) = true];
  if (!(this->right_col() <= 0 && this->right_col() >= 0)) {
    total_size += 1 + 4;
  }

  // bool is_positive = 7;
  if (this->is_positive() != 0) {
    total_size += 1 + 1;
  }

  // int32 track_id = 9;
  if (this->track_id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_track_id());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void BoundingBox::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:BoundingBox)
  GOOGLE_DCHECK_NE(&from, this);
  const BoundingBox* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<BoundingBox>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:BoundingBox)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:BoundingBox)
    MergeFrom(*source);
  }
}

void BoundingBox::MergeFrom(const BoundingBox& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:BoundingBox)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  tag_.MergeFrom(from.tag_);
  embedding_.MergeFrom(from.embedding_);
  if (!(from.top_row() <= 0 && from.top_row() >= 0)) {
    _internal_set_top_row(from._internal_top_row());
  }
  if (!(from.left_col() <= 0 && from.left_col() >= 0)) {
    _internal_set_left_col(from._internal_left_col());
  }
  if (!(from.bottom_row() <= 0 && from.bottom_row() >= 0)) {
    _internal_set_bottom_row(from._internal_bottom_row());
  }
  if (!(from.right_col() <= 0 && from.right_col() >= 0)) {
    _internal_set_right_col(from._internal_right_col());
  }
  if (from.is_positive() != 0) {
    _internal_set_is_positive(from._internal_is_positive());
  }
  if (from.track_id() != 0) {
    _internal_set_track_id(from._internal_track_id());
  }
}

void BoundingBox::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:BoundingBox)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BoundingBox::CopyFrom(const BoundingBox& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:BoundingBox)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BoundingBox::IsInitialized() const {
  return true;
}

void BoundingBox::InternalSwap(BoundingBox* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  tag_.InternalSwap(&other->tag_);
  embedding_.InternalSwap(&other->embedding_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(BoundingBox, track_id_)
      + sizeof(BoundingBox::track_id_)
      - PROTOBUF_FIELD_OFFSET(BoundingBox, top_row_)>(
          reinterpret_cast<char*>(&top_row_),
          reinterpret_cast<char*>(&other->top_row_));
}

::PROTOBUF_NAMESPACE_ID::Metadata BoundingBox::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::BoundingBox* Arena::CreateMaybeMessage< ::BoundingBox >(Arena* arena) {
  return Arena::CreateMessageInternal< ::BoundingBox >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>