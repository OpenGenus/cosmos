package main

import (
	"os"
	"os/exec"
	"bytes"
	"fmt"
	"math/rand"
	"time"
)

type Game struct {
	width int
	height int
	data [][]bool
}

func NewGame(width int, height int) *Game {
	data := make([][]bool, height)
	for i := range data {
		data[i] = make([]bool, width)
	}
	return &Game{
		width: width,
		height: height,
		data: data,
	}
}

func (g *Game) Init(n int) {
	for i := 0; i < n; i ++ {
		g.Set(rand.Intn(g.width), rand.Intn(g.height), true)
	}
}

func (g *Game) Set(i int, j int, b bool) {
	g.data[j][i] = b
}

// Check the cell is alive
func (g *Game) Alive(i int, j int) bool {
	i = (i + g.width) % g.width
	j = (j + g.height) % g.height
	return g.data[j][i]
}

// Return next state of a cell, false = dead, true = alive
func (g *Game) NextState(x int, y int) bool {
	alive := 0
	for i := -1; i <= 1; i++ {
		for j := -1; j <= 1; j++ {
			if !((i == 0) && (j == 0)) && g.Alive(x + i, y + j) {
				alive++
			}
		}
	}
	return alive == 3 || alive == 2 && g.Alive(x, y)
}

func (g *Game) Next() *Game {
	ng := NewGame(g.width, g.height)
	for i := 0; i < g.width; i ++ {
		for j := 0; j < g.height; j ++ {
			ng.Set(i, j, g.NextState(i, j))
		}
	}
	return ng
}

func (g *Game) String() string {
	var buf bytes.Buffer
	for j := 0; j < g.height; j ++ {
		buf.WriteString("'")
		for i := 0; i < g.width; i ++ {
			if g.Alive(i, j) {
				buf.WriteString("o")
			} else {
				buf.WriteString(" ")
			}
		}
		buf.WriteString("'\n")
	}
	return buf.String()
}

func main() {
	g := NewGame(10, 10)
	g.Init(30)
	for i := 0; i < 100; i ++ {
		// Clear screen
		c := exec.Command("clear")
		c.Stdout = os.Stdout
		c.Run()
		fmt.Print(g)
		g = g.Next()
		time.Sleep(100 * time.Millisecond)
	}
	fmt.Println("vim-go")
}

