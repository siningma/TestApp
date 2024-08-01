#!/bin/bash

# Directories
RUST_MODULE_DIR="./rust" # Replace with the path to your Rust module
REACT_NATIVE_ANDROID_DIR="./android/app" # Replace with the path to your React Native Android main directory if different

# Build using cargo-ndk
cd $RUST_MODULE_DIR
cargo build --release --target aarch64-linux-android
cargo build --release --target armv7-linux-androideabi
cargo build --release --target i686-linux-android
cargo build --release --target x86_64-linux-android
cd ..

# Copy the .so files to jniLibs folder
mkdir -p "$REACT_NATIVE_ANDROID_DIR/jniLibs/arm64-v8a"
mkdir -p "$REACT_NATIVE_ANDROID_DIR/jniLibs/armeabi-v7a"
mkdir -p "$REACT_NATIVE_ANDROID_DIR/jniLibs/x86"
mkdir -p "$REACT_NATIVE_ANDROID_DIR/jniLibs/x86_64"

cp "$RUST_MODULE_DIR/target/aarch64-linux-android/release/librust_lib.a" "$REACT_NATIVE_ANDROID_DIR/jniLibs/arm64-v8a/"
cp "$RUST_MODULE_DIR/target/armv7-linux-androideabi/release/librust_lib.a" "$REACT_NATIVE_ANDROID_DIR/jniLibs/armeabi-v7a/"
cp "$RUST_MODULE_DIR/target/i686-linux-android/release/librust_lib.a" "$REACT_NATIVE_ANDROID_DIR/jniLibs/x86/"
cp "$RUST_MODULE_DIR/target/x86_64-linux-android/release/librust_lib.a" "$REACT_NATIVE_ANDROID_DIR/jniLibs/x86_64/"

echo "Build completed and .so files copied successfully!"
