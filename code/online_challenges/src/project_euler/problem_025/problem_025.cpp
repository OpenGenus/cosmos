#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    vector < int > temp, prevFibonacci, currFibonacci;

    int count = 2;

    prevFibonacci.push_back(1);
    currFibonacci.push_back(1);
        
    while (currFibonacci.size() < 1000) 
    {
        int carry = 0;
        count++;
        for (int i = 0; i < prevFibonacci.size(); i++) 
        {
            temp.push_back((currFibonacci[i] + prevFibonacci[i] + carry) % 10);
            carry = (currFibonacci[i] + prevFibonacci[i] + carry) / 10;
        }

        for (int i = prevFibonacci.size(); i < currFibonacci.size(); i++)
        {
            temp.push_back((currFibonacci[i] + carry) % 10);
            carry = (currFibonacci[i] + carry) / 10;
        }

        if (carry) 
            temp.push_back(carry);

        prevFibonacci = currFibonacci;
        currFibonacci = temp;
        temp.clear();
    }
    cout << "Index of 1000 digit Fibonacci Number is " << count << endl;
}