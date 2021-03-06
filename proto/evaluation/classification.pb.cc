// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/evaluation/classification.proto

#include "proto/evaluation/classification.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_proto_2fevaluation_2fclassification_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ClassificationEvalSubset_proto_2fevaluation_2fclassification_2eproto;
class ClassificationEvalResultDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ClassificationEvalResult> _instance;
} _ClassificationEvalResult_default_instance_;
class ClassificationEvalSubsetDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ClassificationEvalSubset> _instance;
} _ClassificationEvalSubset_default_instance_;
static void InitDefaultsscc_info_ClassificationEvalResult_proto_2fevaluation_2fclassification_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_ClassificationEvalResult_default_instance_;
    new (ptr) ::ClassificationEvalResult();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::ClassificationEvalResult::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_ClassificationEvalResult_proto_2fevaluation_2fclassification_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_ClassificationEvalResult_proto_2fevaluation_2fclassification_2eproto}, {
      &scc_info_ClassificationEvalSubset_proto_2fevaluation_2fclassification_2eproto.base,}};

static void InitDefaultsscc_info_ClassificationEvalSubset_proto_2fevaluation_2fclassification_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_ClassificationEvalSubset_default_instance_;
    new (ptr) ::ClassificationEvalSubset();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::ClassificationEvalSubset::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ClassificationEvalSubset_proto_2fevaluation_2fclassification_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_ClassificationEvalSubset_proto_2fevaluation_2fclassification_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_proto_2fevaluation_2fclassification_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_proto_2fevaluation_2fclassification_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_proto_2fevaluation_2fclassification_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_proto_2fevaluation_2fclassification_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ClassificationEvalResult, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::ClassificationEvalResult, top1_correct_),
  PROTOBUF_FIELD_OFFSET(::ClassificationEvalResult, topk_correct_),
  PROTOBUF_FIELD_OFFSET(::ClassificationEvalResult, subsets_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ClassificationEvalSubset, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::ClassificationEvalSubset, concept_name_),
  PROTOBUF_FIELD_OFFSET(::ClassificationEvalSubset, concept_id_),
  PROTOBUF_FIELD_OFFSET(::ClassificationEvalSubset, top1_correct_),
  PROTOBUF_FIELD_OFFSET(::ClassificationEvalSubset, topk_correct_),
  PROTOBUF_FIELD_OFFSET(::ClassificationEvalSubset, auc_),
  PROTOBUF_FIELD_OFFSET(::ClassificationEvalSubset, precision_at_50_),
  PROTOBUF_FIELD_OFFSET(::ClassificationEvalSubset, recall_at_50_),
  PROTOBUF_FIELD_OFFSET(::ClassificationEvalSubset, num_gt_images_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::ClassificationEvalResult)},
  { 8, -1, sizeof(::ClassificationEvalSubset)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_ClassificationEvalResult_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_ClassificationEvalSubset_default_instance_),
};

const char descriptor_table_protodef_proto_2fevaluation_2fclassification_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n%proto/evaluation/classification.proto\""
  "r\n\030ClassificationEvalResult\022\024\n\014top1_corr"
  "ect\030\001 \001(\001\022\024\n\014topk_correct\030\002 \001(\001\022*\n\007subse"
  "ts\030\003 \003(\0132\031.ClassificationEvalSubset\"\303\001\n\030"
  "ClassificationEvalSubset\022\024\n\014concept_name"
  "\030\001 \001(\t\022\022\n\nconcept_id\030\002 \001(\t\022\024\n\014top1_corre"
  "ct\030\n \001(\001\022\024\n\014topk_correct\030\013 \001(\001\022\013\n\003auc\030\014 "
  "\001(\001\022\027\n\017precision_at_50\030\r \001(\001\022\024\n\014recall_a"
  "t_50\030\016 \001(\001\022\025\n\rnum_gt_images\030\021 \001(\003B\014Z\neva"
  "luationb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_proto_2fevaluation_2fclassification_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_proto_2fevaluation_2fclassification_2eproto_sccs[2] = {
  &scc_info_ClassificationEvalResult_proto_2fevaluation_2fclassification_2eproto.base,
  &scc_info_ClassificationEvalSubset_proto_2fevaluation_2fclassification_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_proto_2fevaluation_2fclassification_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2fevaluation_2fclassification_2eproto = {
  false, false, descriptor_table_protodef_proto_2fevaluation_2fclassification_2eproto, "proto/evaluation/classification.proto", 375,
  &descriptor_table_proto_2fevaluation_2fclassification_2eproto_once, descriptor_table_proto_2fevaluation_2fclassification_2eproto_sccs, descriptor_table_proto_2fevaluation_2fclassification_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_proto_2fevaluation_2fclassification_2eproto::offsets,
  file_level_metadata_proto_2fevaluation_2fclassification_2eproto, 2, file_level_enum_descriptors_proto_2fevaluation_2fclassification_2eproto, file_level_service_descriptors_proto_2fevaluation_2fclassification_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_proto_2fevaluation_2fclassification_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_proto_2fevaluation_2fclassification_2eproto)), true);

