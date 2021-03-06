// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/utils/dataset.proto

#include "proto/utils/dataset.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_proto_2futils_2fvocab_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_Vocab_proto_2futils_2fvocab_2eproto;
class DatasetDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Dataset> _instance;
} _Dataset_default_instance_;
static void InitDefaultsscc_info_Dataset_proto_2futils_2fdataset_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_Dataset_default_instance_;
    new (ptr) ::Dataset();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Dataset::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_Dataset_proto_2futils_2fdataset_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_Dataset_proto_2futils_2fdataset_2eproto}, {
      &scc_info_Vocab_proto_2futils_2fvocab_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_proto_2futils_2fdataset_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_proto_2futils_2fdataset_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_proto_2futils_2fdataset_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_proto_2futils_2fdataset_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Dataset, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Dataset, name_),
  PROTOBUF_FIELD_OFFSET(::Dataset, data_dir_),
  PROTOBUF_FIELD_OFFSET(::Dataset, meta_filename_),
  PROTOBUF_FIELD_OFFSET(::Dataset, data_provider_name_),
  PROTOBUF_FIELD_OFFSET(::Dataset, vocab_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::Dataset)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_Dataset_default_instance_),
};

const char descriptor_table_protodef_proto_2futils_2fdataset_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\031proto/utils/dataset.proto\032\027proto/utils"
  "/vocab.proto\"s\n\007Dataset\022\014\n\004name\030\001 \001(\t\022\020\n"
  "\010data_dir\030\002 \001(\t\022\025\n\rmeta_filename\030\003 \001(\t\022\032"
  "\n\022data_provider_name\030\004 \001(\t\022\025\n\005vocab\030\005 \001("
  "\0132\006.VocabB\016\n\005utilsZ\005utilsb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_proto_2futils_2fdataset_2eproto_deps[1] = {
  &::descriptor_table_proto_2futils_2fvocab_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_proto_2futils_2fdataset_2eproto_sccs[1] = {
  &scc_info_Dataset_proto_2futils_2fdataset_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_proto_2futils_2fdataset_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2futils_2fdataset_2eproto = {
  false, false, descriptor_table_protodef_proto_2futils_2fdataset_2eproto, "proto/utils/dataset.proto", 193,
  &descriptor_table_proto_2futils_2fdataset_2eproto_once, descriptor_table_proto_2futils_2fdataset_2eproto_sccs, descriptor_table_proto_2futils_2fdataset_2eproto_deps, 1, 1,
  schemas, file_default_instances, TableStruct_proto_2futils_2fdataset_2eproto::offsets,
  file_level_metadata_proto_2futils_2fdataset_2eproto, 1, file_level_enum_descriptors_proto_2futils_2fdataset_2eproto, file_level_service_descriptors_proto_2futils_2fdataset_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_proto_2futils_2fdataset_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_proto_2futils_2fdataset_2eproto)), true);

// ===================================================================

void Dataset::InitAsDefaultInstance() {
  ::_Dataset_default_instance_._instance.get_mutable()->vocab_ = const_cast< ::Vocab*>(
      ::Vocab::internal_default_instance());
}
class Dataset::_Internal {
 public:
  static const ::Vocab& vocab(const Dataset* msg);
};

const ::Vocab&
Dataset::_Internal::vocab(const Dataset* msg) {
  return *msg->vocab_;
}
void Dataset::clear_vocab() {
  if (GetArena() == nullptr && vocab_ != nullptr) {
    delete vocab_;
  }
  vocab_ = nullptr;
}
Dataset::Dataset(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:Dataset)
}
Dataset::Dataset(const Dataset& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_name().empty()) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_name(),
      GetArena());
  }
  data_dir_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_data_dir().empty()) {
    data_dir_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_data_dir(),
      GetArena());
  }
  meta_filename_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_meta_filename().empty()) {
    meta_filename_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_meta_filename(),
      GetArena());
  }
  data_provider_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_data_provider_name().empty()) {
    data_provider_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_data_provider_name(),
      GetArena());
  }
  if (from._internal_has_vocab()) {
    vocab_ = new ::Vocab(*from.vocab_);
  } else {
    vocab_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:Dataset)
}

