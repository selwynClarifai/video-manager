// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/utils/image.proto

#include "proto/utils/image.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_proto_2futils_2fndarray_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_NDArray_proto_2futils_2fndarray_2eproto;
class ImageDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Image> _instance;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr encoded_bytes_;
  const ::NDArray* ndarray_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr decoded_bytes_;
} _Image_default_instance_;
static void InitDefaultsscc_info_Image_proto_2futils_2fimage_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_Image_default_instance_;
    new (ptr) ::Image();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Image::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_Image_proto_2futils_2fimage_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_Image_proto_2futils_2fimage_2eproto}, {
      &scc_info_NDArray_proto_2futils_2fndarray_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_proto_2futils_2fimage_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_proto_2futils_2fimage_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_proto_2futils_2fimage_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_proto_2futils_2fimage_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Image, _internal_metadata_),
  ~0u,  // no _extensions_
  PROTOBUF_FIELD_OFFSET(::Image, _oneof_case_[0]),
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Image, name_),
  offsetof(::ImageDefaultTypeInternal, encoded_bytes_),
  offsetof(::ImageDefaultTypeInternal, ndarray_),
  offsetof(::ImageDefaultTypeInternal, decoded_bytes_),
  PROTOBUF_FIELD_OFFSET(::Image, url_),
  PROTOBUF_FIELD_OFFSET(::Image, hosted_orig_url_),
  PROTOBUF_FIELD_OFFSET(::Image, hosted_small_url_),
  PROTOBUF_FIELD_OFFSET(::Image, hosted_large_url_),
  PROTOBUF_FIELD_OFFSET(::Image, hosted_tiny_url_),
  PROTOBUF_FIELD_OFFSET(::Image, width_),
  PROTOBUF_FIELD_OFFSET(::Image, height_),
  PROTOBUF_FIELD_OFFSET(::Image, colors_),
  PROTOBUF_FIELD_OFFSET(::Image, mean_value_),
  PROTOBUF_FIELD_OFFSET(::Image, min_value_),
  PROTOBUF_FIELD_OFFSET(::Image, max_value_),
  PROTOBUF_FIELD_OFFSET(::Image, data_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::Image)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_Image_default_instance_),
};

const char descriptor_table_protodef_proto_2futils_2fimage_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\027proto/utils/image.proto\032\031proto/utils/n"
  "darray.proto\"\316\002\n\005Image\022\014\n\004name\030\001 \001(\t\022\027\n\r"
  "encoded_bytes\030\002 \001(\014H\000\022\033\n\007ndarray\030\003 \001(\0132\010"
  ".NDArrayH\000\022\027\n\rdecoded_bytes\030\005 \001(\014H\000\022\013\n\003u"
  "rl\030\004 \001(\t\022\027\n\017hosted_orig_url\030\006 \001(\t\022\030\n\020hos"
  "ted_small_url\030\007 \001(\t\022\030\n\020hosted_large_url\030"
  "\010 \001(\t\022\027\n\017hosted_tiny_url\030\t \001(\t\022\016\n\005width\030"
  "\350\007 \001(\005\022\017\n\006height\030\351\007 \001(\005\022\017\n\006colors\030\352\007 \001(\005"
  "\022\023\n\nmean_value\030\353\007 \001(\002\022\022\n\tmin_value\030\354\007 \001("
  "\002\022\022\n\tmax_value\030\355\007 \001(\002B\006\n\004dataB\016\n\005utilsZ\005"
  "utilsb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_proto_2futils_2fimage_2eproto_deps[1] = {
  &::descriptor_table_proto_2futils_2fndarray_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_proto_2futils_2fimage_2eproto_sccs[1] = {
  &scc_info_Image_proto_2futils_2fimage_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_proto_2futils_2fimage_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2futils_2fimage_2eproto = {
  false, false, descriptor_table_protodef_proto_2futils_2fimage_2eproto, "proto/utils/image.proto", 413,
  &descriptor_table_proto_2futils_2fimage_2eproto_once, descriptor_table_proto_2futils_2fimage_2eproto_sccs, descriptor_table_proto_2futils_2fimage_2eproto_deps, 1, 1,
  schemas, file_default_instances, TableStruct_proto_2futils_2fimage_2eproto::offsets,
  file_level_metadata_proto_2futils_2fimage_2eproto, 1, file_level_enum_descriptors_proto_2futils_2fimage_2eproto, file_level_service_descriptors_proto_2futils_2fimage_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_proto_2futils_2fimage_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_proto_2futils_2fimage_2eproto)), true);

