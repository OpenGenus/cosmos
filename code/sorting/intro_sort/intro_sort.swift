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
        sink(array: &array, at: i, to: b)
    }
    // sort core
    for i in stride(from: b, to: a, by: -1) {
        swap(&array, at: i, and: a)
        sink(array: &array, at: a, to: i - 1)
    }
}

private func sink(array: inout [Int], at indexA: Int, to indexB: Int) {
    var i = indexA
    while (i + 1) * 2 - 1 <= indexB {
        let leftChild = (i + 1) * 2 - 1
        let rightChild = (i + 1) * 2
        let pMax: Int
        if rightChild <= indexB && array[leftChild] < array[rightChild] {
            pMax = rightChild
        } else {
            pMax = leftChild
        }
        if (array[pMax] > array[i]) {
            swap(&array, at: pMax, and: i)
            i = pMax
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
