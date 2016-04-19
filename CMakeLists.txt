cmake_minimum_required (VERSION 3.5)
project (MuSAK-Annotations)

set (MuSAK_Annotations_VERSION_MAJOR 0)
set (MuSAK_Annotations_VERSION_MINOR 1)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11 -pthread")

configure_file (
  ${MuSAK-Annotations_SOURCE_DIR}/musak-annotations-config.h.in
  ${MuSAK-Annotations_BINARY_DIR}/musak-annotations-config.h
  )

include_directories(${MuSAK-Annotations_SOURCE_DIR}/src)
include_directories(${MuSAK-Annotations_SOURCE_DIR}/include)
include_directories(${MuSAK-Annotations_SOURCE_DIR}/lib)
include_directories(${MuSAK-Annotations_BINARY_DIR})

find_package(Boost COMPONENTS filesystem REQUIRED)

add_subdirectory(src)
add_subdirectory(tests)

enable_testing()
add_test(NAME timestamps COMMAND timestamps)
add_test(NAME marks COMMAND marks)
add_test(NAME pages COMMAND pages)
add_test(NAME shapes COMMAND shapes)
