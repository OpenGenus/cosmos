#include <iostream>
#include <stack>
using namespace std;

// funtion to check if character is operator or not
bool isOperator(char x) {
    switch (x) {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

// Convert prefix to Postfix expression
string preToPost(string pre_exp) {

    stack<string> s;

    // length of expression
    int length = pre_exp.size();

    // reading from right to left
    for (int i = length - 1; i >= 0; i--) {

        // check if symbol is operator
        if (isOperator(pre_exp[i])) {

            // pop two operands from stack
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            // concat the operands and operator
            string temp = op1 + op2 + pre_exp[i];

            // Push string temp back to stack
            s.push(temp);
        }

        // if symbol is an operand
        else {

            // push the operand to the stack
            s.push(string(1, pre_exp[i]));
        }
    }

    // stack contains only the Postfix expression
    return s.top();
}

// Driver Code
int main() {
    string pre_exp;
    cout << "Enter the prefix expression:";
    cin >> pre_exp;
    cout << "Postfix : " << preToPost(pre_exp);
    return 0;
}
