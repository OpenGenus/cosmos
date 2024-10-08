/// Part of Cosmos by OpenGenus Foundation
/// Receives a string and returns the reverse of it
/// Contributed by: Joao Pedro Campos Silva (joaopedrocampos)

package main

import (
	"fmt"
)

// Function to reverse a string
func reverseString(s string) string {
	runes := []rune(s)

	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}

	return string(runes)
}

func main() {
	fmt.Println(reverseString("I know what you did last summer")) // Output: remmus tsal did uoy tahw wonk I
	fmt.Println(reverseString("OpenGenus cosmos"))                // Output: somsoc suneGnepO
	fmt.Println(reverseString("GoLang"))                          // Output: gnaLoG
	fmt.Println(reverseString("12345"))                           // Output: 54321
}
