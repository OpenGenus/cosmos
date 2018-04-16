#include <iostream>
#include <vector>

using namespace std;

bool is_perfect(int);

int main()
{
    int max = 8129;
    cout << "List of perfect numbers between 1 and " << max << ": " << endl;
    for (int i = 6; i < max; i++)
        if (is_perfect(i))
            cout << i << ", ";
}

bool is_perfect(int p_num_to_check)
{
    int sum = 0, i; // Class level variables
    for (i = 1; i < p_num_to_check; i++) // Loop from [1, num) TODO: Improve this
        if (p_num_to_check % i == 0)
            sum += i;

    return sum == p_num_to_check;
}
