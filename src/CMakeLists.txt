add_library(rhyme_matcher "")

target_sources(
    rhyme_matcher
    PRIVATE
        min_heap.cpp
        max_heap.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/min_heap.hpp
        ${CMAKE_CURRENT_LIST_DIR}/max_heap.hpp
    )

target_include_directories(
    rhyme_matcher
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
