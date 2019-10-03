package main

import "fmt"
import "strings"

func removeDup(stringValue string) string {
	characterMap := make(map[string]bool)
	uniqueCharacters := []string{}
	for _, char := range stringValue {
		if !characterMap[string(char)] {
			uniqueCharacters = append(uniqueCharacters, string(char))
			characterMap[string(char)] = true
		}
	}

	return strings.Join(uniqueCharacters, "")
}

func main() {
	testValues := []string{"1234567", "aaaaabbbbccccddddeeee", "abcdbcdacdbadbac"}
	for _, testValue := range testValues {
		fmt.Printf("%s: %s\n", testValue, removeDup(testValue))
	}
}
