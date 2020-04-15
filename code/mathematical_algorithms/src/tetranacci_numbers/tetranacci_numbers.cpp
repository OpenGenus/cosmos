#include <iostream>
#include <cstdlib>

using namespace std;

//simple recursive algorithm to find sum of the numbers
int tetranacci(int n){

    //base cases
    if(n <= 2)
        return 0;
    if(n == 3)
        return 1;

    //recurrence relationship
    return tetranacci(n-1) + tetranacci(n-2) + tetranacci(n-3) + tetranacci(n-4);

}


int main(int argc, char** argv){

    int num = atoi(argv[1]);

    cout << tetranacci(num) << endl;


}

