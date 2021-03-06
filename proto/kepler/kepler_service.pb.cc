// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/kepler/kepler_service.proto

#include "proto/kepler/kepler_service.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_proto_2fkepler_2fkepler_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_Region_proto_2fkepler_2fkepler_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_proto_2fkepler_2fkepler_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Status_proto_2fkepler_2fkepler_2eproto;
namespace kepler_clarifai {
class GetStatusRequestDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<GetStatusRequest> _instance;
} _GetStatusRequest_default_instance_;
class GetStatusResponseDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<GetStatusResponse> _instance;
} _GetStatusResponse_default_instance_;
class ResponseDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Response> _instance;
} _Response_default_instance_;
}  // namespace kepler_clarifai
static void InitDefaultsscc_info_GetStatusRequest_proto_2fkepler_2fkepler_5fservice_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::kepler_clarifai::_GetStatusRequest_default_instance_;
    new (ptr) ::kepler_clarifai::GetStatusRequest();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::kepler_clarifai::GetStatusRequest::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_GetStatusRequest_proto_2fkepler_2fkepler_5fservice_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_GetStatusRequest_proto_2fkepler_2fkepler_5fservice_2eproto}, {}};

static void InitDefaultsscc_info_GetStatusResponse_proto_2fkepler_2fkepler_5fservice_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::kepler_clarifai::_GetStatusResponse_default_instance_;
    new (ptr) ::kepler_clarifai::GetStatusResponse();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::kepler_clarifai::GetStatusResponse::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_GetStatusResponse_proto_2fkepler_2fkepler_5fservice_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_GetStatusResponse_proto_2fkepler_2fkepler_5fservice_2eproto}, {
      &scc_info_Status_proto_2fkepler_2fkepler_2eproto.base,}};

static void InitDefaultsscc_info_Response_proto_2fkepler_2fkepler_5fservice_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::kepler_clarifai::_Response_default_instance_;
    new (ptr) ::kepler_clarifai::Response();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::kepler_clarifai::Response::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<2> scc_info_Response_proto_2fkepler_2fkepler_5fservice_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 2, 0, InitDefaultsscc_info_Response_proto_2fkepler_2fkepler_5fservice_2eproto}, {
      &scc_info_Status_proto_2fkepler_2fkepler_2eproto.base,
      &scc_info_Region_proto_2fkepler_2fkepler_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_proto_2fkepler_2fkepler_5fservice_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_proto_2fkepler_2fkepler_5fservice_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_proto_2fkepler_2fkepler_5fservice_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_proto_2fkepler_2fkepler_5fservice_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::kepler_clarifai::GetStatusRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::kepler_clarifai::GetStatusResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::kepler_clarifai::GetStatusResponse, status_),
  PROTOBUF_FIELD_OFFSET(::kepler_clarifai::GetStatusResponse, state_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::kepler_clarifai::Response, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::kepler_clarifai::Response, status_),
  PROTOBUF_FIELD_OFFSET(::kepler_clarifai::Response, regions_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::kepler_clarifai::GetStatusRequest)},
  { 5, -1, sizeof(::kepler_clarifai::GetStatusResponse)},
  { 12, -1, sizeof(::kepler_clarifai::Response)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::kepler_clarifai::_GetStatusRequest_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::kepler_clarifai::_GetStatusResponse_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::kepler_clarifai::_Response_default_instance_),
};

