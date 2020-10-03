#include<iostream>
#include<climits>
using namespace std;
/*
 * Part of Cosmos by OpenGenus Foundation
 * Reference: https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-3-tic-tac-toe-ai-finding-optimal-move/
 */

class Move {
  public:
    int row,col;
    Move(int row, int col){
      this->row = row;
      this->col = col;
    }
};

char player = 'x', opponent = 'o'; 

/* 
 * description: Checks if there is empty space in matrix.
 */

bool isMovesLeft(char board[3][3]) { 
    for (int i = 0; i<3; i++) {
      for (int j = 0; j<3; j++) {
          if (board[i][j]=='_') 
            return true;  
        }
    }        
    return false; 
} 

/*
 *description: Method returns score to player whenever player/opponents makes a move.
 */

int solve(char b[3][3]) { 
    for (int row = 0; row<3; row++) { 
        if (b[row][0]==b[row][1] && 
            b[row][1]==b[row][2]) { 
            if (b[row][0]==player) 
                return +10; 
            else if (b[row][0]==opponent) 
                return -10; 
        } 
    }
    for (int col = 0; col<3; col++) { 
        if (b[0][col]==b[1][col] && b[1][col]==b[2][col]) { 
            if (b[0][col]==player) 
                return +10; 
  
            else if (b[0][col]==opponent) 
                return -10; 
        } 
    } 
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2]) { 
        if (b[0][0]==player) 
            return +10; 
        else if (b[0][0]==opponent) 
            return -10; 
    } 
    if (b[0][2]==b[1][1] && b[1][1]==b[2][0]) { 
        if (b[0][2]==player) 
            return +10; 
        else if (b[0][2]==opponent) 
            return -10; 
    } 
    return 0; 
} 
  
/*
* description: Methods which executes minimax algorithms
*/

int minimax(char board[3][3], int depth, bool isMax) { 
    int score = solve(board); 
    if (score == 10) 
        return score; 
    if (score == -10) 
        return score; 
    if (isMovesLeft(board)==false) 
        return 0; 
    if (isMax) { 
        int best = INT_MIN; 
        for (int i = 0; i<3; i++) { 
            for (int j = 0; j<3; j++) { 
                if (board[i][j]=='_') { 
                    board[i][j] = player; 
                    best = max( best,minimax(board, depth+1, !isMax) ); 
                    board[i][j] = '_'; 
                } 
            } 
        } 
        return best; 
    } 
    else { 
        int best = 1000; 
        for (int i = 0; i<3; i++) { 
            for (int j = 0; j<3; j++) { 
                if (board[i][j]=='_') { 
                    board[i][j] = opponent; 
                    best = min(best,minimax(board, depth+1, !isMax)); 
                    board[i][j] = '_'; 
                } 
            } 
        } 
        return best; 
    } 
} 

/*
*description: Method which finds the best possible move that player can take!
*/

Move findBestMove(char board[3][3]) {
  int bestValue = INT_MIN;
  Move bestMove = Move(-1,-1);
  for(int i =0;i<3;i++ ){
    for(int j=0;j<3;j++) {
      if(board[i][j] == '_') {
        board[i][j] = player;
        int moveVal = minimax(board, 0, false);
        board[i][j] = '_'; 
        if (moveVal > bestValue) { 
          bestMove.row = i; 
          bestMove.col = j; 
          bestValue = moveVal; 
        }
      }
    }
  }
  return bestMove;
}

int main() {
  char board[3][3] = {
    { 'x', 'o', 'x' }, 
    { 'o', 'x', 'o' }, 
    { '_', '_', '_' } 
  };

  Move bestMove = findBestMove(board);

  cout << bestMove.row << " "<<bestMove.col<<endl;

  return 0;
}