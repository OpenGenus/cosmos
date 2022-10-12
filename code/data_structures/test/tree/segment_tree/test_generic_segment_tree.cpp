#include <bits/stdc++.h>

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

  arrow::segment_tree <int> binary_tree_sum (n, values, [] (auto l, auto r) {
    return l + r;
  });

  arrow::segment_tree <int, arrow::tree_memory_layout::euler_tour> euler_tour_tree_sum (n, values, [] (auto l, auto r) {
    return l + r;
  });

  ASSERT(binary_tree_sum.range_query(0, 4), 15, "binary_tree_sum.range_query(0, 4) == 15");
  ASSERT(binary_tree_sum.range_query(1, 2),  5, "binary_tree_sum.range_query(1, 2) == 5");
  ASSERT(binary_tree_sum.range_query(4, 4),  5, "binary_tree_sum.range_query(4, 4) == 5");
  ASSERT(binary_tree_sum.range_query(2, 4), 12, "binary_tree_sum.range_query(2, 4) == 12");
  ASSERT(binary_tree_sum.range_query(0, 3), 10, "binary_tree_sum.range_query(0, 3) == 10");

  ASSERT(euler_tour_tree_sum.range_query(0, 4), 15, "euler_tour_tree_sum.range_query(0, 4) == 15");
  ASSERT(euler_tour_tree_sum.range_query(1, 2),  5, "euler_tour_tree_sum.range_query(1, 2) == 5");
  ASSERT(euler_tour_tree_sum.range_query(4, 4),  5, "euler_tour_tree_sum.range_query(4, 4) == 5");
  ASSERT(euler_tour_tree_sum.range_query(2, 4), 12, "euler_tour_tree_sum.range_query(2, 4) == 12");
  ASSERT(euler_tour_tree_sum.range_query(0, 3), 10, "euler_tour_tree_sum.range_query(0, 3) == 10");

  binary_tree_sum.point_update(2, 10);
  euler_tour_tree_sum.point_update(0, 8);

  ASSERT(binary_tree_sum.point_query(2), 10, "binary_tree_sum.point_query(2) == 10");
  ASSERT(binary_tree_sum.range_query(1, 3), 16, "binary_tree_sum.range_query(1, 3) == 16");
  ASSERT(binary_tree_sum.range_query(0, 4), 22, "binary_tree_sum.range_query(0, 4) == 22");

  ASSERT(euler_tour_tree_sum.point_query(0), 8, "euler_tour_sum.point_query(0) == 8");
  ASSERT(euler_tour_tree_sum.range_query(1, 3), 9, "euler_tour_sum.range_query(1, 3) == 9");
  ASSERT(euler_tour_tree_sum.range_query(0, 4), 22, "euler_tour_sum.range_query(0, 4) == 22");

  values = {
    2, -4, 3, -1, 4, 1, -2, 5
  };
  n = values.size();

  struct node {
    int value;
    int max_prefix;
    int max_suffix;
    int max_subsegment;

    node (int v = 0) {
      int m = std::max(v, 0);

      value = v;
      max_prefix = m;
      max_suffix = m;
      max_subsegment = m;
    }
  };

  std::vector <node> node_values;

  for (auto i: values) {
    node_values.push_back(node(i));
  }
  
  arrow::segment_tree <node> binary_tree_max_subsegment (n, node_values, [] (auto l, auto r) {
    node result;
    result.value = l.value + r.value;
    result.max_prefix = std::max(l.max_prefix, l.value + r.max_prefix);
    result.max_suffix = std::max(l.max_suffix + r.value, r.max_suffix);
    result.max_subsegment = std::max({l.max_subsegment, r.max_subsegment, l.max_suffix + r.max_prefix});
    return result;
  });

  ASSERT(binary_tree_max_subsegment.range_query(0, 7).value, 8, "binary_tree_max_subsegment.range_query(0, 7).value == 8");
  ASSERT(binary_tree_max_subsegment.range_query(3, 5).value, 4, "binary_tree_max_subsegment.range_query(3, 5).value == 4");
  ASSERT(binary_tree_max_subsegment.range_query(2, 6).value, 5, "binary_tree_max_subsegment.range_query(2, 6).value == 5");
  ASSERT(binary_tree_max_subsegment.range_query(1, 4).value, 2, "binary_tree_max_subsegment.range_query(1, 4).value == 2");
  ASSERT(binary_tree_max_subsegment.range_query(7, 7).value, 5, "binary_tree_max_subsegment.range_query(7, 7).value == 5");
  ASSERT(binary_tree_max_subsegment.range_query(0, 4).value, 4, "binary_tree_max_subsegment.range_query(0, 4).value == 4");

  binary_tree_max_subsegment.point_update(5, 4);
  binary_tree_max_subsegment.point_update(3, -7);
  binary_tree_max_subsegment.point_update(1, 3);
  
  ASSERT(binary_tree_max_subsegment.range_query(0, 7).value, 12, "binary_tree_max_subsegment.range_query(0, 7).value == 12");
  ASSERT(binary_tree_max_subsegment.range_query(3, 5).value, 1, "binary_tree_max_subsegment.range_query(3, 5).value == 1");
  ASSERT(binary_tree_max_subsegment.range_query(2, 6).value, 2, "binary_tree_max_subsegment.range_query(2, 6).value == 2");
  ASSERT(binary_tree_max_subsegment.range_query(1, 4).value, 3, "binary_tree_max_subsegment.range_query(1, 4).value == 3");
  ASSERT(binary_tree_max_subsegment.range_query(7, 7).value, 5, "binary_tree_max_subsegment.range_query(7, 7).value == 5");
  ASSERT(binary_tree_max_subsegment.range_query(0, 4).value, 5, "binary_tree_max_subsegment.range_query(0, 4).value == 5");
}

int main () {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  test();

  return 0;
}
