// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/utils/caption.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_proto_2futils_2fcaption_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_proto_2futils_2fcaption_2eproto

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
#include "proto/utils/ndarray.pb.h"
#include "proto/utils/tag.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_proto_2futils_2fcaption_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_proto_2futils_2fcaption_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2futils_2fcaption_2eproto;
class Caption;
class CaptionDefaultTypeInternal;
extern CaptionDefaultTypeInternal _Caption_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::Caption* Arena::CreateMaybeMessage<::Caption>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class Caption PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Caption) */ {
 public:
  inline Caption() : Caption(nullptr) {}
  virtual ~Caption();

  Caption(const Caption& from);
  Caption(Caption&& from) noexcept
    : Caption() {
    *this = ::std::move(from);
  }

  inline Caption& operator=(const Caption& from) {
    CopyFrom(from);
    return *this;
  }
  inline Caption& operator=(Caption&& from) noexcept {
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
  static const Caption& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Caption* internal_default_instance() {
    return reinterpret_cast<const Caption*>(
               &_Caption_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Caption& a, Caption& b) {
    a.Swap(&b);
  }
  inline void Swap(Caption* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Caption* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Caption* New() const final {
    return CreateMaybeMessage<Caption>(nullptr);
  }

  Caption* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Caption>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Caption& from);
  void MergeFrom(const Caption& from);
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
  void InternalSwap(Caption* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Caption";
  }
  protected:
  explicit Caption(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_proto_2futils_2fcaption_2eproto);
    return ::descriptor_table_proto_2futils_2fcaption_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kTagFieldNumber = 2,
    kRawCaptionFieldNumber = 3,
    kTextFieldNumber = 4,
    kTokenizedCaptionFieldNumber = 1,
  };
  // repeated .Tag tag = 2;
  int tag_size() const;
  private:
  int _internal_tag_size() const;
  public:
  void clear_tag();
  ::Tag* mutable_tag(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag >*
      mutable_tag();
  private:
  const ::Tag& _internal_tag(int index) const;
  ::Tag* _internal_add_tag();
  public:
  const ::Tag& tag(int index) const;
  ::Tag* add_tag();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag >&
      tag() const;

  // repeated string raw_caption = 3;
  int raw_caption_size() const;
  private:
  int _internal_raw_caption_size() const;
  public:
  void clear_raw_caption();
  const std::string& raw_caption(int index) const;
  std::string* mutable_raw_caption(int index);
  void set_raw_caption(int index, const std::string& value);
  void set_raw_caption(int index, std::string&& value);
  void set_raw_caption(int index, const char* value);
  void set_raw_caption(int index, const char* value, size_t size);
  std::string* add_raw_caption();
  void add_raw_caption(const std::string& value);
  void add_raw_caption(std::string&& value);
  void add_raw_caption(const char* value);
  void add_raw_caption(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& raw_caption() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_raw_caption();
  private:
  const std::string& _internal_raw_caption(int index) const;
  std::string* _internal_add_raw_caption();
  public:

  // string text = 4;
  void clear_text();
  const std::string& text() const;
  void set_text(const std::string& value);
  void set_text(std::string&& value);
  void set_text(const char* value);
  void set_text(const char* value, size_t size);
  std::string* mutable_text();
  std::string* release_text();
  void set_allocated_text(std::string* text);
  private:
  const std::string& _internal_text() const;
  void _internal_set_text(const std::string& value);
  std::string* _internal_mutable_text();
  public:

  // .NDArray tokenized_caption = 1;
  bool has_tokenized_caption() const;
  private:
  bool _internal_has_tokenized_caption() const;
  public:
  void clear_tokenized_caption();
  const ::NDArray& tokenized_caption() const;
  ::NDArray* release_tokenized_caption();
  ::NDArray* mutable_tokenized_caption();
  void set_allocated_tokenized_caption(::NDArray* tokenized_caption);
  private:
  const ::NDArray& _internal_tokenized_caption() const;
  ::NDArray* _internal_mutable_tokenized_caption();
  public:
  void unsafe_arena_set_allocated_tokenized_caption(
      ::NDArray* tokenized_caption);
  ::NDArray* unsafe_arena_release_tokenized_caption();

  // @@protoc_insertion_point(class_scope:Caption)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag > tag_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> raw_caption_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr text_;
  ::NDArray* tokenized_caption_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_proto_2futils_2fcaption_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Caption

// .NDArray tokenized_caption = 1;
inline bool Caption::_internal_has_tokenized_caption() const {
  return this != internal_default_instance() && tokenized_caption_ != nullptr;
}
inline bool Caption::has_tokenized_caption() const {
  return _internal_has_tokenized_caption();
}
inline const ::NDArray& Caption::_internal_tokenized_caption() const {
  const ::NDArray* p = tokenized_caption_;
  return p != nullptr ? *p : *reinterpret_cast<const ::NDArray*>(
      &::_NDArray_default_instance_);
}
inline const ::NDArray& Caption::tokenized_caption() const {
  // @@protoc_insertion_point(field_get:Caption.tokenized_caption)
  return _internal_tokenized_caption();
}
inline void Caption::unsafe_arena_set_allocated_tokenized_caption(
    ::NDArray* tokenized_caption) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(tokenized_caption_);
  }
  tokenized_caption_ = tokenized_caption;
  if (tokenized_caption) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Caption.tokenized_caption)
}
inline ::NDArray* Caption::release_tokenized_caption() {
  
  ::NDArray* temp = tokenized_caption_;
  tokenized_caption_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::NDArray* Caption::unsafe_arena_release_tokenized_caption() {
  // @@protoc_insertion_point(field_release:Caption.tokenized_caption)
  
  ::NDArray* temp = tokenized_caption_;
  tokenized_caption_ = nullptr;
  return temp;
}
inline ::NDArray* Caption::_internal_mutable_tokenized_caption() {
  
  if (tokenized_caption_ == nullptr) {
    auto* p = CreateMaybeMessage<::NDArray>(GetArena());
    tokenized_caption_ = p;
  }
  return tokenized_caption_;
}
inline ::NDArray* Caption::mutable_tokenized_caption() {
  // @@protoc_insertion_point(field_mutable:Caption.tokenized_caption)
  return _internal_mutable_tokenized_caption();
}
inline void Caption::set_allocated_tokenized_caption(::NDArray* tokenized_caption) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(tokenized_caption_);
  }
  if (tokenized_caption) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(tokenized_caption)->GetArena();
    if (message_arena != submessage_arena) {
      tokenized_caption = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, tokenized_caption, submessage_arena);
    }
    
  } else {
    
  }
  tokenized_caption_ = tokenized_caption;
  // @@protoc_insertion_point(field_set_allocated:Caption.tokenized_caption)
}

