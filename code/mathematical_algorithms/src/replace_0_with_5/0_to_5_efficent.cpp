#include <iostream>
// Part of Cosmos by OpenGenus Foundation
using namespace std;
long long int input()
{
    char c;
    long long int num = 0, neg = 1;
    c = getchar();
    if (c == '-')
    {
        neg = -1;
        c = getchar();
    }
    while (c != '\n')
    {
        if (c == ' ')
            return num * neg;
        if (c == '0')
            c = '5';
        num = num * 10 + (c - '0');
        c = getchar();
    }
    return num * neg;
}
int main()
{
    long long int number;
    number = input();
    cout << number << "\n";
}
