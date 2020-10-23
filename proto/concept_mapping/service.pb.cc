// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/concept_mapping/service.proto

#include "proto/concept_mapping/service.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_proto_2futils_2frequest_5fmeta_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_RequestMeta_proto_2futils_2frequest_5fmeta_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_proto_2futils_2frequest_5fmeta_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_ResponseStatus_proto_2futils_2frequest_5fmeta_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_proto_2fclarifai_2fapi_2fresources_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_KnowledgeGraph_proto_2fclarifai_2fapi_2fresources_2eproto;
class ConceptMappingRequestDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ConceptMappingRequest> _instance;
} _ConceptMappingRequest_default_instance_;
class ConceptMappingResponseDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ConceptMappingResponse> _instance;
} _ConceptMappingResponse_default_instance_;
static void InitDefaultsscc_info_ConceptMappingRequest_proto_2fconcept_5fmapping_2fservice_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_ConceptMappingRequest_default_instance_;
    new (ptr) ::ConceptMappingRequest();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::ConceptMappingRequest::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<2> scc_info_ConceptMappingRequest_proto_2fconcept_5fmapping_2fservice_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 2, 0, InitDefaultsscc_info_ConceptMappingRequest_proto_2fconcept_5fmapping_2fservice_2eproto}, {
      &scc_info_RequestMeta_proto_2futils_2frequest_5fmeta_2eproto.base,
      &scc_info_KnowledgeGraph_proto_2fclarifai_2fapi_2fresources_2eproto.base,}};

static void InitDefaultsscc_info_ConceptMappingResponse_proto_2fconcept_5fmapping_2fservice_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_ConceptMappingResponse_default_instance_;
    new (ptr) ::ConceptMappingResponse();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::ConceptMappingResponse::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_ConceptMappingResponse_proto_2fconcept_5fmapping_2fservice_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_ConceptMappingResponse_proto_2fconcept_5fmapping_2fservice_2eproto}, {
      &scc_info_ResponseStatus_proto_2futils_2frequest_5fmeta_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_proto_2fconcept_5fmapping_2fservice_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_proto_2fconcept_5fmapping_2fservice_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_proto_2fconcept_5fmapping_2fservice_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_proto_2fconcept_5fmapping_2fservice_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ConceptMappingRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::ConceptMappingRequest, meta_),
  PROTOBUF_FIELD_OFFSET(::ConceptMappingRequest, app_id_),
  PROTOBUF_FIELD_OFFSET(::ConceptMappingRequest, concept_ids_),
  PROTOBUF_FIELD_OFFSET(::ConceptMappingRequest, knowledge_graph_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ConceptMappingResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::ConceptMappingResponse, status_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::ConceptMappingRequest)},
  { 9, -1, sizeof(::ConceptMappingResponse)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_ConceptMappingRequest_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_ConceptMappingResponse_default_instance_),
};

