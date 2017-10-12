/* Part of Cosmos by OpenGenus Foundation */

//
//  selection_sort.swift
//  Created by DaiPei on 2017/10/11.
//

import Foundation

func selectionSort(_ array: inout [Int]) {
    for i in 0..<array.count - 1 {
        var min = i
        for j in i+1..<array.count {
            if array[j] < array[min] {
                min = j
            }
        }
        swap(&array, at: min, and: i)
    }
}
