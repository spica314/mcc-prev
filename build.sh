#!/bin/bash

mkdir -p target

BUILD_TARGET=$PWD/target/stage1.out
cd ./src/stage1
BUILD_TARGET=$BUILD_TARGET ./build.sh