// ===================================================================

void Image::InitAsDefaultInstance() {
  ::_Image_default_instance_.encoded_bytes_.UnsafeSetDefault(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::_Image_default_instance_.ndarray_ = const_cast< ::NDArray*>(
      ::NDArray::internal_default_instance());
  ::_Image_default_instance_.decoded_bytes_.UnsafeSetDefault(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
class Image::_Internal {
 public:
  static const ::NDArray& ndarray(const Image* msg);
};

const ::NDArray&
Image::_Internal::ndarray(const Image* msg) {
  return *msg->data_.ndarray_;
}
void Image::set_allocated_ndarray(::NDArray* ndarray) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  clear_data();
  if (ndarray) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(ndarray)->GetArena();
    if (message_arena != submessage_arena) {
      ndarray = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, ndarray, submessage_arena);
    }
    set_has_ndarray();
    data_.ndarray_ = ndarray;
  }
  // @@protoc_insertion_point(field_set_allocated:Image.ndarray)
}
void Image::clear_ndarray() {
  if (_internal_has_ndarray()) {
    if (GetArena() == nullptr) {
      delete data_.ndarray_;
    }
    clear_has_data();
  }
}
Image::Image(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:Image)
}
Image::Image(const Image& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_name().empty()) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_name(),
      GetArena());
  }
  url_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_url().empty()) {
    url_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_url(),
      GetArena());
  }
  hosted_orig_url_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_hosted_orig_url().empty()) {
    hosted_orig_url_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_hosted_orig_url(),
      GetArena());
  }
  hosted_small_url_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_hosted_small_url().empty()) {
    hosted_small_url_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_hosted_small_url(),
      GetArena());
  }
  hosted_large_url_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_hosted_large_url().empty()) {
    hosted_large_url_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_hosted_large_url(),
      GetArena());
  }
  hosted_tiny_url_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_hosted_tiny_url().empty()) {
    hosted_tiny_url_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_hosted_tiny_url(),
      GetArena());
  }
  ::memcpy(&width_, &from.width_,
    static_cast<size_t>(reinterpret_cast<char*>(&max_value_) -
    reinterpret_cast<char*>(&width_)) + sizeof(max_value_));
  clear_has_data();
  switch (from.data_case()) {
    case kEncodedBytes: {
      _internal_set_encoded_bytes(from._internal_encoded_bytes());
      break;
    }
    case kNdarray: {
      _internal_mutable_ndarray()->::NDArray::MergeFrom(from._internal_ndarray());
      break;
    }
    case kDecodedBytes: {
      _internal_set_decoded_bytes(from._internal_decoded_bytes());
      break;
    }
    case DATA_NOT_SET: {
      break;
    }
  }
  // @@protoc_insertion_point(copy_constructor:Image)
}

void Image::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Image_proto_2futils_2fimage_2eproto.base);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  url_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  hosted_orig_url_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  hosted_small_url_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  hosted_large_url_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  hosted_tiny_url_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&width_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&max_value_) -
      reinterpret_cast<char*>(&width_)) + sizeof(max_value_));
  clear_has_data();
}

Image::~Image() {
  // @@protoc_insertion_point(destructor:Image)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Image::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  url_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  hosted_orig_url_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  hosted_small_url_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  hosted_large_url_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  hosted_tiny_url_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (has_data()) {
    clear_data();
  }
}

void Image::ArenaDtor(void* object) {
  Image* _this = reinterpret_cast< Image* >(object);
  (void)_this;
}
void Image::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Image::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Image& Image::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Image_proto_2futils_2fimage_2eproto.base);
  return *internal_default_instance();
}


