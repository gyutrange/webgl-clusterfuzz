#!/bin/bash -eu

mkdir -p $OUT

# Compile the html_repro fuzzer
$CXX $CXXFLAGS -std=c++11 \
  fuzz_targets/html_repro.cc -o $OUT/html_repro \
  $LIB_FUZZING_ENGINE

