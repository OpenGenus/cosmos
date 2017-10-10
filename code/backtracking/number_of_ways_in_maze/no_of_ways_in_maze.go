// Part of Cosmos by OpenGenus Foundation
package main

import "fmt"

type Point struct {
	X int
	Y int
}

var totalWays int

func SolveMaze(maze [][]byte, sol [][]byte, current, end Point, limitH, limitW int) {
	if maze[current.X][current.Y] == '1' {
		return
	}

	if sol[current.X][current.Y] == '1' {
		return
	}

	sol[current.X][current.Y] = '1'
	if current == end {
		totalWays++
		for _, v := range sol {
			for _, k := range v {
				fmt.Printf("%c ", k)
			}
			fmt.Print("\n")
		}
		fmt.Print("\n")
	}

	if current.X+1 < limitH {
		current.X += 1
		SolveMaze(maze, sol, current, end, limitH, limitW)
		current.X -= 1
	}

	if current.X-1 >= 0 {
		current.X -= 1
		SolveMaze(maze, sol, current, end, limitH, limitW)
		current.X += 1
	}

	if current.Y+1 < limitW {
		current.Y += 1
		SolveMaze(maze, sol, current, end, limitH, limitW)
		current.Y -= 1
	}

	if current.Y-1 >= 0 {
		current.Y -= 1
		SolveMaze(maze, sol, current, end, limitH, limitW)
		current.Y += 1
	}

	sol[current.X][current.Y] = '0'
	return
}

func main() {
	maze := [][]byte{
		{'0', '0', '1', '1', '1'},
		{'0', '0', '0', '0', '0'},
		{'0', '1', '1', '0', '0'},
		{'0', '0', '0', '1', '0'},
		{'0', '1', '0', '0', '0'},
	}

	solution := [][]byte{
		{'0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '0'},
	}

	totalWays = 0
	start := Point{X: 0, Y: 0}
	end := Point{X: 4, Y: 4}
	SolveMaze(maze, solution, start, end, 5, 5)
	fmt.Printf("There are %d ways to escape from (%d:%d) to (%d:%d)\n", totalWays, start.X, start.Y, end.X, end.Y)
}
