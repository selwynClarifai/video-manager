// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/model_converter/model_converter.proto

#include "proto/model_converter/model_converter.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_proto_2fspire_2fspire_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<7> scc_info_SpireConfig_proto_2fspire_2fspire_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_proto_2fclarifai_2fmodel_5ffetching_2fresources_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ModelInfo_proto_2fclarifai_2fmodel_5ffetching_2fresources_2eproto;
class ModelConverterConvertModelRequestDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ModelConverterConvertModelRequest> _instance;
} _ModelConverterConvertModelRequest_default_instance_;
class ModelConverterConvertModelResponseDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ModelConverterConvertModelResponse> _instance;
} _ModelConverterConvertModelResponse_default_instance_;
static void InitDefaultsscc_info_ModelConverterConvertModelRequest_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_ModelConverterConvertModelRequest_default_instance_;
    new (ptr) ::ModelConverterConvertModelRequest();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::ModelConverterConvertModelRequest::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<2> scc_info_ModelConverterConvertModelRequest_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 2, 0, InitDefaultsscc_info_ModelConverterConvertModelRequest_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto}, {
      &scc_info_RequestMeta_proto_2futils_2frequest_5fmeta_2eproto.base,
      &scc_info_ModelInfo_proto_2fclarifai_2fmodel_5ffetching_2fresources_2eproto.base,}};

static void InitDefaultsscc_info_ModelConverterConvertModelResponse_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_ModelConverterConvertModelResponse_default_instance_;
    new (ptr) ::ModelConverterConvertModelResponse();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::ModelConverterConvertModelResponse::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<2> scc_info_ModelConverterConvertModelResponse_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 2, 0, InitDefaultsscc_info_ModelConverterConvertModelResponse_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto}, {
      &scc_info_ResponseStatus_proto_2futils_2frequest_5fmeta_2eproto.base,
      &scc_info_SpireConfig_proto_2fspire_2fspire_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ModelConverterConvertModelRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::ModelConverterConvertModelRequest, meta_),
  PROTOBUF_FIELD_OFFSET(::ModelConverterConvertModelRequest, model_info_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ModelConverterConvertModelResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::ModelConverterConvertModelResponse, status_),
  PROTOBUF_FIELD_OFFSET(::ModelConverterConvertModelResponse, config_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::ModelConverterConvertModelRequest)},
  { 7, -1, sizeof(::ModelConverterConvertModelResponse)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_ModelConverterConvertModelRequest_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_ModelConverterConvertModelResponse_default_instance_),
};

const char descriptor_table_protodef_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n+proto/model_converter/model_converter."
  "proto\032-proto/clarifai/model_fetching/res"
  "ources.proto\032\036proto/utils/request_meta.p"
  "roto\032\027proto/spire/spire.proto\"w\n!ModelCo"
  "nverterConvertModelRequest\022\032\n\004meta\030\001 \001(\013"
  "2\014.RequestMeta\0226\n\nmodel_info\030\002 \001(\0132\".cla"
  "rifai.model_fetching.ModelInfo\"c\n\"ModelC"
  "onverterConvertModelResponse\022\037\n\006status\030\001"
  " \001(\0132\017.ResponseStatus\022\034\n\006config\030\002 \001(\0132\014."
  "SpireConfig2\200\001\n\025ModelConverterService\022g\n"
  "\032ModelConverterConvertModel\022\".ModelConve"
  "rterConvertModelRequest\032#.ModelConverter"
  "ConvertModelResponse\"\000B\021Z\017model_converte"
  "rb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto_deps[3] = {
  &::descriptor_table_proto_2fclarifai_2fmodel_5ffetching_2fresources_2eproto,
  &::descriptor_table_proto_2fspire_2fspire_2eproto,
  &::descriptor_table_proto_2futils_2frequest_5fmeta_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto_sccs[2] = {
  &scc_info_ModelConverterConvertModelRequest_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto.base,
  &scc_info_ModelConverterConvertModelResponse_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto = {
  false, false, descriptor_table_protodef_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto, "proto/model_converter/model_converter.proto", 529,
  &descriptor_table_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto_once, descriptor_table_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto_sccs, descriptor_table_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto_deps, 2, 3,
  schemas, file_default_instances, TableStruct_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto::offsets,
  file_level_metadata_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto, 2, file_level_enum_descriptors_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto, file_level_service_descriptors_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto)), true);

