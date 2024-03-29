// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: chat.base.proto

#ifndef PROTOBUF_INCLUDED_chat_2ebase_2eproto
#define PROTOBUF_INCLUDED_chat_2ebase_2eproto

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
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_chat_2ebase_2eproto 

namespace protobuf_chat_2ebase_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_chat_2ebase_2eproto
namespace ChatPb {
}  // namespace ChatPb
namespace ChatPb {

enum CMD {
  CMD_ZERO = 0,
  CMD_PING = 1,
  CMD_PONG = 2,
  CMD_AUTHORIZE_REQ = 101,
  CMD_AUTHORIZE_RES = 102,
  CMD_CONTACTS_REQ = 103,
  CMD_CONTACTS_RES = 104,
  CMD_UNRECEIVE_REQ = 105,
  CMD_UNRECEIVE_RES = 106,
  CMD_MESSAGE_TRANSFER = 108,
  CMD_MESSAGE_ACK = 110,
  CMD_NOTIFY_TRANSFER = 112,
  CMD_NOTIFY_ACK = 114,
  CMD_REFRESH_PROFILE_REQ = 115,
  CMD_REFRESH_PROFILE_RES = 116,
  CMD_SEARCH_USER_REQ = 117,
  CMD_SEARCH_USER_RES = 118,
  CMD_APPLY_FRIEND_REQ = 119,
  CMD_APPLY_FRIEND_RES = 120,
  CMD_AGREE_FRIEND_REQ = 121,
  CMD_AGREE_FRIEND_RES = 122,
  CMD_DELETE_FRIEND_REQ = 123,
  CMD_DELETE_FRIEND_RES = 124,
  CMD_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  CMD_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool CMD_IsValid(int value);
const CMD CMD_MIN = CMD_ZERO;
const CMD CMD_MAX = CMD_DELETE_FRIEND_RES;
const int CMD_ARRAYSIZE = CMD_MAX + 1;

const ::google::protobuf::EnumDescriptor* CMD_descriptor();
inline const ::std::string& CMD_Name(CMD value) {
  return ::google::protobuf::internal::NameOfEnum(
    CMD_descriptor(), value);
}
inline bool CMD_Parse(
    const ::std::string& name, CMD* value) {
  return ::google::protobuf::internal::ParseNamedEnum<CMD>(
    CMD_descriptor(), name, value);
}
enum ErrorCode {
  ERR_NONE = 0,
  ErrorCode_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  ErrorCode_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool ErrorCode_IsValid(int value);
const ErrorCode ErrorCode_MIN = ERR_NONE;
const ErrorCode ErrorCode_MAX = ERR_NONE;
const int ErrorCode_ARRAYSIZE = ErrorCode_MAX + 1;

const ::google::protobuf::EnumDescriptor* ErrorCode_descriptor();
inline const ::std::string& ErrorCode_Name(ErrorCode value) {
  return ::google::protobuf::internal::NameOfEnum(
    ErrorCode_descriptor(), value);
}
inline bool ErrorCode_Parse(
    const ::std::string& name, ErrorCode* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ErrorCode>(
    ErrorCode_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace ChatPb

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::ChatPb::CMD> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::ChatPb::CMD>() {
  return ::ChatPb::CMD_descriptor();
}
template <> struct is_proto_enum< ::ChatPb::ErrorCode> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::ChatPb::ErrorCode>() {
  return ::ChatPb::ErrorCode_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_chat_2ebase_2eproto
