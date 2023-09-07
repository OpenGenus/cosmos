#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int m, i = 0;

    for (int k = 0; k < n; k++)
    {
        int x = v[k];
        if (!i)
        {
            m = x;
            i = 1;
        }
        else if (m == x)
            i++;
        else
            i--;
    }

    cout << "The majority element is: " << m;


    return 0;
}
