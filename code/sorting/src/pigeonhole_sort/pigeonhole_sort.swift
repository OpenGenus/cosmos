/* Part of Cosmos by OpenGenus Foundation */

//
//  pigeonhole_sort.swift
//  Created by DaiPei on 2017/10/18.
//

import Foundation

func pigeonholeSort(_ array: inout [Int]) {
    
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
    
    // put element to right hole
    let range = max - min + 1
    var holes = [[Int]](repeatElement([Int](), count: range))
    for item in array {
        holes[item - min].append(item)
    }
    
    // use holes to make sorted array
    var index = 0
    for hole in holes {
        for item in hole {
            array[index] = item
            index += 1
        }
    }
}
