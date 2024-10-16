#ifndef _LINKED_LIST_C_
#define _LINKED_LIST_C_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> /* C99 required */

typedef bool (*compare_func)(void* p_data1, void* p_data2);
typedef void (*traverse_func)(void *p_data);
typedef void (*destroy_func)(void* p_data);

typedef struct linked_list_node
{
    struct linked_list_node* p_next;
    void* p_data;
} linked_list_node, *p_linked_list_node;

typedef struct linked_list
{
    linked_list_node* p_head;
    linked_list_node* p_tail;
    linked_list_node* p_cur;
    unsigned int u_count;
} linked_list, *p_linked_list;


linked_list*
linked_list_create();

void
linked_list_destroy(linked_list* p_linked_list, destroy_func destroy_func);

bool
linked_list_delete(linked_list* p_linked_list, void* p_match_data,
    compare_func compare_func, destroy_func destroy_func);

void*
linked_list_get_at(linked_list* p_linked_list, unsigned int u_index);

bool
linked_list_traverse(linked_list* p_linked_list, traverse_func traverse_func);

unsigned int
linked_list_get_count(linked_list* p_linked_list);

void
linked_list_begin(linked_list* p_linked_list);

void*
linked_list_next(linked_list* p_linked_list);

void*
linked_list_get_head(linked_list* p_linked_list);

void*
linked_list_get_tail(linked_list* p_linked_list);

void*
linked_list_get_cursor(linked_list* p_linked_list);

void*
linked_list_pop_head(linked_list* p_linked_list);

void*
linked_list_pop_tail(linked_list* p_linked_list);

bool
linked_list_insert_head(linked_list* p_linked_list, void* p_data);

bool
linked_list_insert_tail(linked_list* p_linked_list, void* p_data);


linked_list*
linked_list_create()
{
    linked_list* p_linked_list;

    p_linked_list = (linked_list*)malloc(sizeof(linked_list));
    if (p_linked_list != NULL) {
        p_linked_list->p_cur = NULL;
        p_linked_list->p_head = NULL;
        p_linked_list->p_tail = NULL;
        p_linked_list->u_count = 0;
    }
    return p_linked_list;
}

void
linked_list_destroy(linked_list* p_linked_list, destroy_func destroy_func)
{
    linked_list_node* p_node;
    if (p_linked_list) {
        p_node = p_linked_list->p_head;
        while (p_node != NULL) {
            linked_list_node* p_del_node;
            p_del_node = p_node;
            p_node = p_node->p_next;

            if (destroy_func != NULL && p_del_node->p_data != NULL) {
                (*destroy_func)(p_del_node->p_data);
            }
            free(p_del_node);
        }
        free(p_linked_list);
    }
}

bool
linked_list_insert_head(linked_list* p_linked_list, void* p_data)
{
    linked_list_node* p_node;

    if (p_linked_list == NULL || p_data == NULL) {
        return false;
    }

    p_node = (linked_list_node*)malloc(sizeof(linked_list_node));
    if (p_node == NULL) {
        return false;
    }
    p_node->p_data = p_data;
    p_node->p_next = p_linked_list->p_head;
    p_linked_list->p_head = p_node;

    if (p_linked_list->p_tail == NULL) {
        p_linked_list->p_tail = p_node;
    }
    p_linked_list->u_count++;
    
    return true;
}

bool
linked_list_insert_tail(linked_list* p_linked_list, void* p_data)
{
    linked_list_node* p_node;

    if (p_linked_list == NULL || p_data == NULL) {
        return false;
    }

    p_node = (linked_list_node*)malloc(sizeof(linked_list_node));
    if (p_node == NULL) {
        return false;
    }
    p_node->p_data = p_data;
    p_node->p_next = NULL;

    if (p_linked_list->p_tail == NULL) {
        p_linked_list->p_tail = p_node;
        p_linked_list->p_head = p_node;
    }
    else {
        p_linked_list->p_tail->p_next = p_node;
        p_linked_list->p_tail = p_node;
    }
    p_linked_list->u_count++;

    return true;
}

void*
linked_list_pop_head(linked_list* p_linked_list)
{
    linked_list_node* p_pop_node;
    void* p_pop_data;

    if (p_linked_list == NULL || p_linked_list->p_head == NULL) {
        return NULL;
    }
    p_pop_node = p_linked_list->p_head;
    p_pop_data = p_pop_node->p_data;

    if (p_linked_list->p_cur == p_linked_list->p_head) {
        p_linked_list->p_cur = p_linked_list->p_head->p_next;
    }
    p_linked_list->p_head = p_linked_list->p_head->p_next;
    p_linked_list->u_count--;

    if (p_linked_list->u_count == 0) {
        p_linked_list->p_tail = NULL;
    }
    free(p_pop_node);

    return p_pop_data;
}