// repeated .Tag tag = 2;
inline int Caption::_internal_tag_size() const {
  return tag_.size();
}
inline int Caption::tag_size() const {
  return _internal_tag_size();
}
inline ::Tag* Caption::mutable_tag(int index) {
  // @@protoc_insertion_point(field_mutable:Caption.tag)
  return tag_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag >*
Caption::mutable_tag() {
  // @@protoc_insertion_point(field_mutable_list:Caption.tag)
  return &tag_;
}
inline const ::Tag& Caption::_internal_tag(int index) const {
  return tag_.Get(index);
}
inline const ::Tag& Caption::tag(int index) const {
  // @@protoc_insertion_point(field_get:Caption.tag)
  return _internal_tag(index);
}
inline ::Tag* Caption::_internal_add_tag() {
  return tag_.Add();
}
inline ::Tag* Caption::add_tag() {
  // @@protoc_insertion_point(field_add:Caption.tag)
  return _internal_add_tag();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Tag >&
Caption::tag() const {
  // @@protoc_insertion_point(field_list:Caption.tag)
  return tag_;
}

// repeated string raw_caption = 3;
inline int Caption::_internal_raw_caption_size() const {
  return raw_caption_.size();
}
inline int Caption::raw_caption_size() const {
  return _internal_raw_caption_size();
}
inline void Caption::clear_raw_caption() {
  raw_caption_.Clear();
}
inline std::string* Caption::add_raw_caption() {
  // @@protoc_insertion_point(field_add_mutable:Caption.raw_caption)
  return _internal_add_raw_caption();
}
inline const std::string& Caption::_internal_raw_caption(int index) const {
  return raw_caption_.Get(index);
}
inline const std::string& Caption::raw_caption(int index) const {
  // @@protoc_insertion_point(field_get:Caption.raw_caption)
  return _internal_raw_caption(index);
}
inline std::string* Caption::mutable_raw_caption(int index) {
  // @@protoc_insertion_point(field_mutable:Caption.raw_caption)
  return raw_caption_.Mutable(index);
}
inline void Caption::set_raw_caption(int index, const std::string& value) {
  // @@protoc_insertion_point(field_set:Caption.raw_caption)
  raw_caption_.Mutable(index)->assign(value);
}
inline void Caption::set_raw_caption(int index, std::string&& value) {
  // @@protoc_insertion_point(field_set:Caption.raw_caption)
  raw_caption_.Mutable(index)->assign(std::move(value));
}
inline void Caption::set_raw_caption(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  raw_caption_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:Caption.raw_caption)
}
inline void Caption::set_raw_caption(int index, const char* value, size_t size) {
  raw_caption_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:Caption.raw_caption)
}
inline std::string* Caption::_internal_add_raw_caption() {
  return raw_caption_.Add();
}
inline void Caption::add_raw_caption(const std::string& value) {
  raw_caption_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:Caption.raw_caption)
}
inline void Caption::add_raw_caption(std::string&& value) {
  raw_caption_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:Caption.raw_caption)
}
inline void Caption::add_raw_caption(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  raw_caption_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:Caption.raw_caption)
}
inline void Caption::add_raw_caption(const char* value, size_t size) {
  raw_caption_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:Caption.raw_caption)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
Caption::raw_caption() const {
  // @@protoc_insertion_point(field_list:Caption.raw_caption)
  return raw_caption_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
Caption::mutable_raw_caption() {
  // @@protoc_insertion_point(field_mutable_list:Caption.raw_caption)
  return &raw_caption_;
}

// string text = 4;
inline void Caption::clear_text() {
  text_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& Caption::text() const {
  // @@protoc_insertion_point(field_get:Caption.text)
  return _internal_text();
}
inline void Caption::set_text(const std::string& value) {
  _internal_set_text(value);
  // @@protoc_insertion_point(field_set:Caption.text)
}
inline std::string* Caption::mutable_text() {
  // @@protoc_insertion_point(field_mutable:Caption.text)
  return _internal_mutable_text();
}
inline const std::string& Caption::_internal_text() const {
  return text_.Get();
}
inline void Caption::_internal_set_text(const std::string& value) {
  
  text_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void Caption::set_text(std::string&& value) {
  
  text_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:Caption.text)
}
inline void Caption::set_text(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  text_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:Caption.text)
}
inline void Caption::set_text(const char* value,
    size_t size) {
  
  text_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:Caption.text)
}
inline std::string* Caption::_internal_mutable_text() {
  
  return text_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* Caption::release_text() {
  // @@protoc_insertion_point(field_release:Caption.text)
  return text_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void Caption::set_allocated_text(std::string* text) {
  if (text != nullptr) {
    
  } else {
    
  }
  text_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), text,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:Caption.text)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_proto_2futils_2fcaption_2eproto
