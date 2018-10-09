#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "max_heap.hpp"

namespace data_structures
{
MaxHeap::MaxHeap(unsigned int heap_size)
{
    heap_array.reserve(heap_size);
}

unsigned int MaxHeap::size() const
{
    return heap_array.size();
}

bool MaxHeap::is_empty() const
{
    return heap_array.empty();
}

int MaxHeap::get_root() const
{
    try
    {
        if (heap_array.empty())
        {
            throw std::out_of_range("Index is out of range (heap underflow).");
        }

        return heap_array[0];
    }
    catch (const std::out_of_range& oor)
    {
        std::cerr << oor.what() << std::endl;
    }
}

void MaxHeap::pop()
{
    try
    {
        if (heap_array.empty())
        {
            throw std::out_of_range("Index is out of range (heap underflow).");
        }
        const int root_index = 0;
        heap_array[root_index] = heap_array.back();
        heap_array.pop_back();
    }
    catch (const std::out_of_range& oor)
    {
        std::cerr << oor.what() << std::endl;
    }
}

void MaxHeap::push(int key)
{
    heap_array.push_back(key);
    const size_t last_index = heap_array.size() - 1;
    heapify_up(last_index);
}

size_t MaxHeap::get_parent(size_t heap_index)
{
    return (heap_index - 1) / 2;
}

size_t MaxHeap::get_left_child(size_t heap_index)
{
    return (2 * heap_index) + 1;
}

size_t MaxHeap::get_right_child(size_t heap_index)
{
    return (2 * heap_index) + 2;
}

void MaxHeap::heapify_up(size_t index)
{
    const int parent_index = get_parent(index);
    const int parent = heap_array[parent_index];
    if (parent < heap_array[index])
    {
        std::swap(heap_array[parent_index], heap_array[index]);
        heapify_up(parent_index);
    }

    return;
}

void MaxHeap::heapify_down(size_t index)
{
    const size_t left_child_index = get_left_child(index);
    const size_t right_child_index = get_right_child(index);
    const bool left_child_exists = left_child_index < heap_array.size();
    const bool right_child_exists = right_child_index < heap_array.size();

    if (!left_child_exists && !right_child_exists)
    {
        return;
    }

    // if the largest child is greater than the parent, swap
    int index_of_largest_child =
        heap_array[left_child_index] > heap_array[right_child_index] ? left_child_index : right_child_index;
    if (heap_array[index] < heap_array[index_of_largest_child])
    {
        std::swap(heap_array[index], heap_array[index_of_largest_child]);
        heapify_down(index_of_largest_child);
    }

    return;
}
}  // namespace data_structures