find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

include_directories(${TEST_SOURCE_DIR}/src)
include_directories(${Boost_INCLUDE_DIRS})

add_definitions(-DBOOST_TEST_DYN_LINK)

add_executable(timestamps timestamps.cpp)
target_link_libraries(timestamps
  musakannotations ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_executable(marks marks.cpp)
target_link_libraries(marks
  musakannotations ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_executable(pages pages.cpp)
target_link_libraries(pages
  musakannotations ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_executable(shapes shapes.cpp)
target_link_libraries(shapes
  musakannotations ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
