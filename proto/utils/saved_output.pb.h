// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/utils/saved_output.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_proto_2futils_2fsaved_5foutput_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_proto_2futils_2fsaved_5foutput_2eproto

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
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "proto/utils/ndarray.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_proto_2futils_2fsaved_5foutput_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_proto_2futils_2fsaved_5foutput_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2futils_2fsaved_5foutput_2eproto;
class SavedOutput;
class SavedOutputDefaultTypeInternal;
extern SavedOutputDefaultTypeInternal _SavedOutput_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::SavedOutput* Arena::CreateMaybeMessage<::SavedOutput>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

enum DataLayout : int {
  CWHN = 0,
  NHWC = 1,
  NCHW = 2,
  DataLayout_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  DataLayout_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool DataLayout_IsValid(int value);
constexpr DataLayout DataLayout_MIN = CWHN;
constexpr DataLayout DataLayout_MAX = NCHW;
constexpr int DataLayout_ARRAYSIZE = DataLayout_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* DataLayout_descriptor();
template<typename T>
inline const std::string& DataLayout_Name(T enum_t_value) {
  static_assert(::std::is_same<T, DataLayout>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function DataLayout_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    DataLayout_descriptor(), enum_t_value);
}
inline bool DataLayout_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, DataLayout* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<DataLayout>(
    DataLayout_descriptor(), name, value);
}
// ===================================================================

class SavedOutput PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:SavedOutput) */ {
 public:
  inline SavedOutput() : SavedOutput(nullptr) {}
  virtual ~SavedOutput();

  SavedOutput(const SavedOutput& from);
  SavedOutput(SavedOutput&& from) noexcept
    : SavedOutput() {
    *this = ::std::move(from);
  }

  inline SavedOutput& operator=(const SavedOutput& from) {
    CopyFrom(from);
    return *this;
  }
  inline SavedOutput& operator=(SavedOutput&& from) noexcept {
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
  static const SavedOutput& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SavedOutput* internal_default_instance() {
    return reinterpret_cast<const SavedOutput*>(
               &_SavedOutput_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(SavedOutput& a, SavedOutput& b) {
    a.Swap(&b);
  }
  inline void Swap(SavedOutput* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SavedOutput* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SavedOutput* New() const final {
    return CreateMaybeMessage<SavedOutput>(nullptr);
  }

  SavedOutput* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SavedOutput>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SavedOutput& from);
  void MergeFrom(const SavedOutput& from);
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
  void InternalSwap(SavedOutput* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "SavedOutput";
  }
  protected:
  explicit SavedOutput(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_proto_2futils_2fsaved_5foutput_2eproto);
    return ::descriptor_table_proto_2futils_2fsaved_5foutput_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kLayerNameFieldNumber = 2,
    kArrayFieldNumber = 4,
    kDataLayoutFieldNumber = 5,
  };
  // string layer_name = 2;
  void clear_layer_name();
  const std::string& layer_name() const;
  void set_layer_name(const std::string& value);
  void set_layer_name(std::string&& value);
  void set_layer_name(const char* value);
  void set_layer_name(const char* value, size_t size);
  std::string* mutable_layer_name();
  std::string* release_layer_name();
  void set_allocated_layer_name(std::string* layer_name);
  private:
  const std::string& _internal_layer_name() const;
  void _internal_set_layer_name(const std::string& value);
  std::string* _internal_mutable_layer_name();
  public:

  // .NDArray array = 4;
  bool has_array() const;
  private:
  bool _internal_has_array() const;
  public:
  void clear_array();
  const ::NDArray& array() const;
  ::NDArray* release_array();
  ::NDArray* mutable_array();
  void set_allocated_array(::NDArray* array);
  private:
  const ::NDArray& _internal_array() const;
  ::NDArray* _internal_mutable_array();
  public:
  void unsafe_arena_set_allocated_array(
      ::NDArray* array);
  ::NDArray* unsafe_arena_release_array();

  // .DataLayout data_layout = 5;
  void clear_data_layout();
  ::DataLayout data_layout() const;
  void set_data_layout(::DataLayout value);
  private:
  ::DataLayout _internal_data_layout() const;
  void _internal_set_data_layout(::DataLayout value);
  public:

  // @@protoc_insertion_point(class_scope:SavedOutput)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr layer_name_;
  ::NDArray* array_;
  int data_layout_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_proto_2futils_2fsaved_5foutput_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SavedOutput

// .NDArray array = 4;
inline bool SavedOutput::_internal_has_array() const {
  return this != internal_default_instance() && array_ != nullptr;
}
inline bool SavedOutput::has_array() const {
  return _internal_has_array();
}
inline const ::NDArray& SavedOutput::_internal_array() const {
  const ::NDArray* p = array_;
  return p != nullptr ? *p : *reinterpret_cast<const ::NDArray*>(
      &::_NDArray_default_instance_);
}
inline const ::NDArray& SavedOutput::array() const {
  // @@protoc_insertion_point(field_get:SavedOutput.array)
  return _internal_array();
}
inline void SavedOutput::unsafe_arena_set_allocated_array(
    ::NDArray* array) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(array_);
  }
  array_ = array;
  if (array) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:SavedOutput.array)
}
inline ::NDArray* SavedOutput::release_array() {
  
  ::NDArray* temp = array_;
  array_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::NDArray* SavedOutput::unsafe_arena_release_array() {
  // @@protoc_insertion_point(field_release:SavedOutput.array)
  
  ::NDArray* temp = array_;
  array_ = nullptr;
  return temp;
}
inline ::NDArray* SavedOutput::_internal_mutable_array() {
  
  if (array_ == nullptr) {
    auto* p = CreateMaybeMessage<::NDArray>(GetArena());
    array_ = p;
  }
  return array_;
}
inline ::NDArray* SavedOutput::mutable_array() {
  // @@protoc_insertion_point(field_mutable:SavedOutput.array)
  return _internal_mutable_array();
}
inline void SavedOutput::set_allocated_array(::NDArray* array) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(array_);
  }
  if (array) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(array)->GetArena();
    if (message_arena != submessage_arena) {
      array = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, array, submessage_arena);
    }
    
  } else {
    
  }
  array_ = array;
  // @@protoc_insertion_point(field_set_allocated:SavedOutput.array)
}

