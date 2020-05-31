#include <iostream>
#include <stack>

class InfixToPostfix
{
public:
    InfixToPostfix(const std::string &expression) : expression_(expression) {}

    int getPrecedenceOfOperators(char);

    std::string convertInfixToPostfix();

private:
    std::string expression_;

};

int InfixToPostfix::getPrecedenceOfOperators(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 3;
    else
        return 0;
}

std::string InfixToPostfix::convertInfixToPostfix()
{
    std::stack <char> stack1;
    std::string infixToPostfixExp = "";
    int i = 0;
    while (expression_[i] != '\0')
    {
        //if scanned character is open bracket push it on stack
        if (expression_[i] == '(' || expression_[i] == '[' || expression_[i] == '{')
            stack1.push(expression_[i]);

            //if scanned character is opened bracket pop all literals from stack till matching open bracket gets poped
        else if (expression_[i] == ')' || expression_[i] == ']' || expression_[i] == '}')
        {
            if (expression_[i] == ')')
            {
                while (stack1.top() != '(')
                {
                    infixToPostfixExp = infixToPostfixExp + stack1.top();
                    stack1.pop();
                }
            }
            if (expression_[i] == ']')
            {
                while (stack1.top() != '[')
                {
                    infixToPostfixExp = infixToPostfixExp + stack1.top();
                    stack1.pop();
                }
            }
            if (expression_[i] == '}')
            {
                while (stack1.top() != '{')
                {
                    infixToPostfixExp = infixToPostfixExp + stack1.top();
                    stack1.pop();
                }
            }
            stack1.pop();
        }
            //if scanned character is operator
        else if (expression_[i] == '+' || expression_[i] == '-' || expression_[i] == '*' || expression_[i] == '/' || expression_[i] == '^')
        {
            //very first operator of expression is to be pushed on stack
            if (stack1.empty()) {
                stack1.push(expression_[i]);
            }
            else{
                /*
                 * check the precedence order of instack(means the one on top of stack) and incoming operator,
                 * if instack operator has higher priority than incoming operator pop it out of stack&put it in
                 * final postifix expression, on other side if precedence order of instack operator is less than i
                 * coming operator, push incoming operator on stack.
                 */
                if (getPrecedenceOfOperators(stack1.top()) >= getPrecedenceOfOperators(expression_[i]))
                {
                    infixToPostfixExp = infixToPostfixExp + stack1.top();
                    stack1.pop();
                    stack1.push(expression_[i]);
                }
                else
                {
                    stack1.push(expression_[i]);
                }
            }
        }
        else
        {
            //if literal is operand, put it on to final postfix expression
            infixToPostfixExp = infixToPostfixExp + expression_[i];
        }
        i++;
    }

    //poping out all remainig operator literals & adding to final postfix expression
    if (!stack1.empty())
    {
        while (!stack1.empty())
        {
            infixToPostfixExp = infixToPostfixExp + stack1.top();
            stack1.pop();
        }
    }

    return infixToPostfixExp;

}

int main()
{
    std::string expr;
    std::cout << "\nEnter the Infix Expression : ";
    std::cin >> expr;
    InfixToPostfix p(expr);
    std::cout << "\nPostfix expression         : " << p.convertInfixToPostfix();
}
