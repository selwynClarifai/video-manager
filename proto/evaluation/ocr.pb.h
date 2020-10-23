// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/evaluation/ocr.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_proto_2fevaluation_2focr_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_proto_2fevaluation_2focr_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_proto_2fevaluation_2focr_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_proto_2fevaluation_2focr_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2fevaluation_2focr_2eproto;
class OCREvalResult;
class OCREvalResultDefaultTypeInternal;
extern OCREvalResultDefaultTypeInternal _OCREvalResult_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::OCREvalResult* Arena::CreateMaybeMessage<::OCREvalResult>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class OCREvalResult PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:OCREvalResult) */ {
 public:
  inline OCREvalResult() : OCREvalResult(nullptr) {}
  virtual ~OCREvalResult();

  OCREvalResult(const OCREvalResult& from);
  OCREvalResult(OCREvalResult&& from) noexcept
    : OCREvalResult() {
    *this = ::std::move(from);
  }

  inline OCREvalResult& operator=(const OCREvalResult& from) {
    CopyFrom(from);
    return *this;
  }
  inline OCREvalResult& operator=(OCREvalResult&& from) noexcept {
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
  static const OCREvalResult& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const OCREvalResult* internal_default_instance() {
    return reinterpret_cast<const OCREvalResult*>(
               &_OCREvalResult_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(OCREvalResult& a, OCREvalResult& b) {
    a.Swap(&b);
  }
  inline void Swap(OCREvalResult* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(OCREvalResult* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline OCREvalResult* New() const final {
    return CreateMaybeMessage<OCREvalResult>(nullptr);
  }

  OCREvalResult* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<OCREvalResult>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const OCREvalResult& from);
  void MergeFrom(const OCREvalResult& from);
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
  void InternalSwap(OCREvalResult* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "OCREvalResult";
  }
  protected:
  explicit OCREvalResult(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_proto_2fevaluation_2focr_2eproto);
    return ::descriptor_table_proto_2fevaluation_2focr_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kLevenshteinFieldNumber = 1,
  };
  // double levenshtein = 1;
  void clear_levenshtein();
  double levenshtein() const;
  void set_levenshtein(double value);
  private:
  double _internal_levenshtein() const;
  void _internal_set_levenshtein(double value);
  public:

  // @@protoc_insertion_point(class_scope:OCREvalResult)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  double levenshtein_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_proto_2fevaluation_2focr_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// OCREvalResult

// double levenshtein = 1;
inline void OCREvalResult::clear_levenshtein() {
  levenshtein_ = 0;
}
inline double OCREvalResult::_internal_levenshtein() const {
  return levenshtein_;
}
inline double OCREvalResult::levenshtein() const {
  // @@protoc_insertion_point(field_get:OCREvalResult.levenshtein)
  return _internal_levenshtein();
}
inline void OCREvalResult::_internal_set_levenshtein(double value) {
  
  levenshtein_ = value;
}
inline void OCREvalResult::set_levenshtein(double value) {
  _internal_set_levenshtein(value);
  // @@protoc_insertion_point(field_set:OCREvalResult.levenshtein)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_proto_2fevaluation_2focr_2eproto