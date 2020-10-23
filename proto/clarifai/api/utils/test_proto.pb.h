// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/clarifai/api/utils/test_proto.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto

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
#include "proto/clarifai/api/utils/extensions.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto;
namespace clarifai {
namespace api {
namespace utils {
class TestProto;
class TestProtoDefaultTypeInternal;
extern TestProtoDefaultTypeInternal _TestProto_default_instance_;
class TestProto2;
class TestProto2DefaultTypeInternal;
extern TestProto2DefaultTypeInternal _TestProto2_default_instance_;
}  // namespace utils
}  // namespace api
}  // namespace clarifai
PROTOBUF_NAMESPACE_OPEN
template<> ::clarifai::api::utils::TestProto* Arena::CreateMaybeMessage<::clarifai::api::utils::TestProto>(Arena*);
template<> ::clarifai::api::utils::TestProto2* Arena::CreateMaybeMessage<::clarifai::api::utils::TestProto2>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace clarifai {
namespace api {
namespace utils {

// ===================================================================

class TestProto PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:clarifai.api.utils.TestProto) */ {
 public:
  inline TestProto() : TestProto(nullptr) {}
  virtual ~TestProto();

  TestProto(const TestProto& from);
  TestProto(TestProto&& from) noexcept
    : TestProto() {
    *this = ::std::move(from);
  }

  inline TestProto& operator=(const TestProto& from) {
    CopyFrom(from);
    return *this;
  }
  inline TestProto& operator=(TestProto&& from) noexcept {
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
  static const TestProto& default_instance();

  enum OneOfFieldCase {
    kStringOneof = 5,
    kBoolOneof = 6,
    kMessageOneof = 7,
    ONE_OF_FIELD_NOT_SET = 0,
  };

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const TestProto* internal_default_instance() {
    return reinterpret_cast<const TestProto*>(
               &_TestProto_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(TestProto& a, TestProto& b) {
    a.Swap(&b);
  }
  inline void Swap(TestProto* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(TestProto* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline TestProto* New() const final {
    return CreateMaybeMessage<TestProto>(nullptr);
  }

  TestProto* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<TestProto>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const TestProto& from);
  void MergeFrom(const TestProto& from);
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
  void InternalSwap(TestProto* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "clarifai.api.utils.TestProto";
  }
  protected:
  explicit TestProto(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto);
    return ::descriptor_table_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kIdFieldNumber = 1,
    kMessageFieldNumber = 2,
    kImageBytesFieldNumber = 4,
    kValueFieldNumber = 3,
    kStringOneofFieldNumber = 5,
    kBoolOneofFieldNumber = 6,
    kMessageOneofFieldNumber = 7,
  };
  // string id = 1;
  void clear_id();
  const std::string& id() const;
  void set_id(const std::string& value);
  void set_id(std::string&& value);
  void set_id(const char* value);
  void set_id(const char* value, size_t size);
  std::string* mutable_id();
  std::string* release_id();
  void set_allocated_id(std::string* id);
  private:
  const std::string& _internal_id() const;
  void _internal_set_id(const std::string& value);
  std::string* _internal_mutable_id();
  public:

  // string message = 2 [(.clarifai.api.utils.cl_show_if_empty) = true, (.clarifai.api.utils.cl_moretags) = "protos are cool"];
  void clear_message();
  const std::string& message() const;
  void set_message(const std::string& value);
  void set_message(std::string&& value);
  void set_message(const char* value);
  void set_message(const char* value, size_t size);
  std::string* mutable_message();
  std::string* release_message();
  void set_allocated_message(std::string* message);
  private:
  const std::string& _internal_message() const;
  void _internal_set_message(const std::string& value);
  std::string* _internal_mutable_message();
  public:

  // bytes image_bytes = 4;
  void clear_image_bytes();
  const std::string& image_bytes() const;
  void set_image_bytes(const std::string& value);
  void set_image_bytes(std::string&& value);
  void set_image_bytes(const char* value);
  void set_image_bytes(const void* value, size_t size);
  std::string* mutable_image_bytes();
  std::string* release_image_bytes();
  void set_allocated_image_bytes(std::string* image_bytes);
  private:
  const std::string& _internal_image_bytes() const;
  void _internal_set_image_bytes(const std::string& value);
  std::string* _internal_mutable_image_bytes();
  public:

  // double value = 3 [(.clarifai.api.utils.cl_default_float) = 1];
  void clear_value();
  double value() const;
  void set_value(double value);
  private:
  double _internal_value() const;
  void _internal_set_value(double value);
  public:

  // string string_oneof = 5;
  private:
  bool _internal_has_string_oneof() const;
  public:
  void clear_string_oneof();
  const std::string& string_oneof() const;
  void set_string_oneof(const std::string& value);
  void set_string_oneof(std::string&& value);
  void set_string_oneof(const char* value);
  void set_string_oneof(const char* value, size_t size);
  std::string* mutable_string_oneof();
  std::string* release_string_oneof();
  void set_allocated_string_oneof(std::string* string_oneof);
  private:
  const std::string& _internal_string_oneof() const;
  void _internal_set_string_oneof(const std::string& value);
  std::string* _internal_mutable_string_oneof();
  public:

  // bool bool_oneof = 6;
  private:
  bool _internal_has_bool_oneof() const;
  public:
  void clear_bool_oneof();
  bool bool_oneof() const;
  void set_bool_oneof(bool value);
  private:
  bool _internal_bool_oneof() const;
  void _internal_set_bool_oneof(bool value);
  public:

  // .clarifai.api.utils.TestProto2 message_oneof = 7;
  bool has_message_oneof() const;
  private:
  bool _internal_has_message_oneof() const;
  public:
  void clear_message_oneof();
  const ::clarifai::api::utils::TestProto2& message_oneof() const;
  ::clarifai::api::utils::TestProto2* release_message_oneof();
  ::clarifai::api::utils::TestProto2* mutable_message_oneof();
  void set_allocated_message_oneof(::clarifai::api::utils::TestProto2* message_oneof);
  private:
  const ::clarifai::api::utils::TestProto2& _internal_message_oneof() const;
  ::clarifai::api::utils::TestProto2* _internal_mutable_message_oneof();
  public:
  void unsafe_arena_set_allocated_message_oneof(
      ::clarifai::api::utils::TestProto2* message_oneof);
  ::clarifai::api::utils::TestProto2* unsafe_arena_release_message_oneof();

  void clear_one_of_field();
  OneOfFieldCase one_of_field_case() const;
  // @@protoc_insertion_point(class_scope:clarifai.api.utils.TestProto)
 private:
  class _Internal;
  void set_has_string_oneof();
  void set_has_bool_oneof();
  void set_has_message_oneof();

  inline bool has_one_of_field() const;
  inline void clear_has_one_of_field();

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr id_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr message_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr image_bytes_;
  double value_;
  union OneOfFieldUnion {
    OneOfFieldUnion() {}
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr string_oneof_;
    bool bool_oneof_;
    ::clarifai::api::utils::TestProto2* message_oneof_;
  } one_of_field_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::uint32 _oneof_case_[1];

  friend struct ::TableStruct_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto;
};
// -------------------------------------------------------------------

class TestProto2 PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:clarifai.api.utils.TestProto2) */ {
 public:
  inline TestProto2() : TestProto2(nullptr) {}
  virtual ~TestProto2();

  TestProto2(const TestProto2& from);
  TestProto2(TestProto2&& from) noexcept
    : TestProto2() {
    *this = ::std::move(from);
  }

  inline TestProto2& operator=(const TestProto2& from) {
    CopyFrom(from);
    return *this;
  }
  inline TestProto2& operator=(TestProto2&& from) noexcept {
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
  static const TestProto2& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const TestProto2* internal_default_instance() {
    return reinterpret_cast<const TestProto2*>(
               &_TestProto2_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(TestProto2& a, TestProto2& b) {
    a.Swap(&b);
  }
  inline void Swap(TestProto2* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(TestProto2* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline TestProto2* New() const final {
    return CreateMaybeMessage<TestProto2>(nullptr);
  }

  TestProto2* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<TestProto2>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const TestProto2& from);
  void MergeFrom(const TestProto2& from);
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
  void InternalSwap(TestProto2* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "clarifai.api.utils.TestProto2";
  }
  protected:
  explicit TestProto2(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto);
    return ::descriptor_table_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kIdFieldNumber = 1,
    kFlipFieldNumber = 2,
  };
  // string id = 1;
  void clear_id();
  const std::string& id() const;
  void set_id(const std::string& value);
  void set_id(std::string&& value);
  void set_id(const char* value);
  void set_id(const char* value, size_t size);
  std::string* mutable_id();
  std::string* release_id();
  void set_allocated_id(std::string* id);
  private:
  const std::string& _internal_id() const;
  void _internal_set_id(const std::string& value);
  std::string* _internal_mutable_id();
  public:

  // bool flip = 2;
  void clear_flip();
  bool flip() const;
  void set_flip(bool value);
  private:
  bool _internal_flip() const;
  void _internal_set_flip(bool value);
  public:

  // @@protoc_insertion_point(class_scope:clarifai.api.utils.TestProto2)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr id_;
  bool flip_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// TestProto

// string id = 1;
inline void TestProto::clear_id() {
  id_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& TestProto::id() const {
  // @@protoc_insertion_point(field_get:clarifai.api.utils.TestProto.id)
  return _internal_id();
}
inline void TestProto::set_id(const std::string& value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:clarifai.api.utils.TestProto.id)
}
inline std::string* TestProto::mutable_id() {
  // @@protoc_insertion_point(field_mutable:clarifai.api.utils.TestProto.id)
  return _internal_mutable_id();
}
inline const std::string& TestProto::_internal_id() const {
  return id_.Get();
}
inline void TestProto::_internal_set_id(const std::string& value) {
  
  id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void TestProto::set_id(std::string&& value) {
  
  id_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:clarifai.api.utils.TestProto.id)
}
inline void TestProto::set_id(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:clarifai.api.utils.TestProto.id)
}
inline void TestProto::set_id(const char* value,
    size_t size) {
  
  id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:clarifai.api.utils.TestProto.id)
}
inline std::string* TestProto::_internal_mutable_id() {
  
  return id_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* TestProto::release_id() {
  // @@protoc_insertion_point(field_release:clarifai.api.utils.TestProto.id)
  return id_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void TestProto::set_allocated_id(std::string* id) {
  if (id != nullptr) {
    
  } else {
    
  }
  id_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), id,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:clarifai.api.utils.TestProto.id)
}

// string message = 2 [(.clarifai.api.utils.cl_show_if_empty) = true, (.clarifai.api.utils.cl_moretags) = "protos are cool"];
inline void TestProto::clear_message() {
  message_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& TestProto::message() const {
  // @@protoc_insertion_point(field_get:clarifai.api.utils.TestProto.message)
  return _internal_message();
}
inline void TestProto::set_message(const std::string& value) {
  _internal_set_message(value);
  // @@protoc_insertion_point(field_set:clarifai.api.utils.TestProto.message)
}
inline std::string* TestProto::mutable_message() {
  // @@protoc_insertion_point(field_mutable:clarifai.api.utils.TestProto.message)
  return _internal_mutable_message();
}
inline const std::string& TestProto::_internal_message() const {
  return message_.Get();
}
inline void TestProto::_internal_set_message(const std::string& value) {
  
  message_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void TestProto::set_message(std::string&& value) {
  
  message_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:clarifai.api.utils.TestProto.message)
}
inline void TestProto::set_message(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  message_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:clarifai.api.utils.TestProto.message)
}
inline void TestProto::set_message(const char* value,
    size_t size) {
  
  message_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:clarifai.api.utils.TestProto.message)
}
inline std::string* TestProto::_internal_mutable_message() {
  
  return message_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* TestProto::release_message() {
  // @@protoc_insertion_point(field_release:clarifai.api.utils.TestProto.message)
  return message_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void TestProto::set_allocated_message(std::string* message) {
  if (message != nullptr) {
    
  } else {
    
  }
  message_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), message,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:clarifai.api.utils.TestProto.message)
}

// double value = 3 [(.clarifai.api.utils.cl_default_float) = 1];
inline void TestProto::clear_value() {
  value_ = 0;
}
inline double TestProto::_internal_value() const {
  return value_;
}
inline double TestProto::value() const {
  // @@protoc_insertion_point(field_get:clarifai.api.utils.TestProto.value)
  return _internal_value();
}
inline void TestProto::_internal_set_value(double value) {
  
  value_ = value;
}
inline void TestProto::set_value(double value) {
  _internal_set_value(value);
  // @@protoc_insertion_point(field_set:clarifai.api.utils.TestProto.value)
}

// bytes image_bytes = 4;
inline void TestProto::clear_image_bytes() {
  image_bytes_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& TestProto::image_bytes() const {
  // @@protoc_insertion_point(field_get:clarifai.api.utils.TestProto.image_bytes)
  return _internal_image_bytes();
}
inline void TestProto::set_image_bytes(const std::string& value) {
  _internal_set_image_bytes(value);
  // @@protoc_insertion_point(field_set:clarifai.api.utils.TestProto.image_bytes)
}
inline std::string* TestProto::mutable_image_bytes() {
  // @@protoc_insertion_point(field_mutable:clarifai.api.utils.TestProto.image_bytes)
  return _internal_mutable_image_bytes();
}
inline const std::string& TestProto::_internal_image_bytes() const {
  return image_bytes_.Get();
}
inline void TestProto::_internal_set_image_bytes(const std::string& value) {
  
  image_bytes_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void TestProto::set_image_bytes(std::string&& value) {
  
  image_bytes_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:clarifai.api.utils.TestProto.image_bytes)
}
inline void TestProto::set_image_bytes(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  image_bytes_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:clarifai.api.utils.TestProto.image_bytes)
}
inline void TestProto::set_image_bytes(const void* value,
    size_t size) {
  
  image_bytes_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:clarifai.api.utils.TestProto.image_bytes)
}
inline std::string* TestProto::_internal_mutable_image_bytes() {
  
  return image_bytes_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* TestProto::release_image_bytes() {
  // @@protoc_insertion_point(field_release:clarifai.api.utils.TestProto.image_bytes)
  return image_bytes_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void TestProto::set_allocated_image_bytes(std::string* image_bytes) {
  if (image_bytes != nullptr) {
    
  } else {
    
  }
  image_bytes_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), image_bytes,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:clarifai.api.utils.TestProto.image_bytes)
}

// string string_oneof = 5;
inline bool TestProto::_internal_has_string_oneof() const {
  return one_of_field_case() == kStringOneof;
}
inline void TestProto::set_has_string_oneof() {
  _oneof_case_[0] = kStringOneof;
}
inline void TestProto::clear_string_oneof() {
  if (_internal_has_string_oneof()) {
    one_of_field_.string_oneof_.Destroy(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
    clear_has_one_of_field();
  }
}
inline const std::string& TestProto::string_oneof() const {
  // @@protoc_insertion_point(field_get:clarifai.api.utils.TestProto.string_oneof)
  return _internal_string_oneof();
}
inline void TestProto::set_string_oneof(const std::string& value) {
  _internal_set_string_oneof(value);
  // @@protoc_insertion_point(field_set:clarifai.api.utils.TestProto.string_oneof)
}
inline std::string* TestProto::mutable_string_oneof() {
  // @@protoc_insertion_point(field_mutable:clarifai.api.utils.TestProto.string_oneof)
  return _internal_mutable_string_oneof();
}
inline const std::string& TestProto::_internal_string_oneof() const {
  if (_internal_has_string_oneof()) {
    return one_of_field_.string_oneof_.Get();
  }
  return *&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited();
}
inline void TestProto::_internal_set_string_oneof(const std::string& value) {
  if (!_internal_has_string_oneof()) {
    clear_one_of_field();
    set_has_string_oneof();
    one_of_field_.string_oneof_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  one_of_field_.string_oneof_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void TestProto::set_string_oneof(std::string&& value) {
  // @@protoc_insertion_point(field_set:clarifai.api.utils.TestProto.string_oneof)
  if (!_internal_has_string_oneof()) {
    clear_one_of_field();
    set_has_string_oneof();
    one_of_field_.string_oneof_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  one_of_field_.string_oneof_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:clarifai.api.utils.TestProto.string_oneof)
}
inline void TestProto::set_string_oneof(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  if (!_internal_has_string_oneof()) {
    clear_one_of_field();
    set_has_string_oneof();
    one_of_field_.string_oneof_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  one_of_field_.string_oneof_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:clarifai.api.utils.TestProto.string_oneof)
}
inline void TestProto::set_string_oneof(const char* value,
                             size_t size) {
  if (!_internal_has_string_oneof()) {
    clear_one_of_field();
    set_has_string_oneof();
    one_of_field_.string_oneof_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  one_of_field_.string_oneof_.Set(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size),
      GetArena());
  // @@protoc_insertion_point(field_set_pointer:clarifai.api.utils.TestProto.string_oneof)
}
inline std::string* TestProto::_internal_mutable_string_oneof() {
  if (!_internal_has_string_oneof()) {
    clear_one_of_field();
    set_has_string_oneof();
    one_of_field_.string_oneof_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  return one_of_field_.string_oneof_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* TestProto::release_string_oneof() {
  // @@protoc_insertion_point(field_release:clarifai.api.utils.TestProto.string_oneof)
  if (_internal_has_string_oneof()) {
    clear_has_one_of_field();
    return one_of_field_.string_oneof_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  } else {
    return nullptr;
  }
}
inline void TestProto::set_allocated_string_oneof(std::string* string_oneof) {
  if (has_one_of_field()) {
    clear_one_of_field();
  }
  if (string_oneof != nullptr) {
    set_has_string_oneof();
    one_of_field_.string_oneof_.UnsafeSetDefault(string_oneof);
    ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena();
    if (arena != nullptr) {
      arena->Own(string_oneof);
    }
  }
  // @@protoc_insertion_point(field_set_allocated:clarifai.api.utils.TestProto.string_oneof)
}

// bool bool_oneof = 6;
inline bool TestProto::_internal_has_bool_oneof() const {
  return one_of_field_case() == kBoolOneof;
}
inline void TestProto::set_has_bool_oneof() {
  _oneof_case_[0] = kBoolOneof;
}
inline void TestProto::clear_bool_oneof() {
  if (_internal_has_bool_oneof()) {
    one_of_field_.bool_oneof_ = false;
    clear_has_one_of_field();
  }
}
inline bool TestProto::_internal_bool_oneof() const {
  if (_internal_has_bool_oneof()) {
    return one_of_field_.bool_oneof_;
  }
  return false;
}
inline void TestProto::_internal_set_bool_oneof(bool value) {
  if (!_internal_has_bool_oneof()) {
    clear_one_of_field();
    set_has_bool_oneof();
  }
  one_of_field_.bool_oneof_ = value;
}
inline bool TestProto::bool_oneof() const {
  // @@protoc_insertion_point(field_get:clarifai.api.utils.TestProto.bool_oneof)
  return _internal_bool_oneof();
}
inline void TestProto::set_bool_oneof(bool value) {
  _internal_set_bool_oneof(value);
  // @@protoc_insertion_point(field_set:clarifai.api.utils.TestProto.bool_oneof)
}

// .clarifai.api.utils.TestProto2 message_oneof = 7;
inline bool TestProto::_internal_has_message_oneof() const {
  return one_of_field_case() == kMessageOneof;
}
inline bool TestProto::has_message_oneof() const {
  return _internal_has_message_oneof();
}
inline void TestProto::set_has_message_oneof() {
  _oneof_case_[0] = kMessageOneof;
}
inline void TestProto::clear_message_oneof() {
  if (_internal_has_message_oneof()) {
    if (GetArena() == nullptr) {
      delete one_of_field_.message_oneof_;
    }
    clear_has_one_of_field();
  }
}
inline ::clarifai::api::utils::TestProto2* TestProto::release_message_oneof() {
  // @@protoc_insertion_point(field_release:clarifai.api.utils.TestProto.message_oneof)
  if (_internal_has_message_oneof()) {
    clear_has_one_of_field();
      ::clarifai::api::utils::TestProto2* temp = one_of_field_.message_oneof_;
    if (GetArena() != nullptr) {
      temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
    }
    one_of_field_.message_oneof_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline const ::clarifai::api::utils::TestProto2& TestProto::_internal_message_oneof() const {
  return _internal_has_message_oneof()
      ? *one_of_field_.message_oneof_
      : *reinterpret_cast< ::clarifai::api::utils::TestProto2*>(&::clarifai::api::utils::_TestProto2_default_instance_);
}
inline const ::clarifai::api::utils::TestProto2& TestProto::message_oneof() const {
  // @@protoc_insertion_point(field_get:clarifai.api.utils.TestProto.message_oneof)
  return _internal_message_oneof();
}
inline ::clarifai::api::utils::TestProto2* TestProto::unsafe_arena_release_message_oneof() {
  // @@protoc_insertion_point(field_unsafe_arena_release:clarifai.api.utils.TestProto.message_oneof)
  if (_internal_has_message_oneof()) {
    clear_has_one_of_field();
    ::clarifai::api::utils::TestProto2* temp = one_of_field_.message_oneof_;
    one_of_field_.message_oneof_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline void TestProto::unsafe_arena_set_allocated_message_oneof(::clarifai::api::utils::TestProto2* message_oneof) {
  clear_one_of_field();
  if (message_oneof) {
    set_has_message_oneof();
    one_of_field_.message_oneof_ = message_oneof;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:clarifai.api.utils.TestProto.message_oneof)
}
inline ::clarifai::api::utils::TestProto2* TestProto::_internal_mutable_message_oneof() {
  if (!_internal_has_message_oneof()) {
    clear_one_of_field();
    set_has_message_oneof();
    one_of_field_.message_oneof_ = CreateMaybeMessage< ::clarifai::api::utils::TestProto2 >(GetArena());
  }
  return one_of_field_.message_oneof_;
}
inline ::clarifai::api::utils::TestProto2* TestProto::mutable_message_oneof() {
  // @@protoc_insertion_point(field_mutable:clarifai.api.utils.TestProto.message_oneof)
  return _internal_mutable_message_oneof();
}

inline bool TestProto::has_one_of_field() const {
  return one_of_field_case() != ONE_OF_FIELD_NOT_SET;
}
inline void TestProto::clear_has_one_of_field() {
  _oneof_case_[0] = ONE_OF_FIELD_NOT_SET;
}
inline TestProto::OneOfFieldCase TestProto::one_of_field_case() const {
  return TestProto::OneOfFieldCase(_oneof_case_[0]);
}
// -------------------------------------------------------------------

// TestProto2

// string id = 1;
inline void TestProto2::clear_id() {
  id_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& TestProto2::id() const {
  // @@protoc_insertion_point(field_get:clarifai.api.utils.TestProto2.id)
  return _internal_id();
}
inline void TestProto2::set_id(const std::string& value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:clarifai.api.utils.TestProto2.id)
}
inline std::string* TestProto2::mutable_id() {
  // @@protoc_insertion_point(field_mutable:clarifai.api.utils.TestProto2.id)
  return _internal_mutable_id();
}
inline const std::string& TestProto2::_internal_id() const {
  return id_.Get();
}
inline void TestProto2::_internal_set_id(const std::string& value) {
  
  id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void TestProto2::set_id(std::string&& value) {
  
  id_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:clarifai.api.utils.TestProto2.id)
}
inline void TestProto2::set_id(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:clarifai.api.utils.TestProto2.id)
}
inline void TestProto2::set_id(const char* value,
    size_t size) {
  
  id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:clarifai.api.utils.TestProto2.id)
}
inline std::string* TestProto2::_internal_mutable_id() {
  
  return id_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* TestProto2::release_id() {
  // @@protoc_insertion_point(field_release:clarifai.api.utils.TestProto2.id)
  return id_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void TestProto2::set_allocated_id(std::string* id) {
  if (id != nullptr) {
    
  } else {
    
  }
  id_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), id,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:clarifai.api.utils.TestProto2.id)
}

// bool flip = 2;
inline void TestProto2::clear_flip() {
  flip_ = false;
}
inline bool TestProto2::_internal_flip() const {
  return flip_;
}
inline bool TestProto2::flip() const {
  // @@protoc_insertion_point(field_get:clarifai.api.utils.TestProto2.flip)
  return _internal_flip();
}
inline void TestProto2::_internal_set_flip(bool value) {
  
  flip_ = value;
}
inline void TestProto2::set_flip(bool value) {
  _internal_set_flip(value);
  // @@protoc_insertion_point(field_set:clarifai.api.utils.TestProto2.flip)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace utils
}  // namespace api
}  // namespace clarifai

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_proto_2fclarifai_2fapi_2futils_2ftest_5fproto_2eproto
