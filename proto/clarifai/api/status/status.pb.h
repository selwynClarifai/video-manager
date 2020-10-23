// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/clarifai/api/status/status.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_proto_2fclarifai_2fapi_2fstatus_2fstatus_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_proto_2fclarifai_2fapi_2fstatus_2fstatus_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3013000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3013000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "proto/clarifai/auth/util/extension.pb.h"
#include "proto/clarifai/api/status/status_code.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_proto_2fclarifai_2fapi_2fstatus_2fstatus_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_proto_2fclarifai_2fapi_2fstatus_2fstatus_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2fclarifai_2fapi_2fstatus_2fstatus_2eproto;
namespace clarifai {
namespace api {
namespace status {
class BaseResponse;
class BaseResponseDefaultTypeInternal;
extern BaseResponseDefaultTypeInternal _BaseResponse_default_instance_;
class Status;
class StatusDefaultTypeInternal;
extern StatusDefaultTypeInternal _Status_default_instance_;
}  // namespace status
}  // namespace api
}  // namespace clarifai
PROTOBUF_NAMESPACE_OPEN
template<> ::clarifai::api::status::BaseResponse* Arena::CreateMaybeMessage<::clarifai::api::status::BaseResponse>(Arena*);
template<> ::clarifai::api::status::Status* Arena::CreateMaybeMessage<::clarifai::api::status::Status>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace clarifai {
namespace api {
namespace status {

// ===================================================================

class Status PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:clarifai.api.status.Status) */ {
 public:
  inline Status() : Status(nullptr) {}
  virtual ~Status();

  Status(const Status& from);
  Status(Status&& from) noexcept
    : Status() {
    *this = ::std::move(from);
  }

  inline Status& operator=(const Status& from) {
    CopyFrom(from);
    return *this;
  }
  inline Status& operator=(Status&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Status& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Status* internal_default_instance() {
    return reinterpret_cast<const Status*>(
               &_Status_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Status& a, Status& b) {
    a.Swap(&b);
  }
  inline void Swap(Status* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Status* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Status* New() const final {
    return CreateMaybeMessage<Status>(nullptr);
  }

  Status* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Status>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Status& from);
  void MergeFrom(const Status& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Status* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "clarifai.api.status.Status";
  }
  protected:
  explicit Status(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_proto_2fclarifai_2fapi_2fstatus_2fstatus_2eproto);
    return ::descriptor_table_proto_2fclarifai_2fapi_2fstatus_2fstatus_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kStackTraceFieldNumber = 4,
    kDescriptionFieldNumber = 2,
    kDetailsFieldNumber = 3,
    kReqIdFieldNumber = 7,
    kInternalDetailsFieldNumber = 8,
    kCodeFieldNumber = 1,
    kPercentCompletedFieldNumber = 5,
    kTimeRemainingFieldNumber = 6,
  };
  // repeated string stack_trace = 4 [(.clarifai.auth.util.cl_private_field) = true];
  int stack_trace_size() const;
  private:
  int _internal_stack_trace_size() const;
  public:
  void clear_stack_trace();
  const std::string& stack_trace(int index) const;
  std::string* mutable_stack_trace(int index);
  void set_stack_trace(int index, const std::string& value);
  void set_stack_trace(int index, std::string&& value);
  void set_stack_trace(int index, const char* value);
  void set_stack_trace(int index, const char* value, size_t size);
  std::string* add_stack_trace();
  void add_stack_trace(const std::string& value);
  void add_stack_trace(std::string&& value);
  void add_stack_trace(const char* value);
  void add_stack_trace(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& stack_trace() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_stack_trace();
  private:
  const std::string& _internal_stack_trace(int index) const;
  std::string* _internal_add_stack_trace();
  public:

  // string description = 2;
  void clear_description();
  const std::string& description() const;
  void set_description(const std::string& value);
  void set_description(std::string&& value);
  void set_description(const char* value);
  void set_description(const char* value, size_t size);
  std::string* mutable_description();
  std::string* release_description();
  void set_allocated_description(std::string* description);
  private:
  const std::string& _internal_description() const;
  void _internal_set_description(const std::string& value);
  std::string* _internal_mutable_description();
  public:

  // string details = 3;
  void clear_details();
  const std::string& details() const;
  void set_details(const std::string& value);
  void set_details(std::string&& value);
  void set_details(const char* value);
  void set_details(const char* value, size_t size);
  std::string* mutable_details();
  std::string* release_details();
  void set_allocated_details(std::string* details);
  private:
  const std::string& _internal_details() const;
  void _internal_set_details(const std::string& value);
  std::string* _internal_mutable_details();
  public:

  // string req_id = 7;
  void clear_req_id();
  const std::string& req_id() const;
  void set_req_id(const std::string& value);
  void set_req_id(std::string&& value);
  void set_req_id(const char* value);
  void set_req_id(const char* value, size_t size);
  std::string* mutable_req_id();
  std::string* release_req_id();
  void set_allocated_req_id(std::string* req_id);
  private:
  const std::string& _internal_req_id() const;
  void _internal_set_req_id(const std::string& value);
  std::string* _internal_mutable_req_id();
  public:

  // string internal_details = 8 [(.clarifai.auth.util.cl_private_field) = true];
  void clear_internal_details();
  const std::string& internal_details() const;
  void set_internal_details(const std::string& value);
  void set_internal_details(std::string&& value);
  void set_internal_details(const char* value);
  void set_internal_details(const char* value, size_t size);
  std::string* mutable_internal_details();
  std::string* release_internal_details();
  void set_allocated_internal_details(std::string* internal_details);
  private:
  const std::string& _internal_internal_details() const;
  void _internal_set_internal_details(const std::string& value);
  std::string* _internal_mutable_internal_details();
  public:

  // .clarifai.api.status.StatusCode code = 1;
  void clear_code();
  ::clarifai::api::status::StatusCode code() const;
  void set_code(::clarifai::api::status::StatusCode value);
  private:
  ::clarifai::api::status::StatusCode _internal_code() const;
  void _internal_set_code(::clarifai::api::status::StatusCode value);
  public:

  // uint32 percent_completed = 5;
  void clear_percent_completed();
  ::PROTOBUF_NAMESPACE_ID::uint32 percent_completed() const;
  void set_percent_completed(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_percent_completed() const;
  void _internal_set_percent_completed(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // uint32 time_remaining = 6;
  void clear_time_remaining();
  ::PROTOBUF_NAMESPACE_ID::uint32 time_remaining() const;
  void set_time_remaining(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_time_remaining() const;
  void _internal_set_time_remaining(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:clarifai.api.status.Status)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> stack_trace_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr description_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr details_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr req_id_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr internal_details_;
  int code_;
  ::PROTOBUF_NAMESPACE_ID::uint32 percent_completed_;
  ::PROTOBUF_NAMESPACE_ID::uint32 time_remaining_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_proto_2fclarifai_2fapi_2fstatus_2fstatus_2eproto;
};
// -------------------------------------------------------------------

class BaseResponse PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:clarifai.api.status.BaseResponse) */ {
 public:
  inline BaseResponse() : BaseResponse(nullptr) {}
  virtual ~BaseResponse();

  BaseResponse(const BaseResponse& from);
  BaseResponse(BaseResponse&& from) noexcept
    : BaseResponse() {
    *this = ::std::move(from);
  }

  inline BaseResponse& operator=(const BaseResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline BaseResponse& operator=(BaseResponse&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const BaseResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const BaseResponse* internal_default_instance() {
    return reinterpret_cast<const BaseResponse*>(
               &_BaseResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(BaseResponse& a, BaseResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(BaseResponse* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(BaseResponse* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline BaseResponse* New() const final {
    return CreateMaybeMessage<BaseResponse>(nullptr);
  }

  BaseResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<BaseResponse>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const BaseResponse& from);
  void MergeFrom(const BaseResponse& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(BaseResponse* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "clarifai.api.status.BaseResponse";
  }
  protected:
  explicit BaseResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_proto_2fclarifai_2fapi_2fstatus_2fstatus_2eproto);
    return ::descriptor_table_proto_2fclarifai_2fapi_2fstatus_2fstatus_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kStatusFieldNumber = 1,
  };
  // .clarifai.api.status.Status status = 1;
  bool has_status() const;
  private:
  bool _internal_has_status() const;
  public:
  void clear_status();
  const ::clarifai::api::status::Status& status() const;
  ::clarifai::api::status::Status* release_status();
  ::clarifai::api::status::Status* mutable_status();
  void set_allocated_status(::clarifai::api::status::Status* status);
  private:
  const ::clarifai::api::status::Status& _internal_status() const;
  ::clarifai::api::status::Status* _internal_mutable_status();
  public:
  void unsafe_arena_set_allocated_status(
      ::clarifai::api::status::Status* status);
  ::clarifai::api::status::Status* unsafe_arena_release_status();

  // @@protoc_insertion_point(class_scope:clarifai.api.status.BaseResponse)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::clarifai::api::status::Status* status_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_proto_2fclarifai_2fapi_2fstatus_2fstatus_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Status

// .clarifai.api.status.StatusCode code = 1;
inline void Status::clear_code() {
  code_ = 0;
}
inline ::clarifai::api::status::StatusCode Status::_internal_code() const {
  return static_cast< ::clarifai::api::status::StatusCode >(code_);
}
inline ::clarifai::api::status::StatusCode Status::code() const {
  // @@protoc_insertion_point(field_get:clarifai.api.status.Status.code)
  return _internal_code();
}
inline void Status::_internal_set_code(::clarifai::api::status::StatusCode value) {
  
  code_ = value;
}
inline void Status::set_code(::clarifai::api::status::StatusCode value) {
  _internal_set_code(value);
  // @@protoc_insertion_point(field_set:clarifai.api.status.Status.code)
}

// string description = 2;
inline void Status::clear_description() {
  description_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& Status::description() const {
  // @@protoc_insertion_point(field_get:clarifai.api.status.Status.description)
  return _internal_description();
}
inline void Status::set_description(const std::string& value) {
  _internal_set_description(value);
  // @@protoc_insertion_point(field_set:clarifai.api.status.Status.description)
}
inline std::string* Status::mutable_description() {
  // @@protoc_insertion_point(field_mutable:clarifai.api.status.Status.description)
  return _internal_mutable_description();
}
inline const std::string& Status::_internal_description() const {
  return description_.Get();
}
inline void Status::_internal_set_description(const std::string& value) {
  
  description_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void Status::set_description(std::string&& value) {
  
  description_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:clarifai.api.status.Status.description)
}
inline void Status::set_description(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  description_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:clarifai.api.status.Status.description)
}
inline void Status::set_description(const char* value,
    size_t size) {
  
  description_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:clarifai.api.status.Status.description)
}
inline std::string* Status::_internal_mutable_description() {
  
  return description_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* Status::release_description() {
  // @@protoc_insertion_point(field_release:clarifai.api.status.Status.description)
  return description_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void Status::set_allocated_description(std::string* description) {
  if (description != nullptr) {
    
  } else {
    
  }
  description_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), description,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:clarifai.api.status.Status.description)
}

// string details = 3;
inline void Status::clear_details() {
  details_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& Status::details() const {
  // @@protoc_insertion_point(field_get:clarifai.api.status.Status.details)
  return _internal_details();
}
inline void Status::set_details(const std::string& value) {
  _internal_set_details(value);
  // @@protoc_insertion_point(field_set:clarifai.api.status.Status.details)
}
inline std::string* Status::mutable_details() {
  // @@protoc_insertion_point(field_mutable:clarifai.api.status.Status.details)
  return _internal_mutable_details();
}
inline const std::string& Status::_internal_details() const {
  return details_.Get();
}
inline void Status::_internal_set_details(const std::string& value) {
  
  details_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void Status::set_details(std::string&& value) {
  
  details_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:clarifai.api.status.Status.details)
}
inline void Status::set_details(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  details_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:clarifai.api.status.Status.details)
}
inline void Status::set_details(const char* value,
    size_t size) {
  
  details_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:clarifai.api.status.Status.details)
}
inline std::string* Status::_internal_mutable_details() {
  
  return details_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* Status::release_details() {
  // @@protoc_insertion_point(field_release:clarifai.api.status.Status.details)
  return details_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void Status::set_allocated_details(std::string* details) {
  if (details != nullptr) {
    
  } else {
    
  }
  details_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), details,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:clarifai.api.status.Status.details)
}

// repeated string stack_trace = 4 [(.clarifai.auth.util.cl_private_field) = true];
inline int Status::_internal_stack_trace_size() const {
  return stack_trace_.size();
}
inline int Status::stack_trace_size() const {
  return _internal_stack_trace_size();
}
inline void Status::clear_stack_trace() {
  stack_trace_.Clear();
}
inline std::string* Status::add_stack_trace() {
  // @@protoc_insertion_point(field_add_mutable:clarifai.api.status.Status.stack_trace)
  return _internal_add_stack_trace();
}
inline const std::string& Status::_internal_stack_trace(int index) const {
  return stack_trace_.Get(index);
}
inline const std::string& Status::stack_trace(int index) const {
  // @@protoc_insertion_point(field_get:clarifai.api.status.Status.stack_trace)
  return _internal_stack_trace(index);
}
inline std::string* Status::mutable_stack_trace(int index) {
  // @@protoc_insertion_point(field_mutable:clarifai.api.status.Status.stack_trace)
  return stack_trace_.Mutable(index);
}
inline void Status::set_stack_trace(int index, const std::string& value) {
  // @@protoc_insertion_point(field_set:clarifai.api.status.Status.stack_trace)
  stack_trace_.Mutable(index)->assign(value);
}
inline void Status::set_stack_trace(int index, std::string&& value) {
  // @@protoc_insertion_point(field_set:clarifai.api.status.Status.stack_trace)
  stack_trace_.Mutable(index)->assign(std::move(value));
}
inline void Status::set_stack_trace(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  stack_trace_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:clarifai.api.status.Status.stack_trace)
}
inline void Status::set_stack_trace(int index, const char* value, size_t size) {
  stack_trace_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:clarifai.api.status.Status.stack_trace)
}
inline std::string* Status::_internal_add_stack_trace() {
  return stack_trace_.Add();
}
inline void Status::add_stack_trace(const std::string& value) {
  stack_trace_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:clarifai.api.status.Status.stack_trace)
}
inline void Status::add_stack_trace(std::string&& value) {
  stack_trace_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:clarifai.api.status.Status.stack_trace)
}
inline void Status::add_stack_trace(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  stack_trace_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:clarifai.api.status.Status.stack_trace)
}
inline void Status::add_stack_trace(const char* value, size_t size) {
  stack_trace_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:clarifai.api.status.Status.stack_trace)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
Status::stack_trace() const {
  // @@protoc_insertion_point(field_list:clarifai.api.status.Status.stack_trace)
  return stack_trace_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
Status::mutable_stack_trace() {
  // @@protoc_insertion_point(field_mutable_list:clarifai.api.status.Status.stack_trace)
  return &stack_trace_;
}

// uint32 percent_completed = 5;
inline void Status::clear_percent_completed() {
  percent_completed_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Status::_internal_percent_completed() const {
  return percent_completed_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Status::percent_completed() const {
  // @@protoc_insertion_point(field_get:clarifai.api.status.Status.percent_completed)
  return _internal_percent_completed();
}
inline void Status::_internal_set_percent_completed(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  percent_completed_ = value;
}
inline void Status::set_percent_completed(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_percent_completed(value);
  // @@protoc_insertion_point(field_set:clarifai.api.status.Status.percent_completed)
}

// uint32 time_remaining = 6;
inline void Status::clear_time_remaining() {
  time_remaining_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Status::_internal_time_remaining() const {
  return time_remaining_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Status::time_remaining() const {
  // @@protoc_insertion_point(field_get:clarifai.api.status.Status.time_remaining)
  return _internal_time_remaining();
}
inline void Status::_internal_set_time_remaining(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  time_remaining_ = value;
}
inline void Status::set_time_remaining(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_time_remaining(value);
  // @@protoc_insertion_point(field_set:clarifai.api.status.Status.time_remaining)
}

// string req_id = 7;
inline void Status::clear_req_id() {
  req_id_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& Status::req_id() const {
  // @@protoc_insertion_point(field_get:clarifai.api.status.Status.req_id)
  return _internal_req_id();
}
inline void Status::set_req_id(const std::string& value) {
  _internal_set_req_id(value);
  // @@protoc_insertion_point(field_set:clarifai.api.status.Status.req_id)
}
inline std::string* Status::mutable_req_id() {
  // @@protoc_insertion_point(field_mutable:clarifai.api.status.Status.req_id)
  return _internal_mutable_req_id();
}
inline const std::string& Status::_internal_req_id() const {
  return req_id_.Get();
}
inline void Status::_internal_set_req_id(const std::string& value) {
  
  req_id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void Status::set_req_id(std::string&& value) {
  
  req_id_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:clarifai.api.status.Status.req_id)
}
inline void Status::set_req_id(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  req_id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:clarifai.api.status.Status.req_id)
}
inline void Status::set_req_id(const char* value,
    size_t size) {
  
  req_id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:clarifai.api.status.Status.req_id)
}
inline std::string* Status::_internal_mutable_req_id() {
  
  return req_id_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* Status::release_req_id() {
  // @@protoc_insertion_point(field_release:clarifai.api.status.Status.req_id)
  return req_id_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void Status::set_allocated_req_id(std::string* req_id) {
  if (req_id != nullptr) {
    
  } else {
    
  }
  req_id_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), req_id,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:clarifai.api.status.Status.req_id)
}

// string internal_details = 8 [(.clarifai.auth.util.cl_private_field) = true];
inline void Status::clear_internal_details() {
  internal_details_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& Status::internal_details() const {
  // @@protoc_insertion_point(field_get:clarifai.api.status.Status.internal_details)
  return _internal_internal_details();
}
inline void Status::set_internal_details(const std::string& value) {
  _internal_set_internal_details(value);
  // @@protoc_insertion_point(field_set:clarifai.api.status.Status.internal_details)
}
inline std::string* Status::mutable_internal_details() {
  // @@protoc_insertion_point(field_mutable:clarifai.api.status.Status.internal_details)
  return _internal_mutable_internal_details();
}
inline const std::string& Status::_internal_internal_details() const {
  return internal_details_.Get();
}
inline void Status::_internal_set_internal_details(const std::string& value) {
  
  internal_details_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void Status::set_internal_details(std::string&& value) {
  
  internal_details_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:clarifai.api.status.Status.internal_details)
}
inline void Status::set_internal_details(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  internal_details_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:clarifai.api.status.Status.internal_details)
}
inline void Status::set_internal_details(const char* value,
    size_t size) {
  
  internal_details_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:clarifai.api.status.Status.internal_details)
}
inline std::string* Status::_internal_mutable_internal_details() {
  
  return internal_details_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* Status::release_internal_details() {
  // @@protoc_insertion_point(field_release:clarifai.api.status.Status.internal_details)
  return internal_details_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void Status::set_allocated_internal_details(std::string* internal_details) {
  if (internal_details != nullptr) {
    
  } else {
    
  }
  internal_details_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), internal_details,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:clarifai.api.status.Status.internal_details)
}

// -------------------------------------------------------------------

// BaseResponse

// .clarifai.api.status.Status status = 1;
inline bool BaseResponse::_internal_has_status() const {
  return this != internal_default_instance() && status_ != nullptr;
}
inline bool BaseResponse::has_status() const {
  return _internal_has_status();
}
inline void BaseResponse::clear_status() {
  if (GetArena() == nullptr && status_ != nullptr) {
    delete status_;
  }
  status_ = nullptr;
}
inline const ::clarifai::api::status::Status& BaseResponse::_internal_status() const {
  const ::clarifai::api::status::Status* p = status_;
  return p != nullptr ? *p : *reinterpret_cast<const ::clarifai::api::status::Status*>(
      &::clarifai::api::status::_Status_default_instance_);
}
inline const ::clarifai::api::status::Status& BaseResponse::status() const {
  // @@protoc_insertion_point(field_get:clarifai.api.status.BaseResponse.status)
  return _internal_status();
}
inline void BaseResponse::unsafe_arena_set_allocated_status(
    ::clarifai::api::status::Status* status) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(status_);
  }
  status_ = status;
  if (status) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:clarifai.api.status.BaseResponse.status)
}
inline ::clarifai::api::status::Status* BaseResponse::release_status() {
  
  ::clarifai::api::status::Status* temp = status_;
  status_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::clarifai::api::status::Status* BaseResponse::unsafe_arena_release_status() {
  // @@protoc_insertion_point(field_release:clarifai.api.status.BaseResponse.status)
  
  ::clarifai::api::status::Status* temp = status_;
  status_ = nullptr;
  return temp;
}
inline ::clarifai::api::status::Status* BaseResponse::_internal_mutable_status() {
  
  if (status_ == nullptr) {
    auto* p = CreateMaybeMessage<::clarifai::api::status::Status>(GetArena());
    status_ = p;
  }
  return status_;
}
inline ::clarifai::api::status::Status* BaseResponse::mutable_status() {
  // @@protoc_insertion_point(field_mutable:clarifai.api.status.BaseResponse.status)
  return _internal_mutable_status();
}
inline void BaseResponse::set_allocated_status(::clarifai::api::status::Status* status) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete status_;
  }
  if (status) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(status);
    if (message_arena != submessage_arena) {
      status = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, status, submessage_arena);
    }
    
  } else {
    
  }
  status_ = status;
  // @@protoc_insertion_point(field_set_allocated:clarifai.api.status.BaseResponse.status)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace status
}  // namespace api
}  // namespace clarifai

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_proto_2fclarifai_2fapi_2fstatus_2fstatus_2eproto