void Image::clear_data() {
// @@protoc_insertion_point(one_of_clear_start:Image)
  switch (data_case()) {
    case kEncodedBytes: {
      data_.encoded_bytes_.Destroy(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
      break;
    }
    case kNdarray: {
      if (GetArena() == nullptr) {
        delete data_.ndarray_;
      }
      break;
    }
    case kDecodedBytes: {
      data_.decoded_bytes_.Destroy(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
      break;
    }
    case DATA_NOT_SET: {
      break;
    }
  }
  _oneof_case_[0] = DATA_NOT_SET;
}


void Image::Clear() {
// @@protoc_insertion_point(message_clear_start:Image)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  url_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  hosted_orig_url_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  hosted_small_url_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  hosted_large_url_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  hosted_tiny_url_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::memset(&width_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&max_value_) -
      reinterpret_cast<char*>(&width_)) + sizeof(max_value_));
  clear_data();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Image::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Image.name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bytes encoded_bytes = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_encoded_bytes();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .NDArray ndarray = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr = ctx->ParseMessage(_internal_mutable_ndarray(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string url = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          auto str = _internal_mutable_url();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Image.url"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bytes decoded_bytes = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          auto str = _internal_mutable_decoded_bytes();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string hosted_orig_url = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 50)) {
          auto str = _internal_mutable_hosted_orig_url();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Image.hosted_orig_url"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string hosted_small_url = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 58)) {
          auto str = _internal_mutable_hosted_small_url();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Image.hosted_small_url"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string hosted_large_url = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 66)) {
          auto str = _internal_mutable_hosted_large_url();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Image.hosted_large_url"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string hosted_tiny_url = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 74)) {
          auto str = _internal_mutable_hosted_tiny_url();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Image.hosted_tiny_url"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 width = 1000;
      case 1000:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 64)) {
          width_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 height = 1001;
      case 1001:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 72)) {
          height_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 colors = 1002;
      case 1002:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 80)) {
          colors_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // float mean_value = 1003;
      case 1003:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 93)) {
          mean_value_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float min_value = 1004;
      case 1004:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 101)) {
          min_value_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float max_value = 1005;
      case 1005:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 109)) {
          max_value_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
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

::PROTOBUF_NAMESPACE_ID::uint8* Image::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Image)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (this->name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Image.name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_name(), target);
  }

  // bytes encoded_bytes = 2;
  if (_internal_has_encoded_bytes()) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_encoded_bytes(), target);
  }

  // .NDArray ndarray = 3;
  if (_internal_has_ndarray()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        3, _Internal::ndarray(this), target, stream);
  }

  // string url = 4;
  if (this->url().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_url().data(), static_cast<int>(this->_internal_url().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Image.url");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_url(), target);
  }

  // bytes decoded_bytes = 5;
  if (_internal_has_decoded_bytes()) {
    target = stream->WriteBytesMaybeAliased(
        5, this->_internal_decoded_bytes(), target);
  }

  // string hosted_orig_url = 6;
  if (this->hosted_orig_url().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_hosted_orig_url().data(), static_cast<int>(this->_internal_hosted_orig_url().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Image.hosted_orig_url");
    target = stream->WriteStringMaybeAliased(
        6, this->_internal_hosted_orig_url(), target);
  }

  // string hosted_small_url = 7;
  if (this->hosted_small_url().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_hosted_small_url().data(), static_cast<int>(this->_internal_hosted_small_url().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Image.hosted_small_url");
    target = stream->WriteStringMaybeAliased(
        7, this->_internal_hosted_small_url(), target);
  }

  // string hosted_large_url = 8;
  if (this->hosted_large_url().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_hosted_large_url().data(), static_cast<int>(this->_internal_hosted_large_url().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Image.hosted_large_url");
    target = stream->WriteStringMaybeAliased(
        8, this->_internal_hosted_large_url(), target);
  }

  // string hosted_tiny_url = 9;
  if (this->hosted_tiny_url().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_hosted_tiny_url().data(), static_cast<int>(this->_internal_hosted_tiny_url().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Image.hosted_tiny_url");
    target = stream->WriteStringMaybeAliased(
        9, this->_internal_hosted_tiny_url(), target);
  }

  // int32 width = 1000;
  if (this->width() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1000, this->_internal_width(), target);
  }

  // int32 height = 1001;
  if (this->height() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1001, this->_internal_height(), target);
  }

  // int32 colors = 1002;
  if (this->colors() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1002, this->_internal_colors(), target);
  }

  // float mean_value = 1003;
  if (!(this->mean_value() <= 0 && this->mean_value() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(1003, this->_internal_mean_value(), target);
  }

  // float min_value = 1004;
  if (!(this->min_value() <= 0 && this->min_value() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(1004, this->_internal_min_value(), target);
  }

  // float max_value = 1005;
  if (!(this->max_value() <= 0 && this->max_value() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(1005, this->_internal_max_value(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Image)
  return target;
}

size_t Image::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Image)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string name = 1;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // string url = 4;
  if (this->url().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_url());
  }

  // string hosted_orig_url = 6;
  if (this->hosted_orig_url().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_hosted_orig_url());
  }

  // string hosted_small_url = 7;
  if (this->hosted_small_url().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_hosted_small_url());
  }

  // string hosted_large_url = 8;
  if (this->hosted_large_url().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_hosted_large_url());
  }

  // string hosted_tiny_url = 9;
  if (this->hosted_tiny_url().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_hosted_tiny_url());
  }

  // int32 width = 1000;
  if (this->width() != 0) {
    total_size += 2 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_width());
  }

  // int32 height = 1001;
  if (this->height() != 0) {
    total_size += 2 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_height());
  }

  // int32 colors = 1002;
  if (this->colors() != 0) {
    total_size += 2 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_colors());
  }

  // float mean_value = 1003;
  if (!(this->mean_value() <= 0 && this->mean_value() >= 0)) {
    total_size += 2 + 4;
  }

  // float min_value = 1004;
  if (!(this->min_value() <= 0 && this->min_value() >= 0)) {
    total_size += 2 + 4;
  }

  // float max_value = 1005;
  if (!(this->max_value() <= 0 && this->max_value() >= 0)) {
    total_size += 2 + 4;
  }

  switch (data_case()) {
    // bytes encoded_bytes = 2;
    case kEncodedBytes: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
          this->_internal_encoded_bytes());
      break;
    }
    // .NDArray ndarray = 3;
    case kNdarray: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *data_.ndarray_);
      break;
    }
    // bytes decoded_bytes = 5;
    case kDecodedBytes: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
          this->_internal_decoded_bytes());
      break;
    }
    case DATA_NOT_SET: {
      break;
    }
  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Image::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Image)
  GOOGLE_DCHECK_NE(&from, this);
  const Image* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Image>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Image)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Image)
    MergeFrom(*source);
  }
}

