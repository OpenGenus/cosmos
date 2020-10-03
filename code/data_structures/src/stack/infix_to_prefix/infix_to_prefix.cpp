// Including Library
#include <iostream>
#include <ctype.h>
#include <string.h>
#include <stack>

/** Function to check if given character is
    an operator or not. **/
bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

/** Function to find priority of given
    operator.**/
int getPriority(char c)
{
    if (c == '-' || c == '+')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    return 0;
}

/** Function that converts infix
    expression to prefix expression. **/
std::string infixToPrefix(std::string infix)
{
    // stack for operators.
    std::stack<char> operators;
    // stack for operands.
    std::stack<std::string> operands;

    for (int i = 0; i < infix.length(); i++)
    {
        /** If current character is an
        opening bracket, then
        push into the operators stack. **/
        if (infix[i] == '(')
            operators.push(infix[i]);


        /** If current character is a
            closing bracket, then pop from
            both stacks and push result
            in operands stack until
            matching opening bracket is
            not found. **/
        else if (infix[i] == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                // operand 1
                std::string op1 = operands.top();
                operands.pop();
                // operand 2
                std::string op2 = operands.top();
                operands.pop();
                // operator
                char op = operators.top();
                operators.pop();
                /** Add operands and operator
                   in form operator +
                   operand1 + operand2. **/
                std::string tmp = op + op2 + op1;
                operands.push(tmp);
            }

            /** Pop opening bracket from stack. **/
            operators.pop();
        }

        /** If current character is an
            operand then push it into
            operands stack. **/
        else if (!isOperator(infix[i]))
            operands.push(std::string(1, infix[i]));


        /** If current character is an
            operator, then push it into
            operators stack after popping
            high priority operators from
            operators stack and pushing
            result in operands stack. **/
        else
        {
            while (!operators.empty() && getPriority(infix[i]) <= getPriority(operators.top())) {
                std::string op1 = operands.top();
                operands.pop();
                std::string op2 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                std::string tmp = op + op2 + op1;
                operands.push(tmp);
            }
            operators.push(infix[i]);
        }
    }

    /** Pop operators from operators stack
        until it is empty and add result
        of each pop operation in
        operands stack. **/
    while (!operators.empty())
    {
        std::string op1 = operands.top();
        operands.pop();

        std::string op2 = operands.top();
        operands.pop();

        char op = operators.top();
        operators.pop();

        std::string tmp = op + op2 + op1;
        operands.push(tmp);
    }

    /** Final prefix expression is
        present in operands stack. **/
    return operands.top();
}

// Driver code
int main()
{
    std::string s;
    std::cin >> s;
    std::cout << infixToPrefix(s);
    return 0;
}

// Input - (A-B/C)*(A/K-L)
// Output - *-A/BC-/AKL
