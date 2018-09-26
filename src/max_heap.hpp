#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "heap.hpp"

namespace data_structures
{
class MaxHeap : protected Heap
{
    public:
       explicit MaxHeap(unsigned int largest_heap_size);
};
}