// ===================================================================

void ClassificationEvalResult::InitAsDefaultInstance() {
}
class ClassificationEvalResult::_Internal {
 public:
};

ClassificationEvalResult::ClassificationEvalResult(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  subsets_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:ClassificationEvalResult)
}
ClassificationEvalResult::ClassificationEvalResult(const ClassificationEvalResult& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      subsets_(from.subsets_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&top1_correct_, &from.top1_correct_,
    static_cast<size_t>(reinterpret_cast<char*>(&topk_correct_) -
    reinterpret_cast<char*>(&top1_correct_)) + sizeof(topk_correct_));
  // @@protoc_insertion_point(copy_constructor:ClassificationEvalResult)
}

void ClassificationEvalResult::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ClassificationEvalResult_proto_2fevaluation_2fclassification_2eproto.base);
  ::memset(&top1_correct_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&topk_correct_) -
      reinterpret_cast<char*>(&top1_correct_)) + sizeof(topk_correct_));
}

ClassificationEvalResult::~ClassificationEvalResult() {
  // @@protoc_insertion_point(destructor:ClassificationEvalResult)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void ClassificationEvalResult::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void ClassificationEvalResult::ArenaDtor(void* object) {
  ClassificationEvalResult* _this = reinterpret_cast< ClassificationEvalResult* >(object);
  (void)_this;
}
void ClassificationEvalResult::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ClassificationEvalResult::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ClassificationEvalResult& ClassificationEvalResult::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ClassificationEvalResult_proto_2fevaluation_2fclassification_2eproto.base);
  return *internal_default_instance();
}


void ClassificationEvalResult::Clear() {
// @@protoc_insertion_point(message_clear_start:ClassificationEvalResult)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  subsets_.Clear();
  ::memset(&top1_correct_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&topk_correct_) -
      reinterpret_cast<char*>(&top1_correct_)) + sizeof(topk_correct_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ClassificationEvalResult::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // double top1_correct = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 9)) {
          top1_correct_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double topk_correct = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 17)) {
          topk_correct_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // repeated .ClassificationEvalSubset subsets = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_subsets(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<26>(ptr));
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

::PROTOBUF_NAMESPACE_ID::uint8* ClassificationEvalResult::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ClassificationEvalResult)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // double top1_correct = 1;
  if (!(this->top1_correct() <= 0 && this->top1_correct() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(1, this->_internal_top1_correct(), target);
  }

  // double topk_correct = 2;
  if (!(this->topk_correct() <= 0 && this->topk_correct() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(2, this->_internal_topk_correct(), target);
  }

  // repeated .ClassificationEvalSubset subsets = 3;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_subsets_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(3, this->_internal_subsets(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ClassificationEvalResult)
  return target;
}

size_t ClassificationEvalResult::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ClassificationEvalResult)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .ClassificationEvalSubset subsets = 3;
  total_size += 1UL * this->_internal_subsets_size();
  for (const auto& msg : this->subsets_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // double top1_correct = 1;
  if (!(this->top1_correct() <= 0 && this->top1_correct() >= 0)) {
    total_size += 1 + 8;
  }

  // double topk_correct = 2;
  if (!(this->topk_correct() <= 0 && this->topk_correct() >= 0)) {
    total_size += 1 + 8;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ClassificationEvalResult::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ClassificationEvalResult)
  GOOGLE_DCHECK_NE(&from, this);
  const ClassificationEvalResult* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ClassificationEvalResult>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ClassificationEvalResult)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ClassificationEvalResult)
    MergeFrom(*source);
  }
}

void ClassificationEvalResult::MergeFrom(const ClassificationEvalResult& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ClassificationEvalResult)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  subsets_.MergeFrom(from.subsets_);
  if (!(from.top1_correct() <= 0 && from.top1_correct() >= 0)) {
    _internal_set_top1_correct(from._internal_top1_correct());
  }
  if (!(from.topk_correct() <= 0 && from.topk_correct() >= 0)) {
    _internal_set_topk_correct(from._internal_topk_correct());
  }
}

