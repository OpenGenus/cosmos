#include <iostream>
using namespace std;
 
void printTrib(int n)
{
    if (n < 1)
        return;
 
    int first = 0, second = 0, third = 1;
 
    cout << first << " ";
    if (n > 1)
        cout << second << " ";
    if (n > 2)
        cout << second << " ";
 
    for (int i = 3; i < n; i++) {
        int curr = first + second + third;
        first = second;
        second = third;
        third = curr;
 
        cout << curr << " ";
    }
}

int main()
{
    int n = 10;
    printTrib(n);
    return 0;
}