const char descriptor_table_protodef_proto_2fkepler_2fkepler_5fservice_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n!proto/kepler/kepler_service.proto\022\017kep"
  "ler_clarifai\032\031proto/kepler/kepler.proto\""
  "\022\n\020GetStatusRequest\"K\n\021GetStatusResponse"
  "\022\'\n\006status\030\001 \001(\0132\027.kepler_clarifai.Statu"
  "s\022\r\n\005state\030\002 \001(\t\"]\n\010Response\022\'\n\006status\030\001"
  " \001(\0132\027.kepler_clarifai.Status\022(\n\007regions"
  "\030\002 \003(\0132\027.kepler_clarifai.Region2\266\001\n\rKepl"
  "erService\022T\n\tGetStatus\022!.kepler_clarifai"
  ".GetStatusRequest\032\".kepler_clarifai.GetS"
  "tatusResponse\"\000\022O\n\022ProcessFrameBundle\022\034."
  "kepler_clarifai.FrameBundle\032\031.kepler_cla"
  "rifai.Response\"\000b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_proto_2fkepler_2fkepler_5fservice_2eproto_deps[1] = {
  &::descriptor_table_proto_2fkepler_2fkepler_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_proto_2fkepler_2fkepler_5fservice_2eproto_sccs[3] = {
  &scc_info_GetStatusRequest_proto_2fkepler_2fkepler_5fservice_2eproto.base,
  &scc_info_GetStatusResponse_proto_2fkepler_2fkepler_5fservice_2eproto.base,
  &scc_info_Response_proto_2fkepler_2fkepler_5fservice_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_proto_2fkepler_2fkepler_5fservice_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2fkepler_2fkepler_5fservice_2eproto = {
  false, false, descriptor_table_protodef_proto_2fkepler_2fkepler_5fservice_2eproto, "proto/kepler/kepler_service.proto", 464,
  &descriptor_table_proto_2fkepler_2fkepler_5fservice_2eproto_once, descriptor_table_proto_2fkepler_2fkepler_5fservice_2eproto_sccs, descriptor_table_proto_2fkepler_2fkepler_5fservice_2eproto_deps, 3, 1,
  schemas, file_default_instances, TableStruct_proto_2fkepler_2fkepler_5fservice_2eproto::offsets,
  file_level_metadata_proto_2fkepler_2fkepler_5fservice_2eproto, 3, file_level_enum_descriptors_proto_2fkepler_2fkepler_5fservice_2eproto, file_level_service_descriptors_proto_2fkepler_2fkepler_5fservice_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_proto_2fkepler_2fkepler_5fservice_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_proto_2fkepler_2fkepler_5fservice_2eproto)), true);
namespace kepler_clarifai {

// ===================================================================

void GetStatusRequest::InitAsDefaultInstance() {
}
class GetStatusRequest::_Internal {
 public:
};

GetStatusRequest::GetStatusRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:kepler_clarifai.GetStatusRequest)
}
GetStatusRequest::GetStatusRequest(const GetStatusRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:kepler_clarifai.GetStatusRequest)
}

void GetStatusRequest::SharedCtor() {
}

GetStatusRequest::~GetStatusRequest() {
  // @@protoc_insertion_point(destructor:kepler_clarifai.GetStatusRequest)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void GetStatusRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void GetStatusRequest::ArenaDtor(void* object) {
  GetStatusRequest* _this = reinterpret_cast< GetStatusRequest* >(object);
  (void)_this;
}
void GetStatusRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void GetStatusRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const GetStatusRequest& GetStatusRequest::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_GetStatusRequest_proto_2fkepler_2fkepler_5fservice_2eproto.base);
  return *internal_default_instance();
}


void GetStatusRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:kepler_clarifai.GetStatusRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* GetStatusRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* GetStatusRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:kepler_clarifai.GetStatusRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:kepler_clarifai.GetStatusRequest)
  return target;
}

size_t GetStatusRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:kepler_clarifai.GetStatusRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void GetStatusRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:kepler_clarifai.GetStatusRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const GetStatusRequest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<GetStatusRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:kepler_clarifai.GetStatusRequest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:kepler_clarifai.GetStatusRequest)
    MergeFrom(*source);
  }
}

void GetStatusRequest::MergeFrom(const GetStatusRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:kepler_clarifai.GetStatusRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

}

void GetStatusRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:kepler_clarifai.GetStatusRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetStatusRequest::CopyFrom(const GetStatusRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:kepler_clarifai.GetStatusRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetStatusRequest::IsInitialized() const {
  return true;
}

void GetStatusRequest::InternalSwap(GetStatusRequest* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
}

::PROTOBUF_NAMESPACE_ID::Metadata GetStatusRequest::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void GetStatusResponse::InitAsDefaultInstance() {
  ::kepler_clarifai::_GetStatusResponse_default_instance_._instance.get_mutable()->status_ = const_cast< ::kepler_clarifai::Status*>(
      ::kepler_clarifai::Status::internal_default_instance());
}
class GetStatusResponse::_Internal {
 public:
  static const ::kepler_clarifai::Status& status(const GetStatusResponse* msg);
};

const ::kepler_clarifai::Status&
GetStatusResponse::_Internal::status(const GetStatusResponse* msg) {
  return *msg->status_;
}
void GetStatusResponse::clear_status() {
  if (GetArena() == nullptr && status_ != nullptr) {
    delete status_;
  }
  status_ = nullptr;
}
GetStatusResponse::GetStatusResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:kepler_clarifai.GetStatusResponse)
}
GetStatusResponse::GetStatusResponse(const GetStatusResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  state_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_state().empty()) {
    state_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_state(),
      GetArena());
  }
  if (from._internal_has_status()) {
    status_ = new ::kepler_clarifai::Status(*from.status_);
  } else {
    status_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:kepler_clarifai.GetStatusResponse)
}

void GetStatusResponse::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_GetStatusResponse_proto_2fkepler_2fkepler_5fservice_2eproto.base);
  state_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  status_ = nullptr;
}

GetStatusResponse::~GetStatusResponse() {
  // @@protoc_insertion_point(destructor:kepler_clarifai.GetStatusResponse)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void GetStatusResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  state_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete status_;
}

void GetStatusResponse::ArenaDtor(void* object) {
  GetStatusResponse* _this = reinterpret_cast< GetStatusResponse* >(object);
  (void)_this;
}
void GetStatusResponse::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void GetStatusResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const GetStatusResponse& GetStatusResponse::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_GetStatusResponse_proto_2fkepler_2fkepler_5fservice_2eproto.base);
  return *internal_default_instance();
}


void GetStatusResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:kepler_clarifai.GetStatusResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  state_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  if (GetArena() == nullptr && status_ != nullptr) {
    delete status_;
  }
  status_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* GetStatusResponse::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // .kepler_clarifai.Status status = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_status(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string state = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_state();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "kepler_clarifai.GetStatusResponse.state"));
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

::PROTOBUF_NAMESPACE_ID::uint8* GetStatusResponse::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:kepler_clarifai.GetStatusResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .kepler_clarifai.Status status = 1;
  if (this->has_status()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::status(this), target, stream);
  }

  // string state = 2;
  if (this->state().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_state().data(), static_cast<int>(this->_internal_state().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "kepler_clarifai.GetStatusResponse.state");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_state(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:kepler_clarifai.GetStatusResponse)
  return target;
}

size_t GetStatusResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:kepler_clarifai.GetStatusResponse)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string state = 2;
  if (this->state().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_state());
  }

  // .kepler_clarifai.Status status = 1;
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

void GetStatusResponse::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:kepler_clarifai.GetStatusResponse)
  GOOGLE_DCHECK_NE(&from, this);
  const GetStatusResponse* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<GetStatusResponse>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:kepler_clarifai.GetStatusResponse)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:kepler_clarifai.GetStatusResponse)
    MergeFrom(*source);
  }
}

void GetStatusResponse::MergeFrom(const GetStatusResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:kepler_clarifai.GetStatusResponse)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.state().size() > 0) {
    _internal_set_state(from._internal_state());
  }
  if (from.has_status()) {
    _internal_mutable_status()->::kepler_clarifai::Status::MergeFrom(from._internal_status());
  }
}

