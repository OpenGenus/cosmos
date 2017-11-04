/* Part of Cosmos by OpenGenus Foundation */

//
//  intro_sort.swift
//  Created by DaiPei on 2017/10/21.
//

import Foundation

func introSort(_ array: inout [Int]) {
    introSortCore(&array, from: 0, to: array.count - 1, depth: Int(2 * log(Double(array.count))));
}

private func introSortCore(_ array: inout [Int], from a: Int, to b: Int, depth: Int) {
    if a < b {
        if depth == 0 {
            heapSort(&array, from: a, to: b)
        } else {
            if isSorted(&array, from: a, to: b) {
                return
            }
            let div = partition(&array, low: a, high: b)
            introSortCore(&array, from: a, to: div - 1, depth: depth - 1)
            introSortCore(&array, from: div + 1, to: b, depth: depth - 1)
        }
    }
}

// quick sort core
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


// heap sort part
private func heapSort(_ array: inout [Int], from a: Int, to b: Int) {
    // create heap
    for i in stride(from: (a + b) / 2, to: a - 1, by: -1) {
        sink(&array, at: i, from: a, to: b)
    }
    // sort core
    for i in stride(from: b, to: a, by: -1) {
        swap(&array, at: i, and: a)
        sink(&array, at: a, from: a, to: i - 1)
    }
}

private func sink(_ array: inout [Int], at x: Int, from a: Int, to b: Int) {
    let b1 = b - a + 1
    var i = x
    var i1 = i - a + 1
    while 2 * i1 <= b1 {
        let l1 = 2 * i1
        let r1 = 2 * i1 + 1
        let l = l1 + a - 1
        let r = r1 + a - 1
        let p: Int
        if r <= b && array[l] < array[r] {
            p = r
        } else {
            p = l
        }
        if array[p] > array[i] {
            swap(&array, at: p, and: i)
            i = p
            i1 = i - a + 1
        } else {
            break
        }
    }
}

private func swap(_ array: inout [Int], at indexA: Int, and indexB: Int) {
    let tmp = array[indexA]
    array[indexA] = array[indexB]
    array[indexB] = tmp
}

private func isSorted(_ array: inout [Int], from a: Int, to b: Int) -> Bool {
    for i in a+1...b {
        if array[i] < array[i - 1] {
            return false
        }
    }
    return true
}
