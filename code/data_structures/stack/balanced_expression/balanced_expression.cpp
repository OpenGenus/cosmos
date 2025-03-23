#include<iostream>
using namespace std;

bool isValid(char expression[]) {

    char stack[100];
    int len=0;
    int expressionLength = strlen(expression);
    
    for (int i=0;i<expressionLength;i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
            stack[len++] = expression[i];
        else {
            if (expression[i] == ')')
                if (stack[len-1] == '(')
                    len--;
                else
                    return false;
            else if (expression[i] == '}')
                if (stack[len-1] == '{')
                    len--;
                else
                    return false;
            else if (expression[i] == ']')
                if (stack[len-1] == '[')
                    len--;
                else
                    return false;
        }
    }

    if (len==0)
        return true;
    else
        return false;
}

int main() {

    char expression[100];
    cout<<"Enter your expression : ";
    cin>>expression;

    bool result = isValid(expression);
    if (result)
        cout<<"It is a valid expression\n";
    else
        cout<<"It is not a valid expression\n";

    return 0;
}
