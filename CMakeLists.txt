cmake_minimum_required (VERSION 3.5)
project (MuSAK-Annotations)

set (MuSAK_Annotations_VERSION_MAJOR 0)
set (MuSAK_Annotations_VERSION_MINOR 1)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

configure_file (
  "${PROJECT_SOURCE_DIR}/musak-annotations-config.h.in"
  "${PROJECT_BINARY_DIR}/musak-annotations-config.h"
  )

include_directories("${PROJECT_SOURCE_DIR}/src")
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_BINARY_DIR}")

add_executable(MuSAK-Annotations src/musak-annotations.cpp)
