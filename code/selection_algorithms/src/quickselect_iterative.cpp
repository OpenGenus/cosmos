// Quick Select (Iterative)

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;
/*This algorithm finds the kth largest element in an array. Sorting the list takes O<logn> time, but that is essentially
too much work. Quick select partitions the array and can find the kth largest or smallest element in an average case time
complexity of O(n). In the worst case, we pick the worst possible random partition every time, and the time complexity is
 O(n^2), but this is highly unlikely, and in most cases this is the most efficient algorithm for finding the kth largest
 or smallest element. It was implemented recursively previously, but here it is implemented iteratively, which may be
 more clear to some, especially myself.
*/
int findKthLargest(vector<int>& nums, int k) {
    //We initialize a left and right border because these borders will close in on our "Kth largest" value.
    int leftBorder = 0, rightBorder = nums.size()-1, i = 0, n = nums.size();
    //This algorithm runs until the left and right borders close in on our kth largest element, or we find it.
    while (leftBorder < rightBorder) {
        //We set our iterator, i, to start at the left
        i = leftBorder;
        //Here we create random pivot index, and use this to set a pivot element.
        int pivotIndex = (rand() % (rightBorder -leftBorder)) + leftBorder;
        int pivotVal = nums[pivotIndex];
        //We then swap this element with the last element of the array, so we can keep track of where it is.
        swap(nums[rightBorder], nums[pivotIndex]);
        //We now iterate through the array. We use two pointers, j to represent the current element we are iterating,
        // and i to represent the front of the list of all elements in the array smaller than pivot value.
        for (int j = leftBorder; j <= rightBorder; j++) {
            //When we find a number larger than the pivotValue, we add move it back into the list of numbers smaller than
            //the pivot value, which is represented by all items in the list from index 0 to j.
            if (nums[j] < pivotVal ) {
                swap(nums[j],nums[i]);
                i++;
            }
        }
        //We finally put the pivotValue back where it belongs. This happens to be at index j, which represents all values
        //smaller than it. At this point we know that everything to the left of the pivot is smaller than it, and everything
        // to the right is larger. Think about it!
        swap(nums[i],nums[rightBorder]);

        //If we have say the 4th largest, and we want the 2nd largest, we know the answer is to the right because everything
        //to the right is bigger, so we can move our leftBorder over and repeat.
        if (i < n-k ) {
            leftBorder = i+1;
        }
            //If we have say the 4th largest, and we want the 8th largest, we know the answer is to the left because everything
            //to the left is smaller, so we can move our rightBorder over and repeat.
        else if (i > n-k) {
            rightBorder = i -1;
        }
            //This is the case where we want the 4th largest and the pivot is the 4th largest. We have our answer!
        else {
            return nums[i];
        }
    }
    //We have closed in on our answer, and return it.
    return nums[leftBorder];
}
/*Because we are choosing a random pivot, this algorithm on average takes O(n) runtime in the longrun. While it's worst case
 * time complexity of O(n^2) is worse than that of a sorting algorithm, in most cases, it's time complexity is O(n).*/

int main() {
    bool execute = true;
    while (execute) {
        vector<int> v = {6, 4, 3, 1, 2, 7, 9, 10, 5, 8};
        cout << "v = {6, 4, 3, 1, 2, 7, 9, 10, 5, 8};" << endl;
        int k;
        cout << "Pick a number 1-10 to represent the Kth largest element, 0 to exit: ";
        cin >> k;
        if (k == 0)
            execute = false;
        if (k >= 1 && k <= 10) {
            cout << k << " Largest Element: " << findKthLargest(v,k) << endl;
        }
        else {
            cout << "Invalid entry... Try Again" << endl;
        }
    }
    return 0;
}


