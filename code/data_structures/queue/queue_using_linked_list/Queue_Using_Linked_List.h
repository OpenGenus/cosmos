#ifndef __QUEUE_H__
#define __QUEUE_H__

#define ERR_NULL_ARG    -3
#define ERR_QUEUE_NULL  -1
#define ERR_QUEUE_EMPTY -2
#define SUCCESS          0

#include <stdint.h>
#include <stdlib.h>

typedef struct node_s {
    int32_t         id;
    struct node_s * next;
    struct node_s * prev;
} node_t;

typedef struct queue_s {
    size_t   len;
    node_t * head;
    node_t * tail;
} queue_t;

queue_t * qe_create    ();
int8_t    qe_destroy   (queue_t *q);
int8_t    qe_insert    (queue_t *q, node_t * data);
node_t *  qe_get       (queue_t *q);
size_t    qe_len       (queue_t *q);
void      qe_print     (queue_t *q);

#endif
