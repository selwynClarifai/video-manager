// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/clarifai/auth/scope/scope.proto

#include "proto/clarifai/auth/scope/scope.pb.h"

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
namespace clarifai {
namespace auth {
namespace scope {
class ScopeListDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ScopeList> _instance;
} _ScopeList_default_instance_;
}  // namespace scope
}  // namespace auth
}  // namespace clarifai
static void InitDefaultsscc_info_ScopeList_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::clarifai::auth::scope::_ScopeList_default_instance_;
    new (ptr) ::clarifai::auth::scope::ScopeList();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::clarifai::auth::scope::ScopeList::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ScopeList_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_ScopeList_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto[1];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::clarifai::auth::scope::ScopeList, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::clarifai::auth::scope::ScopeList, scopes_),
  PROTOBUF_FIELD_OFFSET(::clarifai::auth::scope::ScopeList, endpoints_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::clarifai::auth::scope::ScopeList)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::clarifai::auth::scope::_ScopeList_default_instance_),
};

const char descriptor_table_protodef_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n%proto/clarifai/auth/scope/scope.proto\022"
  "\023clarifai.auth.scope\032 google/protobuf/de"
  "scriptor.proto\"F\n\tScopeList\022&\n\006scopes\030\001 "
  "\003(\0162\026.clarifai.auth.scope.S\022\021\n\tendpoints"
  "\030\002 \003(\t*\367\t\n\001S\022\t\n\005undef\020\000\022\r\n\003All\020\001\032\004\360\233\'\001\022\021"
  "\n\007Predict\020\002\032\004\360\233\'\001\022\034\n\020Predict_Feedback\020\035\032"
  "\006\010\001\360\233\'\000\022\020\n\006Search\020\003\032\004\360\233\'\001\022\033\n\017Search_Feed"
  "back\020\034\032\006\010\001\360\233\'\000\022\030\n\nInputs_Add\020\004\032\010\360\233\'\001\370\233\'\005"
  "\022\024\n\nInputs_Get\020\005\032\004\360\233\'\001\022 \n\014Inputs_Patch\020\007"
  "\032\016\010\001\360\233\'\001\370\233\'\004\370\233\'\005\022\037\n\rInputs_Delete\020\010\032\014\360\233\'"
  "\001\370\233\'\004\370\233\'\005\022\035\n\rOutputs_Patch\020\t\032\n\010\001\370\233\'\005\370\233\'\002"
  "\022\032\n\014Concepts_Add\020\n\032\010\360\233\'\001\370\233\'\013\022\026\n\014Concepts"
  "_Get\020\013\032\004\360\233\'\001\022\"\n\016Concepts_Patch\020\014\032\016\010\001\360\233\'\001"
  "\370\233\'\n\370\233\'\013\022\035\n\017Concepts_Delete\020\r\032\010\370\233\'\n\370\233\'\013\022"
  "\030\n\nModels_Add\020\016\032\010\360\233\'\001\370\233\'\017\022\024\n\nModels_Get\020"
  "\017\032\004\360\233\'\001\022$\n\014Models_Patch\020\020\032\022\010\001\360\233\'\001\370\233\'\016\370\233\'"
  "\017\370\233\'\032\022\037\n\rModels_Delete\020\021\032\014\360\233\'\001\370\233\'\016\370\233\'\017\022\032"
  "\n\014Models_Train\020\032\032\010\360\233\'\001\370\233\'\017\022\025\n\013Models_Syn"
  "c\020\033\032\004\370\233\'\017\022\033\n\rModels_Deploy\020\"\032\010\360\233\'\001\370\233\'\017\022\033"
  "\n\rWorkflows_Add\020\022\032\010\360\233\'\001\370\233\'\023\022\027\n\rWorkflows"
  "_Get\020\023\032\004\360\233\'\001\022#\n\017Workflows_Patch\020\024\032\016\010\001\360\233\'"
  "\001\370\233\'\022\370\233\'\023\022\"\n\020Workflows_Delete\020\025\032\014\360\233\'\001\370\233\'"
  "\022\370\233\'\023\022\"\n\026TSNEVisualizations_Add\020\030\032\006\010\001\370\233\'"
  "\031\022\036\n\026TSNEVisualizations_Get\020\031\032\002\010\001\022\031\n\013Wor"
  "kers_Add\020\036\032\010\360\233\'\001\370\233\'\037\022\025\n\013Workers_Get\020\037\032\004\360"
  "\233\'\001\022 \n\016Workers_Delete\020 \032\014\360\233\'\001\370\233\'\036\370\233\'\037\022\027\n"
  "\rTemplates_Get\020!\032\004\360\233\'\001\022\035\n\017Annotations_Ad"
  "d\020%\032\010\360\233\'\001\370\233\'&\022\031\n\017Annotations_Get\020&\032\004\360\233\'\001"
  "\022%\n\021Annotations_Patch\020\'\032\016\010\001\360\233\'\001\370\233\'%\370\233\'&\022"
  "$\n\022Annotations_Delete\020(\032\014\360\233\'\001\370\233\'%\370\233\'&\022\034\n"
  "\016Collectors_Add\020)\032\010\360\233\'\000\370\233\'*\022\030\n\016Collector"
  "s_Get\020*\032\004\360\233\'\000\022#\n\021Collectors_Delete\020+\032\014\360\233"
  "\'\000\370\233\')\370\233\'*\022\026\n\010Apps_Add\020,\032\010\360\233\'\001\370\233\'-\022\022\n\010Ap"
  "ps_Get\020-\032\004\360\233\'\001\022\035\n\013Apps_Delete\020.\032\014\360\233\'\001\370\233\'"
  ",\370\233\'-\022\026\n\010Keys_Add\020/\032\010\360\233\'\001\370\233\'0\022\022\n\010Keys_Ge"
  "t\0200\032\004\360\233\'\001\022\035\n\013Keys_Delete\0201\032\014\360\233\'\001\370\233\'/\370\233\'0"
  ":<\n\017clarfai_exposed\022!.google.protobuf.En"
  "umValueOptions\030\276\363\004 \001(\010:^\n\031clarifai_depen"
  "ding_scopes\022!.google.protobuf.EnumValueO"
  "ptions\030\277\363\004 \003(\0162\026.clarifai.auth.scope.SB)"
  "\n\027com.clarifai.auth.scopeP\001Z\005scope\242\002\004CAI"
  "Pb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto_deps[1] = {
  &::descriptor_table_google_2fprotobuf_2fdescriptor_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto_sccs[1] = {
  &scc_info_ScopeList_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto = {
  false, false, descriptor_table_protodef_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto, "proto/clarifai/auth/scope/scope.proto", 1649,
  &descriptor_table_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto_once, descriptor_table_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto_sccs, descriptor_table_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto_deps, 1, 1,
  schemas, file_default_instances, TableStruct_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto::offsets,
  file_level_metadata_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto, 1, file_level_enum_descriptors_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto, file_level_service_descriptors_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto)), true);
