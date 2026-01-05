cmake_minimum_required(VERSION 3.14)

project(SimpleAnimation VERSION 0.1)
include(src/CMakeLists.txt)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Useless
# add_subdirectory(src)

add_executable(SimpleAnimation src/main.cpp ${SRC_FILES})
target_include_directories(SimpleAnimation PUBLIC ${PROJECT_SOURCE_DIR}/include)