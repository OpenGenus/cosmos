/*
 * Part of Cosmos by OpenGenus Foundation.
 * Author : ABDOUS Kamel
 * Stack for pushing nodes ids.
 */

#ifndef LGRAPH_STACK_H
#define LGRAPH_STACK_H

#include "lgraph_struct.h"

/*
 * A common stack definition.
 */
typedef struct
{
  size_t n;
  Node_ID* nodes;

  int head;

} LG_Stack;

/*
 * Creates a stack of size n.
 * @n The size of the stack.
 * @stack A pointer to a stack struct.
 * @return 0 on success, -1 on malloc failure.
 */
int 
createLG_Stack(size_t n, LG_Stack* stack);

/*
 * Frees the stack.
 * @stack A pointer to a stack struct.
 */
void 
freeLG_Stack(LG_Stack* stack);

/*
 * @stack A pointer to a stack struct.
 * @return 1 if the stack is full, 0 otherwise.
 */
int 
LG_StackFull(LG_Stack* stack);

/*
 * @stack A pointer to a stack struct.
 * @return 1 if the stack is empty, 0 otherwise.
 */
int 
LG_StackEmpty(LG_Stack* stack);

/*
 * Pushes node on top of the stack.
 * Doesn't push if the stack is full.
 * @stack A pointer to a stack struct.
 * @node id of the node to push.
 */
void 
LG_StackPush(LG_Stack* stack, Node_ID node);

/*
 * Pops the top of the stack.
 * Doesn't pop if the stack is empty.
 * @stack A pointer to a stack struct.
 * @return The id of the node of the top of the stack.
 *         If the stack is empty, returns 0, but this shouldn't be an indicator,
 *         since a node of id 0 can be of the top of the stack. Use LG_StackEmpty for checking.
 */
Node_ID 
LG_StackPop(LG_Stack* stack);

/*
 * Peeks the top of the stack whitout poping it.
 * @stack A pointer to a stack struct.
 * @return Same as LG_StackPop.
 */
Node_ID 
LG_StackPeek(LG_Stack* stack);

#endif // LGRAPH_STACK
