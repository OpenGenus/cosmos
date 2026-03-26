#include <iostream>
using namespace std;

// User-defined function
float calculate(float num1, float num2, char op)
{
    switch (op)
    {
        case '+':
            return num1 + num2;

        case '-':
            return num1 - num2;

        case '*':
            return num1 * num2;

        case '/':
            if (num2 == 0)
            {
                cout << "Error! Division by zero.\n";
                return 0;
            }
            return num1 / num2;

        default:
            cout << "Error! Operator is not correct.\n";
            return 0;
    }
}

int main()
{
    char op;
    float num1, num2, result;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter two operands: ";
    cin >> num1 >> num2;

    result = calculate(num1, num2, op);

    // Print result only if operator is valid
    if (op == '+' || op == '-' || op == '*' || op == '/')
    {
        cout << num1 << " " << op << " " << num2 << " = " << result;
    }

    return 0;
}
