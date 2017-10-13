/* Part of Cosmos by OpenGenus Foundation */

//
//  bead_sort.swift
//  Created by DaiPei on 2017/10/12.
//

import Foundation

func beadSort(_ array: inout [Int]) {
    let n = array.count
    var max = Int.min
    for i in 0..<array.count {
        if array[i] > max {
            max = array[i]
        }
    }
    var beads = [Int8](repeatElement(0, count: max * array.count))
    // put beads
    for i in 0..<array.count {
        for j in 0..<max {
            if j < array[i] {
                beads[i * max + j] = 1
            }
        }
    }
    for j in 0..<max {
        // count beads
        var sum = 0
        for i in 0..<array.count {
            sum += Int(beads[i * max + j])
            beads[i * max + j] = 0
        }
        // move down beads
        for i in n - sum..<array.count {
            beads[i * max + j] = 1
        }
    }
    // put sorted value in array using beads
    for i in 0..<array.count {
        var j = 0
        while j < max {
            if beads[i * max + j] == 0 {
                break
            }
            j += 1
        }
        array[i] = j
    }
}
