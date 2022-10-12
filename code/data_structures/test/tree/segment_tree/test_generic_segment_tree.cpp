#include <algorithm>
#include <iostream>
#include <vector>

// Note that the below line includes a translation unit and not header file

#include "../../../src/tree/segment_tree/generic_segment_tree.cpp"

#define ASSERT(value, expected_value, message)                   \
{                                                                \
  if (value != expected_value)                                   \
    std::cerr << "[assertion failed]\n"                          \
              << "   Line: " << __LINE__ << '\n'                 \
              << "   File: " << __FILE__ << '\n'                 \
              << "Message: " << message << std::endl;            \
  else                                                           \
    std::cerr << "[assertion passed]: " << message << std::endl; \
}

/**
 * This program tests the generic segment tree implementation that can be found in the include location above.
 * The implementation requires C++20 in order to compile.
 * 
 * Compilation: g++ test_generic_segment_tree.cpp -o test_generic_segment_tree -Wall -Wextra -pedantic -std=c++20 -O3
 */

constexpr bool is_multitest = false;
constexpr int32_t inf32 = int32_t(1) << 30;
constexpr int64_t inf64 = int64_t(1) << 60;

void test () {
  std::vector <int> values = { 1, 2, 3, 4, 5 };
  int n = values.size();

  arrow::SegmentTree <int> binaryTreeSum (n, values, [] (auto l, auto r) {
    return l + r;
  });

  arrow::SegmentTree <int, arrow::TreeMemoryLayout::EulerTour> eulerTourTreeSum (n, values, [] (auto l, auto r) {
    return l + r;
  });

  ASSERT(binaryTreeSum.rangeQuery(0, 4), 15, "binaryTreeSum.rangeQuery(0, 4) == 15");
  ASSERT(binaryTreeSum.rangeQuery(1, 2),  5, "binaryTreeSum.rangeQuery(1, 2) == 5");
  ASSERT(binaryTreeSum.rangeQuery(4, 4),  5, "binaryTreeSum.rangeQuery(4, 4) == 5");
  ASSERT(binaryTreeSum.rangeQuery(2, 4), 12, "binaryTreeSum.rangeQuery(2, 4) == 12");
  ASSERT(binaryTreeSum.rangeQuery(0, 3), 10, "binaryTreeSum.rangeQuery(0, 3) == 10");

  ASSERT(eulerTourTreeSum.rangeQuery(0, 4), 15, "eulerTourTreeSum.rangeQuery(0, 4) == 15");
  ASSERT(eulerTourTreeSum.rangeQuery(1, 2),  5, "eulerTourTreeSum.rangeQuery(1, 2) == 5");
  ASSERT(eulerTourTreeSum.rangeQuery(4, 4),  5, "eulerTourTreeSum.rangeQuery(4, 4) == 5");
  ASSERT(eulerTourTreeSum.rangeQuery(2, 4), 12, "eulerTourTreeSum.rangeQuery(2, 4) == 12");
  ASSERT(eulerTourTreeSum.rangeQuery(0, 3), 10, "eulerTourTreeSum.rangeQuery(0, 3) == 10");

  binaryTreeSum.pointUpdate(2, 10);
  eulerTourTreeSum.pointUpdate(0, 8);

  ASSERT(binaryTreeSum.pointQuery(2), 10, "binaryTreeSum.pointQuery(2) == 10");
  ASSERT(binaryTreeSum.rangeQuery(1, 3), 16, "binaryTreeSum.rangeQuery(1, 3) == 16");
  ASSERT(binaryTreeSum.rangeQuery(0, 4), 22, "binaryTreeSum.rangeQuery(0, 4) == 22");

  ASSERT(eulerTourTreeSum.pointQuery(0), 8, "euler_tour_sum.pointQuery(0) == 8");
  ASSERT(eulerTourTreeSum.rangeQuery(1, 3), 9, "euler_tour_sum.rangeQuery(1, 3) == 9");
  ASSERT(eulerTourTreeSum.rangeQuery(0, 4), 22, "euler_tour_sum.rangeQuery(0, 4) == 22");

  values = {
    2, -4, 3, -1, 4, 1, -2, 5
  };
  n = values.size();

  struct node {
    int value;
    int maxPrefix;
    int maxSuffix;
    int maxSubsegment;

    node (int v = 0) {
      int m = std::max(v, 0);

      value = v;
      maxPrefix = m;
      maxSuffix = m;
      maxSubsegment = m;
    }
  };

  std::vector <node> node_values;

  for (auto i: values) {
    node_values.push_back(node(i));
  }
  
  arrow::SegmentTree <node> binaryTreeMaxSubsegment (n, node_values, [] (auto l, auto r) {
    node result;
    result.value = l.value + r.value;
    result.maxPrefix = std::max(l.maxPrefix, l.value + r.maxPrefix);
    result.maxSuffix = std::max(l.maxSuffix + r.value, r.maxSuffix);
    result.maxSubsegment = std::max({l.maxSubsegment, r.maxSubsegment, l.maxSuffix + r.maxPrefix});
    return result;
  });

  ASSERT(binaryTreeMaxSubsegment.rangeQuery(0, 7).value, 8, "binaryTreeMaxSubsegment.rangeQuery(0, 7).value == 8");
  ASSERT(binaryTreeMaxSubsegment.rangeQuery(3, 5).value, 4, "binaryTreeMaxSubsegment.rangeQuery(3, 5).value == 4");
  ASSERT(binaryTreeMaxSubsegment.rangeQuery(2, 6).value, 5, "binaryTreeMaxSubsegment.rangeQuery(2, 6).value == 5");
  ASSERT(binaryTreeMaxSubsegment.rangeQuery(1, 4).value, 2, "binaryTreeMaxSubsegment.rangeQuery(1, 4).value == 2");
  ASSERT(binaryTreeMaxSubsegment.rangeQuery(7, 7).value, 5, "binaryTreeMaxSubsegment.rangeQuery(7, 7).value == 5");
  ASSERT(binaryTreeMaxSubsegment.rangeQuery(0, 4).value, 4, "binaryTreeMaxSubsegment.rangeQuery(0, 4).value == 4");

  binaryTreeMaxSubsegment.pointUpdate(5, 4);
  binaryTreeMaxSubsegment.pointUpdate(3, -7);
  binaryTreeMaxSubsegment.pointUpdate(1, 3);
  
  ASSERT(binaryTreeMaxSubsegment.rangeQuery(0, 7).value, 12, "binaryTreeMaxSubsegment.rangeQuery(0, 7).value == 12");
  ASSERT(binaryTreeMaxSubsegment.rangeQuery(3, 5).value, 1, "binaryTreeMaxSubsegment.rangeQuery(3, 5).value == 1");
  ASSERT(binaryTreeMaxSubsegment.rangeQuery(2, 6).value, 2, "binaryTreeMaxSubsegment.rangeQuery(2, 6).value == 2");
  ASSERT(binaryTreeMaxSubsegment.rangeQuery(1, 4).value, 3, "binaryTreeMaxSubsegment.rangeQuery(1, 4).value == 3");
  ASSERT(binaryTreeMaxSubsegment.rangeQuery(7, 7).value, 5, "binaryTreeMaxSubsegment.rangeQuery(7, 7).value == 5");
  ASSERT(binaryTreeMaxSubsegment.rangeQuery(0, 4).value, 5, "binaryTreeMaxSubsegment.rangeQuery(0, 4).value == 5");
}

int main () {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  test();

  return 0;
}
