#include <gtest/gtest.h>
#include "../../src/min_heap.hpp"

namespace data_structures
{
struct MinHeapTest : testing::Test
{
    const double resolution = 1.;
    const double tolerance = 1.e-8;
};

TEST_F(MinHeapTest, single_node_in_heap)
{
    // Given...
    const auto min_heap = MinHeap();

    // When...
    min_heap.push(3);

    // Then
    ASSERT_EQUAL(min_heap.size(), 1);
}
}
