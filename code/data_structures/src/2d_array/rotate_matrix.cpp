//#rotate square matrix by 90 degrees

#include <bits/stdc++.h>
#define n 5
using namespace std;

void displayimage(
    int arr[n][n]);

/* A function to
 * rotate a n x n matrix
 * by 90 degrees in
 * anti-clockwise direction */
void rotateimage(int arr[][n])
{ // Performing Transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
            swap(arr[i][j], arr[j][i]);
    }

    // Reverse every row
    for (int i = 0; i < n; i++)
        reverse(arr[i], arr[i] + n);
}

// Function to print the matrix
void displayimage(int arr[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << "  ";

        cout << "\n";
    }
    cout << "\n";
}

int main()
{

    int arr[n][n] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};

    // displayimage(arr);
    rotateimage(arr);

    // Print rotated matrix
    displayimage(arr);

    return 0;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Test Case 2
 *    int arr[n][n] = {
 *                       {1, 2, 3, 4},
 *                       {5, 6, 7, 8},
 *                       {9, 10, 11, 12},
 *                       {13, 14, 15, 16}
 *                   };
 */

/* Tese Case 3
 *int mat[n][n] = {
 *               {1, 2},
 *               {3, 4}
 *           };*/

 /*
Time complexity : O(n*n)
Space complexity: O(1)
 */
