/* Part of Cosmos by OpenGenus Foundation */

//  fibonacci_search.swift
//  Created by erwolfe on 11/17/2017

/**
 Fibonacci Search looks through an array for an element and returns it if its found otherwise -1 is returned.

 - parameters:
     - numberArray: An array of ints that is being traversed to find an element.
     - x: An int that is been looked for in the array.
     - n: The size of the of the array.

 - returns:
 An int that is the index of the element in the array unless its not found and then -1 is returned.
 */
func fibonacciSearch(_ numberArray: [Int], _ x: Int, _ n: Int) -> Int {
    var fibM2 = 0 //(m-2)'th Fibonacci number
    var fibM1 = 1 //(m-1)'th Fibonacci number
    var fibM = fibM2 + fibM1 //m'th Fibonacci

    // Gets the smallest fibonacci number greater than or equal to n
    while(fibM < n){
        fibM2 = fibM1
        fibM1 = fibM
        fibM = fibM2 + fibM1
    }

    // Set offset to -1
    var offset = -1

    // Continue looping until the index of element in the array is found
    while(fibM > 1){
        let i = minimumNumber(offset+fibM2, n-1)
        if numberArray[i] < x {
            fibM = fibM1
            fibM1 = fibM2
            fibM2 = fibM - fibM1
            offset = i
        } else if numberArray[i] > x {
            fibM = fibM2
            fibM1 = fibM1 - fibM2
            fibM2 = fibM - fibM1
        } else {
            return i
        }
    }

    // If the element is found then return the offset plus 1
    if fibM1 == 1 && numberArray[offset+1] == x {
        return offset + 1
    }

    // If the element x is not found then return -1
    return -1
}

/**
 Utility function that returns the minimum number between two ints.

 - parameters:
    - x: An int to check to see if it's the minimum number.
    - y: An int to check to see if it's the minimum number.

 - returns:
 An int that is the minimum number between the two ints.
 */
private func minimumNumber(_ x: Int, _ y: Int) -> Int {
    return x <= y ? x : y
}
