#include <gmock/gmock.h>
#include "gtest/gtest.h"
#include <iterator>
#include <algorithm>
#include <array>
#include <fstream>
#include <vector>
#include <string>

#include "../src/min_heap.hpp"

namespace data_structures
{
TEST(MinHeapTest, heap_is_initially_empty)
{
    data_structures::MinHeap heap = data_structures::MinHeap(0);
    ASSERT_TRUE(heap.is_empty());
}

TEST(MinHeapTest, heap_is_correctly_sized)
{
    const size_t reserved_size = 100;
    data_structures::MinHeap heap = data_structures::MinHeap(reserved_size);
    ASSERT_TRUE(heap.is_empty());
}

TEST(MinHeapTest, adding_five_different_values_gives_correct_heap_size)
{
    const size_t reserved_size = 100;
    data_structures::MinHeap heap = data_structures::MinHeap(reserved_size);

    const size_t heap_size = 5;
    const std::array<int, heap_size> values = {4, 0, 7, 3, 2};
    for (size_t i = 0; i < heap_size; ++i)
    {
        heap.push(values[i]);
    }

    ASSERT_EQ(heap_size, heap.size());
}

TEST(MinHeapTest, gives_correct_min_value)
{
    const size_t reserved_size = 100;
    data_structures::MinHeap heap = data_structures::MinHeap(reserved_size);

    const size_t heap_size = 5;
    const std::array<int, heap_size> values = {4, 1, 7, 3, 2};
    for (size_t i = 0; i < heap_size; ++i)
    {
        heap.push(values[i]);
    }

    ASSERT_EQ(1, heap.get_root());
}

TEST(MinHeapTest, adding_same_value_over_and_over_gives_correct_min_value)
{
    const size_t reserved_size = 100;
    data_structures::MinHeap heap = data_structures::MinHeap(reserved_size);

    const size_t heap_size = 100;
    for (size_t i = 0; i < heap_size; ++i)
    {
        heap.push(3);
    }

    ASSERT_EQ(heap_size, heap.size());
}

TEST(MinHeapTest, push_and_pop_all_values_yields_empty_heap)
{
    const size_t reserved_size = 100;
    data_structures::MinHeap heap = data_structures::MinHeap(reserved_size);

    const size_t heap_size = 100;
    for (size_t i = 0; i < heap_size; ++i)
    {
        heap.push(3);
    }

    for (size_t i = 0; i < heap_size; ++i)
    {
        heap.pop();
    }

    ASSERT_TRUE(heap.is_empty());
}

TEST(MinHeapTest, try_pop_empty_heap)
{
    const size_t reserved_size = 100;
    data_structures::MinHeap heap = data_structures::MinHeap(reserved_size);

    heap.pop();

    ASSERT_TRUE(heap.is_empty());
}
}  // namespace data_structures
