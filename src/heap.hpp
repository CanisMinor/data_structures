#include <vector>

#pragma once

namespace data_structures
{
class Heap
{
  public:
    // return number of entries in heap
    virtual unsigned int size() const;

    // return whether or not heap is empty
    virtual bool is_empty() const;

    // return root element of heap
    virtual int get_root() const;

    // pop element off heap
    virtual void pop();

    // push element onto heap
    virtual void push(int key);

  protected:
    // storage of the heap contents
    std::vector<int> heap_array;

    // get parent of given entry in heap
    virtual size_t get_parent(size_t heap_index);

    // get left and right children of given entry in heap
    virtual size_t get_right_child(size_t heap_index);
    virtual size_t get_left_child(size_t heap_index);

    // re-heapify heap from leaf
    virtual void heapify_up(size_t index);

    // re-heapify heap from root
    virtual void heapify_down(size_t index);
};
}