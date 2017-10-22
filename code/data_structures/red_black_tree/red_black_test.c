/**
 * author: JonNRb <jonbetti@gmail.com>
 * license: GPLv3
 * file: @cosmos//code/data_structures/red_black_tree/red_black_test.c
 * info: red black tree
 */

#include "red_black_tree.h"

#include <assert.h>
#include <inttypes.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define red_printf(f, ...) printf("\x1b[31m" f "\x1b[0m", __VA_ARGS__)

extern int is_rb_correct(cosmos_red_black_tree_t tree);

typedef struct item {
  char label;

  cosmos_red_black_node_t node;
  uint64_t sort_key;
} item_t;

typedef struct {
  char text[8];
  size_t depth;
  int red;
} item_repr_t;

void iot_1(cosmos_red_black_tree_t tree, size_t* size) {
  ++*size;
  if (tree != NULL) {
    iot_1(tree->link[0], size);
    iot_1(tree->link[1], size);
  }
}

void iot_2(cosmos_red_black_tree_t tree, item_repr_t* arr, size_t* i,
           size_t depth) {
  if (tree == NULL) {
    strncpy(arr[*i].text, "[ NIL ]", 8);
    arr[*i].depth = depth;
    arr[*i].red = 0;
    ++*i;
    return;
  }

  iot_2(tree->link[0], arr, i, depth + 1);

  item_t* item = container_of(tree, struct item, node);
  snprintf(arr[*i].text, 8, "[%c,%03" PRIu64 "]", item->label, item->sort_key);
  arr[*i].depth = depth;
  arr[*i].red = tree->red;
  ++*i;

  iot_2(tree->link[1], arr, i, depth + 1);
}

void print_tree(cosmos_red_black_tree_t tree) {
  size_t size = 0;
  iot_1(tree, &size);

  item_repr_t* arr = (item_repr_t*)malloc(size * sizeof(item_repr_t));
  size_t i = 0;
  iot_2(tree, arr, &i, 0);

  assert(i == size);

  for (size_t depth = 0, i = 0; i < size; ++depth) {
    for (size_t j = 0; j < size; ++j) {
      if (arr[j].depth == depth) {
        if (arr[j].red) {
          red_printf("%s", arr[j].text);
        } else {
          printf("%s", arr[j].text);
        }
        ++i;
      } else {
        printf("       ");
      }
    }
    printf("\n");
  }
}

void assert_tree_invalid() {
  printf("checking we can check tree validity\n");

  assert(is_rb_correct(NULL));

  item_t items[7];
  items[0] = (item_t){'A', {{NULL, NULL}, 1}, 1};
  items[1] = (item_t){'B', {{&items[0].node, &items[2].node}, 1}, 2};
  items[2] = (item_t){'C', {{NULL, NULL}, 1}, 3};
  items[3] = (item_t){'D', {{&items[1].node, &items[5].node}, 1}, 4};
  items[4] = (item_t){'E', {{NULL, NULL}, 1}, 5};
  items[5] = (item_t){'F', {{&items[4].node, &items[6].node}, 1}, 6};
  items[6] = (item_t){'G', {{NULL, NULL}, 1}, 7};
  assert(!is_rb_correct(&items[3].node));
}

void print_sanity_tree() {
  item_t items[7];

  items[0] = (item_t){'A', {{NULL, NULL}, 0}, 1};
  items[1] = (item_t){'B', {{&items[0].node, &items[2].node}, 1}, 2};
  items[2] = (item_t){'C', {{NULL, NULL}, 0}, 3};
  items[3] = (item_t){'D', {{&items[1].node, &items[5].node}, 0}, 4};
  items[4] = (item_t){'E', {{NULL, NULL}, 0}, 5};
  items[5] = (item_t){'F', {{&items[4].node, &items[6].node}, 1}, 6};
  items[6] = (item_t){'G', {{NULL, NULL}, 0}, 7};

  printf("printing sanity tree\n");
  print_tree(&items[3].node);
}

