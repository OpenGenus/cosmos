/* Part of Cosmos by OpenGenus Foundation */

#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int get_fib(int num);

int main()
{  
    int number;

    cout << "Enter the value of n: ";
    cin >> number;
  
    if(number > 46 || number < 0)
    {
        cout << "Must enter an integer between 0 and 46\n";
        exit(0);
    }
    
    int n_fib = get_fib(number);

    cout << "Fibonacci number is: " << n_fib << endl;

    return 0;
}

int get_fib(int num)
{    
    vector<int> fibnum(num+1);

    //Fibonacci first two number are always 0 and 1
    fibnum[0] = 0;
    fibnum[1] = 1;

    //Stores the values of the Fibnonacci numbers inside the vector
    for (int i = 2; i <= num; i++)
        fibnum[i] = fibnum[i-1] + fibnum[i-2];
    
    return fibnum[num];
}
