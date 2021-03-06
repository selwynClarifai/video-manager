// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/utils/databatch.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_proto_2futils_2fdatabatch_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_proto_2futils_2fdatabatch_2eproto

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
#include <google/protobuf/timestamp.pb.h>
#include "proto/utils/data_example.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_proto_2futils_2fdatabatch_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_proto_2futils_2fdatabatch_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2futils_2fdatabatch_2eproto;
class DataBatch;
class DataBatchDefaultTypeInternal;
extern DataBatchDefaultTypeInternal _DataBatch_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::DataBatch* Arena::CreateMaybeMessage<::DataBatch>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class DataBatch PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:DataBatch) */ {
 public:
  inline DataBatch() : DataBatch(nullptr) {}
  virtual ~DataBatch();

  DataBatch(const DataBatch& from);
  DataBatch(DataBatch&& from) noexcept
    : DataBatch() {
    *this = ::std::move(from);
  }

  inline DataBatch& operator=(const DataBatch& from) {
    CopyFrom(from);
    return *this;
  }
  inline DataBatch& operator=(DataBatch&& from) noexcept {
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
  static const DataBatch& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const DataBatch* internal_default_instance() {
    return reinterpret_cast<const DataBatch*>(
               &_DataBatch_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(DataBatch& a, DataBatch& b) {
    a.Swap(&b);
  }
  inline void Swap(DataBatch* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(DataBatch* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline DataBatch* New() const final {
    return CreateMaybeMessage<DataBatch>(nullptr);
  }

  DataBatch* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<DataBatch>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const DataBatch& from);
  void MergeFrom(const DataBatch& from);
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
  void InternalSwap(DataBatch* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "DataBatch";
  }
  protected:
  explicit DataBatch(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_proto_2futils_2fdatabatch_2eproto);
    return ::descriptor_table_proto_2futils_2fdatabatch_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kExampleFieldNumber = 1,
    kSourceFieldNumber = 2,
    kCreatedFieldNumber = 3,
  };
  // repeated .DataExample example = 1;
  int example_size() const;
  private:
  int _internal_example_size() const;
  public:
  void clear_example();
  ::DataExample* mutable_example(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::DataExample >*
      mutable_example();
  private:
  const ::DataExample& _internal_example(int index) const;
  ::DataExample* _internal_add_example();
  public:
  const ::DataExample& example(int index) const;
  ::DataExample* add_example();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::DataExample >&
      example() const;

  // string source = 2;
  void clear_source();
  const std::string& source() const;
  void set_source(const std::string& value);
  void set_source(std::string&& value);
  void set_source(const char* value);
  void set_source(const char* value, size_t size);
  std::string* mutable_source();
  std::string* release_source();
  void set_allocated_source(std::string* source);
  private:
  const std::string& _internal_source() const;
  void _internal_set_source(const std::string& value);
  std::string* _internal_mutable_source();
  public:

  // .google.protobuf.Timestamp created = 3;
  bool has_created() const;
  private:
  bool _internal_has_created() const;
  public:
  void clear_created();
  const PROTOBUF_NAMESPACE_ID::Timestamp& created() const;
  PROTOBUF_NAMESPACE_ID::Timestamp* release_created();
  PROTOBUF_NAMESPACE_ID::Timestamp* mutable_created();
  void set_allocated_created(PROTOBUF_NAMESPACE_ID::Timestamp* created);
  private:
  const PROTOBUF_NAMESPACE_ID::Timestamp& _internal_created() const;
  PROTOBUF_NAMESPACE_ID::Timestamp* _internal_mutable_created();
  public:
  void unsafe_arena_set_allocated_created(
      PROTOBUF_NAMESPACE_ID::Timestamp* created);
  PROTOBUF_NAMESPACE_ID::Timestamp* unsafe_arena_release_created();

  // @@protoc_insertion_point(class_scope:DataBatch)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::DataExample > example_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr source_;
  PROTOBUF_NAMESPACE_ID::Timestamp* created_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_proto_2futils_2fdatabatch_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// DataBatch

// repeated .DataExample example = 1;
inline int DataBatch::_internal_example_size() const {
  return example_.size();
}
inline int DataBatch::example_size() const {
  return _internal_example_size();
}
inline ::DataExample* DataBatch::mutable_example(int index) {
  // @@protoc_insertion_point(field_mutable:DataBatch.example)
  return example_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::DataExample >*
DataBatch::mutable_example() {
  // @@protoc_insertion_point(field_mutable_list:DataBatch.example)
  return &example_;
}
inline const ::DataExample& DataBatch::_internal_example(int index) const {
  return example_.Get(index);
}
inline const ::DataExample& DataBatch::example(int index) const {
  // @@protoc_insertion_point(field_get:DataBatch.example)
  return _internal_example(index);
}
inline ::DataExample* DataBatch::_internal_add_example() {
  return example_.Add();
}
inline ::DataExample* DataBatch::add_example() {
  // @@protoc_insertion_point(field_add:DataBatch.example)
  return _internal_add_example();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::DataExample >&
DataBatch::example() const {
  // @@protoc_insertion_point(field_list:DataBatch.example)
  return example_;
}

// string source = 2;
inline void DataBatch::clear_source() {
  source_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& DataBatch::source() const {
  // @@protoc_insertion_point(field_get:DataBatch.source)
  return _internal_source();
}
inline void DataBatch::set_source(const std::string& value) {
  _internal_set_source(value);
  // @@protoc_insertion_point(field_set:DataBatch.source)
}
inline std::string* DataBatch::mutable_source() {
  // @@protoc_insertion_point(field_mutable:DataBatch.source)
  return _internal_mutable_source();
}
inline const std::string& DataBatch::_internal_source() const {
  return source_.Get();
}
inline void DataBatch::_internal_set_source(const std::string& value) {
  
  source_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void DataBatch::set_source(std::string&& value) {
  
  source_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:DataBatch.source)
}
inline void DataBatch::set_source(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  source_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:DataBatch.source)
}
inline void DataBatch::set_source(const char* value,
    size_t size) {
  
  source_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:DataBatch.source)
}
inline std::string* DataBatch::_internal_mutable_source() {
  
  return source_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* DataBatch::release_source() {
  // @@protoc_insertion_point(field_release:DataBatch.source)
  return source_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void DataBatch::set_allocated_source(std::string* source) {
  if (source != nullptr) {
    
  } else {
    
  }
  source_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), source,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:DataBatch.source)
}

// .google.protobuf.Timestamp created = 3;
inline bool DataBatch::_internal_has_created() const {
  return this != internal_default_instance() && created_ != nullptr;
}
inline bool DataBatch::has_created() const {
  return _internal_has_created();
}
inline const PROTOBUF_NAMESPACE_ID::Timestamp& DataBatch::_internal_created() const {
  const PROTOBUF_NAMESPACE_ID::Timestamp* p = created_;
  return p != nullptr ? *p : *reinterpret_cast<const PROTOBUF_NAMESPACE_ID::Timestamp*>(
      &PROTOBUF_NAMESPACE_ID::_Timestamp_default_instance_);
}
inline const PROTOBUF_NAMESPACE_ID::Timestamp& DataBatch::created() const {
  // @@protoc_insertion_point(field_get:DataBatch.created)
  return _internal_created();
}
inline void DataBatch::unsafe_arena_set_allocated_created(
    PROTOBUF_NAMESPACE_ID::Timestamp* created) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(created_);
  }
  created_ = created;
  if (created) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:DataBatch.created)
}
inline PROTOBUF_NAMESPACE_ID::Timestamp* DataBatch::release_created() {
  
  PROTOBUF_NAMESPACE_ID::Timestamp* temp = created_;
  created_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline PROTOBUF_NAMESPACE_ID::Timestamp* DataBatch::unsafe_arena_release_created() {
  // @@protoc_insertion_point(field_release:DataBatch.created)
  
  PROTOBUF_NAMESPACE_ID::Timestamp* temp = created_;
  created_ = nullptr;
  return temp;
}
inline PROTOBUF_NAMESPACE_ID::Timestamp* DataBatch::_internal_mutable_created() {
  
  if (created_ == nullptr) {
    auto* p = CreateMaybeMessage<PROTOBUF_NAMESPACE_ID::Timestamp>(GetArena());
    created_ = p;
  }
  return created_;
}
inline PROTOBUF_NAMESPACE_ID::Timestamp* DataBatch::mutable_created() {
  // @@protoc_insertion_point(field_mutable:DataBatch.created)
  return _internal_mutable_created();
}
inline void DataBatch::set_allocated_created(PROTOBUF_NAMESPACE_ID::Timestamp* created) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(created_);
  }
  if (created) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(created)->GetArena();
    if (message_arena != submessage_arena) {
      created = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, created, submessage_arena);
    }
    
  } else {
    
  }
  created_ = created;
  // @@protoc_insertion_point(field_set_allocated:DataBatch.created)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_proto_2futils_2fdatabatch_2eproto
