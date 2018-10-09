find_package(Boost COMPONENTS system filesystem REQUIRED)

add_executable(
    unit_tests
    min_heap_test.cpp
    )

target_link_libraries(
    unit_tests
    gtest_main
    heap_lib
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    )

add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
  )