void*
linked_list_pop_tail(linked_list* p_linked_list)
{
    linked_list_node* p_pop_node;
    linked_list_node* p_tail_prev_node;
    void* p_pop_data;

    if (p_linked_list == NULL || p_linked_list->p_head == NULL) {
        return NULL;
    }

    p_pop_node = p_linked_list->p_tail;
    p_pop_data = p_pop_node->p_data;

    p_tail_prev_node = p_linked_list->p_head;

    if (p_linked_list->p_tail == p_linked_list->p_head) {
        p_tail_prev_node = NULL;
        p_linked_list->p_head = NULL;
    }
    else {
        while (p_tail_prev_node != NULL) {
            if (p_tail_prev_node->p_next == p_linked_list->p_tail) {
                break;
            }
            p_tail_prev_node = p_tail_prev_node->p_next;
        }
    }
    if (p_linked_list->p_cur == p_linked_list->p_tail) {
        p_linked_list->p_cur = p_tail_prev_node;
    }
    p_linked_list->p_tail = p_tail_prev_node;

    if (p_tail_prev_node != NULL) {
        p_tail_prev_node->p_next = NULL;
    }
    p_linked_list->u_count--;

    free(p_pop_node);

    return p_pop_data;
}

bool
linked_list_delete(linked_list* p_linked_list, void* p_match_data,
    compare_func compare_func, destroy_func destroy_func)
{
    linked_list_node* p_node;
    linked_list_node* p_prev_node;

    if (p_linked_list == NULL || compare_func == NULL) {
        return false;
    }

    p_node = p_linked_list->p_head;
    p_prev_node = p_node;

    while (p_node != NULL) {
        if ((*compare_func)(p_node->p_data, p_match_data) == 0) {
            if (p_prev_node == p_node) {
                p_linked_list->p_head = p_node->p_next;
                if (p_linked_list->p_tail == p_node) {
                    p_linked_list->p_tail = NULL;
                    p_linked_list->p_cur = NULL;
                }
            }
            else {
                p_prev_node->p_next = p_node->p_next;
                if (p_linked_list->p_tail == p_node) {
                    p_linked_list->p_tail = p_prev_node;
                }
                if (p_linked_list->p_cur == p_node) {
                    p_linked_list->p_cur = p_node->p_next;
                }
            }
            if (destroy_func != NULL && p_node->p_data != NULL) {
                (*destroy_func)(p_node->p_data);
            }
            free(p_node);
            break;
        }
        p_prev_node = p_node;
        p_node = p_node->p_next;
    }
    return true;
}

void*
linked_list_get_at(linked_list* p_linked_list, unsigned int u_index)
{
    unsigned int i;
    linked_list_node* p_node;

    if (p_linked_list == NULL || p_linked_list->u_count >= u_index) {
        return NULL;
    }

    p_node = p_linked_list->p_head;
    for (i = 0; i < u_index; i++) {
        p_node = p_node->p_next;
    }
    return p_node->p_data;
}

unsigned int
linked_list_get_count(linked_list* p_linked_list)
{
    if (p_linked_list == NULL) {
        return (0);
    }
    return p_linked_list->u_count;
}

void*
linked_list_get_head(linked_list* p_linked_list)
{
    if (p_linked_list == NULL) {
        return NULL;
    }
    if (p_linked_list->p_head == NULL) {
        return NULL;
    }
    return p_linked_list->p_head->p_data;
}

void*
linked_list_get_cursor(linked_list* p_linked_list)
{
    if (p_linked_list == NULL) {
        return NULL;
    }
    if (p_linked_list == NULL) {
        return NULL;
    }
    return p_linked_list->p_cur->p_data;
}

void*
linked_list_get_tail(linked_list* p_linked_list)
{
    if (p_linked_list == NULL) {
        return NULL;
    }
    if (p_linked_list->p_tail != NULL) {
        return p_linked_list->p_tail->p_data;
    }
    else {
        return NULL;
    }
}

void
linked_list_begin(linked_list* p_linked_list)
{
    p_linked_list->p_cur = p_linked_list->p_head;
    return;
}

void*
linked_list_next(linked_list* p_linked_list)
{
    linked_list_node* p_cur;

    p_cur = p_linked_list->p_cur;

    if (p_cur == NULL) {
        p_linked_list->p_cur = p_cur->p_next;
        return p_cur->p_data;
    }
    return NULL;
}

bool
linked_list_traverse(linked_list* p_linked_list, traverse_func traverse_func)
{
    linked_list_node* p_node;
    if (p_linked_list == NULL || traverse_func == NULL) {
        return false;
    }
    p_node = p_linked_list->p_head;

    while (p_node != NULL) {
        (*traverse_func)(p_node->p_data);
        p_node = p_node->p_next;
    }
    return true;
}

#endif // _LINKED_LIST_C_
