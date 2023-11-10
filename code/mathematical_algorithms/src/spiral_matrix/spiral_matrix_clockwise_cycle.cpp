/*
* Part of Cosmos by OpenGenus Foundation
*/

#include <iostream>
#include <vector>

using namespace std;

void print_top_row(int x, int y, int X, int Y, vector<vector<int>>matrix) {
    for (int i = y; i<= Y; ++i) cout<<matrix[x][i]<<" ";
}

void print_right_column(int x, int y, int X, int Y, vector<vector<int>>matrix) {
    for(int i = x; i<= X; ++i) cout<<matrix[i][Y]<<" ";
}

void print_bottom_row(int x, int y, int X, int Y, vector<vector<int>>matrix) {
    for(int i = Y; i>= y; --i) cout<<matrix[X][i]<<" ";
}

void print_left_column(int x, int y, int X, int Y, vector<vector<int>>matrix) {
    for(int i = X; i >= x; --i) cout<<matrix[i][y]<<" ";
}

void cartisian_cycle(vector<vector<int>>matrix) {
    int x = 0, y = 0;
    int X = matrix.size() - 1; 
    int Y = matrix[0].size() - 1;
    
    while (true)
    {
        if (x > X || y > Y) break;
        print_top_row(x, y, X, Y, matrix); ++x;
        if (x > X || y > Y) break;
        print_right_column(x, y, X, Y, matrix); --Y;
        if (x > X || y > Y) break;
        print_bottom_row(x, y, X, Y, matrix); --X;
        if (x > X || y > Y) break;
        print_left_column(x, y, X, Y, matrix); ++y;
    }  
}

/* Driver Code */
int main()
{
	vector<vector<int>> a = { { 1, 2, 3, 4 }, 
                              { 12, 13, 14, 5 }, 
                              { 11, 16, 15, 6 }, 
                              { 10, 9, 8, 7 } };
					         
	cartisian_cycle(a);
	
	vector<vector<int>> b = { {1,2,3},
	                          {12,13,4},
	                          {11,14,5},
	                          {10,15,6},
	                          {9,8,7} };
	                
	cartisian_cycle(b);
	
	return 0;
}
