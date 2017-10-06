#include<iostream>
using namespace std;
#include<cctype>
#define MAX_SIZE 100
char a[MAX_SIZE], top = -1;
bool isEmpty()
{
    if(top == -1)
        return true;
    return false;
}
void push(char x)
{
    if(top == MAX_SIZE-1)
    {
        cout<<"Stack is full"<<endl;
        return;
    }
    a[++top] = x;
}
char pop()
{
    char x;
    if(isEmpty())
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        x = a[top];
        top--;
    }
    return x;
}
int atop()
{
    return a[top];
}
int presedence(char x)
{
    switch(x)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}
string InToPostfix(string x)
{
    string r = "";
    for(int i=0; i<x.length(); i++)
    {
        char c = x[i];
        if(isalnum(c))
        {
            r += c;
        }
        else if(c == '(')
        {
            push(c);
        }
        else if(c == ')')
        {
            while(!isEmpty() && atop() != '(')
            {
                r += pop();
            }
            if(atop() == '(')
            {
                pop();
            }
            else
                cout<<"Invalid Expression"<<endl;
        }
        else
        {
            while(!isEmpty() && presedence(c)<=presedence(atop()))
            {
                r += pop();
            }
            push(c);
        }
    }
    while(!isEmpty())
    {
        r += pop();
    }
    return r;
}
int main()
{
    string x,r;
    cout<<"Enter infix expression: ";
    cin>>x;
    r = InToPostfix(x);
    cout<<"Postfix evaluated expression: "<<r<<endl;
    return 0;
}
