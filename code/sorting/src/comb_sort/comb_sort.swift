/* Part of Cosmos by OpenGenus Foundation */

//
//  comb_sort.swift
//  Created by DaiPei on 2017/10/15.
//

import Foundation

func combSort(_ array: inout [Int]) {
    let shrinkFactor = 0.8
    var gap = array.count
    var swapped = true
    while gap >= 1 || swapped {
        swapped = false
        if gap >= 1 {
            gap = Int(Double(gap) * shrinkFactor)
        }
        for i in stride(from: 0, to: array.count - gap, by: 1) {
            if array[i] > array[i + gap] {
                swap(&array, at: i, and: i + gap)
                swapped = true
            }
        }
    }
}

private func swap(_ array: inout [Int], at indexA: Int, and indexB: Int) {
    let tmp = array[indexA]
    array[indexA] = array[indexB]
    array[indexB] = tmp
}
