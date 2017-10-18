/* Part of Cosmos by OpenGenus Foundation */

//
//  pigeonhole_sort.swift
//  Created by DaiPei on 2017/10/18.
//

import Foundation

func pigeonhole_sort(_ array: inout [Int]) {
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
    let range = max - min + 1
    var hole = [Int](repeatElement(0, count: range))
    for item in array {
        hole[item - min] += 1
    }
    var index = 0
    for i in 0..<range {
        var count = hole[i]
        while count > 0 {
            array[index] = i + min
            index += 1
            count -= 1
        }
    }
}
