/*
 * Part of Cosmos by OpenGenus Foundation.
 * Author : ABDOUS Kamel
 */

#include "lgraph_stack.h"

/*
 * Creates a stack of size n.
 * @n The size of the stack.
 * @stack A pointer to a stack struct.
 * @return 0 on success, -1 on malloc failure.
 */
int
createLG_Stack(size_t n, LG_Stack* stack)
{
  stack->n = n;
  stack->nodes = malloc(sizeof(*stack->nodes) * n);

  if (stack->nodes == NULL)
    return (-1);

  stack->head = -1;
  return (0);
}

/*
 * Frees the stack.
 * @stack A pointer to a stack struct.
 */
void
freeLG_Stack(LG_Stack* stack)
{
  stack->n = 0;
  stack->head = -1;

  free(stack->nodes);
}

/*
 * @stack A pointer to a stack struct.
 * @return 1 if the stack is full, 0 otherwise.
 */
inline int
LG_StackFull(LG_Stack* stack)
{
  return (stack->head == stack->n);
}

/*
 * @stack A pointer to a stack struct.
 * @return 1 if the stack is empty, 0 otherwise.
 */
inline int
LG_StackEmpty(LG_Stack* stack)
{
  return (stack->head == -1);
}

/*
 * Pushes node on top of the stack.
 * Doesn't push if the stack is full.
 * @stack A pointer to a stack struct.
 * @node id of the node to push.
 */
void
LG_StackPush(LG_Stack* stack, Node_ID node)
{
  if (LG_StackFull(stack))
    return ;

  stack->head++;
  stack->nodes[stack->head] = node;
}

/*
 * Pops the top of the stack.
 * Doesn't pop if the stack is empty.
 * @stack A pointer to a stack struct.
 * @return The id of the node of the top of the stack.
 *         If the stack is empty, returns 0, but this shouldn't be an indicator,
 *         since a node of id 0 can be of the top of the stack. Use LG_StackEmpty for checking.
 */
Node_ID
LG_StackPop(LG_Stack* stack)
{
  if (LG_StackEmpty(stack))
    return (0);

  Node_ID ret = stack->nodes[stack->head];

  stack->head--;
  return (ret);
}

/*
 * Peeks the top of the stack whitout poping it.
 * @stack A pointer to a stack struct.
 * @return Same as LG_StackPop.
 */
Node_ID
LG_StackPeek(LG_Stack* stack)
{
  if (LG_StackEmpty(stack))
    return (0);

  return (stack->nodes[stack->head]);
}
