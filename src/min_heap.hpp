#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "heap.hpp"

namespace data_structures
{
class MinHeap : public Heap
{
    public:
        explicit MinHeap(unsigned int largest_heap_size);
};
}