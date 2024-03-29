// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: chat.authenticate.proto

#ifndef PROTOBUF_INCLUDED_chat_2eauthenticate_2eproto
#define PROTOBUF_INCLUDED_chat_2eauthenticate_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "chat.base.pb.h"
#include "chat.user.pb.h"
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_chat_2eauthenticate_2eproto 

namespace protobuf_chat_2eauthenticate_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_chat_2eauthenticate_2eproto
namespace ChatPb {
class AuthenticateREQ;
class AuthenticateREQDefaultTypeInternal;
extern AuthenticateREQDefaultTypeInternal _AuthenticateREQ_default_instance_;
class AuthenticateRES;
class AuthenticateRESDefaultTypeInternal;
extern AuthenticateRESDefaultTypeInternal _AuthenticateRES_default_instance_;
}  // namespace ChatPb
namespace google {
namespace protobuf {
template<> ::ChatPb::AuthenticateREQ* Arena::CreateMaybeMessage<::ChatPb::AuthenticateREQ>(Arena*);
template<> ::ChatPb::AuthenticateRES* Arena::CreateMaybeMessage<::ChatPb::AuthenticateRES>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace ChatPb {

// ===================================================================

class AuthenticateREQ : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ChatPb.AuthenticateREQ) */ {
 public:
  AuthenticateREQ();
  virtual ~AuthenticateREQ();

  AuthenticateREQ(const AuthenticateREQ& from);

