// C++ program to rotate a linked list counter clock wise by k nodes
// where k can be greater than length of linked list

#include <bits/stdc++.h>

class node {
public:
	int data;
	node *next;

	node(int data) {
		this->data = data;
		next = NULL;
	}
};

node *insert() {
	// no. of values to insert
	std::cout << "Enter no. of nodes you want to insert in linked list: " << "\n";
	int n;
	std::cin >> n;
	node *head = NULL;
	node *temp = head;

	std::cout << "Enter " << n << " values of linked list : " << "\n";
	for (int i = 0; i < n; i++) {
		int value;
		std::cin >> value;
		if (i == 0) {
			// insert at head
			head = new node(value);
			temp = head;
			continue;
		} else {
			temp->next = new node(value);
			temp = temp->next;
		}
	}
	return head;
}

node *rotate(node *head, int k) {
	// first check whether k is small or greater than length of linked list
	// so first find length of linked list
	int len = 0;
	node *temp = head;
	while (temp != NULL) {
		temp = temp->next;
		len++;
	}
	// length of linked list = len

	// update k according to length of linked list
	// because k can be greater than length of linked list
	k = k % len;

	if (k == 0) {
		// since when k is multiple of len its mod becomes zero
		// so we have to correct it
		k = len;
	}
	if (k == len) {
		// since if k==len then even after rotating it linked list will remain same
		return head;
	}

	int count = 1;
	temp = head;
	while (count < k and temp != NULL) {
		temp = temp->next;
		count++;
	}

	node *newHead = temp->next;
	temp->next = NULL;
	temp = newHead;

	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = head;
	return newHead;
}

void printList(node *head) {
	node *temp = head;
	while (temp != NULL) {
		std::cout << temp->data << " --> ";
		temp = temp->next;
	}
	std::cout << "NULL" << "\n";
	return;
}

int main() {
	node *head = insert();
	printList(head);
	std::cout << "Enter value of k: " << "\n";
	int k;
	std::cin >> k;
	head = rotate(head, k);
	std::cout << "After rotation : " << "\n";
	printList(head);
	return 0;
}

// Input and Output :
/*
Enter no. of nodes you want to insert in linked list:
9
Enter 9 values of linked list :
1 2 3 4 5 6 7 8 9
1 --> 2 --> 3 --> 4 --> 5 --> 6 --> 7 --> 8 --> 9 --> NULL
Enter value of k:
3
After rotation :
4 --> 5 --> 6 --> 7 --> 8 --> 9 --> 1 --> 2 --> 3 --> NULL
*/
