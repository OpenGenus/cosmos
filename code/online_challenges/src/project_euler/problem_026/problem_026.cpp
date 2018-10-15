#include <iostream>
#include <vector>

int main()
{
    int remainder, value, position, sequenceLength = 0;

    for (int i = 1000; i > 0; --i)
    {
        std::vector<int> cycleCheckArray;

        for (int j = 0; j < i; ++j)
            cycleCheckArray.push_back(0);

        remainder = 1, value = 1, position = 0;
        while (true)
        {
            value = remainder * 10;
            remainder = value % i;

            if (cycleCheckArray[remainder])
            {
                sequenceLength = position - cycleCheckArray[remainder];
                break;
            }

            cycleCheckArray[remainder] = position;
            ++position;
        }
        if (sequenceLength == i - 1)
            std::cout << i << "\n";
    }

    return 0;
}
