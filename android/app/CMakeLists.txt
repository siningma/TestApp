cmake_minimum_required(VERSION 3.4.1)
project(TestApp)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 14)

add_library(react-native-jsi-module SHARED
    ../../cpp/react-native-jsi-module.cpp
    cpp-adapter.cpp
)

# Specifies a path to native header files.
include_directories(
    ../../cpp
)

# add_library(rust_multiply STATIC IMPORTED)
# set_target_properties(rust_multiply PROPERTIES IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/librust_lib.a")
# add_library(add_benchmark STATIC IMPORTED)
# set_target_properties(add_benchmark PROPERTIES IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/librust_lib.a")
# Include static library depending on the architecture
add_library(
        add_benchmark
        STATIC
        IMPORTED
)
if(ANDROID_ABI STREQUAL "arm64-v8a")
    message(STATUS "Configuring for arm64-v8a")
    set_target_properties(
        add_benchmark
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/jniLibs/arm64-v8a/librust_lib.a
    )
elseif(ANDROID_ABI STREQUAL "armeabi-v7a")
    set_target_properties(
            add_benchmark
            PROPERTIES IMPORTED_LOCATION
            ${CMAKE_SOURCE_DIR}/jniLibs/armeabi-v7a/librust_lib.a
    )
elseif(ANDROID_ABI STREQUAL "x86")
    set_target_properties(
            add_benchmark
            PROPERTIES IMPORTED_LOCATION
            ${CMAKE_SOURCE_DIR}/jniLibs/x86/librust_lib.a
    )
elseif(ANDROID_ABI STREQUAL "x86_64")
    set_target_properties(
            add_benchmark
            PROPERTIES IMPORTED_LOCATION
            ${CMAKE_SOURCE_DIR}/jniLibs/x86_64/librust_lib.a
    )
endif()

find_package(ReactAndroid REQUIRED CONFIG)
target_link_libraries(
    react-native-jsi-module
    ReactAndroid::jsi
    android
    add_benchmark
)
