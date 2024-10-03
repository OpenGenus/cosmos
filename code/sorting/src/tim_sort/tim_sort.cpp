/* Part of Cosmos by OpenGenus Foundation */
#include <iostream>

using namespace std;
const int RUN = 32;

/*****************************************************************
Insertion sort is a simple sorting algorithm with a best case time-
complexity of O(n) and average/worst case time-complexity of O(n^2)

It sorts by iterating over the array, checking if the current element
is less than the element before it and, if it is less, swaps it
position with it's predecessor, continuing backwards until its
predecessor is indeed less than itself.

Example:
  Say we begin with an unsorted array, A, of 5 elements
    A = [ 23  1  10  5  2 ]

  First pass:
    starting index = 1, is A[1] < A[0]? Yes, so swap values
          ⤺
      [ 23  1  10  5  2 ]  →  [ 1  23  10  5  2 ]
          ⤻

  Second pass:
    starting index = 2, is A[2] < A[1]? Yes, so swap values
                        is A[1] < A[0]? No, so go to next pass
             ⤺                   ⤺ x
      [ 1  23  10  5  2 ]  →  [ 1  10  23  5  2 ]
             ⤻

  Third pass:
    starting index = 3, is A[3] < A[2]? Yes, so swap values
                        is A[2] < A[1]? Yes, so swap values
                        is A[1] < A[0]? No, so go to next pass
                 ⤺                  ⤺                   ⤺ x
      [ 1  10  23  5  2 ]  →  [ 1  10  5  23  2 ]  →  [ 1  5  10  23  2 ]
                 ⤻                  ⤻

  Fourth pass:
    starting index = 4, is A[4] < A[3]? Yes, so swap values
                        is A[3] < A[2]? Yes, so swap values
                        is A[2] < A[1]? Yes, so swap values
                        is A[1] < A[0]? No, reached end of array so contents should be sorted
                    ⤺                  ⤺                   ⤺                   ⤺ x
      [ 1  5  10  23  2 ]  →  [ 1  5  10  2  23 ]  →  [ 1  5  2  10  23 ]  →  [ 1  2  5  10  23 ]
                    ⤻                  ⤻                   ⤻

  Final order of array:

    [ 1  2  5  10  23 ]
******************************************************************/
void insertion_sort(int A[], int start_i, int end_i) {

    for (int i = start_i + 1; i <= end_i; i++) {
        int temp = A[i];
        int j = i - 1;
        while (j >= start_i && A[j] > temp) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
}

/*****************************************************************
This function merge takes in 2 already sorted arrays and "merges" them
into a singular sorted array. It is used in many different types of
applications along with a few sorting algorithms. It has a time complexity
of O(m + n), where m and n are the sizes of each pre-sorted array.

Example:
  Say we begin with two sorted arrays, A and B, and will merge these into an array C
    A = [ 2  3  7  11  15  36  41 ]
    B = [ 5  7  13  38 ]
    C = [ ]

  We start by getting iterators to the beginning of each array, and comparing
  the element pointed to by A's iterator to the element pointed to by B's iterator.
  If A's element is less than B's, then we add that element to C, and vice versa.
        ↓                                  ↓
  A = [ 2  3  7  11  15  36  41 ]    B = [ 5  7  13  38 ]
         ↘︎
            C = [ 2 ]
  Since A's element is less than B's we add that element to C and increment A's iterator.

  Now, we have A's 3 is less than B's 5
           ↓                               ↓
  A = [ 2  3  7  11  15  36  41 ]    B = [ 5  7  13 ]
            ↘︎
               C = [ 2  3 ]

  Next, B's 5 is less than A's 7
              ↓                            ↓
  A = [ 2  3  7  11  15  36  41 ]    B = [ 5  7  13 ]
                                          ↙︎
                           C = [ 2  3  5 ]

  Now, we have A's 7 is equal to B's 7
              ↓                               ↓
  A = [ 2  3  7  11  15  36  41 ]    B = [ 5  7  13 ]
               ↘︎
                 C = [ 2  3  5  7 ]
  We end up taking A's element since it doesn't matter which we choose

  Next, We have B's 7 is less than A's 11
                 ↓                            ↓
  A = [ 2  3  7  11  15  36  41 ]    B = [ 5  7  13 ]
                                             ↙︎
                        C = [ 2  3  5  7  7 ]

  Next, A's 11 is less than B's 13
                 ↓                               ↓
  A = [ 2  3  7  11  15  36  41 ]    B = [ 5  7  13 ]
                   ↘︎
                     C = [ 2  3  5  7  7  11 ]

  Next, B's 13 is less than A's 15
                     ↓                           ↓
  A = [ 2  3  7  11  15  36  41 ]    B = [ 5  7  13 ]
                                                ↙︎
                    C = [ 2  3  5  7  7  11  13 ]

  Now, since B has no more elements, we empty the rest of A into C
                            ↓
  A   =   [ 2  3  7  7  11  15  36  41 ]
                              ↘︎   ↘︎   ↘︎
  C = [ 2  3  5  7  7  11  13  15  36  41 ]

  Leaving us with a merged sorted array, C, of the two subarrays, A and B.
*****************************************************************/
void merge(int A[], int left_i, int mid_i, int right_i) {

    // calculate length of left and right subarrays
    int left_len = mid_i - left_i + 1;
    int right_len = right_i - mid_i;

    // create and fill temp arrays to hold array contents
    int left_A[left_len];
    int right_A[right_len];
    for (int i = 0; i < left_len; i++) {
        left_A[i] = A[left_i + i];
    }
    for (int i = 0; i < right_len; i++) {
        right_A[i] = A[mid_i + 1 + i];
    }

    // iterators for left and right arrays
    int l = 0, r = 0;
    // iterator for Array A, starting at left index
    int pos = left_i;

    // merge left and right arrays into A in sorted order
    while (l < left_len && r < right_len) {
        if (left_A[l] <= right_A[r]) {
            A[pos] = left_A[l];
            l++;
        } else {
            A[pos] = right_A[r];
            r++;
        }
        pos++;
    }

    // if there are any remaining elements from
    // the left array, add them to array A
    while (l < left_len) {
        A[pos] = left_A[l];
        pos++;
        l++;
    }
    // if there are any remaining elements from
    // the right array, add them to array A
    while (r < right_len) {
        A[pos] = right_A[r];
        pos++;
        r++;
    }
}

/**********************************************************
Timsort is an efficient sorting algorithm with a best case time
complexity of O(n), and an average/worst case time complexity of
O(n * log(n)). It is a combination of Insertion sort and Merge
sort and, with the above examples, shouldn't be too hard to understand.
First, the unsorted array is divided into "runs" of a specific size
(usually 32 or 64), but for the example we will use runs of size 4.
Each "run" is sorted using insertion sort and those runs are then
merged together.

Example:  RUN = 4, for brevity
  Say we begin with an unsorted array, A,
  A = [ 4  6  1  30  21  14  5  39  18  2  9 ]

  The first step is to sort each "run" of the array using insertion sort.
  You can think of each "run" as its own individual subarray.

  A = [ 4  6  1  30    21  14  5  39    18  2  9 ]
            ↙︎                ↓              ↘︎
   insertion sort    insertion sort    insertion sort
          ↓                  ↓               ↓
  A = [ 1  4  6  30    5  14  21  39    2  9  18 ]

  The next step is to mege each sorted subarray back into one
  continuous sorted array. So, from above,

  A = [ 1  4  6  30    5  14  21  39    2  9  18 ]
            ↘︎               ↙︎
                  merge
                    ↓
  A = [ 1  4  5  6  14  21  30  39      2  9  18 ]
                    ↘︎                     ↙︎
                             merge
                               ↓
  A = [ 1  2  4  5  6  9  14  18  21  30  39 ]

  Now, A is a fully sorted array!
**********************************************************/
void tim_sort(int A[], int n) {

    // Sort subarrays of A of size RUN
    for (int i = 0; i < n; i += RUN) {
        if (i + RUN - 1 < n - 1) {
            insertion_sort(A, i, i + RUN - 1);
        } else {
            insertion_sort(A, i, n - 1);
        }
    }

    // Merge previously sorted subarrays from above
    for (int len = RUN; len < n; len = 2 * len) {

        // assign starting point of left subarray,
        // iterates by increasing left by 2 * len
        // since we're merging the subarray to the right
        // which will also be the size of len
        for (int left = 0; left < n; left += 2 * len) {

            // calculate end index of left subarray
            int mid = left + len - 1;
            // calculate end index of right subarray;
            // the right subarray's start index will be mid + 1
            int right;
            if (left + 2 * len - 1 < n - 1) {
                right = left + 2 * len - 1;
            } else {
                right = n - 1;
            }

            // call merge to merge left and right subarrays,
            // those being A[left ... mid] and A[mid + 1 ... right]
            merge(A, left, mid, right);
        }
    }
}

// Driver
int main()
{
    int A[] = {-2, 7, 15, -14, 0, 15, 0, 7, -7, -4, -13, 5, 8, -14, 12};
    int n = 15;

    tim_sort(A, n);

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << '\n';
}
