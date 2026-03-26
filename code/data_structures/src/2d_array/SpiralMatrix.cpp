#include <iostream>
#include <vector>
using namespace std;

// Function to generate an n x n spiral matrix
vector<vector<int>> generateSpiralMatrix(int n) {

    // Create an empty n x n matrix filled with 0
    vector<vector<int>> matrix(n, vector<int>(n));

    // These variables represent the current boundaries
    int left = 0;        // left column boundary
    int right = n - 1;   // right column boundary
    int top = 0;         // top row boundary
    int bottom = n - 1;  // bottom row boundary

    // Direction indicator
    // 0 -> left to right
    // 1 -> top to bottom
    // 2 -> right to left
    // 3 -> bottom to top
    int direction = 0;

    // Value that will be filled inside the matrix
    int value = 1;

    // Continue while the boundaries are valid
    while (left <= right && top <= bottom) {

        // Move from LEFT to RIGHT across the top row
        if (direction == 0) {
            for (int i = left; i <= right; i++) {
                matrix[top][i] = value++; // fill value then increment
            }
            top++; // move the top boundary downward
        }

        // Move from TOP to BOTTOM down the right column
        else if (direction == 1) {
            for (int j = top; j <= bottom; j++) {
                matrix[j][right] = value++;
            }
            right--; // move the right boundary left
        }

        // Move from RIGHT to LEFT across the bottom row
        else if (direction == 2) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = value++;
            }
            bottom--; // move the bottom boundary upward
        }

        // Move from BOTTOM to TOP up the left column
        else {
            for (int j = bottom; j >= top; j--) {
                matrix[j][left] = value++;
            }
            left++; // move the left boundary right
        }

        // Change direction (cycle through 0 → 1 → 2 → 3 → 0)
        direction = (direction + 1) % 4;
    }

    // Return the completed spiral matrix
    return matrix;
}

int main() {
    int n;

    // Take matrix size as input
    cin >> n;

    // Generate the spiral matrix
    vector<vector<int>> spiralMatrix = generateSpiralMatrix(n);

    // Print the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << spiralMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
