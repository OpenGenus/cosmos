Reversing a linked list using 2 pointers using XOR :

We reverse a given linked list by link reversal and not by swapping the values of the nodes in the linked list.
The common technique to reverse a linked list involves using 3 pointers.
But by using properties of the xor operation, we learn to reverse the linked list with only 2 pointers.
By using xor, we eliminate the need for an extra pointer.
For the 2 pointer technique, we need to caste the pointers to type unitpr_t and then perform bitwise operations (in this case, xor operation) since we cannot perform bitwise operations directly on pointers.

https://iq.opengenus.org/reverse-linked-list-using-2-pointers-xor/
