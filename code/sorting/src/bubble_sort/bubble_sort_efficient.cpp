#include <vector>
#include <iostream>
using namespace std;

void bubbleSort(vector<int> &v)
{

    for (size_t i = 0; i < v.size() - 1; i++)
    {

        bool isSorted = 1;

        for (size_t j = 0; j < v.size() - 1 - i; j++)
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
                isSorted = 0;
            }

        for (size_t j = v.size() - 2; j >= i; j--)
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
                isSorted = 0;
            }

        if (isSorted)
            break;

    }
    /*
     * In this implementation,
     * Modification From Normal Bubble Sort:
     * 1) Sorting From Both the Sides Simultaneously
     * 2) A variable isSorted which automatically breaks out of loop when elements get sorted reducing the total number of iterations.
     */
}

int main()
{
    int n;
    cout << "Enter the number of elements you want to enter: " << endl;
    cin >> n;
    vector<int> v(n);
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    bubbleSort(v);
    cout << "Sorted Elements: " << endl;
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}
