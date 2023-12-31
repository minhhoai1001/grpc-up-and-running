// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: order_management.proto

#include "order_management.pb.h"

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

PROTOBUF_PRAGMA_INIT_SEG
namespace ecommerce {
constexpr Order::Order(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : items_()
  , id_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , description_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , destination_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , price_(0){}
struct OrderDefaultTypeInternal {
  constexpr OrderDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~OrderDefaultTypeInternal() {}
  union {
    Order _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT OrderDefaultTypeInternal _Order_default_instance_;
constexpr CombinedShipment::CombinedShipment(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : orderslist_()
  , id_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , status_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct CombinedShipmentDefaultTypeInternal {
  constexpr CombinedShipmentDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~CombinedShipmentDefaultTypeInternal() {}
  union {
    CombinedShipment _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT CombinedShipmentDefaultTypeInternal _CombinedShipment_default_instance_;
}  // namespace ecommerce
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_order_5fmanagement_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_order_5fmanagement_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_order_5fmanagement_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_order_5fmanagement_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ecommerce::Order, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::ecommerce::Order, id_),
  PROTOBUF_FIELD_OFFSET(::ecommerce::Order, items_),
  PROTOBUF_FIELD_OFFSET(::ecommerce::Order, description_),
  PROTOBUF_FIELD_OFFSET(::ecommerce::Order, price_),
  PROTOBUF_FIELD_OFFSET(::ecommerce::Order, destination_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ecommerce::CombinedShipment, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::ecommerce::CombinedShipment, id_),
  PROTOBUF_FIELD_OFFSET(::ecommerce::CombinedShipment, status_),
  PROTOBUF_FIELD_OFFSET(::ecommerce::CombinedShipment, orderslist_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::ecommerce::Order)},
  { 10, -1, sizeof(::ecommerce::CombinedShipment)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::ecommerce::_Order_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::ecommerce::_CombinedShipment_default_instance_),
};

const char descriptor_table_protodef_order_5fmanagement_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\026order_management.proto\022\tecommerce\032\036goo"
  "gle/protobuf/wrappers.proto\"[\n\005Order\022\n\n\002"
  "id\030\001 \001(\t\022\r\n\005items\030\002 \003(\t\022\023\n\013description\030\003"
  " \001(\t\022\r\n\005price\030\004 \001(\002\022\023\n\013destination\030\005 \001(\t"
  "\"T\n\020CombinedShipment\022\n\n\002id\030\001 \001(\t\022\016\n\006stat"
  "us\030\002 \001(\t\022$\n\nordersList\030\003 \003(\0132\020.ecommerce"
  ".Order2\335\002\n\017OrderManagement\022:\n\010addOrder\022\020"
  ".ecommerce.Order\032\034.google.protobuf.Strin"
  "gValue\022:\n\010getOrder\022\034.google.protobuf.Str"
  "ingValue\032\020.ecommerce.Order\022@\n\014searchOrde"
  "rs\022\034.google.protobuf.StringValue\032\020.ecomm"
  "erce.Order0\001\022@\n\014updateOrders\022\020.ecommerce"
  ".Order\032\034.google.protobuf.StringValue(\001\022N"
  "\n\rprocessOrders\022\034.google.protobuf.String"
  "Value\032\033.ecommerce.CombinedShipment(\0010\001b\006"
  "proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_order_5fmanagement_2eproto_deps[1] = {
  &::descriptor_table_google_2fprotobuf_2fwrappers_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_order_5fmanagement_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_order_5fmanagement_2eproto = {
  false, false, 606, descriptor_table_protodef_order_5fmanagement_2eproto, "order_management.proto", 
  &descriptor_table_order_5fmanagement_2eproto_once, descriptor_table_order_5fmanagement_2eproto_deps, 1, 2,
  schemas, file_default_instances, TableStruct_order_5fmanagement_2eproto::offsets,
  file_level_metadata_order_5fmanagement_2eproto, file_level_enum_descriptors_order_5fmanagement_2eproto, file_level_service_descriptors_order_5fmanagement_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK ::PROTOBUF_NAMESPACE_ID::Metadata
descriptor_table_order_5fmanagement_2eproto_metadata_getter(int index) {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_order_5fmanagement_2eproto);
  return descriptor_table_order_5fmanagement_2eproto.file_level_metadata[index];
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_order_5fmanagement_2eproto(&descriptor_table_order_5fmanagement_2eproto);
namespace ecommerce {

// ===================================================================

class Order::_Internal {
 public:
};

Order::Order(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  items_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:ecommerce.Order)
}
Order::Order(const Order& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      items_(from.items_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_id().empty()) {
    id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_id(), 
      GetArena());
  }
  description_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_description().empty()) {
    description_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_description(), 
      GetArena());
  }
  destination_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_destination().empty()) {
    destination_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_destination(), 
      GetArena());
  }
  price_ = from.price_;
  // @@protoc_insertion_point(copy_constructor:ecommerce.Order)
}

