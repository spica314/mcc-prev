#!/bin/bash

./build.sh
BUILD_TARGET=$PWD/target/stage1.out
cd ./test/stage1/function-generation
BUILD_TARGET=$BUILD_TARGET ./test.sh as gcc
