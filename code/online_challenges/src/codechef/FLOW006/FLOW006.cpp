#include <iostream>

int main()
{
    int t, n;

    //Input number of testcases-->t
    std::cin >> t;

    while (t > 0)
    {
        std::cin >> n;
        //Initialise sum with
        int sum = 0;

        while (n != 0)
        {
            sum = sum + n % 10;
            n = n / 10;
        }

        std::cout << sum << "\n";
        --t;
    }
    return 0;
}