namespace clarifai {
namespace auth {
namespace scope {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* S_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto);
  return file_level_enum_descriptors_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto[0];
}
bool S_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
      return true;
    default:
      return false;
  }
}


// ===================================================================

void ScopeList::InitAsDefaultInstance() {
}
class ScopeList::_Internal {
 public:
};

ScopeList::ScopeList(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  scopes_(arena),
  endpoints_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:clarifai.auth.scope.ScopeList)
}
ScopeList::ScopeList(const ScopeList& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      scopes_(from.scopes_),
      endpoints_(from.endpoints_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:clarifai.auth.scope.ScopeList)
}

void ScopeList::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ScopeList_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto.base);
}

ScopeList::~ScopeList() {
  // @@protoc_insertion_point(destructor:clarifai.auth.scope.ScopeList)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void ScopeList::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void ScopeList::ArenaDtor(void* object) {
  ScopeList* _this = reinterpret_cast< ScopeList* >(object);
  (void)_this;
}
void ScopeList::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ScopeList::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ScopeList& ScopeList::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ScopeList_proto_2fclarifai_2fauth_2fscope_2fscope_2eproto.base);
  return *internal_default_instance();
}


void ScopeList::Clear() {
// @@protoc_insertion_point(message_clear_start:clarifai.auth.scope.ScopeList)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  scopes_.Clear();
  endpoints_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ScopeList::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .clarifai.auth.scope.S scopes = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedEnumParser(_internal_mutable_scopes(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_add_scopes(static_cast<::clarifai::auth::scope::S>(val));
        } else goto handle_unusual;
        continue;
      // repeated string endpoints = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_endpoints();
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
            CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "clarifai.auth.scope.ScopeList.endpoints"));
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

