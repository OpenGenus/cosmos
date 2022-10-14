#include <iostream>
#include <stack>
using namespace std;

int arr[] = {4, 1, 5, 3, 50, 30, 70, 80, 28, 22};
stack<int> higherStack, lowerStack;

void displayArray();
void quick_sort(int lower, int higher);
void partition(int lower, int higher);

int main()
{
    lowerStack.push(0);
    higherStack.push(9);
    quick_sort(0,9);
    displayArray();
}

void quick_sort(int lower, int higher)
{
    if (sizeof(arr) / 4 <= 1)
    {
        return;
    }

    while (!lowerStack.empty())
    {
        partition(lower, higher);

        quick_sort(lowerStack.top(), higherStack.top());
        lowerStack.pop();
        higherStack.pop();
    }
}

void displayArray()
{
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void partition(int lower, int higher)
{
    int i = lower;
    int j = higher;
    int pivot = arr[lower];
    while (i <= j)
    {
        while (pivot <= arr[i] && i<=higher)
        {
            i++;
        }
        while (pivot > arr[j] && j<=lower)
        {
            j--;
        }

        if(i>j) swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[lower]);

    lowerStack.push(lower);
    lowerStack.push(j + 1);
    higherStack.push(j - 1);
    higherStack.push(higher);
}