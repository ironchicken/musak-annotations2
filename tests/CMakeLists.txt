find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

include_directories(${TEST_SOURCE_DIR}/src)
include_directories(${Boost_INCLUDE_DIRS})

add_definitions(-DBOOST_TEST_DYN_LINK)

add_executable(timestamp_read timestamp_read.cpp)
target_link_libraries(timestamp_read
  musakannotations ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_executable(mark_create mark_create.cpp)
target_link_libraries(mark_create
  musakannotations ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_executable(page_load page_load.cpp)
target_link_libraries(page_load
  musakannotations ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_executable(shapes shapes.cpp)
target_link_libraries(shapes
  musakannotations ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
