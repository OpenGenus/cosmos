#include <iostream>
#include <vector>

// Naive O(sum^3) solution
void solveNaive(int sum)
{
    for (int i = 1; i < sum; ++i)
        for (int j = 1; j < sum; ++j)
        {
            for (int k = 1; k < sum; ++k)
                if (((i * i) + (j * j) == (k * k)) && ((i + j + k) == sum))
                {
                    std::cout << i * j * k << "\n";
                    goto OutsideLoop;
                }
        }
OutsideLoop:     // Need this for breaking outside all three loops
    return;
}

/*
 * O(sum) solution
 * From the equations below:
 *   a^2 + b^2 = c^2
 *   a + b + c = sum
 * We can get that:
 *   c = sum - a - b
 *   b = a^2 / 2(sum-a) + (sum-a) / 2
 * This way the value of a determines
 * uniquely the values of b and c
 */   
std::vector<int> findPythTripletWithSum(int sum)
{
    for (int a = 1; a < sum; ++a)
        if ((a*a) % (2*(sum - a)) == 0 && (sum - a) % 2 == 0)
        {
            int b = a*a / (2*(sum - a)) + (sum - a) / 2;
            int c = sum - a - b;
            if (b > 0 && b < sum && c > 0 && c < sum)
                return { a, b, c };
        }
    return { -1, -1, -1 };
}

int main()
{
    std::vector<int> result = findPythTripletWithSum(1000);
    std::cout << result[0] * result[1] * result[2] << std::endl;
    return 0;
}
