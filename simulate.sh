#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
BUILD_DIR="$DIR/cmake-build"

rm -rf $BUILD_DIR

NINJA=""
if [ -x "$(command -v ninja)" ]; then
  NINJA="-GNinja"
fi

cmake -H"$DIR" -B"$BUILD_DIR" -DCMAKE_BUILD_TYPE=Release $NINJA && cmake --build $BUILD_DIR --target simulate

gtkwave "$BUILD_DIR/gtkwave_trace.vcd"
