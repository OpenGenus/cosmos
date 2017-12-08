/// Part of Cosmos by OpenGenus Foundation
/// Find out if a given string is palindrome
/// Contributed by: Guilherme Lucas (guilhermeslucas)

package main

import (
    "fmt"
    "strings"
)

func palindrome(array string) bool {
    array = strings.ToLower(array)
    size := len(array)
    var l int
    var r int
    l = 0
    r = size - 1

    for l <= r {
        if array[l] != array[r] {
            return false
        }
        l = l + 1
        r = r - 1
    }
    return true
}

func main() {
    if (palindrome("Anna")) {
        fmt.Println("anna is palindrome")
    } else {
        fmt.Println("anna is not palindrome")
    }
    if (palindrome("HelLo")) {
        fmt.Println("hello is palindrome")
    } else {
        fmt.Println("hello is not palindrome")
    }
}
