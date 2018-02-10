/*
 * Part of Cosmos by OpenGenus Foundation.
 * Basic queue.
 * Author : ABDOUS Kamel
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

typedef int QUEUE_VAL;

typedef struct
{
  QUEUE_VAL* vals;
  size_t n;

  int head, tail;

} queue;

int
init_queue(queue* q, size_t n);

void
free_queue(queue* q);

int
queue_empty(queue* q);

int
queue_full(queue* q);

int
enqueue(queue* q, QUEUE_VAL val);

QUEUE_VAL
dequeue(queue* q);

#endif // DEQUEUE
