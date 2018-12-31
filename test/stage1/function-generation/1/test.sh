#!/bin/bash

# $1: assembler
# $2: copmiler for test

$1 -o in.o example.s
$2 -o test test.c in.o
./test
if [ $? -ne 0 ]; then
  echo "Failed to test using example.s"
  exit 1
fi
rm in.o
rm test

$BUILD_TARGET < test.in > test.out
$1 -o in.o test.out
$2 -o test test.c in.o
./test
if [ $? -ne 0 ]; then
  echo "Failed to test, compiler = $BUILD_TARGET"
  exit 1
fi
rm in.o
rm test
rm test.out
