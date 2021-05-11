// Part of Cosmos by OpenGenus
#include <iostream>
using namespace std;

int fib(int n)
{
    int *ans = new int[n + 1]; //creating an array to store the outputs
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];  // storing outputs for further use
    }
    return ans[n];
}
int main()
{
    int n;
    cout << "Enter the Number:";  // taking input
    cin >> n;
    int output = fib(n);
    cout << "Nth fibonacci no. is:" << output << endl;  //printing nth fibonacci number
}