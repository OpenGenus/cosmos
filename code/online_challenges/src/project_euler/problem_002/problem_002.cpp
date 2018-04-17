#include <iostream>

int main()
{
    // Variables to keep track of Fibonacci numbers
    int p2 = 0;
    int p1 = 0;
    int current = 1;

    int sum = 0;

    while (current <= 4000000)
    {
        // Add even fibonacci numbers
        sum += (current % 2 == 0) ? current : 0;

        // Update fibonacci numbers
        p2 = p1;
        p1 = current;
        current = p2 + p1;
    }

    std::cout << sum << "\n";
}
