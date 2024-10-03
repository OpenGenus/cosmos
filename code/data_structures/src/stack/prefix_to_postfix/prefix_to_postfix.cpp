// CPP Program to convert prefix to postfix
#include <iostream>
#include <stack>
using namespace std;

// funtion to check if character is operator or not
bool IsOperator(char x)
{
  switch (x)
  {
  case '+':
  case '-':
  case '/':
  case '*':
    return true;
  }
  return false;
}

// Function to convert prefix expression to Postfix expression
string preToPost(string pre_exp)
{

  stack<string> s;

  // length of expression
  int length = pre_exp.size();

  // reading from right to left
  for (int i = length - 1; i >= 0; i--)
  {

    // check if symbol is operator
    if (IsOperator(pre_exp[i]))
     {

      // pop two operands from stack
      string op1 = s.top(); s.pop();
      string op2 = s.top(); s.pop();

      // concat the operands and operator
      string temp = op1 + op2 + pre_exp[i];

      // Push string temp back to stack
      s.push(temp);
    }

    // if symbol is an operand
    else
    {

      // push the operand to the stack
      s.push(string(1, pre_exp[i]));
    }
  }

  // stack contains only the Postfix expression
  return s.top();
}

// Main function
int main()
{
  string pre_exp;
  cout<<"Enter a prefix expression:";
  getline(cin,pre_exp);
  cout << "Postfix expression: " << preToPost(pre_exp);
  return 0;
}
