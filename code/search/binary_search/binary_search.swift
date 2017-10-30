//  binary_search.swift
//  Created by iraniya on 10/4/17.

// Part of Cosmos by OpenGenus Foundation

/**
 Binary Search
 
 Recursively splits the array in half until the value is found.
 
 If there is more than one occurrence of the search key in the array, then
 there is no guarantee which one it finds.
 
 Note: The array must be sorted!
 **/

import Foundation

// The recursive version of binary search.
public func binarySearch<T: Comparable>(_ a: [T], key: T, range: Range<Int>) -> Int? {
    if range.lowerBound >= range.upperBound {
        return nil
    } else {
        let midIndex = range.lowerBound + (range.upperBound - range.lowerBound) / 2
        if a[midIndex] > key {
            return binarySearch(a, key: key, range: range.lowerBound ..< midIndex)
        } else if a[midIndex] < key {
            return binarySearch(a, key: key, range: midIndex + 1 ..< range.upperBound)
        } else {
            return midIndex
        }
    }
}

/**
 The iterative version of binary search.
 
 Notice how similar these functions are. The difference is that this one
 uses a while loop, while the other calls itself recursively.
 **/

public func binarySearch<T: Comparable>(_ a: [T], key: T) -> Int? {
    var lowerBound = 0
    var upperBound = a.count
    while lowerBound < upperBound {
        let midIndex = lowerBound + (upperBound - lowerBound) / 2
        if a[midIndex] == key {
            return midIndex
        } else if a[midIndex] < key {
            lowerBound = midIndex + 1
        } else {
            upperBound = midIndex
        }
    }
    return nil
}

let numbers = [1,2,3,4,5]

let key = 5
var find = binarySearch(numbers, key: key, range: 0 ..< numbers.count)  // gives 13

print("Position of \(key) is \(find)")
//printf("Position of %d is %d\n", find, binarySearch(arr, 0, size-1, find));
