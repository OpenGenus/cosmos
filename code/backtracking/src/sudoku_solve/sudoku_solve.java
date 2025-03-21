public void solve(int row, int col)
   {
      if (row > 8)
      {
         printBoard();
         System.out.println();
         return;
      }
      if (board[row][col] != 0)
      {
         if (col < 8)
            solve(row, col + 1);
         else
            solve(row + 1, 0);
      }
      else
      {
         for (int i = 0; i < 10; i++)
            if (checkRow(row, i) && checkCol(col, i))
                  //&& checkSquare(row, col, i))
            {
               board[row][col] = i;
               if (col < 8)
                  solve(row, col + 1);
               else
                  solve(row + 1, 0);
            }
         board[row][col] = 0;
      }
   }

   private boolean checkRow(int row, int numberToCheck)
   {
      for (int i = 0; i < 9; i++)
         if (board[row][i] == numberToCheck)
            return false;

      return true;
   }

   private boolean checkCol(int col, int numberToCheck)
   {
      for (int i = 0; i < 9; i++)
         if (board[i][col] == numberToCheck)
            return false;

      return true;
   }
