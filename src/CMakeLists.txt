add_library (heaps heap.hpp max_head.cpp min_heap.cpp)
add_executable (demo main.cpp)
target_link_libraries (demo Sqr)