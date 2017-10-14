/* Part of Cosmos by OpenGenus Foundation */

//
//  selection_sort.swift
//  Created by DaiPei on 2017/10/11.
//

import Foundation

func selectionSort(_ array: inout [Int]) {
    for i in stride(from: 0, to: array.count - 1, by: 1) {
        var min = i
        for j in i+1..<array.count {
            if array[j] < array[min] {
                min = j
            }
        }
        swap(&array, at: min, and: i)
    }
}

private func swap(_ array: inout [Int], at indexA: Int, and indexB: Int) {
    let tmp = array[indexA]
    array[indexA] = array[indexB]
    array[indexB] = tmp
}
