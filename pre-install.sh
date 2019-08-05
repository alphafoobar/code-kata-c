#!/usr/bin/env bash

ROOT_WORKING_DIR=$(pwd)/build-dependencies
export ROOT_WORKING_DIR

cd "${ROOT_WORKING_DIR}/cmocka-1.1.5" || exit

rm -rf build && \
    mkdir -p build && \
    cd build && \
    cmake \
        -DCMAKE_INSTALL_PREFIX="${ROOT_WORKING_DIR}/install/cmocka-1.1.5" \
        -DCMAKE_BUILD_TYPE=Debug .. && \
    make install
