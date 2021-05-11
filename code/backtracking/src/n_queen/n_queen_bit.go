// Part of Cosmos by OpenGenus Foundation
package main

import "fmt"

/*
Expected output

Total solutions 73712 for bordsize 13
*/

var totalSol int
var limit uint
var boardSize uint

func nQueen(boardSize, position, left, right, depth uint) {
	if boardSize == depth {
		totalSol++
		return
	}

	var newPos uint
	currentPos := position | left | right

	for currentPos < limit {
		newPos = (currentPos + 1) & ^currentPos
		nQueen(boardSize, position|newPos, limit&((left|newPos)<<1), limit&((right|newPos)>>1), depth+1)
		currentPos = currentPos | newPos

	}
	return
}

func main() {
	boardSize = 13

	limit = (1 << (boardSize)) - 1
	totalSol = 0
	nQueen(boardSize, 0, 0, 0, 0)
	fmt.Printf("Total solutions %d for bordsize %d\n", totalSol, boardSize)
}

