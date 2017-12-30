// Part of Cosmos by OpenGenus Foundation
package main

import "fmt"

/* Expect Result

 0  59  38  33  30  17   8  63
37  34  31  60   9  62  29  16
58   1  36  39  32  27  18   7
35  48  41  26  61  10  15  28
42  57   2  49  40  23   6  19
47  50  45  54  25  20  11  14
56  43  52   3  22  13  24   5
51  46  55  44  53   4  21  12
*/
type Move struct {
	X int
	Y int
}

var boardSize int

func isSafe(nextX, nextY int) bool {
	return nextX >= 0 && nextX < boardSize && nextY >= 0 && nextY < boardSize
}

func solveKT(board [][]int, currentStep, currentX, currentY int, moves []Move) bool {
	if currentStep == boardSize*boardSize {
		return true
	}

	for _, v := range moves {
		nextX := currentX + v.X
		nextY := currentY + v.Y
		if isSafe(nextX, nextY) && board[nextX][nextY] == -1 {
			board[nextX][nextY] = currentStep
			if solveKT(board, currentStep+1, nextX, nextY, moves) {
				return true
			} else {

				board[nextX][nextY] = -1
			}

		}
	}
	return false
}

func main() {
	boardSize = 8
	board := make([][]int, boardSize)
	for i := range board {
		board[i] = make([]int, boardSize)
		for j := range board[i] {
			board[i][j] = -1
		}
	}

	//Init how knight can walk
	moves := []Move{
		{X: 2, Y: 1},
		{X: 1, Y: 2},
		{X: -1, Y: 2},
		{X: -2, Y: 1},
		{X: -2, Y: -1},
		{X: -1, Y: -2},
		{X: 1, Y: -2},
		{X: 2, Y: -1},
	}

	//Knight start from (0,0)
	board[0][0] = 0
	if !solveKT(board, 1, 0, 0, moves) {
		fmt.Println("solutions don't exist")
	} else {
		for _, row := range board {
			for _, v := range row {
				fmt.Printf("%4d", v)
			}
			fmt.Printf("\n")
		}
	}
}