::PROTOBUF_NAMESPACE_ID::uint8* ScopeList::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:clarifai.auth.scope.ScopeList)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .clarifai.auth.scope.S scopes = 1;
  {
    int byte_size = _scopes_cached_byte_size_.load(std::memory_order_relaxed);
    if (byte_size > 0) {
      target = stream->WriteEnumPacked(
          1, scopes_, byte_size, target);
    }
  }

  // repeated string endpoints = 2;
  for (int i = 0, n = this->_internal_endpoints_size(); i < n; i++) {
    const auto& s = this->_internal_endpoints(i);
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      s.data(), static_cast<int>(s.length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "clarifai.auth.scope.ScopeList.endpoints");
    target = stream->WriteString(2, s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:clarifai.auth.scope.ScopeList)
  return target;
}

size_t ScopeList::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:clarifai.auth.scope.ScopeList)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .clarifai.auth.scope.S scopes = 1;
  {
    size_t data_size = 0;
    unsigned int count = static_cast<unsigned int>(this->_internal_scopes_size());for (unsigned int i = 0; i < count; i++) {
      data_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(
        this->_internal_scopes(static_cast<int>(i)));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
            static_cast<::PROTOBUF_NAMESPACE_ID::int32>(data_size));
    }
    int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(data_size);
    _scopes_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  // repeated string endpoints = 2;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(endpoints_.size());
  for (int i = 0, n = endpoints_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
      endpoints_.Get(i));
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ScopeList::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:clarifai.auth.scope.ScopeList)
  GOOGLE_DCHECK_NE(&from, this);
  const ScopeList* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ScopeList>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:clarifai.auth.scope.ScopeList)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:clarifai.auth.scope.ScopeList)
    MergeFrom(*source);
  }
}

void ScopeList::MergeFrom(const ScopeList& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:clarifai.auth.scope.ScopeList)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  scopes_.MergeFrom(from.scopes_);
  endpoints_.MergeFrom(from.endpoints_);
}

void ScopeList::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:clarifai.auth.scope.ScopeList)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ScopeList::CopyFrom(const ScopeList& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:clarifai.auth.scope.ScopeList)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ScopeList::IsInitialized() const {
  return true;
}

void ScopeList::InternalSwap(ScopeList* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  scopes_.InternalSwap(&other->scopes_);
  endpoints_.InternalSwap(&other->endpoints_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ScopeList::GetMetadata() const {
  return GetMetadataStatic();
}

::PROTOBUF_NAMESPACE_ID::internal::ExtensionIdentifier< ::google::protobuf::EnumValueOptions,
    ::PROTOBUF_NAMESPACE_ID::internal::PrimitiveTypeTraits< bool >, 8, false >
  clarfai_exposed(kClarfaiExposedFieldNumber, false);
::PROTOBUF_NAMESPACE_ID::internal::ExtensionIdentifier< ::google::protobuf::EnumValueOptions,
    ::PROTOBUF_NAMESPACE_ID::internal::RepeatedEnumTypeTraits< ::clarifai::auth::scope::S, ::clarifai::auth::scope::S_IsValid>, 14, true >
  clarifai_depending_scopes(kClarifaiDependingScopesFieldNumber, static_cast< ::clarifai::auth::scope::S >(0));

// @@protoc_insertion_point(namespace_scope)
}  // namespace scope
}  // namespace auth
}  // namespace clarifai
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::clarifai::auth::scope::ScopeList* Arena::CreateMaybeMessage< ::clarifai::auth::scope::ScopeList >(Arena* arena) {
  return Arena::CreateMessageInternal< ::clarifai::auth::scope::ScopeList >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>