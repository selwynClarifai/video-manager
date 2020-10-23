// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/utils/ndarray.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_proto_2futils_2fndarray_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_proto_2futils_2fndarray_2eproto

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
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_proto_2futils_2fndarray_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_proto_2futils_2fndarray_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2futils_2fndarray_2eproto;
class NDArray;
class NDArrayDefaultTypeInternal;
extern NDArrayDefaultTypeInternal _NDArray_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::NDArray* Arena::CreateMaybeMessage<::NDArray>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class NDArray PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:NDArray) */ {
 public:
  inline NDArray() : NDArray(nullptr) {}
  virtual ~NDArray();

  NDArray(const NDArray& from);
  NDArray(NDArray&& from) noexcept
    : NDArray() {
    *this = ::std::move(from);
  }

  inline NDArray& operator=(const NDArray& from) {
    CopyFrom(from);
    return *this;
  }
  inline NDArray& operator=(NDArray&& from) noexcept {
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
  static const NDArray& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const NDArray* internal_default_instance() {
    return reinterpret_cast<const NDArray*>(
               &_NDArray_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(NDArray& a, NDArray& b) {
    a.Swap(&b);
  }
  inline void Swap(NDArray* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(NDArray* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline NDArray* New() const final {
    return CreateMaybeMessage<NDArray>(nullptr);
  }

  NDArray* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<NDArray>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const NDArray& from);
  void MergeFrom(const NDArray& from);
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
  void InternalSwap(NDArray* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "NDArray";
  }
  protected:
  explicit NDArray(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_proto_2futils_2fndarray_2eproto);
    return ::descriptor_table_proto_2futils_2fndarray_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kShapeFieldNumber = 2,
    kDataFieldNumber = 1,
    kDtypeFieldNumber = 3,
  };
  // repeated uint32 shape = 2;
  int shape_size() const;
  private:
  int _internal_shape_size() const;
  public:
  void clear_shape();
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_shape(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >&
      _internal_shape() const;
  void _internal_add_shape(::PROTOBUF_NAMESPACE_ID::uint32 value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >*
      _internal_mutable_shape();
  public:
  ::PROTOBUF_NAMESPACE_ID::uint32 shape(int index) const;
  void set_shape(int index, ::PROTOBUF_NAMESPACE_ID::uint32 value);
  void add_shape(::PROTOBUF_NAMESPACE_ID::uint32 value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >&
      shape() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >*
      mutable_shape();

  // bytes data = 1;
  void clear_data();
  const std::string& data() const;
  void set_data(const std::string& value);
  void set_data(std::string&& value);
  void set_data(const char* value);
  void set_data(const void* value, size_t size);
  std::string* mutable_data();
  std::string* release_data();
  void set_allocated_data(std::string* data);
  private:
  const std::string& _internal_data() const;
  void _internal_set_data(const std::string& value);
  std::string* _internal_mutable_data();
  public:

  // string dtype = 3;
  void clear_dtype();
  const std::string& dtype() const;
  void set_dtype(const std::string& value);
  void set_dtype(std::string&& value);
  void set_dtype(const char* value);
  void set_dtype(const char* value, size_t size);
  std::string* mutable_dtype();
  std::string* release_dtype();
  void set_allocated_dtype(std::string* dtype);
  private:
  const std::string& _internal_dtype() const;
  void _internal_set_dtype(const std::string& value);
  std::string* _internal_mutable_dtype();
  public:

  // @@protoc_insertion_point(class_scope:NDArray)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 > shape_;
  mutable std::atomic<int> _shape_cached_byte_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr data_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr dtype_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_proto_2futils_2fndarray_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// NDArray

// bytes data = 1;
inline void NDArray::clear_data() {
  data_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& NDArray::data() const {
  // @@protoc_insertion_point(field_get:NDArray.data)
  return _internal_data();
}
inline void NDArray::set_data(const std::string& value) {
  _internal_set_data(value);
  // @@protoc_insertion_point(field_set:NDArray.data)
}
inline std::string* NDArray::mutable_data() {
  // @@protoc_insertion_point(field_mutable:NDArray.data)
  return _internal_mutable_data();
}
inline const std::string& NDArray::_internal_data() const {
  return data_.Get();
}
inline void NDArray::_internal_set_data(const std::string& value) {
  
  data_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void NDArray::set_data(std::string&& value) {
  
  data_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:NDArray.data)
}
inline void NDArray::set_data(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  data_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:NDArray.data)
}
inline void NDArray::set_data(const void* value,
    size_t size) {
  
  data_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:NDArray.data)
}
inline std::string* NDArray::_internal_mutable_data() {
  
  return data_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* NDArray::release_data() {
  // @@protoc_insertion_point(field_release:NDArray.data)
  return data_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void NDArray::set_allocated_data(std::string* data) {
  if (data != nullptr) {
    
  } else {
    
  }
  data_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), data,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:NDArray.data)
}

// repeated uint32 shape = 2;
inline int NDArray::_internal_shape_size() const {
  return shape_.size();
}
inline int NDArray::shape_size() const {
  return _internal_shape_size();
}
inline void NDArray::clear_shape() {
  shape_.Clear();
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 NDArray::_internal_shape(int index) const {
  return shape_.Get(index);
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 NDArray::shape(int index) const {
  // @@protoc_insertion_point(field_get:NDArray.shape)
  return _internal_shape(index);
}
inline void NDArray::set_shape(int index, ::PROTOBUF_NAMESPACE_ID::uint32 value) {
  shape_.Set(index, value);
  // @@protoc_insertion_point(field_set:NDArray.shape)
}
inline void NDArray::_internal_add_shape(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  shape_.Add(value);
}
inline void NDArray::add_shape(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_add_shape(value);
  // @@protoc_insertion_point(field_add:NDArray.shape)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >&
NDArray::_internal_shape() const {
  return shape_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >&
NDArray::shape() const {
  // @@protoc_insertion_point(field_list:NDArray.shape)
  return _internal_shape();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >*
NDArray::_internal_mutable_shape() {
  return &shape_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >*
NDArray::mutable_shape() {
  // @@protoc_insertion_point(field_mutable_list:NDArray.shape)
  return _internal_mutable_shape();
}

// string dtype = 3;
inline void NDArray::clear_dtype() {
  dtype_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& NDArray::dtype() const {
  // @@protoc_insertion_point(field_get:NDArray.dtype)
  return _internal_dtype();
}
inline void NDArray::set_dtype(const std::string& value) {
  _internal_set_dtype(value);
  // @@protoc_insertion_point(field_set:NDArray.dtype)
}
inline std::string* NDArray::mutable_dtype() {
  // @@protoc_insertion_point(field_mutable:NDArray.dtype)
  return _internal_mutable_dtype();
}
inline const std::string& NDArray::_internal_dtype() const {
  return dtype_.Get();
}
inline void NDArray::_internal_set_dtype(const std::string& value) {
  
  dtype_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void NDArray::set_dtype(std::string&& value) {
  
  dtype_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:NDArray.dtype)
}
inline void NDArray::set_dtype(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  dtype_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:NDArray.dtype)
}
inline void NDArray::set_dtype(const char* value,
    size_t size) {
  
  dtype_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:NDArray.dtype)
}
inline std::string* NDArray::_internal_mutable_dtype() {
  
  return dtype_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* NDArray::release_dtype() {
  // @@protoc_insertion_point(field_release:NDArray.dtype)
  return dtype_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void NDArray::set_allocated_dtype(std::string* dtype) {
  if (dtype != nullptr) {
    
  } else {
    
  }
  dtype_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), dtype,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:NDArray.dtype)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_proto_2futils_2fndarray_2eproto