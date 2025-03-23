package main

import "fmt"

func towerOfHanoi(n int, from, to, aux string) {
	if n >= 1 {
		towerOfHanoi(n-1, from, aux, to)
		fmt.Printf("Move %d, from %s to %s\n", n, from, to)
		towerOfHanoi(n-1, aux, to, from)
	}
}

func main() {
	towerOfHanoi(5, "A", "C", "B")
}
