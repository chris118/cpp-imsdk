### build iOS
step 1:

```
include_directories (
./include/ios
)

LINK_DIRECTORIES(
./libs/ios
)
```

step 2:
```
cd ios-build
cmake .. -DCMAKE_TOOLCHAIN_FILE=./iOS-64.cmake -GXcode

```

step 3:

打开privchat.xcodeproj,使用xcode编译privchat.a


### build Android
```
cd android-build
ndk-build NDK_PROJECT_PATH=. APP_BUILD_SCRIPT=./Android.mk NDK_APPLICATION_MK=./Application.mk
```

### protoc 命令
```
protoc --cpp_out=. chat.user.proto

```

### lipo

```
lipo -create libprivchat-s.a libprivchat-d.a -output libprivchat.a

```
