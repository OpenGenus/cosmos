#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void swap (Node *ptr1, Node *ptr2)
{
	int temp = ptr1->data;
	ptr1->data = ptr2 -> data;
	ptr2 -> data = temp;
}

void bubbleSort(struct Node *head)
{
	if(head==NULL)
		return;

	bool flag = false;
	struct Node *ptr1;  //left pointer will always point to the start of the list
    struct Node *ptr2 = NULL;  //right pointer will always point to the end of the list

	while(true)
	{
		flag = false;
		ptr1 = head;

		while(ptr1->next != ptr2)
		{
			if (ptr1->data > ptr1->next->data) 
            {  
                swap(ptr1, ptr1->next); 
                flag = true; 
            } 
            ptr1 = ptr1->next;
		}

		//as the largest element is at the end of the list, assign that to ptr2 as there is no need to
		//check already sorted list

		ptr2 = ptr1;

		if(flag==false)
			break; 
	}
}

void printList(struct Node* head) {

    while (head != NULL) {
        printf("%d-->", head->data);
        head = head->next;
    }

    printf("NULL");
}

/*
Sample Input
1 - Test cases
5 - Total number of elements to be inserted in linked list
23 2 34 5 1 - Adding the contents of the linked list

Sample Output
1 2 5 23 34
*/


int main() 
{
    int test,n,ele;
    scanf("%d", &test);

    /* Inserting elements into linked list*/
    while (test--) 
    {
        struct Node* head = NULL;
        struct Node *temp = NULL;
        scanf("%d", &n);

        while(n--)
        {
            scanf("%d", &ele);

            struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
            ptr->data = ele;
            ptr->next = NULL;

            if(head==NULL)
                head = ptr;
            else
                temp->next = ptr;

            temp = ptr;
        }

        bubbleSort(head);
        printList(head);
    }
    return 0;
}
