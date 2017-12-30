/*
 * Part of Cosmos by OpenGenus Foundation.
 * Basic queue.
 * Author : ABDOUS Kamel
 */

#include "queue.h"

int
init_queue(queue* q, size_t n)
{
  q->vals = malloc(sizeof(QUEUE_VAL) * (n + 1));

  if (q->vals == NULL)
    return (-1);

  q->n = n + 1;
  q->head = q->tail = 0;

  return (0);
}

void
free_queue(queue* q)
{
  free(q->vals);
}

inline int
queue_empty(queue* q)
{
  return (q->head == q->tail);
}

inline int
queue_full(queue* q)
{
  return ((q->tail + 1) % q->n == q->head);
}

int
enqueue(queue* q, QUEUE_VAL val)
{
  if (queue_full(q))
    return (-1);

  q->vals[q->tail] = val;
  q->tail = (q->tail + 1) % q->n;

  return (0);
}

QUEUE_VAL
dequeue(queue* q)
{
  if (queue_empty(q))
    return (0);

  QUEUE_VAL ret = q->vals[q->head];

  q->head = (q->head + 1) % q->n;
  return (ret);
}