void construct_and_insert(cosmos_red_black_tree_t* tree, item_t* item,
                          char label, uint64_t sort_key) {
  item->label = label;
  item->sort_key = sort_key;
  cosmos_red_black_construct(&item->node);

  cosmos_red_black_push(tree, &item->node);

  if (!is_rb_correct(*tree)) {
    printf("incorrect tree inserting %" PRIu64 ":\n", sort_key);
    print_tree(*tree);
    abort();
  }
}

void build_and_print() {
  cosmos_red_black_tree_t tree = NULL;
  item_t items[7];

  printf("no nodes\n");
  print_tree(tree);

  for (int i = 0; i < 7; ++i) {
    printf("%d node%s\n", i + 1, i != 0 ? "s" : "");
    construct_and_insert(&tree, items + i, 'A' + i, i + 1);
    print_tree(tree);
  }
}

static inline void swap(uint64_t* a, uint64_t* b) {
  uint64_t temp = *a;
  *a = *b;
  *b = temp;
}

void stress() {
  static const size_t num_nodes = 2 << 12;
  uint64_t nums[num_nodes];
  for (size_t i = 0; i < num_nodes; ++i) {
    nums[i] = i;
  }

  // janky shuffle
  srand(time(NULL));
  for (size_t i = 0; i < num_nodes - 1; ++i) {
    swap(nums + i, nums + i + 1 + (rand() % (num_nodes - i - 1)));
  }

  printf("stress adding %zu things in random order\n", num_nodes);
  cosmos_red_black_tree_t tree = NULL;
  item_t items[num_nodes];
  for (size_t i = 0; i < num_nodes; ++i) {
    construct_and_insert(&tree, items + i, 'X', nums[i]);
  }

  printf("stress popping %zu those things from front\n", num_nodes);
  for (size_t i = 0; i < num_nodes; ++i) {
    cosmos_red_black_node_t* popped = cosmos_red_black_pop_min(&tree);
    assert(popped != NULL);
    if (!is_rb_correct(tree)) {
      printf("incorrect tree popping %" PRIu64 "\n",
             container_of(popped, item_t, node)->sort_key);
      print_tree(tree);
      abort();
    }
  }

  assert(tree == NULL);
}

void time_test() {
  static const size_t max_num_nodes = 2 << 10;
  uint64_t nums[max_num_nodes];

  for (size_t num_nodes = 8; num_nodes < max_num_nodes; num_nodes <<= 1) {
    for (size_t i = 0; i < num_nodes; ++i) {
      nums[i] = i;
    }

    // janky shuffle
    srand(time(NULL));
    for (size_t i = 0; i < num_nodes - 1; ++i) {
      swap(nums + i, nums + i + 1 + (rand() % (num_nodes - i - 1)));
    }

    clock_t start = clock();
    cosmos_red_black_tree_t tree = NULL;
    item_t items[num_nodes];
    for (size_t i = 0; i < num_nodes; ++i) {
      construct_and_insert(&tree, items + i, 'X', nums[i]);
    }
    clock_t t = clock() - start;
    printf("adding  %4zu things took %9" PRId64 " µs (log => %5.02f)\n",
           num_nodes, ((uint64_t)t * 1000000) / CLOCKS_PER_SEC, log((double)t));

    start = clock();
    for (size_t i = 0; i < num_nodes; ++i) {
      cosmos_red_black_node_t* popped = cosmos_red_black_pop_min(&tree);
      assert(popped != NULL);
      if (!is_rb_correct(tree)) {
        printf("incorrect tree popping %" PRIu64 "\n",
               container_of(popped, item_t, node)->sort_key);
        print_tree(tree);
        abort();
      }
    }
    t = clock() - start;
    printf("popping %4zu things took %9" PRId64 " µs (log => %5.02f)\n",
           num_nodes, ((uint64_t)t * 1000000) / CLOCKS_PER_SEC, log((double)t));

    assert(tree == NULL);
  }
}

int main() {
  print_sanity_tree();
  assert_tree_invalid();
  build_and_print();
  stress();
  time_test();

  return 0;
}
