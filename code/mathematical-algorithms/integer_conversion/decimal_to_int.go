//Part of cosmos project from OpenGenus Foundation
//Decimal to binay conversion on golang
//Written by Guilherme Lucas (guilhermeslcs)
package main

import (
    "strconv"
    "fmt"
)

func to_bin(decimal int) string {
    var a string;
    a = ""
    for decimal > 0 {
        bit := decimal%2
        decimal = decimal/2
        //Itoa just converts int to char
        a = a + strconv.Itoa(bit)
    }
    return a
}

func main() {
    fmt.Println("Conversion of 5 is", to_bin(5))
    fmt.Println("Conversion of 1 is", to_bin(1))
    fmt.Println("Conversion of 2 is", to_bin(2))
}
