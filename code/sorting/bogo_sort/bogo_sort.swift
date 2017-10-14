/* Part of Cosmos by OpenGenus Foundation */

//
//  bogo_sort.swift
//  Created by DaiPei on 2017/10/14.
//

import Foundation

func bogoSort(_ array: inout [Int]) {
    while !isSorted(array) {
        shuffle(&array)
    }
}

private func shuffle(_ array: inout [Int]) {
    for i in 0..<array.count {
        let j = Int(arc4random()) % array.count
        swap(&array, at: i, and: j)
    }
}

private func isSorted(_ array: [Int]) -> Bool {
    if array.count <= 1 {
        return true
    }
    for i in 1..<array.count {
        if array[i] < array[i - 1] {
            return false
        }
    }
    return true
}

private func swap(_ array: inout [Int], at indexA: Int, and indexB: Int) {
    let tmp = array[indexA]
    array[indexA] = array[indexB]
    array[indexB] = tmp
}
