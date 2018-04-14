#include <vector>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
int selectPivotIndex(const vector<int>& A, const int left, const int right)
{
    const int mid = (left + right) / 2; // median of three
    if (A[left] > A[mid]) // this is really insertion sort
    {
        if (A[left] > A[right])
        {
            if (A[right] > A[mid])
                return right;
            else
                return mid;
        }
        else
            return left;
    }
    else
    {
        if (A[mid] > A[right])
        {
            if (A[left] > A[right])
                return left;
            else
                return right;
        }
        else
            return mid;
    }
}

int partition(vector<int>& A, const int left, const int right,
              const int pivot)
{
    swap(A[pivot], A[right]);
    int store = left;
    for (int i = left; i < right; i++)
        if (A[i] <= A[right])
        {
            swap(A[i], A[store]); store++;
        }
    swap(A[store], A[right]);
    return store;
}

int selectKth(vector<int>& A, const int k, const int left, const int right)
{
    const int idx = selectPivotIndex(A, left, right); // pivot around element
    const int pivot = partition(A, left, right, idx);
    const int kth = left + k - 1;
    if (kth == pivot)
        return pivot;
    if (kth < pivot)
        return selectKth(A, k, left, pivot - 1);
    else
        return selectKth(A, kth - pivot, pivot + 1, right);
}

void medianSort(vector<int>& A, const int left, const int right)
{
    if (left >= right)
        return;
    const int medianIdx = selectKth(A, 1 + (right - left) / 2, left, right);
    const int mid = (right + left) / 2;
    swap(A[mid], A[medianIdx]); // median valued element is now the middle
    int k = mid + 1;
    for (int i = left; i < mid; i++)
        if (A[i] > A[mid])
        {
            while (A[k] > A[mid])
                k++;             // find element on right to move left of mid
            swap(A[i], A[k]);
        }
    medianSort(A, left, mid - 1);
    medianSort(A, mid + 1, right);
}

void sort(vector<int>& A)
{
    medianSort(A, 0, A.size() - 1);
}
