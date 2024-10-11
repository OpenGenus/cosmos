#include <iostream>
#include <vector>
using namespace std;

// Function to generate odd-order magic square
void generateMagicSquare(int n) {
    vector<vector<int>> magicSquare(n, vector<int>(n, 0));

    // Starting position for 1
    int i = 0, j = n / 2;

    // Fill the magic square by placing values
    for (int num = 1; num <= n * n; num++) {
        magicSquare[i][j] = num;

        // Store previous position
        int new_i = (i - 1 + n) % n;
        int new_j = (j + 1) % n;

        // Check if the calculated position is already filled
        if (magicSquare[new_i][new_j]) {
            i = (i + 1) % n;
        } else {
            i = new_i;
            j = new_j;
        }
    }

    // Output the magic square
    cout << "The Magic Square for n = " << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << magicSquare[i][j] << "\t";
        }
        cout << endl;
    }

    // Display the sum of each row (which is the same for all rows/columns/diagonals)
    cout << "Sum of each row or column = " << n * (n * n + 1) / 2 << endl;
}

int main() {
    int n;
    cout << "Enter the size of the magic square (odd number): ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "Magic square works only for odd numbers!" << endl;
        return 1;
    }

    generateMagicSquare(n);
    return 0;
}
