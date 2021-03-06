// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/utils/face.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_proto_2futils_2fface_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_proto_2futils_2fface_2eproto

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
#include "proto/utils/tag.pb.h"
#include "proto/utils/boundingbox.pb.h"
#include "proto/utils/embedding.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_proto_2futils_2fface_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_proto_2futils_2fface_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2futils_2fface_2eproto;
class Face;
class FaceDefaultTypeInternal;
extern FaceDefaultTypeInternal _Face_default_instance_;
class FaceDetection;
class FaceDetectionDefaultTypeInternal;
extern FaceDetectionDefaultTypeInternal _FaceDetection_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::Face* Arena::CreateMaybeMessage<::Face>(Arena*);
template<> ::FaceDetection* Arena::CreateMaybeMessage<::FaceDetection>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class Face PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Face) */ {
 public:
  inline Face() : Face(nullptr) {}
  virtual ~Face();

  Face(const Face& from);
  Face(Face&& from) noexcept
    : Face() {
    *this = ::std::move(from);
  }

  inline Face& operator=(const Face& from) {
    CopyFrom(from);
    return *this;
  }
  inline Face& operator=(Face&& from) noexcept {
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
  static const Face& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Face* internal_default_instance() {
    return reinterpret_cast<const Face*>(
               &_Face_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Face& a, Face& b) {
    a.Swap(&b);
  }
  inline void Swap(Face* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Face* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Face* New() const final {
    return CreateMaybeMessage<Face>(nullptr);
  }

  Face* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Face>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Face& from);
  void MergeFrom(const Face& from);
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
  void InternalSwap(Face* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Face";
  }
  protected:
  explicit Face(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_proto_2futils_2fface_2eproto);
    return ::descriptor_table_proto_2futils_2fface_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kIdentityFieldNumber = 1,
    kAgeFieldNumber = 2,
    kGenderFieldNumber = 3,
    kEthnicityFieldNumber = 4,
  };
  // repeated .Tag identity = 1;
  int identity_size() const;
  private:
  int _internal_identity_size() const;
  public:
  void clear_identity();
  ::Tag* mutable_identity(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag >*
      mutable_identity();
  private:
  const ::Tag& _internal_identity(int index) const;
  ::Tag* _internal_add_identity();
  public:
  const ::Tag& identity(int index) const;
  ::Tag* add_identity();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag >&
      identity() const;

  // repeated .Tag age = 2;
  int age_size() const;
  private:
  int _internal_age_size() const;
  public:
  void clear_age();
  ::Tag* mutable_age(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag >*
      mutable_age();
  private:
  const ::Tag& _internal_age(int index) const;
  ::Tag* _internal_add_age();
  public:
  const ::Tag& age(int index) const;
  ::Tag* add_age();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag >&
      age() const;

  // repeated .Tag gender = 3;
  int gender_size() const;
  private:
  int _internal_gender_size() const;
  public:
  void clear_gender();
  ::Tag* mutable_gender(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag >*
      mutable_gender();
  private:
  const ::Tag& _internal_gender(int index) const;
  ::Tag* _internal_add_gender();
  public:
  const ::Tag& gender(int index) const;
  ::Tag* add_gender();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag >&
      gender() const;

  // repeated .Tag ethnicity = 4;
  int ethnicity_size() const;
  private:
  int _internal_ethnicity_size() const;
  public:
  void clear_ethnicity();
  ::Tag* mutable_ethnicity(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag >*
      mutable_ethnicity();
  private:
  const ::Tag& _internal_ethnicity(int index) const;
  ::Tag* _internal_add_ethnicity();
  public:
  const ::Tag& ethnicity(int index) const;
  ::Tag* add_ethnicity();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag >&
      ethnicity() const;

  // @@protoc_insertion_point(class_scope:Face)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag > identity_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag > age_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag > gender_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag > ethnicity_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_proto_2futils_2fface_2eproto;
};
// -------------------------------------------------------------------

class FaceDetection PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:FaceDetection) */ {
 public:
  inline FaceDetection() : FaceDetection(nullptr) {}
  virtual ~FaceDetection();

  FaceDetection(const FaceDetection& from);
  FaceDetection(FaceDetection&& from) noexcept
    : FaceDetection() {
    *this = ::std::move(from);
  }

  inline FaceDetection& operator=(const FaceDetection& from) {
    CopyFrom(from);
    return *this;
  }
  inline FaceDetection& operator=(FaceDetection&& from) noexcept {
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
  static const FaceDetection& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const FaceDetection* internal_default_instance() {
    return reinterpret_cast<const FaceDetection*>(
               &_FaceDetection_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(FaceDetection& a, FaceDetection& b) {
    a.Swap(&b);
  }
  inline void Swap(FaceDetection* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(FaceDetection* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline FaceDetection* New() const final {
    return CreateMaybeMessage<FaceDetection>(nullptr);
  }

  FaceDetection* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<FaceDetection>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const FaceDetection& from);
  void MergeFrom(const FaceDetection& from);
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
  void InternalSwap(FaceDetection* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "FaceDetection";
  }
  protected:
  explicit FaceDetection(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_proto_2futils_2fface_2eproto);
    return ::descriptor_table_proto_2futils_2fface_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kBoxFieldNumber = 1,
    kFaceFieldNumber = 2,
    kEmbeddingFieldNumber = 3,
  };
  // .BoundingBox box = 1;
  bool has_box() const;
  private:
  bool _internal_has_box() const;
  public:
  void clear_box();
  const ::BoundingBox& box() const;
  ::BoundingBox* release_box();
  ::BoundingBox* mutable_box();
  void set_allocated_box(::BoundingBox* box);
  private:
  const ::BoundingBox& _internal_box() const;
  ::BoundingBox* _internal_mutable_box();
  public:
  void unsafe_arena_set_allocated_box(
      ::BoundingBox* box);
  ::BoundingBox* unsafe_arena_release_box();

  // .Face face = 2;
  bool has_face() const;
  private:
  bool _internal_has_face() const;
  public:
  void clear_face();
  const ::Face& face() const;
  ::Face* release_face();
  ::Face* mutable_face();
  void set_allocated_face(::Face* face);
  private:
  const ::Face& _internal_face() const;
  ::Face* _internal_mutable_face();
  public:
  void unsafe_arena_set_allocated_face(
      ::Face* face);
  ::Face* unsafe_arena_release_face();

  // .Embedding embedding = 3;
  bool has_embedding() const;
  private:
  bool _internal_has_embedding() const;
  public:
  void clear_embedding();
  const ::Embedding& embedding() const;
  ::Embedding* release_embedding();
  ::Embedding* mutable_embedding();
  void set_allocated_embedding(::Embedding* embedding);
  private:
  const ::Embedding& _internal_embedding() const;
  ::Embedding* _internal_mutable_embedding();
  public:
  void unsafe_arena_set_allocated_embedding(
      ::Embedding* embedding);
  ::Embedding* unsafe_arena_release_embedding();

  // @@protoc_insertion_point(class_scope:FaceDetection)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::BoundingBox* box_;
  ::Face* face_;
  ::Embedding* embedding_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_proto_2futils_2fface_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Face

// repeated .Tag identity = 1;
inline int Face::_internal_identity_size() const {
  return identity_.size();
}
inline int Face::identity_size() const {
  return _internal_identity_size();
}
inline ::Tag* Face::mutable_identity(int index) {
  // @@protoc_insertion_point(field_mutable:Face.identity)
  return identity_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag >*
Face::mutable_identity() {
  // @@protoc_insertion_point(field_mutable_list:Face.identity)
  return &identity_;
}
inline const ::Tag& Face::_internal_identity(int index) const {
  return identity_.Get(index);
}
inline const ::Tag& Face::identity(int index) const {
  // @@protoc_insertion_point(field_get:Face.identity)
  return _internal_identity(index);
}
inline ::Tag* Face::_internal_add_identity() {
  return identity_.Add();
}
inline ::Tag* Face::add_identity() {
  // @@protoc_insertion_point(field_add:Face.identity)
  return _internal_add_identity();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag >&
Face::identity() const {
  // @@protoc_insertion_point(field_list:Face.identity)
  return identity_;
}

// repeated .Tag age = 2;
inline int Face::_internal_age_size() const {
  return age_.size();
}
inline int Face::age_size() const {
  return _internal_age_size();
}
inline ::Tag* Face::mutable_age(int index) {
  // @@protoc_insertion_point(field_mutable:Face.age)
  return age_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag >*
Face::mutable_age() {
  // @@protoc_insertion_point(field_mutable_list:Face.age)
  return &age_;
}
inline const ::Tag& Face::_internal_age(int index) const {
  return age_.Get(index);
}
inline const ::Tag& Face::age(int index) const {
  // @@protoc_insertion_point(field_get:Face.age)
  return _internal_age(index);
}
inline ::Tag* Face::_internal_add_age() {
  return age_.Add();
}
inline ::Tag* Face::add_age() {
  // @@protoc_insertion_point(field_add:Face.age)
  return _internal_add_age();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag >&
Face::age() const {
  // @@protoc_insertion_point(field_list:Face.age)
  return age_;
}

// repeated .Tag gender = 3;
inline int Face::_internal_gender_size() const {
  return gender_.size();
}
inline int Face::gender_size() const {
  return _internal_gender_size();
}
inline ::Tag* Face::mutable_gender(int index) {
  // @@protoc_insertion_point(field_mutable:Face.gender)
  return gender_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag >*
Face::mutable_gender() {
  // @@protoc_insertion_point(field_mutable_list:Face.gender)
  return &gender_;
}
inline const ::Tag& Face::_internal_gender(int index) const {
  return gender_.Get(index);
}
inline const ::Tag& Face::gender(int index) const {
  // @@protoc_insertion_point(field_get:Face.gender)
  return _internal_gender(index);
}
inline ::Tag* Face::_internal_add_gender() {
  return gender_.Add();
}
inline ::Tag* Face::add_gender() {
  // @@protoc_insertion_point(field_add:Face.gender)
  return _internal_add_gender();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag >&
Face::gender() const {
  // @@protoc_insertion_point(field_list:Face.gender)
  return gender_;
}

// repeated .Tag ethnicity = 4;
inline int Face::_internal_ethnicity_size() const {
  return ethnicity_.size();
}
inline int Face::ethnicity_size() const {
  return _internal_ethnicity_size();
}
inline ::Tag* Face::mutable_ethnicity(int index) {
  // @@protoc_insertion_point(field_mutable:Face.ethnicity)
  return ethnicity_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag >*
Face::mutable_ethnicity() {
  // @@protoc_insertion_point(field_mutable_list:Face.ethnicity)
  return &ethnicity_;
}
inline const ::Tag& Face::_internal_ethnicity(int index) const {
  return ethnicity_.Get(index);
}
inline const ::Tag& Face::ethnicity(int index) const {
  // @@protoc_insertion_point(field_get:Face.ethnicity)
  return _internal_ethnicity(index);
}
inline ::Tag* Face::_internal_add_ethnicity() {
  return ethnicity_.Add();
}
inline ::Tag* Face::add_ethnicity() {
  // @@protoc_insertion_point(field_add:Face.ethnicity)
  return _internal_add_ethnicity();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag >&
Face::ethnicity() const {
  // @@protoc_insertion_point(field_list:Face.ethnicity)
  return ethnicity_;
}

// -------------------------------------------------------------------

// FaceDetection

// .BoundingBox box = 1;
inline bool FaceDetection::_internal_has_box() const {
  return this != internal_default_instance() && box_ != nullptr;
}
inline bool FaceDetection::has_box() const {
  return _internal_has_box();
}
inline const ::BoundingBox& FaceDetection::_internal_box() const {
  const ::BoundingBox* p = box_;
  return p != nullptr ? *p : *reinterpret_cast<const ::BoundingBox*>(
      &::_BoundingBox_default_instance_);
}
inline const ::BoundingBox& FaceDetection::box() const {
  // @@protoc_insertion_point(field_get:FaceDetection.box)
  return _internal_box();
}
inline void FaceDetection::unsafe_arena_set_allocated_box(
    ::BoundingBox* box) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(box_);
  }
  box_ = box;
  if (box) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:FaceDetection.box)
}
inline ::BoundingBox* FaceDetection::release_box() {
  
  ::BoundingBox* temp = box_;
  box_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::BoundingBox* FaceDetection::unsafe_arena_release_box() {
  // @@protoc_insertion_point(field_release:FaceDetection.box)
  
  ::BoundingBox* temp = box_;
  box_ = nullptr;
  return temp;
}
inline ::BoundingBox* FaceDetection::_internal_mutable_box() {
  
  if (box_ == nullptr) {
    auto* p = CreateMaybeMessage<::BoundingBox>(GetArena());
    box_ = p;
  }
  return box_;
}
inline ::BoundingBox* FaceDetection::mutable_box() {
  // @@protoc_insertion_point(field_mutable:FaceDetection.box)
  return _internal_mutable_box();
}
inline void FaceDetection::set_allocated_box(::BoundingBox* box) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(box_);
  }
  if (box) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(box)->GetArena();
    if (message_arena != submessage_arena) {
      box = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, box, submessage_arena);
    }
    
  } else {
    
  }
  box_ = box;
  // @@protoc_insertion_point(field_set_allocated:FaceDetection.box)
}

// .Face face = 2;
inline bool FaceDetection::_internal_has_face() const {
  return this != internal_default_instance() && face_ != nullptr;
}
inline bool FaceDetection::has_face() const {
  return _internal_has_face();
}
inline void FaceDetection::clear_face() {
  if (GetArena() == nullptr && face_ != nullptr) {
    delete face_;
  }
  face_ = nullptr;
}
inline const ::Face& FaceDetection::_internal_face() const {
  const ::Face* p = face_;
  return p != nullptr ? *p : *reinterpret_cast<const ::Face*>(
      &::_Face_default_instance_);
}
inline const ::Face& FaceDetection::face() const {
  // @@protoc_insertion_point(field_get:FaceDetection.face)
  return _internal_face();
}
inline void FaceDetection::unsafe_arena_set_allocated_face(
    ::Face* face) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(face_);
  }
  face_ = face;
  if (face) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:FaceDetection.face)
}
inline ::Face* FaceDetection::release_face() {
  
  ::Face* temp = face_;
  face_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::Face* FaceDetection::unsafe_arena_release_face() {
  // @@protoc_insertion_point(field_release:FaceDetection.face)
  
  ::Face* temp = face_;
  face_ = nullptr;
  return temp;
}
inline ::Face* FaceDetection::_internal_mutable_face() {
  
  if (face_ == nullptr) {
    auto* p = CreateMaybeMessage<::Face>(GetArena());
    face_ = p;
  }
  return face_;
}
inline ::Face* FaceDetection::mutable_face() {
  // @@protoc_insertion_point(field_mutable:FaceDetection.face)
  return _internal_mutable_face();
}
inline void FaceDetection::set_allocated_face(::Face* face) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete face_;
  }
  if (face) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(face);
    if (message_arena != submessage_arena) {
      face = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, face, submessage_arena);
    }
    
  } else {
    
  }
  face_ = face;
  // @@protoc_insertion_point(field_set_allocated:FaceDetection.face)
}

// .Embedding embedding = 3;
inline bool FaceDetection::_internal_has_embedding() const {
  return this != internal_default_instance() && embedding_ != nullptr;
}
inline bool FaceDetection::has_embedding() const {
  return _internal_has_embedding();
}
inline const ::Embedding& FaceDetection::_internal_embedding() const {
  const ::Embedding* p = embedding_;
  return p != nullptr ? *p : *reinterpret_cast<const ::Embedding*>(
      &::_Embedding_default_instance_);
}
inline const ::Embedding& FaceDetection::embedding() const {
  // @@protoc_insertion_point(field_get:FaceDetection.embedding)
  return _internal_embedding();
}
inline void FaceDetection::unsafe_arena_set_allocated_embedding(
    ::Embedding* embedding) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(embedding_);
  }
  embedding_ = embedding;
  if (embedding) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:FaceDetection.embedding)
}
inline ::Embedding* FaceDetection::release_embedding() {
  
  ::Embedding* temp = embedding_;
  embedding_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::Embedding* FaceDetection::unsafe_arena_release_embedding() {
  // @@protoc_insertion_point(field_release:FaceDetection.embedding)
  
  ::Embedding* temp = embedding_;
  embedding_ = nullptr;
  return temp;
}
inline ::Embedding* FaceDetection::_internal_mutable_embedding() {
  
  if (embedding_ == nullptr) {
    auto* p = CreateMaybeMessage<::Embedding>(GetArena());
    embedding_ = p;
  }
  return embedding_;
}
inline ::Embedding* FaceDetection::mutable_embedding() {
  // @@protoc_insertion_point(field_mutable:FaceDetection.embedding)
  return _internal_mutable_embedding();
}
inline void FaceDetection::set_allocated_embedding(::Embedding* embedding) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(embedding_);
  }
  if (embedding) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(embedding)->GetArena();
    if (message_arena != submessage_arena) {
      embedding = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, embedding, submessage_arena);
    }
    
  } else {
    
  }
  embedding_ = embedding;
  // @@protoc_insertion_point(field_set_allocated:FaceDetection.embedding)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_proto_2futils_2fface_2eproto