void ClassificationEvalResult::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ClassificationEvalResult)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ClassificationEvalResult::CopyFrom(const ClassificationEvalResult& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ClassificationEvalResult)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ClassificationEvalResult::IsInitialized() const {
  return true;
}

void ClassificationEvalResult::InternalSwap(ClassificationEvalResult* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  subsets_.InternalSwap(&other->subsets_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(ClassificationEvalResult, topk_correct_)
      + sizeof(ClassificationEvalResult::topk_correct_)
      - PROTOBUF_FIELD_OFFSET(ClassificationEvalResult, top1_correct_)>(
          reinterpret_cast<char*>(&top1_correct_),
          reinterpret_cast<char*>(&other->top1_correct_));
}

::PROTOBUF_NAMESPACE_ID::Metadata ClassificationEvalResult::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void ClassificationEvalSubset::InitAsDefaultInstance() {
}
class ClassificationEvalSubset::_Internal {
 public:
};

ClassificationEvalSubset::ClassificationEvalSubset(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:ClassificationEvalSubset)
}
ClassificationEvalSubset::ClassificationEvalSubset(const ClassificationEvalSubset& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  concept_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_concept_name().empty()) {
    concept_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_concept_name(),
      GetArena());
  }
  concept_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_concept_id().empty()) {
    concept_id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_concept_id(),
      GetArena());
  }
  ::memcpy(&top1_correct_, &from.top1_correct_,
    static_cast<size_t>(reinterpret_cast<char*>(&num_gt_images_) -
    reinterpret_cast<char*>(&top1_correct_)) + sizeof(num_gt_images_));
  // @@protoc_insertion_point(copy_constructor:ClassificationEvalSubset)
}

void ClassificationEvalSubset::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ClassificationEvalSubset_proto_2fevaluation_2fclassification_2eproto.base);
  concept_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  concept_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&top1_correct_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&num_gt_images_) -
      reinterpret_cast<char*>(&top1_correct_)) + sizeof(num_gt_images_));
}

ClassificationEvalSubset::~ClassificationEvalSubset() {
  // @@protoc_insertion_point(destructor:ClassificationEvalSubset)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void ClassificationEvalSubset::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  concept_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  concept_id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void ClassificationEvalSubset::ArenaDtor(void* object) {
  ClassificationEvalSubset* _this = reinterpret_cast< ClassificationEvalSubset* >(object);
  (void)_this;
}
void ClassificationEvalSubset::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ClassificationEvalSubset::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ClassificationEvalSubset& ClassificationEvalSubset::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ClassificationEvalSubset_proto_2fevaluation_2fclassification_2eproto.base);
  return *internal_default_instance();
}


