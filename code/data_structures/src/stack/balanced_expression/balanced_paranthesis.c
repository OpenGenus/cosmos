#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
	char data;
	struct stack* next;
}stack;

void push(stack** top, char data) {
    stack* new = (stack*)malloc(sizeof(stack));
    new->data = data;
    new->next = *top;
    *top = new;
}

char peek(stack* top) {
    return top->data;
}

int empty(stack* top) {
    if(top == NULL) return 1;
    return 0;
}

void pop(stack** top) {
    stack* temp = *top;
    *top = (*top)->next;
    free(temp);
    temp = NULL;    
}

int checkBalanced(char *s) {
	if (strlen(s) % 2 != 0) return 0;
	stack *head = NULL;
	for (int i=0;i < strlen(s);i++) {
		if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
			push(&head,s[i]);
		}
		else {
			char temp = peek(head);
			if (s[i] == '}' && temp == '{') pop(&head);
			else if (s[i] == ']' && temp == '[') pop(&head);
			else if (s[i] == ')' && temp == '(') pop(&head);
			else return 0;
		}
	}
	return empty(head);
}

int main()
{
	char *s = (char*)malloc(sizeof(char) * 100);
	printf("Enter the expression\n");
	scanf("%[^\n]s" , s);
	int res = checkBalanced(s);
	if (res) printf("Expression is valid\n");
	else printf("Expression is not valid\n");
	return 0;
}
