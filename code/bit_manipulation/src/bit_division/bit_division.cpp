/*
Problem Statement : 
Divide two numbers using bitwise operators
(i.e without using arithmetic operators)
*/

#include <iostream>
using namespace std;

int bitDivision(int numerator, int denominator) 
{
    int current = 1;
    int answer = 0;

    if (denominator > numerator)
        return 0;
    else if (denominator == numerator)
        return 1;

    while (denominator < numerator) 
    {
        denominator <<= 1;
        current <<= 1;
    }

    denominator >>= 1;
    current >>= 1;

    while (current != 0) 
    {
        if (numerator >= denominator) 
        {
            numerator -= denominator;
            answer |= current;
        }

        current >>= 1;
        denominator >>= 1;
    }

    return answer;
}

int main() 
{
    int numerator, denominator;
    // numerator -> represents dividend
    // denominator -> represents divisor

    cout << "Enter numerator and denominator : ";
    cin >> numerator >> denominator;

    cout << "\nQuotient after bitwise division : " << bitDivision(numerator, denominator) << endl;

    return 0;
}

/*
Enter numerator and denominator : 10 4

Quotient after bitwise division : 2
*/
