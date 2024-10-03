#include <iostream>

using namespace std;

int main() {
    int array[] = {1,2,3,4,5,6,7,8,9,10}; // array of elements

    int valToFind = 4; // the number to find in the array

    int upperLimit = 1;
    int sizeOfArray = sizeof(array)/sizeof(array[0]);

    // Calculate the upperLimit index for binary search
    while(upperLimit < sizeOfArray && array[upperLimit] <= valToFind) {
        upperLimit = upperLimit * 2;
    }

    // Implement binary search from index 0 to upperLimit
    bool foundElement = false;
    int index;
    int low = 0;
    int high = upperLimit;

    // Implement search from [low...high] until the element is found and value of low is less than high
    while(low <= high && !foundElement) {
        int mid = low + (high - low) / 2;
        if(array[mid] == valToFind) { //Element found!
            index = mid; // index of the element in the array
            foundElement = true;
        }
        if (array[mid] >= valToFind) {
            high = mid - 1;
        } else { // array[mid] < valToFind
            low = mid + 1;
        }
    }

    if(foundElement)
        cout << "The entered element " << valToFind << " exists at index " << index << ".\n";
    else
        cout << "The entered element " << valToFind << " doesn't exist in the array.\n";

    return 0;
}