  inline AuthenticateREQ& operator=(const AuthenticateREQ& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  AuthenticateREQ(AuthenticateREQ&& from) noexcept
    : AuthenticateREQ() {
    *this = ::std::move(from);
  }

  inline AuthenticateREQ& operator=(AuthenticateREQ&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const AuthenticateREQ& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const AuthenticateREQ* internal_default_instance() {
    return reinterpret_cast<const AuthenticateREQ*>(
               &_AuthenticateREQ_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(AuthenticateREQ* other);
  friend void swap(AuthenticateREQ& a, AuthenticateREQ& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline AuthenticateREQ* New() const final {
    return CreateMaybeMessage<AuthenticateREQ>(NULL);
  }

  AuthenticateREQ* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<AuthenticateREQ>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const AuthenticateREQ& from);
  void MergeFrom(const AuthenticateREQ& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(AuthenticateREQ* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string openId = 1;
  void clear_openid();
  static const int kOpenIdFieldNumber = 1;
  const ::std::string& openid() const;
  void set_openid(const ::std::string& value);
  #if LANG_CXX11
  void set_openid(::std::string&& value);
  #endif
  void set_openid(const char* value);
  void set_openid(const char* value, size_t size);
  ::std::string* mutable_openid();
  ::std::string* release_openid();
  void set_allocated_openid(::std::string* openid);

  // string accessToken = 2;
  void clear_accesstoken();
  static const int kAccessTokenFieldNumber = 2;
  const ::std::string& accesstoken() const;
  void set_accesstoken(const ::std::string& value);
  #if LANG_CXX11
  void set_accesstoken(::std::string&& value);
  #endif
  void set_accesstoken(const char* value);
  void set_accesstoken(const char* value, size_t size);
  ::std::string* mutable_accesstoken();
  ::std::string* release_accesstoken();
  void set_allocated_accesstoken(::std::string* accesstoken);

  // string appId = 3;
  void clear_appid();
  static const int kAppIdFieldNumber = 3;
  const ::std::string& appid() const;
  void set_appid(const ::std::string& value);
  #if LANG_CXX11
  void set_appid(::std::string&& value);
  #endif
  void set_appid(const char* value);
  void set_appid(const char* value, size_t size);
  ::std::string* mutable_appid();
  ::std::string* release_appid();
  void set_allocated_appid(::std::string* appid);

  // @@protoc_insertion_point(class_scope:ChatPb.AuthenticateREQ)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr openid_;
  ::google::protobuf::internal::ArenaStringPtr accesstoken_;
  ::google::protobuf::internal::ArenaStringPtr appid_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_chat_2eauthenticate_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class AuthenticateRES : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ChatPb.AuthenticateRES) */ {
 public:
  AuthenticateRES();
  virtual ~AuthenticateRES();

  AuthenticateRES(const AuthenticateRES& from);

  inline AuthenticateRES& operator=(const AuthenticateRES& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  AuthenticateRES(AuthenticateRES&& from) noexcept
    : AuthenticateRES() {
    *this = ::std::move(from);
  }

  inline AuthenticateRES& operator=(AuthenticateRES&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const AuthenticateRES& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const AuthenticateRES* internal_default_instance() {
    return reinterpret_cast<const AuthenticateRES*>(
               &_AuthenticateRES_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(AuthenticateRES* other);
  friend void swap(AuthenticateRES& a, AuthenticateRES& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline AuthenticateRES* New() const final {
    return CreateMaybeMessage<AuthenticateRES>(NULL);
  }

  AuthenticateRES* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<AuthenticateRES>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const AuthenticateRES& from);
  void MergeFrom(const AuthenticateRES& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(AuthenticateRES* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string message = 3;
  void clear_message();
  static const int kMessageFieldNumber = 3;
  const ::std::string& message() const;
  void set_message(const ::std::string& value);
  #if LANG_CXX11
  void set_message(::std::string&& value);
  #endif
  void set_message(const char* value);
  void set_message(const char* value, size_t size);
  ::std::string* mutable_message();
  ::std::string* release_message();
  void set_allocated_message(::std::string* message);

  // .ChatPb.User user = 2;
  bool has_user() const;
  void clear_user();
  static const int kUserFieldNumber = 2;
  private:
  const ::ChatPb::User& _internal_user() const;
  public:
  const ::ChatPb::User& user() const;
  ::ChatPb::User* release_user();
  ::ChatPb::User* mutable_user();
  void set_allocated_user(::ChatPb::User* user);

  // bool authorized = 1;
  void clear_authorized();
  static const int kAuthorizedFieldNumber = 1;
  bool authorized() const;
  void set_authorized(bool value);

  // .ChatPb.ErrorCode code = 4;
  void clear_code();
  static const int kCodeFieldNumber = 4;
  ::ChatPb::ErrorCode code() const;
  void set_code(::ChatPb::ErrorCode value);

  // @@protoc_insertion_point(class_scope:ChatPb.AuthenticateRES)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr message_;
  ::ChatPb::User* user_;
  bool authorized_;
  int code_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_chat_2eauthenticate_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// AuthenticateREQ

// string openId = 1;
inline void AuthenticateREQ::clear_openid() {
  openid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& AuthenticateREQ::openid() const {
  // @@protoc_insertion_point(field_get:ChatPb.AuthenticateREQ.openId)
  return openid_.GetNoArena();
}
inline void AuthenticateREQ::set_openid(const ::std::string& value) {
  
  openid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ChatPb.AuthenticateREQ.openId)
}
#if LANG_CXX11
inline void AuthenticateREQ::set_openid(::std::string&& value) {
  
  openid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:ChatPb.AuthenticateREQ.openId)
}
#endif
inline void AuthenticateREQ::set_openid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  openid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ChatPb.AuthenticateREQ.openId)
}
inline void AuthenticateREQ::set_openid(const char* value, size_t size) {
  
  openid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ChatPb.AuthenticateREQ.openId)
}
inline ::std::string* AuthenticateREQ::mutable_openid() {
  
  // @@protoc_insertion_point(field_mutable:ChatPb.AuthenticateREQ.openId)
  return openid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* AuthenticateREQ::release_openid() {
  // @@protoc_insertion_point(field_release:ChatPb.AuthenticateREQ.openId)
  
  return openid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void AuthenticateREQ::set_allocated_openid(::std::string* openid) {
  if (openid != NULL) {
    
  } else {
    
  }
  openid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), openid);
  // @@protoc_insertion_point(field_set_allocated:ChatPb.AuthenticateREQ.openId)
}

// string accessToken = 2;
inline void AuthenticateREQ::clear_accesstoken() {
  accesstoken_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& AuthenticateREQ::accesstoken() const {
  // @@protoc_insertion_point(field_get:ChatPb.AuthenticateREQ.accessToken)
  return accesstoken_.GetNoArena();
}
inline void AuthenticateREQ::set_accesstoken(const ::std::string& value) {
  
  accesstoken_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ChatPb.AuthenticateREQ.accessToken)
}
#if LANG_CXX11
inline void AuthenticateREQ::set_accesstoken(::std::string&& value) {
  
  accesstoken_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:ChatPb.AuthenticateREQ.accessToken)
}
#endif
inline void AuthenticateREQ::set_accesstoken(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  accesstoken_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ChatPb.AuthenticateREQ.accessToken)
}
inline void AuthenticateREQ::set_accesstoken(const char* value, size_t size) {
  
  accesstoken_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ChatPb.AuthenticateREQ.accessToken)
}
inline ::std::string* AuthenticateREQ::mutable_accesstoken() {
  
  // @@protoc_insertion_point(field_mutable:ChatPb.AuthenticateREQ.accessToken)
  return accesstoken_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* AuthenticateREQ::release_accesstoken() {
  // @@protoc_insertion_point(field_release:ChatPb.AuthenticateREQ.accessToken)
  
  return accesstoken_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void AuthenticateREQ::set_allocated_accesstoken(::std::string* accesstoken) {
  if (accesstoken != NULL) {
    
  } else {
    
  }
  accesstoken_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), accesstoken);
  // @@protoc_insertion_point(field_set_allocated:ChatPb.AuthenticateREQ.accessToken)
}

// string appId = 3;
inline void AuthenticateREQ::clear_appid() {
  appid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& AuthenticateREQ::appid() const {
  // @@protoc_insertion_point(field_get:ChatPb.AuthenticateREQ.appId)
  return appid_.GetNoArena();
}
inline void AuthenticateREQ::set_appid(const ::std::string& value) {
  
  appid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ChatPb.AuthenticateREQ.appId)
}
#if LANG_CXX11
inline void AuthenticateREQ::set_appid(::std::string&& value) {
  
  appid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:ChatPb.AuthenticateREQ.appId)
}
#endif
inline void AuthenticateREQ::set_appid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  appid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ChatPb.AuthenticateREQ.appId)
}
inline void AuthenticateREQ::set_appid(const char* value, size_t size) {
  
  appid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ChatPb.AuthenticateREQ.appId)
}
inline ::std::string* AuthenticateREQ::mutable_appid() {
  
  // @@protoc_insertion_point(field_mutable:ChatPb.AuthenticateREQ.appId)
  return appid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* AuthenticateREQ::release_appid() {
  // @@protoc_insertion_point(field_release:ChatPb.AuthenticateREQ.appId)
  
  return appid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void AuthenticateREQ::set_allocated_appid(::std::string* appid) {
  if (appid != NULL) {
    
  } else {
    
  }
  appid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), appid);
  // @@protoc_insertion_point(field_set_allocated:ChatPb.AuthenticateREQ.appId)
}

// -------------------------------------------------------------------

// AuthenticateRES

// bool authorized = 1;
inline void AuthenticateRES::clear_authorized() {
  authorized_ = false;
}
inline bool AuthenticateRES::authorized() const {
  // @@protoc_insertion_point(field_get:ChatPb.AuthenticateRES.authorized)
  return authorized_;
}
inline void AuthenticateRES::set_authorized(bool value) {
  
  authorized_ = value;
  // @@protoc_insertion_point(field_set:ChatPb.AuthenticateRES.authorized)
}

// .ChatPb.User user = 2;
inline bool AuthenticateRES::has_user() const {
  return this != internal_default_instance() && user_ != NULL;
}
inline const ::ChatPb::User& AuthenticateRES::_internal_user() const {
  return *user_;
}
inline const ::ChatPb::User& AuthenticateRES::user() const {
  const ::ChatPb::User* p = user_;
  // @@protoc_insertion_point(field_get:ChatPb.AuthenticateRES.user)
  return p != NULL ? *p : *reinterpret_cast<const ::ChatPb::User*>(
      &::ChatPb::_User_default_instance_);
}
inline ::ChatPb::User* AuthenticateRES::release_user() {
  // @@protoc_insertion_point(field_release:ChatPb.AuthenticateRES.user)
  
  ::ChatPb::User* temp = user_;
  user_ = NULL;
  return temp;
}
inline ::ChatPb::User* AuthenticateRES::mutable_user() {
  
  if (user_ == NULL) {
    auto* p = CreateMaybeMessage<::ChatPb::User>(GetArenaNoVirtual());
    user_ = p;
  }
  // @@protoc_insertion_point(field_mutable:ChatPb.AuthenticateRES.user)
  return user_;
}
inline void AuthenticateRES::set_allocated_user(::ChatPb::User* user) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(user_);
  }
  if (user) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      user = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, user, submessage_arena);
    }
    
  } else {
    
  }
  user_ = user;
  // @@protoc_insertion_point(field_set_allocated:ChatPb.AuthenticateRES.user)
}

