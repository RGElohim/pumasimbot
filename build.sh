#!/usr/bin/env bash


CMAKE_FLAGS="-DDEBUG=1 -DTCP_CLIPS60_FETCH_FROM_GIT=1 -DMINIBOT_DRIVER_FETCH_FROM_GIT=1 -DMINIBOT_TCP_API_FETCH_FROM_GIT=1"

[ -d build ] || mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug ${CMAKE_FLAGS} && make
RET=$?
cd ..
exit ${RET}
