/* Part of Cosmos by OpenGenus Foundation */

//
//  bead_sort.swift
//  Created by DaiPei on 2017/10/12.
//

import Foundation

func beadSort(_ array: inout [Int]) {
    let n = array.count
    var m = Int.min
    // find the max value
    for i in 0..<n {
        if array[i] > m {
            m = array[i]
        }
    }
    var beads = [Int8](repeatElement(0, count: m * n))
    // put beads
    for i in 0..<n {
        for j in 0..<m {
            if j < array[i] {
                beads[i * m + j] = 1
            }
        }
    }
    for j in 0..<m {
        // count beads
        var sum = 0
        for i in 0..<n {
            sum += Int(beads[i * m + j])
            beads[i * m + j] = 0
        }
        // move down beads
        for i in n - sum..<n {
            beads[i * m + j] = 1
        }
    }
    // put sorted value in array using beads
    for i in 0..<n {
        var j = 0
        while j < m {
            if beads[i * m + j] == 0 {
                break
            }
            j += 1
        }
        array[i] = j
    }
}
