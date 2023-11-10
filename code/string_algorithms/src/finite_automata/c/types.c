/*
 * Part of Cosmos by OpenGenus.
 * Author : ABDOUS Kamel
 */

#include "types.h"
#include <stdlib.h>

/*
 * Allocate a new state_link_t and return a pointer to it.
 */
state_link_t* alloc_state_link(state_id_t id)
{
  state_link_t* ret = malloc(sizeof(*ret));
  ret->state = id;
  ret->next = NULL;

  return (ret);
}
