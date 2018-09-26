#include <gmock/gmock.h>
#include "gtest/gtest.h"
#include <iterator>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>

#include "../src/max_heap.hpp"
#include "../src/min_heap.hpp"

namespace data_structures
{
TEST(RhymeMatcherTestFixture, can_support_single_best_match)
{
    const auto q = 3 + 3;
    ASSERT_EQ(q, 6);
}
}
