#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

dllist_t *dl_create() {
    dllist_t *l = (dllist_t *) calloc(1, sizeof(dllist_t));
    return l;
}

int8_t dl_destroy(dllist_t **l) {
    if (*l == (dllist_t *) NULL)
	return ERR_NO_LIST;

    if ((*l)->head == (node_t *) NULL)
	return ERR_EMPTY_LIST;

    node_t *p = (*l)->head;

    while (p != (node_t *) NULL) {
	(*l)->head = p->next;
	free(p);
	p = (*l)->head;
    }

    (*l)->tail = (node_t *) NULL;
    *l = (dllist_t *) NULL;

    return SUCCESS;
}

int8_t dl_insert_beginning(dllist_t *l, int32_t value) {
    if (l == (dllist_t *) NULL)
	return ERR_NO_LIST;

    node_t *nn = (node_t *) calloc(1, sizeof(node_t));

    if (nn == (node_t *) NULL)
	return ERR_MALLOC_FAIL;

    nn->id = l->tail_id++;
    nn->data = value;
    nn->prev = (node_t *) NULL;

    node_t *p = l->head;

    if (p == (node_t *) NULL) {
	l->tail = nn;
    } else {
	nn->next = p;
	p->prev = nn;
    }
    l->head = nn;
    l->len++;

    return SUCCESS;
}

int8_t dl_insert_tail(dllist_t *l, int32_t value) {
    if (l == (dllist_t *) NULL)
	return ERR_NO_LIST;

    node_t *nn = (node_t *) calloc(1, sizeof(node_t));

    if (nn == (node_t *) NULL)
	return ERR_MALLOC_FAIL;

    nn->id = l->tail_id++;
    nn->data = value;
    node_t *p = l->tail;

    if (l->head == (node_t *) NULL) {
	l->head = nn;
	l->tail = nn;
    } else {
	p->next = nn;
	nn->prev = p;
	l->tail = nn;
    }
    l->len++;

    return SUCCESS;
}

int8_t dl_insert_after(dllist_t *l, int32_t key, int32_t value) {
    if (l == (dllist_t *) NULL)
	return ERR_NO_LIST;

    if (l->head == (node_t *) NULL)
	return ERR_EMPTY_LIST;

    node_t *nn = (node_t *) calloc(1, sizeof(node_t));

    if (nn == (node_t *) NULL)
	return ERR_MALLOC_FAIL;

    nn->id = l->tail_id++;
    nn->data = value;

    node_t *p = l->head;

    while (p != (node_t *) NULL) {
	if (p->data == key) {
	    nn->next = p->next;
	    p->next = nn;
	    nn->prev = p;
	    if (p == l->tail) {
		l->tail = nn;
	    }
	    break;
	}
	p = p->next;
    }

    return SUCCESS;
}

int8_t dl_insert_before(dllist_t *l, int32_t key, int32_t value) {
    if (l == (dllist_t *) NULL)
	return ERR_NO_LIST;

    if (l->head == (node_t *) NULL)
	return ERR_EMPTY_LIST;

    node_t *nn = (node_t *) calloc(1, sizeof(node_t));

    if (nn == (node_t *) NULL)
	return ERR_MALLOC_FAIL;

    nn->id = l->tail_id++;
    nn->data = value;

    node_t *p = l->head;

    while (p != (node_t *) NULL) {
	if (p->data == key) {
	    if (p == l->head) {
		l->head = nn;
	    } else {
		p->prev->next = nn;
	    }
	    nn->next = p;
	    nn->prev = p->prev;

	    break;
	}
	p = p->next;
    }

    return SUCCESS;
}

int8_t dl_remove_beginning(dllist_t *l) {
    if (l == (dllist_t *) NULL)
	return ERR_NO_LIST;

    if (l->head == (node_t *) NULL)
	return ERR_EMPTY_LIST;

    node_t *p = l->head;

    l->head = p->next;
    p->next = (node_t *) NULL;

    free(p);

    l->len--;

    return SUCCESS;
}

int8_t dl_remove_tail(dllist_t *l) {
    if (l == (dllist_t *) NULL)
	return ERR_NO_LIST;

    if (l->head == (node_t *) NULL)
	return ERR_EMPTY_LIST;

    node_t *p = l->tail;

    if (p == l->head) {
	l->head = (node_t *) NULL;
    } else {
	p->prev->next = (node_t *) NULL;
	l->tail = p->prev;
    }

    free(p);

    l->len--;

    return SUCCESS;

}

int8_t dl_remove_next(dllist_t *l, int32_t key) {
    if (l == (dllist_t *) NULL)
	return ERR_NO_LIST;

    if (l->head == (node_t *) NULL)
	return ERR_EMPTY_LIST;

    node_t *p = l->head;
    node_t *r = (node_t *) NULL;

    while (p->next != (node_t *) NULL) {
	if (p->id == key) {
	    r = p->next;

	    if (r->next == (node_t *) NULL) {
		l->tail = p;
		p->next = (node_t *) NULL;
	    } else {
		r->next->prev = p;
		p->next = r->next;
	    }

	    free(r);
	    l->len--;
	    r = (node_t *) NULL;
	    break;
	}
	p = p->next;
    }

    return SUCCESS;
}

int8_t dl_remove_prev(dllist_t *l, int32_t key) {
    if (l == (dllist_t *) NULL)
	return ERR_NO_LIST;

    if (l->head == (node_t *) NULL)
	return ERR_EMPTY_LIST;

    node_t *p = l->head->next;
    node_t *r = (node_t *) NULL;

    while (p != (node_t *) NULL) {
	if (p->id == key) {
	    r = p->prev;
	    if (r == l->head) {
		l->head = p;
		p->prev = (node_t *) NULL;
	    } else {
		p->prev = r->prev;
		r->prev->next = p;
	    }
	    free(r);
	    l->len--;
	    r = (node_t *) NULL;
	    break;
	}
	p = p->next;
    }

    return SUCCESS;
}