void Dataset::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Dataset_proto_2futils_2fdataset_2eproto.base);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  data_dir_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  meta_filename_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  data_provider_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  vocab_ = nullptr;
}

Dataset::~Dataset() {
  // @@protoc_insertion_point(destructor:Dataset)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Dataset::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  data_dir_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  meta_filename_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  data_provider_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete vocab_;
}

void Dataset::ArenaDtor(void* object) {
  Dataset* _this = reinterpret_cast< Dataset* >(object);
  (void)_this;
}
void Dataset::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Dataset::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Dataset& Dataset::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Dataset_proto_2futils_2fdataset_2eproto.base);
  return *internal_default_instance();
}


void Dataset::Clear() {
// @@protoc_insertion_point(message_clear_start:Dataset)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  data_dir_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  meta_filename_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  data_provider_name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  if (GetArena() == nullptr && vocab_ != nullptr) {
    delete vocab_;
  }
  vocab_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Dataset::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
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
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Dataset.name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string data_dir = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_data_dir();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Dataset.data_dir"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string meta_filename = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_meta_filename();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Dataset.meta_filename"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string data_provider_name = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          auto str = _internal_mutable_data_provider_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Dataset.data_provider_name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .Vocab vocab = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          ptr = ctx->ParseMessage(_internal_mutable_vocab(), ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* Dataset::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Dataset)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (this->name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Dataset.name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_name(), target);
  }

  // string data_dir = 2;
  if (this->data_dir().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_data_dir().data(), static_cast<int>(this->_internal_data_dir().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Dataset.data_dir");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_data_dir(), target);
  }

  // string meta_filename = 3;
  if (this->meta_filename().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_meta_filename().data(), static_cast<int>(this->_internal_meta_filename().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Dataset.meta_filename");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_meta_filename(), target);
  }

  // string data_provider_name = 4;
  if (this->data_provider_name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_data_provider_name().data(), static_cast<int>(this->_internal_data_provider_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Dataset.data_provider_name");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_data_provider_name(), target);
  }

  // .Vocab vocab = 5;
  if (this->has_vocab()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        5, _Internal::vocab(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Dataset)
  return target;
}

size_t Dataset::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Dataset)
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

  // string data_dir = 2;
  if (this->data_dir().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_data_dir());
  }

  // string meta_filename = 3;
  if (this->meta_filename().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_meta_filename());
  }

  // string data_provider_name = 4;
  if (this->data_provider_name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_data_provider_name());
  }

  // .Vocab vocab = 5;
  if (this->has_vocab()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *vocab_);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Dataset::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Dataset)
  GOOGLE_DCHECK_NE(&from, this);
  const Dataset* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Dataset>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Dataset)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Dataset)
    MergeFrom(*source);
  }
}

void Dataset::MergeFrom(const Dataset& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Dataset)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.name().size() > 0) {
    _internal_set_name(from._internal_name());
  }
  if (from.data_dir().size() > 0) {
    _internal_set_data_dir(from._internal_data_dir());
  }
  if (from.meta_filename().size() > 0) {
    _internal_set_meta_filename(from._internal_meta_filename());
  }
  if (from.data_provider_name().size() > 0) {
    _internal_set_data_provider_name(from._internal_data_provider_name());
  }
  if (from.has_vocab()) {
    _internal_mutable_vocab()->::Vocab::MergeFrom(from._internal_vocab());
  }
}

void Dataset::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Dataset)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Dataset::CopyFrom(const Dataset& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Dataset)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Dataset::IsInitialized() const {
  return true;
}

void Dataset::InternalSwap(Dataset* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  name_.Swap(&other->name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  data_dir_.Swap(&other->data_dir_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  meta_filename_.Swap(&other->meta_filename_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  data_provider_name_.Swap(&other->data_provider_name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  swap(vocab_, other->vocab_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Dataset::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Dataset* Arena::CreateMaybeMessage< ::Dataset >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Dataset >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