const char descriptor_table_protodef_proto_2fconcept_5fmapping_2fservice_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n#proto/concept_mapping/service.proto\032\"p"
  "roto/clarifai/api/resources.proto\032\036proto"
  "/utils/request_meta.proto\"\217\001\n\025ConceptMap"
  "pingRequest\022\032\n\004meta\030\001 \001(\0132\014.RequestMeta\022"
  "\016\n\006app_id\030\002 \001(\t\022\023\n\013concept_ids\030\003 \003(\t\0225\n\017"
  "knowledge_graph\030\004 \001(\0132\034.clarifai.api.Kno"
  "wledgeGraph\"9\n\026ConceptMappingResponse\022\037\n"
  "\006status\030\001 \001(\0132\017.ResponseStatus2Y\n\025Concep"
  "tMappingService\022@\n\013MapConcepts\022\026.Concept"
  "MappingRequest\032\027.ConceptMappingResponse\""
  "\000B\"\n\017concept_mappingZ\017concept_mappingb\006p"
  "roto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_proto_2fconcept_5fmapping_2fservice_2eproto_deps[2] = {
  &::descriptor_table_proto_2fclarifai_2fapi_2fresources_2eproto,
  &::descriptor_table_proto_2futils_2frequest_5fmeta_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_proto_2fconcept_5fmapping_2fservice_2eproto_sccs[2] = {
  &scc_info_ConceptMappingRequest_proto_2fconcept_5fmapping_2fservice_2eproto.base,
  &scc_info_ConceptMappingResponse_proto_2fconcept_5fmapping_2fservice_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_proto_2fconcept_5fmapping_2fservice_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2fconcept_5fmapping_2fservice_2eproto = {
  false, false, descriptor_table_protodef_proto_2fconcept_5fmapping_2fservice_2eproto, "proto/concept_mapping/service.proto", 445,
  &descriptor_table_proto_2fconcept_5fmapping_2fservice_2eproto_once, descriptor_table_proto_2fconcept_5fmapping_2fservice_2eproto_sccs, descriptor_table_proto_2fconcept_5fmapping_2fservice_2eproto_deps, 2, 2,
  schemas, file_default_instances, TableStruct_proto_2fconcept_5fmapping_2fservice_2eproto::offsets,
  file_level_metadata_proto_2fconcept_5fmapping_2fservice_2eproto, 2, file_level_enum_descriptors_proto_2fconcept_5fmapping_2fservice_2eproto, file_level_service_descriptors_proto_2fconcept_5fmapping_2fservice_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_proto_2fconcept_5fmapping_2fservice_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_proto_2fconcept_5fmapping_2fservice_2eproto)), true);

// ===================================================================

void ConceptMappingRequest::InitAsDefaultInstance() {
  ::_ConceptMappingRequest_default_instance_._instance.get_mutable()->meta_ = const_cast< ::RequestMeta*>(
      ::RequestMeta::internal_default_instance());
  ::_ConceptMappingRequest_default_instance_._instance.get_mutable()->knowledge_graph_ = const_cast< ::clarifai::api::KnowledgeGraph*>(
      ::clarifai::api::KnowledgeGraph::internal_default_instance());
}
class ConceptMappingRequest::_Internal {
 public:
  static const ::RequestMeta& meta(const ConceptMappingRequest* msg);
  static const ::clarifai::api::KnowledgeGraph& knowledge_graph(const ConceptMappingRequest* msg);
};

const ::RequestMeta&
ConceptMappingRequest::_Internal::meta(const ConceptMappingRequest* msg) {
  return *msg->meta_;
}
const ::clarifai::api::KnowledgeGraph&
ConceptMappingRequest::_Internal::knowledge_graph(const ConceptMappingRequest* msg) {
  return *msg->knowledge_graph_;
}
void ConceptMappingRequest::clear_meta() {
  if (GetArena() == nullptr && meta_ != nullptr) {
    delete meta_;
  }
  meta_ = nullptr;
}
void ConceptMappingRequest::clear_knowledge_graph() {
  if (GetArena() == nullptr && knowledge_graph_ != nullptr) {
    delete knowledge_graph_;
  }
  knowledge_graph_ = nullptr;
}
ConceptMappingRequest::ConceptMappingRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  concept_ids_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:ConceptMappingRequest)
}
ConceptMappingRequest::ConceptMappingRequest(const ConceptMappingRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      concept_ids_(from.concept_ids_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  app_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_app_id().empty()) {
    app_id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_app_id(),
      GetArena());
  }
  if (from._internal_has_meta()) {
    meta_ = new ::RequestMeta(*from.meta_);
  } else {
    meta_ = nullptr;
  }
  if (from._internal_has_knowledge_graph()) {
    knowledge_graph_ = new ::clarifai::api::KnowledgeGraph(*from.knowledge_graph_);
  } else {
    knowledge_graph_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:ConceptMappingRequest)
}

void ConceptMappingRequest::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ConceptMappingRequest_proto_2fconcept_5fmapping_2fservice_2eproto.base);
  app_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&meta_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&knowledge_graph_) -
      reinterpret_cast<char*>(&meta_)) + sizeof(knowledge_graph_));
}

