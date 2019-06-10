cmake_minimum_required (VERSION 3.7)
project (privchat C CXX)

# CMake -DCMAKE_BUILD_TYPE=Debug .
SET(CMAKE_CXX_FLAGS_DEBUG"$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#SET(CMAKE_CXX_FLAGS_RELEASE"$ENV{CXXFLAGS} -O3 -Wall")

set(CMAKE_CXX_STANDARD 11)

#ios
set(BUILD_SHARED false)
#anroid
#set(BUILD_SHARED true)

set(LIBRARIES protobuf handy)

# Includes
include_directories (
        ${imsdk_SOURCE_DIR}
        ./include/mac
#        ./include/ios
)

LINK_DIRECTORIES(
        ./libs/mac
#        ./libs/ios
)

# Source files
set (SOURCES
        Client.cpp
        ClientImpl.cpp
        Tcp.cpp
        Tool.cpp
        Packet.cpp
        ObjectMapper.cpp
        ./proto/chat.base.pb.cc
        ./proto/chat.user.pb.cc
        ./proto/chat.contacts.pb.cc
        ./proto/chat.message.pb.cc
        ./proto/chat.authenticate.pb.cc
        ./proto/chat.notification.pb.cc
)

# Library
if (BUILD_SHARED)
    add_library (privchat SHARED ${SOURCES})
    message(STATUS "Building shared version...")
else()
    add_library (privchat STATIC ${SOURCES})
    message(STATUS "Building static version...")
endif()

# Link the privchat with the LIBRARIES
target_link_libraries(privchat ${LIBRARIES})


# Executable
add_executable (demo main.cpp)

# Link the library with the executable
target_link_libraries(demo privchat ${LIBRARIES})

#Installation
set (CMAKE_INSTALL_PREFIX "${imsdk_SOURCE_DIR}")
install (TARGETS privchat DESTINATION lib)
install (FILES Client.h DESTINATION include)









