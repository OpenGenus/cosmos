#include <iostream>
// Part of Cosmos by OpenGenus Foundation
using namespace std;

void print_matrix(char matrix[][100], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << matrix[i][j];
        cout << endl;
    }
}


void paint_fill(int i, int j, char dot, char colour, char matrix[][100], int n, int m)
{
    if (matrix[i][j] != dot || i<0 || j<0 || i>n - 1 || j>m - 1)
        return;

    matrix[i][j] = colour;

    paint_fill(i + 1, j, dot, colour, matrix, n, m);
    paint_fill(i - 1, j, dot, colour, matrix, n, m);
    paint_fill(i, j + 1, dot, colour, matrix, n, m);
    paint_fill(i, j - 1, dot, colour, matrix, n, m);

}


int main()
{
    int n, m;
    char matrix[100][100];
    cout << "Enter N and M: ";
    cin >> n >> m;

    //enter matrix i.e. the image
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    print_matrix(matrix, n, m);
    paint_fill(8, 13, '.', 'R', matrix, n, m);
    print_matrix(matrix, n, m);

    return 0;
}
