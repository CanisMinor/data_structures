add_library(heap_lib "")

target_sources(
    heap_lib
    PRIVATE
        min_heap.cpp
        max_heap.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/heap.hpp
        ${CMAKE_CURRENT_LIST_DIR}/min_heap.hpp
        ${CMAKE_CURRENT_LIST_DIR}/max_heap.hpp
    )

target_include_directories(
    heap_lib
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
