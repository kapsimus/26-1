cmake_minimum_required(VERSION 3.22)
project(26_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(26_1 src/main.cpp include/track.h include/player.h src/track.cpp src/player.cpp)
target_include_directories(26_1 PUBLIC include)