// string message = 3;
inline void AuthenticateRES::clear_message() {
  message_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& AuthenticateRES::message() const {
  // @@protoc_insertion_point(field_get:ChatPb.AuthenticateRES.message)
  return message_.GetNoArena();
}
inline void AuthenticateRES::set_message(const ::std::string& value) {
  
  message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ChatPb.AuthenticateRES.message)
}
#if LANG_CXX11
inline void AuthenticateRES::set_message(::std::string&& value) {
  
  message_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:ChatPb.AuthenticateRES.message)
}
#endif
inline void AuthenticateRES::set_message(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ChatPb.AuthenticateRES.message)
}
inline void AuthenticateRES::set_message(const char* value, size_t size) {
  
  message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ChatPb.AuthenticateRES.message)
}
inline ::std::string* AuthenticateRES::mutable_message() {
  
  // @@protoc_insertion_point(field_mutable:ChatPb.AuthenticateRES.message)
  return message_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* AuthenticateRES::release_message() {
  // @@protoc_insertion_point(field_release:ChatPb.AuthenticateRES.message)
  
  return message_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void AuthenticateRES::set_allocated_message(::std::string* message) {
  if (message != NULL) {
    
  } else {
    
  }
  message_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), message);
  // @@protoc_insertion_point(field_set_allocated:ChatPb.AuthenticateRES.message)
}

// .ChatPb.ErrorCode code = 4;
inline void AuthenticateRES::clear_code() {
  code_ = 0;
}
inline ::ChatPb::ErrorCode AuthenticateRES::code() const {
  // @@protoc_insertion_point(field_get:ChatPb.AuthenticateRES.code)
  return static_cast< ::ChatPb::ErrorCode >(code_);
}
inline void AuthenticateRES::set_code(::ChatPb::ErrorCode value) {
  
  code_ = value;
  // @@protoc_insertion_point(field_set:ChatPb.AuthenticateRES.code)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace ChatPb

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_chat_2eauthenticate_2eproto
