LOCAL_PATH := $(call my-dir)/..

#引用第三方库

include $(CLEAR_VARS)
LOCAL_MODULE := handy
LOCAL_SRC_FILES := libs/jni/handy/$(TARGET_ARCH_ABI)/libhandy.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libprotobuf
LOCAL_SRC_FILES := libs/jni/protobuf/$(TARGET_ARCH_ABI)/libprotobuf.so
include $(PREBUILT_SHARED_LIBRARY)



include $(CLEAR_VARS)
LOCAL_MODULE := privchat

#source
LOCAL_SRC_FILES := \
             Client.cpp\
             ClientImpl.cpp\
             Tcp.cpp\
             Tool.cpp\
             Packet.cpp\
             ObjectMapper.cpp\
             ./proto/chat.base.pb.cc\
             ./proto/chat.user.pb.cc\
             ./proto/chat.authenticate.pb.cc\
             ./proto/chat.contacts.pb.cc\
             ./proto/chat.message.pb.cc\

#include
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include/mac

#链接的系统默认库
LOCAL_LDLIBS := -pthread -llog -lz

#链接的第三方库
#LOCAL_STATIC_LIBRARIES := libprotobuf libhandy
LOCAL_SHARED_LIBRARIES := libprotobuf libhandy

include $(BUILD_SHARED_LIBRARY)