ConceptMappingRequest::~ConceptMappingRequest() {
  // @@protoc_insertion_point(destructor:ConceptMappingRequest)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void ConceptMappingRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  app_id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete meta_;
  if (this != internal_default_instance()) delete knowledge_graph_;
}

void ConceptMappingRequest::ArenaDtor(void* object) {
  ConceptMappingRequest* _this = reinterpret_cast< ConceptMappingRequest* >(object);
  (void)_this;
}
void ConceptMappingRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ConceptMappingRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ConceptMappingRequest& ConceptMappingRequest::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ConceptMappingRequest_proto_2fconcept_5fmapping_2fservice_2eproto.base);
  return *internal_default_instance();
}


void ConceptMappingRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:ConceptMappingRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  concept_ids_.Clear();
  app_id_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  if (GetArena() == nullptr && meta_ != nullptr) {
    delete meta_;
  }
  meta_ = nullptr;
  if (GetArena() == nullptr && knowledge_graph_ != nullptr) {
    delete knowledge_graph_;
  }
  knowledge_graph_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ConceptMappingRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // .RequestMeta meta = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_meta(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string app_id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_app_id();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ConceptMappingRequest.app_id"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated string concept_ids = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_concept_ids();
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
            CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ConceptMappingRequest.concept_ids"));
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<26>(ptr));
        } else goto handle_unusual;
        continue;
      // .clarifai.api.KnowledgeGraph knowledge_graph = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr = ctx->ParseMessage(_internal_mutable_knowledge_graph(), ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* ConceptMappingRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ConceptMappingRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .RequestMeta meta = 1;
  if (this->has_meta()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::meta(this), target, stream);
  }

  // string app_id = 2;
  if (this->app_id().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_app_id().data(), static_cast<int>(this->_internal_app_id().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "ConceptMappingRequest.app_id");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_app_id(), target);
  }

  // repeated string concept_ids = 3;
  for (int i = 0, n = this->_internal_concept_ids_size(); i < n; i++) {
    const auto& s = this->_internal_concept_ids(i);
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      s.data(), static_cast<int>(s.length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "ConceptMappingRequest.concept_ids");
    target = stream->WriteString(3, s, target);
  }

  // .clarifai.api.KnowledgeGraph knowledge_graph = 4;
  if (this->has_knowledge_graph()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        4, _Internal::knowledge_graph(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ConceptMappingRequest)
  return target;
}

size_t ConceptMappingRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ConceptMappingRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated string concept_ids = 3;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(concept_ids_.size());
  for (int i = 0, n = concept_ids_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
      concept_ids_.Get(i));
  }

  // string app_id = 2;
  if (this->app_id().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_app_id());
  }

  // .RequestMeta meta = 1;
  if (this->has_meta()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *meta_);
  }

  // .clarifai.api.KnowledgeGraph knowledge_graph = 4;
  if (this->has_knowledge_graph()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *knowledge_graph_);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ConceptMappingRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ConceptMappingRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const ConceptMappingRequest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ConceptMappingRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ConceptMappingRequest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ConceptMappingRequest)
    MergeFrom(*source);
  }
}

void ConceptMappingRequest::MergeFrom(const ConceptMappingRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ConceptMappingRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  concept_ids_.MergeFrom(from.concept_ids_);
  if (from.app_id().size() > 0) {
    _internal_set_app_id(from._internal_app_id());
  }
  if (from.has_meta()) {
    _internal_mutable_meta()->::RequestMeta::MergeFrom(from._internal_meta());
  }
  if (from.has_knowledge_graph()) {
    _internal_mutable_knowledge_graph()->::clarifai::api::KnowledgeGraph::MergeFrom(from._internal_knowledge_graph());
  }
}

void ConceptMappingRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ConceptMappingRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ConceptMappingRequest::CopyFrom(const ConceptMappingRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ConceptMappingRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ConceptMappingRequest::IsInitialized() const {
  return true;
}

void ConceptMappingRequest::InternalSwap(ConceptMappingRequest* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  concept_ids_.InternalSwap(&other->concept_ids_);
  app_id_.Swap(&other->app_id_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(ConceptMappingRequest, knowledge_graph_)
      + sizeof(ConceptMappingRequest::knowledge_graph_)
      - PROTOBUF_FIELD_OFFSET(ConceptMappingRequest, meta_)>(
          reinterpret_cast<char*>(&meta_),
          reinterpret_cast<char*>(&other->meta_));
}

::PROTOBUF_NAMESPACE_ID::Metadata ConceptMappingRequest::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void ConceptMappingResponse::InitAsDefaultInstance() {
  ::_ConceptMappingResponse_default_instance_._instance.get_mutable()->status_ = const_cast< ::ResponseStatus*>(
      ::ResponseStatus::internal_default_instance());
}
class ConceptMappingResponse::_Internal {
 public:
  static const ::ResponseStatus& status(const ConceptMappingResponse* msg);
};

const ::ResponseStatus&
ConceptMappingResponse::_Internal::status(const ConceptMappingResponse* msg) {
  return *msg->status_;
}
void ConceptMappingResponse::clear_status() {
  if (GetArena() == nullptr && status_ != nullptr) {
    delete status_;
  }
  status_ = nullptr;
}
ConceptMappingResponse::ConceptMappingResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:ConceptMappingResponse)
}
ConceptMappingResponse::ConceptMappingResponse(const ConceptMappingResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_status()) {
    status_ = new ::ResponseStatus(*from.status_);
  } else {
    status_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:ConceptMappingResponse)
}

void ConceptMappingResponse::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ConceptMappingResponse_proto_2fconcept_5fmapping_2fservice_2eproto.base);
  status_ = nullptr;
}

ConceptMappingResponse::~ConceptMappingResponse() {
  // @@protoc_insertion_point(destructor:ConceptMappingResponse)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void ConceptMappingResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete status_;
}

void ConceptMappingResponse::ArenaDtor(void* object) {
  ConceptMappingResponse* _this = reinterpret_cast< ConceptMappingResponse* >(object);
  (void)_this;
}
void ConceptMappingResponse::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ConceptMappingResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ConceptMappingResponse& ConceptMappingResponse::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ConceptMappingResponse_proto_2fconcept_5fmapping_2fservice_2eproto.base);
  return *internal_default_instance();
}


void ConceptMappingResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:ConceptMappingResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArena() == nullptr && status_ != nullptr) {
    delete status_;
  }
  status_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ConceptMappingResponse::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // .ResponseStatus status = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_status(), ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* ConceptMappingResponse::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ConceptMappingResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .ResponseStatus status = 1;
  if (this->has_status()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::status(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ConceptMappingResponse)
  return target;
}

size_t ConceptMappingResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ConceptMappingResponse)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .ResponseStatus status = 1;
  if (this->has_status()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *status_);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ConceptMappingResponse::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ConceptMappingResponse)
  GOOGLE_DCHECK_NE(&from, this);
  const ConceptMappingResponse* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ConceptMappingResponse>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ConceptMappingResponse)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ConceptMappingResponse)
    MergeFrom(*source);
  }
}

void ConceptMappingResponse::MergeFrom(const ConceptMappingResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ConceptMappingResponse)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_status()) {
    _internal_mutable_status()->::ResponseStatus::MergeFrom(from._internal_status());
  }
}

void ConceptMappingResponse::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ConceptMappingResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ConceptMappingResponse::CopyFrom(const ConceptMappingResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ConceptMappingResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ConceptMappingResponse::IsInitialized() const {
  return true;
}

void ConceptMappingResponse::InternalSwap(ConceptMappingResponse* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(status_, other->status_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ConceptMappingResponse::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::ConceptMappingRequest* Arena::CreateMaybeMessage< ::ConceptMappingRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ConceptMappingRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::ConceptMappingResponse* Arena::CreateMaybeMessage< ::ConceptMappingResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ConceptMappingResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>