// ===================================================================

void ModelConverterConvertModelRequest::InitAsDefaultInstance() {
  ::_ModelConverterConvertModelRequest_default_instance_._instance.get_mutable()->meta_ = const_cast< ::RequestMeta*>(
      ::RequestMeta::internal_default_instance());
  ::_ModelConverterConvertModelRequest_default_instance_._instance.get_mutable()->model_info_ = const_cast< ::clarifai::model_fetching::ModelInfo*>(
      ::clarifai::model_fetching::ModelInfo::internal_default_instance());
}
class ModelConverterConvertModelRequest::_Internal {
 public:
  static const ::RequestMeta& meta(const ModelConverterConvertModelRequest* msg);
  static const ::clarifai::model_fetching::ModelInfo& model_info(const ModelConverterConvertModelRequest* msg);
};

const ::RequestMeta&
ModelConverterConvertModelRequest::_Internal::meta(const ModelConverterConvertModelRequest* msg) {
  return *msg->meta_;
}
const ::clarifai::model_fetching::ModelInfo&
ModelConverterConvertModelRequest::_Internal::model_info(const ModelConverterConvertModelRequest* msg) {
  return *msg->model_info_;
}
void ModelConverterConvertModelRequest::clear_meta() {
  if (GetArena() == nullptr && meta_ != nullptr) {
    delete meta_;
  }
  meta_ = nullptr;
}
void ModelConverterConvertModelRequest::clear_model_info() {
  if (GetArena() == nullptr && model_info_ != nullptr) {
    delete model_info_;
  }
  model_info_ = nullptr;
}
ModelConverterConvertModelRequest::ModelConverterConvertModelRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:ModelConverterConvertModelRequest)
}
ModelConverterConvertModelRequest::ModelConverterConvertModelRequest(const ModelConverterConvertModelRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_meta()) {
    meta_ = new ::RequestMeta(*from.meta_);
  } else {
    meta_ = nullptr;
  }
  if (from._internal_has_model_info()) {
    model_info_ = new ::clarifai::model_fetching::ModelInfo(*from.model_info_);
  } else {
    model_info_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:ModelConverterConvertModelRequest)
}

void ModelConverterConvertModelRequest::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ModelConverterConvertModelRequest_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto.base);
  ::memset(&meta_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&model_info_) -
      reinterpret_cast<char*>(&meta_)) + sizeof(model_info_));
}

ModelConverterConvertModelRequest::~ModelConverterConvertModelRequest() {
  // @@protoc_insertion_point(destructor:ModelConverterConvertModelRequest)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void ModelConverterConvertModelRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete meta_;
  if (this != internal_default_instance()) delete model_info_;
}

void ModelConverterConvertModelRequest::ArenaDtor(void* object) {
  ModelConverterConvertModelRequest* _this = reinterpret_cast< ModelConverterConvertModelRequest* >(object);
  (void)_this;
}
void ModelConverterConvertModelRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ModelConverterConvertModelRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ModelConverterConvertModelRequest& ModelConverterConvertModelRequest::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ModelConverterConvertModelRequest_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto.base);
  return *internal_default_instance();
}


void ModelConverterConvertModelRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:ModelConverterConvertModelRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArena() == nullptr && meta_ != nullptr) {
    delete meta_;
  }
  meta_ = nullptr;
  if (GetArena() == nullptr && model_info_ != nullptr) {
    delete model_info_;
  }
  model_info_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ModelConverterConvertModelRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
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
      // .clarifai.model_fetching.ModelInfo model_info = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_model_info(), ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* ModelConverterConvertModelRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ModelConverterConvertModelRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .RequestMeta meta = 1;
  if (this->has_meta()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::meta(this), target, stream);
  }

  // .clarifai.model_fetching.ModelInfo model_info = 2;
  if (this->has_model_info()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        2, _Internal::model_info(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ModelConverterConvertModelRequest)
  return target;
}

size_t ModelConverterConvertModelRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ModelConverterConvertModelRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .RequestMeta meta = 1;
  if (this->has_meta()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *meta_);
  }

  // .clarifai.model_fetching.ModelInfo model_info = 2;
  if (this->has_model_info()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *model_info_);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ModelConverterConvertModelRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ModelConverterConvertModelRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const ModelConverterConvertModelRequest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ModelConverterConvertModelRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ModelConverterConvertModelRequest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ModelConverterConvertModelRequest)
    MergeFrom(*source);
  }
}

void ModelConverterConvertModelRequest::MergeFrom(const ModelConverterConvertModelRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ModelConverterConvertModelRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_meta()) {
    _internal_mutable_meta()->::RequestMeta::MergeFrom(from._internal_meta());
  }
  if (from.has_model_info()) {
    _internal_mutable_model_info()->::clarifai::model_fetching::ModelInfo::MergeFrom(from._internal_model_info());
  }
}

void ModelConverterConvertModelRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ModelConverterConvertModelRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ModelConverterConvertModelRequest::CopyFrom(const ModelConverterConvertModelRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ModelConverterConvertModelRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ModelConverterConvertModelRequest::IsInitialized() const {
  return true;
}

void ModelConverterConvertModelRequest::InternalSwap(ModelConverterConvertModelRequest* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(ModelConverterConvertModelRequest, model_info_)
      + sizeof(ModelConverterConvertModelRequest::model_info_)
      - PROTOBUF_FIELD_OFFSET(ModelConverterConvertModelRequest, meta_)>(
          reinterpret_cast<char*>(&meta_),
          reinterpret_cast<char*>(&other->meta_));
}

::PROTOBUF_NAMESPACE_ID::Metadata ModelConverterConvertModelRequest::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void ModelConverterConvertModelResponse::InitAsDefaultInstance() {
  ::_ModelConverterConvertModelResponse_default_instance_._instance.get_mutable()->status_ = const_cast< ::ResponseStatus*>(
      ::ResponseStatus::internal_default_instance());
  ::_ModelConverterConvertModelResponse_default_instance_._instance.get_mutable()->config_ = const_cast< ::SpireConfig*>(
      ::SpireConfig::internal_default_instance());
}
class ModelConverterConvertModelResponse::_Internal {
 public:
  static const ::ResponseStatus& status(const ModelConverterConvertModelResponse* msg);
  static const ::SpireConfig& config(const ModelConverterConvertModelResponse* msg);
};

const ::ResponseStatus&
ModelConverterConvertModelResponse::_Internal::status(const ModelConverterConvertModelResponse* msg) {
  return *msg->status_;
}
const ::SpireConfig&
ModelConverterConvertModelResponse::_Internal::config(const ModelConverterConvertModelResponse* msg) {
  return *msg->config_;
}
void ModelConverterConvertModelResponse::clear_status() {
  if (GetArena() == nullptr && status_ != nullptr) {
    delete status_;
  }
  status_ = nullptr;
}
void ModelConverterConvertModelResponse::clear_config() {
  if (GetArena() == nullptr && config_ != nullptr) {
    delete config_;
  }
  config_ = nullptr;
}
ModelConverterConvertModelResponse::ModelConverterConvertModelResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:ModelConverterConvertModelResponse)
}
ModelConverterConvertModelResponse::ModelConverterConvertModelResponse(const ModelConverterConvertModelResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_status()) {
    status_ = new ::ResponseStatus(*from.status_);
  } else {
    status_ = nullptr;
  }
  if (from._internal_has_config()) {
    config_ = new ::SpireConfig(*from.config_);
  } else {
    config_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:ModelConverterConvertModelResponse)
}