void Image::MergeFrom(const Image& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Image)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.name().size() > 0) {
    _internal_set_name(from._internal_name());
  }
  if (from.url().size() > 0) {
    _internal_set_url(from._internal_url());
  }
  if (from.hosted_orig_url().size() > 0) {
    _internal_set_hosted_orig_url(from._internal_hosted_orig_url());
  }
  if (from.hosted_small_url().size() > 0) {
    _internal_set_hosted_small_url(from._internal_hosted_small_url());
  }
  if (from.hosted_large_url().size() > 0) {
    _internal_set_hosted_large_url(from._internal_hosted_large_url());
  }
  if (from.hosted_tiny_url().size() > 0) {
    _internal_set_hosted_tiny_url(from._internal_hosted_tiny_url());
  }
  if (from.width() != 0) {
    _internal_set_width(from._internal_width());
  }
  if (from.height() != 0) {
    _internal_set_height(from._internal_height());
  }
  if (from.colors() != 0) {
    _internal_set_colors(from._internal_colors());
  }
  if (!(from.mean_value() <= 0 && from.mean_value() >= 0)) {
    _internal_set_mean_value(from._internal_mean_value());
  }
  if (!(from.min_value() <= 0 && from.min_value() >= 0)) {
    _internal_set_min_value(from._internal_min_value());
  }
  if (!(from.max_value() <= 0 && from.max_value() >= 0)) {
    _internal_set_max_value(from._internal_max_value());
  }
  switch (from.data_case()) {
    case kEncodedBytes: {
      _internal_set_encoded_bytes(from._internal_encoded_bytes());
      break;
    }
    case kNdarray: {
      _internal_mutable_ndarray()->::NDArray::MergeFrom(from._internal_ndarray());
      break;
    }
    case kDecodedBytes: {
      _internal_set_decoded_bytes(from._internal_decoded_bytes());
      break;
    }
    case DATA_NOT_SET: {
      break;
    }
  }
}

void Image::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Image)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Image::CopyFrom(const Image& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Image)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Image::IsInitialized() const {
  return true;
}

void Image::InternalSwap(Image* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  name_.Swap(&other->name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  url_.Swap(&other->url_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  hosted_orig_url_.Swap(&other->hosted_orig_url_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  hosted_small_url_.Swap(&other->hosted_small_url_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  hosted_large_url_.Swap(&other->hosted_large_url_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  hosted_tiny_url_.Swap(&other->hosted_tiny_url_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Image, max_value_)
      + sizeof(Image::max_value_)
      - PROTOBUF_FIELD_OFFSET(Image, width_)>(
          reinterpret_cast<char*>(&width_),
          reinterpret_cast<char*>(&other->width_));
  swap(data_, other->data_);
  swap(_oneof_case_[0], other->_oneof_case_[0]);
}

::PROTOBUF_NAMESPACE_ID::Metadata Image::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Image* Arena::CreateMaybeMessage< ::Image >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Image >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
