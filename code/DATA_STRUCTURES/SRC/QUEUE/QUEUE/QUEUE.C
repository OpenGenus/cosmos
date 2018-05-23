/*
 * C Program to Implement a Queue using an Array
 * Part of Cosmos by OpenGenus Foundation
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 50
int queue_array[MAX];
int rear  = -1;
int front = -1;

void insert() {
    int add_item;
    if (rear == MAX - 1) {
        printf("Queue Overflow \n");
    } else {
		/*If queue is initially empty */
        if (front == -1) {
            front = 0;
		}
        printf("Insert the element in queue: ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
	
	return;
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Element deleted from queue is: %d\n", queue_array[front]);
        front = front + 1;
    }
	
	return;
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is: \n");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue_array[i]);
        }
        printf("\n");
    }
	
	return;
}

int main(void) {
    int choice;
    while (1) {
        printf("1. Insert element to queue\n");
        printf("2. Delete element from queue\n");
        printf("3. Display all elements of queue\n");
        printf("4. Quit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Wrong choice\n");
            break;
        }
    }
	
	return 0;
}
