find_package(Boost COMPONENTS system filesystem REQUIRED)

add_executable(
    unit_tests
    rhyme_matcher_test.cpp
    )

target_link_libraries(
    unit_tests
    gtest_main
    rhyme_matcher
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    )

add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
  )
