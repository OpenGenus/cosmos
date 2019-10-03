#include <iostream>
#include <vector>
using namespace std;

void bar(int, int, int)
{
    // less space
    if (true)  
    {
        vector<int> vec{1, 2, 3};
        int i = (1 + 2) * 3;
    }
}
void foo()
{  
    // more space
    if (true)
    {
        vector<int> vec{1, 2, 3};
        int i = (1 + 2) * 3;
        bar(1, 2, 3);
    }

    while (true)
        for (int i = 0; i < 10; ++i)
            do
                cout << 123;
            while (true);

    int i = 1;
    switch (i)
    {
        case 1:
            cout << 1;
            break;
        default:
            break;
    }
}