void Order::SharedCtor() {
id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
description_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
destination_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
price_ = 0;
}

Order::~Order() {
  // @@protoc_insertion_point(destructor:ecommerce.Order)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Order::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  description_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  destination_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Order::ArenaDtor(void* object) {
  Order* _this = reinterpret_cast< Order* >(object);
  (void)_this;
}
void Order::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Order::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Order::Clear() {
// @@protoc_insertion_point(message_clear_start:ecommerce.Order)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  items_.Clear();
  id_.ClearToEmpty();
  description_.ClearToEmpty();
  destination_.ClearToEmpty();
  price_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Order::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_id();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ecommerce.Order.id"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated string items = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_items();
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
            CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ecommerce.Order.items"));
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else goto handle_unusual;
        continue;
      // string description = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_description();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ecommerce.Order.description"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // float price = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 37)) {
          price_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // string destination = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          auto str = _internal_mutable_destination();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ecommerce.Order.destination"));
          CHK_(ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* Order::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ecommerce.Order)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string id = 1;
  if (this->id().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_id().data(), static_cast<int>(this->_internal_id().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "ecommerce.Order.id");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_id(), target);
  }

  // repeated string items = 2;
  for (int i = 0, n = this->_internal_items_size(); i < n; i++) {
    const auto& s = this->_internal_items(i);
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      s.data(), static_cast<int>(s.length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "ecommerce.Order.items");
    target = stream->WriteString(2, s, target);
  }

  // string description = 3;
  if (this->description().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_description().data(), static_cast<int>(this->_internal_description().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "ecommerce.Order.description");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_description(), target);
  }

  // float price = 4;
  if (!(this->price() <= 0 && this->price() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(4, this->_internal_price(), target);
  }

  // string destination = 5;
  if (this->destination().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_destination().data(), static_cast<int>(this->_internal_destination().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "ecommerce.Order.destination");
    target = stream->WriteStringMaybeAliased(
        5, this->_internal_destination(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ecommerce.Order)
  return target;
}

size_t Order::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ecommerce.Order)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated string items = 2;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(items_.size());
  for (int i = 0, n = items_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
      items_.Get(i));
  }

  // string id = 1;
  if (this->id().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_id());
  }

  // string description = 3;
  if (this->description().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_description());
  }

  // string destination = 5;
  if (this->destination().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_destination());
  }

  // float price = 4;
  if (!(this->price() <= 0 && this->price() >= 0)) {
    total_size += 1 + 4;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Order::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ecommerce.Order)
  GOOGLE_DCHECK_NE(&from, this);
  const Order* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Order>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ecommerce.Order)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ecommerce.Order)
    MergeFrom(*source);
  }
}

void Order::MergeFrom(const Order& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ecommerce.Order)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  items_.MergeFrom(from.items_);
  if (from.id().size() > 0) {
    _internal_set_id(from._internal_id());
  }
  if (from.description().size() > 0) {
    _internal_set_description(from._internal_description());
  }
  if (from.destination().size() > 0) {
    _internal_set_destination(from._internal_destination());
  }
  if (!(from.price() <= 0 && from.price() >= 0)) {
    _internal_set_price(from._internal_price());
  }
}

