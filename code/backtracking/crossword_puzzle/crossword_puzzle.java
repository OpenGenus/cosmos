import java.io.*;
import java.util.*;

public class CrosswordPuzzle {
    public static void display(String[][] arr){
        for(int i = 0; i < arr.length; i++){
            for(int j = 0; j < arr[i].length; j++){
                System.out.print(arr[i][j]);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        String[][] grid = new String[10][10];
        for(int i = 0; i < 10; i++){
            grid[i] = scn.nextLine().split("");
        }

        String[] words = scn.nextLine().split(";");

        for(int i = 0; i < words.length; i++){
            if(puzzleSolved(grid, words, words[i], 0, 0)){
                break;
            }
        }

        display(grid);
    }

    public static boolean puzzleSolved(String[][] grid, String[] words, String word, int row, int col){

      if(col >= grid.length){
            col = 0;
            row += 1;
        }

      while(row < grid.length && !grid[row][col].equals("-")){
            col += 1;
            if(col >= grid.length){
                col = 0;
                row += 1;
            }
        }

        if(row == grid.length){
          return false;
        }

        boolean isPlacedHoz = false, isPlacedVer = false;
        while(row - 1 >= 0 && !grid[row - 1][col].equals("+")){
          row -= 1;
        }

        isPlacedVer = placeVertical(grid, row, col, word);
        if(!isPlacedVer){
          while(col - 1 >= 0 && !grid[row][col - 1].equals("+")){
              col -= 1;
            }

          isPlacedHoz = placeHorizontal(grid, row, col, word);
        }
        if( isPlacedVer || isPlacedHoz){
          String[] remainingWords = new String[words.length - 1];

          if(remainingWords.length == 0){
                return true;
            }

          int i = 0, j = 0;
            while(i < words.length){
              if(!words[i].equals(word)){
                remainingWords[j] = words[i];
                  j++;
              }
              i++;
            }

            String pword = word;
          for(int k = 0; k < remainingWords.length; k++){
            word = remainingWords[k];
              if(puzzleSolved(grid, remainingWords, word, row, col + 1)){
                   return true;
                }
            }
          if(isPlacedHoz){
            clearHorizontal(grid, row, col, pword);
          }
          if(isPlacedVer){
            clearVertical(grid, row, col, pword);
          }
        }
        return false;
    }

    public static boolean placeHorizontal(String[][] grid, int row, int col, String word){
        if(word.length() == 0 && (col == grid.length || grid[row][col].equals("+"))){
          return true;
        }else if(col == grid.length || word.length() == 0){
            return false;
        }

        if(grid[row][col].equals("-") || grid[row][col].equals(word.charAt(0)+"")){
          String prev = grid[row][col];
            grid[row][col] = word.charAt(0) + "";
            if(placeHorizontal(grid, row, col + 1, word.substring(1))){
                return true;
            }
            grid[row][col] = prev;
        }
        return false;
    }

    public static boolean placeVertical(String[][] grid, int row, int col,String word){
        if(word.length() == 0 && (row == grid.length || grid[row][col].equals("+"))){
            return true;
        } else if(row == grid.length || word.length() == 0){
            return false;
        }
        if(grid[row][col].equals("-") || grid[row][col].equals(word.charAt(0)+"")){
          String prev = grid[row][col];
            grid[row][col] = word.charAt(0) + "";
            if(placeVertical(grid, row + 1, col, word.substring(1))){
                return true;
            }
            grid[row][col] = prev;
        }
        return false;
    }

    public static void clearHorizontal(String[][] grid, int row, int col, String word){
        int pcol = col;
      while(pcol < grid.length && pcol < col + word.length()){
            grid[row][pcol] = "-";
            pcol++;
        }
    }

    public static void clearVertical(String[][] grid, int row, int col, String word){
        int prow = row;
      while(prow < grid.length && prow < row + word.length()){
            grid[prow][col] = "-";
            prow++;
        }
    }
}
