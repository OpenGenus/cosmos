//Part of the Cosmos Project by OpenGenus
//Find out if two strings are angram
//Written by Guilherme Lucas (guilhermeslucas)
package main

import (
    "fmt"
    "sort"
    "strings"
)

func prepareString(w string) string {
    s := strings.Split(w, "")
    sort.Strings(s)
    return strings.Join(s, "")
}

func isAnagram (first_word string, second_word string) bool {
    first := prepareString(strings.ToLower(first_word))
    second := prepareString(strings.ToLower(second_word))
    return first == second
}

func main() {
    if (isAnagram("god","dog")) {
        fmt.Println("Dog and God are anagrams")
    } else {
        fmt.Println("Dog and God are not anagrams")
    }
    if (isAnagram("pie","apple")) {
        fmt.Println("Pie and Apple are anagrams")
    } else {
        fmt.Println("Pie and Apple are not anagrams")
    }
}