void Order::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ecommerce.Order)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Order::CopyFrom(const Order& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ecommerce.Order)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Order::IsInitialized() const {
  return true;
}

void Order::InternalSwap(Order* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  items_.InternalSwap(&other->items_);
  id_.Swap(&other->id_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  description_.Swap(&other->description_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  destination_.Swap(&other->destination_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  swap(price_, other->price_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Order::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

class CombinedShipment::_Internal {
 public:
};

CombinedShipment::CombinedShipment(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  orderslist_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:ecommerce.CombinedShipment)
}
CombinedShipment::CombinedShipment(const CombinedShipment& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      orderslist_(from.orderslist_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_id().empty()) {
    id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_id(), 
      GetArena());
  }
  status_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_status().empty()) {
    status_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_status(), 
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:ecommerce.CombinedShipment)
}

void CombinedShipment::SharedCtor() {
id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
status_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

CombinedShipment::~CombinedShipment() {
  // @@protoc_insertion_point(destructor:ecommerce.CombinedShipment)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void CombinedShipment::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  status_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void CombinedShipment::ArenaDtor(void* object) {
  CombinedShipment* _this = reinterpret_cast< CombinedShipment* >(object);
  (void)_this;
}
void CombinedShipment::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void CombinedShipment::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void CombinedShipment::Clear() {
// @@protoc_insertion_point(message_clear_start:ecommerce.CombinedShipment)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  orderslist_.Clear();
  id_.ClearToEmpty();
  status_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* CombinedShipment::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_id();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ecommerce.CombinedShipment.id"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string status = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_status();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ecommerce.CombinedShipment.status"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .ecommerce.Order ordersList = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_orderslist(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<26>(ptr));
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

::PROTOBUF_NAMESPACE_ID::uint8* CombinedShipment::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ecommerce.CombinedShipment)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string id = 1;
  if (this->id().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_id().data(), static_cast<int>(this->_internal_id().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "ecommerce.CombinedShipment.id");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_id(), target);
  }

  // string status = 2;
  if (this->status().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_status().data(), static_cast<int>(this->_internal_status().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "ecommerce.CombinedShipment.status");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_status(), target);
  }

  // repeated .ecommerce.Order ordersList = 3;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_orderslist_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(3, this->_internal_orderslist(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ecommerce.CombinedShipment)
  return target;
}

size_t CombinedShipment::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ecommerce.CombinedShipment)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .ecommerce.Order ordersList = 3;
  total_size += 1UL * this->_internal_orderslist_size();
  for (const auto& msg : this->orderslist_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // string id = 1;
  if (this->id().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_id());
  }

  // string status = 2;
  if (this->status().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_status());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void CombinedShipment::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ecommerce.CombinedShipment)
  GOOGLE_DCHECK_NE(&from, this);
  const CombinedShipment* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<CombinedShipment>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ecommerce.CombinedShipment)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ecommerce.CombinedShipment)
    MergeFrom(*source);
  }
}

void CombinedShipment::MergeFrom(const CombinedShipment& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ecommerce.CombinedShipment)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  orderslist_.MergeFrom(from.orderslist_);
  if (from.id().size() > 0) {
    _internal_set_id(from._internal_id());
  }
  if (from.status().size() > 0) {
    _internal_set_status(from._internal_status());
  }
}

void CombinedShipment::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ecommerce.CombinedShipment)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CombinedShipment::CopyFrom(const CombinedShipment& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ecommerce.CombinedShipment)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CombinedShipment::IsInitialized() const {
  return true;
}

void CombinedShipment::InternalSwap(CombinedShipment* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  orderslist_.InternalSwap(&other->orderslist_);
  id_.Swap(&other->id_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  status_.Swap(&other->status_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

::PROTOBUF_NAMESPACE_ID::Metadata CombinedShipment::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace ecommerce
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::ecommerce::Order* Arena::CreateMaybeMessage< ::ecommerce::Order >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ecommerce::Order >(arena);
}
template<> PROTOBUF_NOINLINE ::ecommerce::CombinedShipment* Arena::CreateMaybeMessage< ::ecommerce::CombinedShipment >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ecommerce::CombinedShipment >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
