#include <iostream>
using namespace std;

int BinarySearch(int arr[], int start, int end, int item){

    if(start > end)
        return -1;

    int mid = start + (end-start)/2;

    if (arr[mid] == item)
        return mid;
    else if(arr[mid] < item)
        BinarySearch(arr, mid+1, end, item);
    else
        BinarySearch(arr, start, mid-1, item);
}

int main(){
    int arr[5] = {2,4,5,6,8};
    int n = 5;
    int item = 6;

    int index = BinarySearch(arr, 0, n-1, item);

    if(index>=0)
        cout << "Element Found at index - " << index;
    else
        cout << "Element Not Found!!";

    return 0;
}
