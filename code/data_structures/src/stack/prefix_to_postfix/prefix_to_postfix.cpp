#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

// Stack structure and operations
struct Stack 
{
    int top;
    char** stacks;
    
    Stack(int x) 
    { 
        top = -1;
        stacks = (char**)malloc(x * sizeof(char*));
    }
    char* rtop() 
    { 
        if(top!= -1)
            return stacks[top];
        else
            return "$";
    }
    void push(char* x) 
    {
        top++;
        stacks[top] = x;
    }
    void pop() 
    {
        if (top > -1) 
            top--;
    }
};

// Utility to check if the given character is an operand
int isOperand(char ch) 
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Converts prefix to Postfix expression
char* preToPost(char* pre_exp) 
{
    // Length of expression the old fashioned way
    char* ptr = pre_exp;
    while (*ptr != '\0') {
        ptr++;
    }
    int length = ptr - pre_exp;

    // Declare a stack of maximum size: length/2 + 1 
    Stack s(length / 2 + 1);

    // Reading from right to left
    for (int i = length - 1; i > -1; i--) 
    {
        // If symbol is an operand
        if (isOperand(pre_exp[i]))
        {
            char* op3 = (char*)malloc(2 * sizeof(char*));
            op3[0] = pre_exp[i];
            op3[1] = '\0';
            // push the operand to the stack
            s.push(op3);
        }
        // If symbol is operator
        else if(pre_exp[i] != '(' || pre_exp[i] != ')')
        {
            // Pop two operands from stack
            char* op1 = s.rtop();
            s.pop();
            char* op2 = s.rtop();
            s.pop();

            // Concat the operands and operator 
            // in the form op1 + op2 + pre_exp[i]
            strcat(op1, op2);
            char* ptr = op1;
            while (*ptr != '\0') {
                ptr++;
            }
            *ptr = pre_exp[i];
            ptr++;
            *ptr = '\0';

            // Push string temp back to stack
            s.push(op1);
        }
    }

    // Stack contains only the Postfix expression
    return s.rtop();
}

// Driver Code
int main() 
{
    char exp[] = "+++*AB/CDEF";
    printf("%s\n", preToPost(exp));
    
    return 0;
}