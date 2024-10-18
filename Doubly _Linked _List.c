#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};
struct DoublyLinkedList {
    struct Node *head;
    struct Node *tail;
};
struct DoublyLinkedList *create_doubly_linked_list() {
    struct DoublyLinkedList *list = (struct DoublyLinkedList *)malloc(sizeof(struct DoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}
void add_to_head(struct DoublyLinkedList *list, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = list->head;
    new_node->prev = NULL;
    if (list->head != NULL) {
        list->head->prev = new_node;
    }
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
}
void add_to_tail(struct DoublyLinkedList *list, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = list->tail;
    if (list->tail != NULL) {
        list->tail->next = new_node;
    }
    list->tail = new_node;
    if (list->head == NULL) {
        list->head = new_node;
    }
}
void remove_from_head(struct DoublyLinkedList *list) {
    if (list->head == NULL) {
        return;
    }
    struct Node *node_to_remove = list->head;
    list->head = node_to_remove->next;
    if (list->head != NULL) {
        list->head->prev = NULL;
    }
    free(node_to_remove);
}
void remove_from_tail(struct DoublyLinkedList *list) {
    if
