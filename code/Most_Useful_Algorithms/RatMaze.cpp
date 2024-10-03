#include <iostream>
#include <vector>

using namespace std;

const int N = 4; 
void printSolution(vector<vector<int>>& sol) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}


bool isSafe(vector<vector<int>>& maze, int x, int y) {
    
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}


bool solveMaze(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& sol) {
    
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    
    if (isSafe(maze, x, y)) {
        
        sol[x][y] = 1;

        
        if (solveMaze(maze, x, y + 1, sol)) {
            return true;
        }

        
        if (solveMaze(maze, x + 1, y, sol)) {
            return true;
        }

        
        sol[x][y] = 0;
        return false;
    }

    return false;
}

int main() {
    vector<vector<int>> maze(N, vector<int>(N, 0));

    cout << "Enter the 4x4 maze (0 for blocked cell, 1 for open cell):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
        }
    }

    vector<vector<int>> solution(N, vector<int>(N, 0));

    if (solveMaze(maze, 0, 0, solution)) {
        cout << "Solution Path:" << endl;
        printSolution(solution);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
