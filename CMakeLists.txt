cmake_minimum_required (VERSION 3.5)
project (MuSAK-Annotations)

set (MuSAK_Annotations_VERSION_MAJOR 0)
set (MuSAK_Annotations_VERSION_MINOR 1)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

configure_file (
  ${MuSAK-Annotations_SOURCE_DIR}/musak-annotations-config.h.in
  ${MuSAK-Annotations_BINARY_DIR}/musak-annotations-config.h
  )

include_directories(${MuSAK-Annotations_SOURCE_DIR}/src)
include_directories(${MuSAK-Annotations_SOURCE_DIR}/include)
include_directories(${MuSAK-Annotations_BINARY_DIR})

add_executable(MuSAK-Annotations src/musak-annotations.cpp)