void GetStatusResponse::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:kepler_clarifai.GetStatusResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetStatusResponse::CopyFrom(const GetStatusResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:kepler_clarifai.GetStatusResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetStatusResponse::IsInitialized() const {
  return true;
}

void GetStatusResponse::InternalSwap(GetStatusResponse* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  state_.Swap(&other->state_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  swap(status_, other->status_);
}

::PROTOBUF_NAMESPACE_ID::Metadata GetStatusResponse::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void Response::InitAsDefaultInstance() {
  ::kepler_clarifai::_Response_default_instance_._instance.get_mutable()->status_ = const_cast< ::kepler_clarifai::Status*>(
      ::kepler_clarifai::Status::internal_default_instance());
}
class Response::_Internal {
 public:
  static const ::kepler_clarifai::Status& status(const Response* msg);
};

const ::kepler_clarifai::Status&
Response::_Internal::status(const Response* msg) {
  return *msg->status_;
}
void Response::clear_status() {
  if (GetArena() == nullptr && status_ != nullptr) {
    delete status_;
  }
  status_ = nullptr;
}
void Response::clear_regions() {
  regions_.Clear();
}
Response::Response(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  regions_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:kepler_clarifai.Response)
}
Response::Response(const Response& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      regions_(from.regions_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_status()) {
    status_ = new ::kepler_clarifai::Status(*from.status_);
  } else {
    status_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:kepler_clarifai.Response)
}

void Response::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Response_proto_2fkepler_2fkepler_5fservice_2eproto.base);
  status_ = nullptr;
}

Response::~Response() {
  // @@protoc_insertion_point(destructor:kepler_clarifai.Response)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Response::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete status_;
}

void Response::ArenaDtor(void* object) {
  Response* _this = reinterpret_cast< Response* >(object);
  (void)_this;
}
void Response::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Response::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Response& Response::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Response_proto_2fkepler_2fkepler_5fservice_2eproto.base);
  return *internal_default_instance();
}


void Response::Clear() {
// @@protoc_insertion_point(message_clear_start:kepler_clarifai.Response)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  regions_.Clear();
  if (GetArena() == nullptr && status_ != nullptr) {
    delete status_;
  }
  status_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Response::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // .kepler_clarifai.Status status = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_status(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .kepler_clarifai.Region regions = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_regions(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
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

::PROTOBUF_NAMESPACE_ID::uint8* Response::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:kepler_clarifai.Response)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .kepler_clarifai.Status status = 1;
  if (this->has_status()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::status(this), target, stream);
  }

  // repeated .kepler_clarifai.Region regions = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_regions_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, this->_internal_regions(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:kepler_clarifai.Response)
  return target;
}

size_t Response::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:kepler_clarifai.Response)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .kepler_clarifai.Region regions = 2;
  total_size += 1UL * this->_internal_regions_size();
  for (const auto& msg : this->regions_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // .kepler_clarifai.Status status = 1;
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

void Response::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:kepler_clarifai.Response)
  GOOGLE_DCHECK_NE(&from, this);
  const Response* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Response>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:kepler_clarifai.Response)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:kepler_clarifai.Response)
    MergeFrom(*source);
  }
}

void Response::MergeFrom(const Response& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:kepler_clarifai.Response)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  regions_.MergeFrom(from.regions_);
  if (from.has_status()) {
    _internal_mutable_status()->::kepler_clarifai::Status::MergeFrom(from._internal_status());
  }
}

void Response::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:kepler_clarifai.Response)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Response::CopyFrom(const Response& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:kepler_clarifai.Response)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Response::IsInitialized() const {
  return true;
}

void Response::InternalSwap(Response* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  regions_.InternalSwap(&other->regions_);
  swap(status_, other->status_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Response::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace kepler_clarifai
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::kepler_clarifai::GetStatusRequest* Arena::CreateMaybeMessage< ::kepler_clarifai::GetStatusRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::kepler_clarifai::GetStatusRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::kepler_clarifai::GetStatusResponse* Arena::CreateMaybeMessage< ::kepler_clarifai::GetStatusResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::kepler_clarifai::GetStatusResponse >(arena);
}
template<> PROTOBUF_NOINLINE ::kepler_clarifai::Response* Arena::CreateMaybeMessage< ::kepler_clarifai::Response >(Arena* arena) {
  return Arena::CreateMessageInternal< ::kepler_clarifai::Response >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
