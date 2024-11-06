#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void RowReduce(float A[int x][int y]);

void RowReduce(float A[int x][int y])
{
    const int nrows = x; // number of rows
    const int ncols = y; // number of columns
    int count = 0;

    while (lead < nrows) {
        float d;
        float m;

        for (int r = 0; r < nrows; r++) {
            d = A[count][count];
            m = A[r][count] / A[count][count];

            for (int c = 0; c < ncols; c++) { 
                if (r == count)
                    A[r][c] /= d;               
                else
                    A[r][c] -= A[count][c] * m;  
            }
        }
        count++;
    }
    if (A[nrows][ncols] != 1) {
        //is consistent
        vector<float> solutions;
        for (vector<float> row : matrix) {
            if (FirstNonZero(row) != -1) {
                return;
            }
            float val = round(row.back() * 100.0) / 100.0;
            if (val == -0)
                val = 0;
            solutions.at(FirstNonZero(row)) = val;
        }

        cout << "solution to this set of equations is ";
        for (float val : solutions) {
            if (val == solutions.back())
                cout << val;
            else
                cout << val << ", ";
        }
    }
}