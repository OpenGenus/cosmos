// Part of Cosmos by OpenGenus Foundation
package main

import "fmt"

func abs(number int) int {
	if number < 0 {
		return number * -1
	}
	return number
}

//Check could we put a queen on specific row,col
func checkPlace(board []int, row, col int) bool {
	for i := 0; i < row; i++ {
		//check same col
		if board[i] == col {
			return false
		}
		//check diag, if the different count between rows is same as the different count between col
		if abs(board[i]-col) == abs(i-row) {
			return false
		}
	}

	return true

}

func nQueen(board []int, currentRow int) {
	if currentRow == len(board) {
		fmt.Println("Done", board)
		return
	}

	for i := 0; i < len(board); i++ {
		if checkPlace(board, currentRow, i) {
			board[currentRow] = i
			nQueen(board, currentRow+1)
		}
	}

}

func main() {
	boardSize := 4
	board := make([]int, boardSize)
	nQueen(board, 0)
}
