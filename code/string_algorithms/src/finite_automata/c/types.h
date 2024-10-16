/*
 * Part of Cosmos by OpenGenus.
 * Author : ABDOUS Kamel
 */

#ifndef AUTOMATA_TYPES_H
#define AUTOMATA_TYPES_H

#include <stdbool.h>

/* States are labelled by positive integers instead of strings */
typedef int state_id_t;

/* A symbol is a single char */
typedef char symbol_t;

typedef enum dfs_color_e
{
  WHITE, 
  BLACK

} dfs_color_t;

/*
 * State of a finite automaton.
 */
typedef struct state_s
{
  state_id_t id;

  /* Indicates if this state is a final state */
  bool is_final;

} state_t;

/*
 * A single link in a linked-list of state ids.
 */
typedef struct state_link_s
{
  state_id_t state;
  struct state_link_s* next;

} state_link_t;

/*
 * Allocate a new state_link_t and return a pointer to it.
 */
state_link_t* alloc_state_link(state_id_t id);

#endif // AUTOMATA_TYPES_H
