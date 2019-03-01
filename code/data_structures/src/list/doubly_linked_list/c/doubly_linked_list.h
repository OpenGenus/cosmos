#ifndef _D_L_LIST_H_
#define _D_L_LIST_H_

#include <stdint.h>

#define SUCCESS          0
#define ERR_NO_LIST     -1
#define ERR_EMPTY_LIST  -2
#define ERR_MALLOC_FAIL -3

typedef struct node_s {
    int32_t       id;
    int32_t       data;
    struct node_s *next;
    struct node_s *prev;
} node_t ;

typedef struct dllist_s {
    int32_t  len;
    int32_t  tail_id;
    node_t   *head;
    node_t   *tail;
} dllist_t;

dllist_t * dl_create            ();
int8_t     dl_destroy           (dllist_t **l);

int8_t     dl_insert_beginning  (dllist_t *l, int32_t value);
int8_t     dl_insert_end        (dllist_t *l, int32_t value);
int8_t     dl_insert_after      (dllist_t *l, int32_t key, int32_t value);
int8_t     dl_insert_before     (dllist_t *l, int32_t key, int32_t value);

int8_t     dl_remove_beginning  (dllist_t *l);
int8_t     dl_remove_end        (dllist_t *l);
int8_t     dl_remove_next       (dllist_t *l, int32_t key);
int8_t     dl_remove_prev       (dllist_t *l, int32_t key);

#endif
