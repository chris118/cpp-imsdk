rm -rf CMakeFiles/
rm CMakeCache.txt


cmake -DCMAKE_BUILD_TYPE=Debug .
#cmake .
make -j8



# build iOS
#cmake .. -DCMAKE_TOOLCHAIN_FILE=./iOS-64.cmake -GXcode

# build Android
# ndk-build NDK_PROJECT_PATH=. APP_BUILD_SCRIPT=./Android.mk NDK_APPLICATION_MK=./Application.mk



# build android
#ndk-build NDK_PROJECT_PATH=./ NDK_APPLICATION_MK=./Application.mk APP_BUILD_SCRIPT=./Android.mk
