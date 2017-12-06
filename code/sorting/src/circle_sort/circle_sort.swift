/* Part of Cosmos by OpenGenus Foundation */

//
//  circle_sort.swift
//  Created by DaiPei on 2017/10/14.
//

import Foundation

func circleSort(_ array: inout [Int]) {
    while circleSort(&array, low: 0, high: array.count - 1) {}
}

private func circleSort(_ array: inout [Int], low: Int, high: Int) -> Bool {
    var swaped = false
    if low == high {
        return swaped
    }
    var l = low
    var h = high
    while l < h {
        if array[l] > array[h] {
            swap(&array, at: l, and: h)
            swaped = true
        }
        l += 1
        h -= 1
    }
    if l == h {
        if l + 1 < array.count && array[l] > array[l + 1] {
            swap(&array, at: l, and: l + 1)
            swaped = true
        }
    }
    let mid = (low + high) / 2
    let left = circleSort(&array, low: low, high: mid)
    let right = circleSort(&array, low: mid + 1, high: high)
    return swaped || left || right
}

private func swap(_ array: inout [Int], at indexA: Int, and indexB: Int) {
    let tmp = array[indexA]
    array[indexA] = array[indexB]
    array[indexB] = tmp
}
