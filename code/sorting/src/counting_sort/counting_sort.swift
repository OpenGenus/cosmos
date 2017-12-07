/* Part of Cosmos by OpenGenus Foundation */

//
//  counting_sort.swift
//  Created by DaiPei on 2017/10/15.
//

import Foundation

func countingSort(_ array: inout [Int]) {
    // find max and min value in array
    var max = Int.min
    var min = Int.max
    for item in array {
        if item > max {
            max = item
        }
        if item < min {
            min = item
        }
    }
    
    // calculate every element position
    let range = max - min + 1
    var position = [Int](repeatElement(0, count: range))
    for item in array {
        position[item - min] += 1
    }
    for i in 1..<position.count {
        position[i] += position[i - 1]
    }
    
    // put every element to right position
    var index = 0
    for i in 0..<range {
        while index < position[i] {
            array[index] = i + min
            index += 1
        }
    }
}