// string layer_name = 2;
inline void SavedOutput::clear_layer_name() {
  layer_name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& SavedOutput::layer_name() const {
  // @@protoc_insertion_point(field_get:SavedOutput.layer_name)
  return _internal_layer_name();
}
inline void SavedOutput::set_layer_name(const std::string& value) {
  _internal_set_layer_name(value);
  // @@protoc_insertion_point(field_set:SavedOutput.layer_name)
}
inline std::string* SavedOutput::mutable_layer_name() {
  // @@protoc_insertion_point(field_mutable:SavedOutput.layer_name)
  return _internal_mutable_layer_name();
}
inline const std::string& SavedOutput::_internal_layer_name() const {
  return layer_name_.Get();
}
inline void SavedOutput::_internal_set_layer_name(const std::string& value) {
  
  layer_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void SavedOutput::set_layer_name(std::string&& value) {
  
  layer_name_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:SavedOutput.layer_name)
}
inline void SavedOutput::set_layer_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  layer_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:SavedOutput.layer_name)
}
inline void SavedOutput::set_layer_name(const char* value,
    size_t size) {
  
  layer_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:SavedOutput.layer_name)
}
inline std::string* SavedOutput::_internal_mutable_layer_name() {
  
  return layer_name_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* SavedOutput::release_layer_name() {
  // @@protoc_insertion_point(field_release:SavedOutput.layer_name)
  return layer_name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void SavedOutput::set_allocated_layer_name(std::string* layer_name) {
  if (layer_name != nullptr) {
    
  } else {
    
  }
  layer_name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), layer_name,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:SavedOutput.layer_name)
}

// .DataLayout data_layout = 5;
inline void SavedOutput::clear_data_layout() {
  data_layout_ = 0;
}
inline ::DataLayout SavedOutput::_internal_data_layout() const {
  return static_cast< ::DataLayout >(data_layout_);
}
inline ::DataLayout SavedOutput::data_layout() const {
  // @@protoc_insertion_point(field_get:SavedOutput.data_layout)
  return _internal_data_layout();
}
inline void SavedOutput::_internal_set_data_layout(::DataLayout value) {
  
  data_layout_ = value;
}
inline void SavedOutput::set_data_layout(::DataLayout value) {
  _internal_set_data_layout(value);
  // @@protoc_insertion_point(field_set:SavedOutput.data_layout)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::DataLayout> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::DataLayout>() {
  return ::DataLayout_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_proto_2futils_2fsaved_5foutput_2eproto
