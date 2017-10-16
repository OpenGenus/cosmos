/**
 * author: JonNRb <jonbetti@gmail.com>
 * license: GPLv3
 * file: @cosmos//code/data_structures/red_black_tree/red_black.h
 * info: red black tree
 */

#ifndef COSMOS_RED_BLACK_H_
#define COSMOS_RED_BLACK_H_

#include <stdint.h>

/**
 * this macro subtracts off the offset of |member| within |type| from |ptr|,
 * allowing you to easily get a pointer to the containing struct of |ptr|
 *
 *           ┌─────────────┬──────────┬──────┐
 * |type| -> │ XXXXXXXXXXX │ |member| │ YYYY │
 *           └─────────────┴──────────┴──────┘
 *           ^             ^
 *        returns        |ptr|
 */
#define container_of(ptr, type, member)              \
  ({                                                 \
    const typeof(((type*)0)->member)* __mptr =       \
        (const typeof(((type*)0)->member)*)(__mptr); \
    (type*)((char*)ptr - __offsetof(type, member));  \
  })

/**
 * node structure to be embedded in your data object.
 *
 * NOTE: it is expected that there will be a `uint64_t` immediately following
 * the embedded node (which will be used as a sorting key).
 */
typedef struct _cosmos_red_black_node cosmos_red_black_node_t;
struct _cosmos_red_black_node {
  cosmos_red_black_node_t* link[2];
  int red;
  uint64_t sort_key[0];  // place a `uint64_t` sort key immediately after this
                         // struct in the data struct
};

/**
 * represents a whole tree. should be initialized to NULL.
 */
typedef cosmos_red_black_node_t* cosmos_red_black_tree_t;

/**
 * initializes a node to default values
 */
void cosmos_red_black_construct(cosmos_red_black_node_t* node);

/**
 * takes a pointer to |tree| and |node| to insert. will update |tree| if
 * necessary.
 */
void cosmos_red_black_push(cosmos_red_black_tree_t* tree,
                           cosmos_red_black_node_t* node);

/**
 * takes a pointer to the |tree| and returns a pointer to the minimum node in
 * the tree, which is removed from |tree|
 */
cosmos_red_black_node_t* cosmos_red_black_pop_min(
    cosmos_red_black_tree_t* tree);

#endif  // COSMOS_RED_BLACK_H_
