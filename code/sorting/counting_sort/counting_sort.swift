/* Part of Cosmos by OpenGenus Foundation */

//
//  counting_sort.swift
//  Created by DaiPei on 2017/10/15.
//

import Foundation

func countingSort(_ array: inout [Int]) {

    // find the max value
    var m = Int.min
    for val in array {
        if val < 0 {
            return
        }
        if m < val {
            m = val
        }
    }
    
    // count every element and save it
    var freq = [Int](repeatElement(0, count: m + 1))
    for val in array {
        freq[val] += 1
    }
    
    // use freq to create sorted array
    var j = 0
    for i in 0..<freq.count {
        var count = freq[i]
        while count > 0 {
            array[j] = i
            j += 1
            count -= 1
        }
    }
}
