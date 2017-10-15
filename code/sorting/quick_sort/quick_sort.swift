/* Part of Cosmos by OpenGenus Foundation */

//
//  quick_sort.swift
//  Created by DaiPei on 2017/10/11.
//

import Foundation

func quickSort(_ array: inout [Int]) {
    quickSort(&array, low: 0, high: array.count - 1)
}

private func quickSort(_ array: inout [Int], low: Int, high: Int) {
    if low < high {
        let div = partition(&array, low: low, high: high)
        quickSort(&array, low: low, high: div - 1)
        quickSort(&array, low: div + 1, high: high)
    }
}

private func partition(_ array: inout [Int], low: Int, high: Int) -> Int {
    var div = low
    var p = low
    let mid = (low + high) / 2
    swap(&array, at: mid, and: high)
    while p < high {
        if array[p] < array[high] {
            swap(&array, at: p, and: div)
            div += 1
        }
        p += 1
    }
    swap(&array, at: high, and: div)
    return div
}

private func swap(_ array: inout [Int], at indexA: Int, and indexB: Int) {
    let tmp = array[indexA]
    array[indexA] = array[indexB]
    array[indexB] = tmp
}
