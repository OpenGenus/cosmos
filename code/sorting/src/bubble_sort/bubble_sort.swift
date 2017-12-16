/* Part of Cosmos by OpenGenus Foundation */

//
//  bubble_sort.swift
//  Created by DaiPei on 2017/10/10.
//

import Foundation

func bubbleSort(_ array: inout [Int]) {
    let n: Int = array.count
    for i in stride(from: 0, to: n - 1, by: 1) {
        var swapped = false
        for j in stride(from: 0, to: n - i - 1, by: 1) {
            if array[j] > array[j+1] {
                swapped = true
                swap(&array, at: j, and: j+1)
            }
        }
        if !swapped {
            break
        }
    }
}

private func swap(_ array: inout [Int], at indexA: Int, and indexB: Int) {
    let tmp = array[indexA]
    array[indexA] = array[indexB]
    array[indexB] = tmp
}
