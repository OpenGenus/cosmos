// Calculation of PI using Leibniz formula

#include <iostream>
#include "cmath"
typedef long double ld;
using namespace std;

// Function to calculate pi using Leibniz
ld leibniz(int n)
{
    ld sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += pow(-1,i) / (ld)(2 * i + 1);
    }
    sum *= 4;
    return sum;
}

int main()
{
    // Reading number of terms to be considered in Leibniz formula
    long long int terms;
    cout << "Enter number of terms (More number of terms gives accurate value): \n";
    cin >> terms;
    
    //Function call
    ld pi = leibniz(terms);
    
    // Code to help display upto 10 digits after decimal
    cout.setf(ios::fixed, ios::floatfield );
    cout.precision(10);
    cout <<  "pi = " << pi << endl;
}