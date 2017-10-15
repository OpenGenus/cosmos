#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "Queue_Using_Linked_List.h"

queue_t * qe_create() {
    queue_t * q = (queue_t *) calloc(1, sizeof(queue_t));
    return q;
}

int8_t qe_destroy(queue_t *q) {
    if (q == (queue_t *) NULL)
	return ERR_QUEUE_NULL;

    node_t *p = q->head;

    while (p != (node_t *) NULL) {
	q->head = p->next;
	free(p);
	p = q->head;;
    }

    q->len = 0;

    return SUCCESS;
}

int8_t qe_insert(queue_t *q, node_t * data) {
    if (q == (queue_t *) NULL)
	return ERR_QUEUE_NULL;

    if (data == (node_t *) NULL)
	return ERR_NULL_ARG;

    if (q->head == (node_t *) NULL) {
	q->head = data;
	q->tail = data;
    } else {
	data->prev = (node_t *) NULL;
	data->next = q->head;
	q->head->prev = data;
	q->head = data;
    }

    ++q->len;

    return SUCCESS;
}

node_t *qe_get(queue_t *q) {
    if (q == (queue_t *) NULL)
	return (node_t *) NULL;
    if (q->head == (node_t *) NULL)
	return (node_t *) NULL;

    node_t *p = (node_t *) NULL;

    if (q->head == q->tail) {
	p = q->tail;
	q->head = (node_t *) NULL;
	q->tail = (node_t *) NULL;
    } else {
	p = q->tail;
	q->tail->prev->next = (node_t *) NULL;
	q->tail = q->tail->prev;
	p->prev = (node_t *) NULL;
    }

    --q->len;

    return p;
}

size_t qe_len(queue_t *q) {
    if (q == (queue_t *) NULL)
	return ERR_QUEUE_NULL;

    return q->len;
}

void qe_print(queue_t *q) {
    if (q == (queue_t *) NULL)
	return;
    if (q->head == (node_t *) NULL)
	return;

    node_t *p = q->head;
    while (p != (node_t *) NULL) {
	printf("[%d] ", p->id);
	p = p->next;
    }
    printf("\n");
}