void ModelConverterConvertModelResponse::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ModelConverterConvertModelResponse_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto.base);
  ::memset(&status_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&config_) -
      reinterpret_cast<char*>(&status_)) + sizeof(config_));
}

ModelConverterConvertModelResponse::~ModelConverterConvertModelResponse() {
  // @@protoc_insertion_point(destructor:ModelConverterConvertModelResponse)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void ModelConverterConvertModelResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete status_;
  if (this != internal_default_instance()) delete config_;
}

void ModelConverterConvertModelResponse::ArenaDtor(void* object) {
  ModelConverterConvertModelResponse* _this = reinterpret_cast< ModelConverterConvertModelResponse* >(object);
  (void)_this;
}
void ModelConverterConvertModelResponse::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ModelConverterConvertModelResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ModelConverterConvertModelResponse& ModelConverterConvertModelResponse::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ModelConverterConvertModelResponse_proto_2fmodel_5fconverter_2fmodel_5fconverter_2eproto.base);
  return *internal_default_instance();
}


void ModelConverterConvertModelResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:ModelConverterConvertModelResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArena() == nullptr && status_ != nullptr) {
    delete status_;
  }
  status_ = nullptr;
  if (GetArena() == nullptr && config_ != nullptr) {
    delete config_;
  }
  config_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ModelConverterConvertModelResponse::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
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
      // .SpireConfig config = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_config(), ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* ModelConverterConvertModelResponse::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ModelConverterConvertModelResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .ResponseStatus status = 1;
  if (this->has_status()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::status(this), target, stream);
  }

  // .SpireConfig config = 2;
  if (this->has_config()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        2, _Internal::config(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ModelConverterConvertModelResponse)
  return target;
}

size_t ModelConverterConvertModelResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ModelConverterConvertModelResponse)
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

  // .SpireConfig config = 2;
  if (this->has_config()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *config_);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ModelConverterConvertModelResponse::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ModelConverterConvertModelResponse)
  GOOGLE_DCHECK_NE(&from, this);
  const ModelConverterConvertModelResponse* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ModelConverterConvertModelResponse>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ModelConverterConvertModelResponse)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ModelConverterConvertModelResponse)
    MergeFrom(*source);
  }
}

void ModelConverterConvertModelResponse::MergeFrom(const ModelConverterConvertModelResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ModelConverterConvertModelResponse)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_status()) {
    _internal_mutable_status()->::ResponseStatus::MergeFrom(from._internal_status());
  }
  if (from.has_config()) {
    _internal_mutable_config()->::SpireConfig::MergeFrom(from._internal_config());
  }
}

void ModelConverterConvertModelResponse::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ModelConverterConvertModelResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ModelConverterConvertModelResponse::CopyFrom(const ModelConverterConvertModelResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ModelConverterConvertModelResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ModelConverterConvertModelResponse::IsInitialized() const {
  return true;
}

void ModelConverterConvertModelResponse::InternalSwap(ModelConverterConvertModelResponse* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(ModelConverterConvertModelResponse, config_)
      + sizeof(ModelConverterConvertModelResponse::config_)
      - PROTOBUF_FIELD_OFFSET(ModelConverterConvertModelResponse, status_)>(
          reinterpret_cast<char*>(&status_),
          reinterpret_cast<char*>(&other->status_));
}

::PROTOBUF_NAMESPACE_ID::Metadata ModelConverterConvertModelResponse::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::ModelConverterConvertModelRequest* Arena::CreateMaybeMessage< ::ModelConverterConvertModelRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ModelConverterConvertModelRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::ModelConverterConvertModelResponse* Arena::CreateMaybeMessage< ::ModelConverterConvertModelResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ModelConverterConvertModelResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
