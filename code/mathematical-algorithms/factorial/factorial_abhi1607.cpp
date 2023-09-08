    /* 

     * C++ Program to Find Factorial of a Number using Dynamic Programming 

     */

    #include <cstring>

    #include <iostream>

    #include <cstdlib>

    #define ll long long

    using namespace std;

     

    int result[1000] = {0};

    /* 

     * Find Factorial of a Number using Dynamic Programming 

     */

    ll fact_dp(int n)

    {

        if (n >= 0) 

        {

            result[0] = 1;

            for (int i = 1; i <= n; ++i) 

            {

                result[i] = i * result[i - 1];

            }

            return result[n];

        }

    }

    /* 

     * Main

     */

    int main()

    {

        int n;

        while (1)

        {

            cout<<"Enter interger to compute factorial(0 to exit): ";

            cin>>n;

            if (n == 0)

                break;

            cout<<fact_dp(n)<<endl;

        }

        return 0;

    }