void ClassificationEvalSubset::Clear() {
// @@protoc_insertion_point(message_clear_start:ClassificationEvalSubset)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  concept_name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  concept_id_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::memset(&top1_correct_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&num_gt_images_) -
      reinterpret_cast<char*>(&top1_correct_)) + sizeof(num_gt_images_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ClassificationEvalSubset::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string concept_name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_concept_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ClassificationEvalSubset.concept_name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string concept_id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_concept_id();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ClassificationEvalSubset.concept_id"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // double top1_correct = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 81)) {
          top1_correct_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double topk_correct = 11;
      case 11:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 89)) {
          topk_correct_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double auc = 12;
      case 12:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 97)) {
          auc_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double precision_at_50 = 13;
      case 13:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 105)) {
          precision_at_50_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // double recall_at_50 = 14;
      case 14:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 113)) {
          recall_at_50_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // int64 num_gt_images = 17;
      case 17:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 136)) {
          num_gt_images_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* ClassificationEvalSubset::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ClassificationEvalSubset)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string concept_name = 1;
  if (this->concept_name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_concept_name().data(), static_cast<int>(this->_internal_concept_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "ClassificationEvalSubset.concept_name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_concept_name(), target);
  }

  // string concept_id = 2;
  if (this->concept_id().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_concept_id().data(), static_cast<int>(this->_internal_concept_id().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "ClassificationEvalSubset.concept_id");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_concept_id(), target);
  }

  // double top1_correct = 10;
  if (!(this->top1_correct() <= 0 && this->top1_correct() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(10, this->_internal_top1_correct(), target);
  }

  // double topk_correct = 11;
  if (!(this->topk_correct() <= 0 && this->topk_correct() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(11, this->_internal_topk_correct(), target);
  }

  // double auc = 12;
  if (!(this->auc() <= 0 && this->auc() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(12, this->_internal_auc(), target);
  }

  // double precision_at_50 = 13;
  if (!(this->precision_at_50() <= 0 && this->precision_at_50() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(13, this->_internal_precision_at_50(), target);
  }

  // double recall_at_50 = 14;
  if (!(this->recall_at_50() <= 0 && this->recall_at_50() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(14, this->_internal_recall_at_50(), target);
  }

  // int64 num_gt_images = 17;
  if (this->num_gt_images() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(17, this->_internal_num_gt_images(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ClassificationEvalSubset)
  return target;
}

size_t ClassificationEvalSubset::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ClassificationEvalSubset)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string concept_name = 1;
  if (this->concept_name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_concept_name());
  }

  // string concept_id = 2;
  if (this->concept_id().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_concept_id());
  }

  // double top1_correct = 10;
  if (!(this->top1_correct() <= 0 && this->top1_correct() >= 0)) {
    total_size += 1 + 8;
  }

  // double topk_correct = 11;
  if (!(this->topk_correct() <= 0 && this->topk_correct() >= 0)) {
    total_size += 1 + 8;
  }

  // double auc = 12;
  if (!(this->auc() <= 0 && this->auc() >= 0)) {
    total_size += 1 + 8;
  }

  // double precision_at_50 = 13;
  if (!(this->precision_at_50() <= 0 && this->precision_at_50() >= 0)) {
    total_size += 1 + 8;
  }

  // double recall_at_50 = 14;
  if (!(this->recall_at_50() <= 0 && this->recall_at_50() >= 0)) {
    total_size += 1 + 8;
  }

  // int64 num_gt_images = 17;
  if (this->num_gt_images() != 0) {
    total_size += 2 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
        this->_internal_num_gt_images());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ClassificationEvalSubset::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ClassificationEvalSubset)
  GOOGLE_DCHECK_NE(&from, this);
  const ClassificationEvalSubset* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ClassificationEvalSubset>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ClassificationEvalSubset)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ClassificationEvalSubset)
    MergeFrom(*source);
  }
}

void ClassificationEvalSubset::MergeFrom(const ClassificationEvalSubset& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ClassificationEvalSubset)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.concept_name().size() > 0) {
    _internal_set_concept_name(from._internal_concept_name());
  }
  if (from.concept_id().size() > 0) {
    _internal_set_concept_id(from._internal_concept_id());
  }
  if (!(from.top1_correct() <= 0 && from.top1_correct() >= 0)) {
    _internal_set_top1_correct(from._internal_top1_correct());
  }
  if (!(from.topk_correct() <= 0 && from.topk_correct() >= 0)) {
    _internal_set_topk_correct(from._internal_topk_correct());
  }
  if (!(from.auc() <= 0 && from.auc() >= 0)) {
    _internal_set_auc(from._internal_auc());
  }
  if (!(from.precision_at_50() <= 0 && from.precision_at_50() >= 0)) {
    _internal_set_precision_at_50(from._internal_precision_at_50());
  }
  if (!(from.recall_at_50() <= 0 && from.recall_at_50() >= 0)) {
    _internal_set_recall_at_50(from._internal_recall_at_50());
  }
  if (from.num_gt_images() != 0) {
    _internal_set_num_gt_images(from._internal_num_gt_images());
  }
}

void ClassificationEvalSubset::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ClassificationEvalSubset)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ClassificationEvalSubset::CopyFrom(const ClassificationEvalSubset& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ClassificationEvalSubset)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ClassificationEvalSubset::IsInitialized() const {
  return true;
}

void ClassificationEvalSubset::InternalSwap(ClassificationEvalSubset* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  concept_name_.Swap(&other->concept_name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  concept_id_.Swap(&other->concept_id_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(ClassificationEvalSubset, num_gt_images_)
      + sizeof(ClassificationEvalSubset::num_gt_images_)
      - PROTOBUF_FIELD_OFFSET(ClassificationEvalSubset, top1_correct_)>(
          reinterpret_cast<char*>(&top1_correct_),
          reinterpret_cast<char*>(&other->top1_correct_));
}

::PROTOBUF_NAMESPACE_ID::Metadata ClassificationEvalSubset::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::ClassificationEvalResult* Arena::CreateMaybeMessage< ::ClassificationEvalResult >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ClassificationEvalResult >(arena);
}
template<> PROTOBUF_NOINLINE ::ClassificationEvalSubset* Arena::CreateMaybeMessage< ::ClassificationEvalSubset >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ClassificationEvalSubset >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
