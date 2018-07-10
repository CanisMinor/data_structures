file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(heap_tests ${SRCS})

TARGET_LINK_LIBRARIES(heap_tests
    libheap
)

add_test(NAME heap_tests
         COMMAND heap_tests)