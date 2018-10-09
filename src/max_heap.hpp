#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

#pragma once

namespace data_structures
{
class MaxHeap
{
  public:
    explicit MaxHeap(unsigned int largest_heap_size);

    // return number of entries in heap
    unsigned int size() const;

    // return whether or not heap is empty
    bool is_empty() const;

    // return root element of heap
    int get_root() const;

    // pop element off heap
    void pop();

    // push element onto heap
    void push(int key);

  protected:
    // storage of the heap contents
    std::vector<int> heap_array;

    // get parent of given entry in heap
    size_t get_parent(size_t heap_index);

    // get left and right children of given entry in heap
    size_t get_right_child(size_t heap_index);
    size_t get_left_child(size_t heap_index);

    // re-heapify heap from leaf
    void heapify_up(size_t index);

    // re-heapify heap from root
    void heapify_down(size_t index);
};
}  // namespace data_structures