/* Part of Cosmos by OpenGenus Foundation */

//
//  heap_sort.swift
//  Created by DaiPei on 2017/10/11.
//

import Foundation

func heapSort(_ array: inout [Int]) {
    // create heap
    for i in stride(from: array.count / 2, to: -1, by: -1) {
        sink(array: &array, at: i, to: array.count - 1)
    }
    // sort core
    for i in stride(from: array.count - 1, to: 0, by: -1) {
        swap(&array, at: i, and: 0)
        sink(array: &array, at: 0, to: i - 1)
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
