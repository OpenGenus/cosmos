/* Part of Cosmos by OpenGenus Foundation */

//
//  insertion_sort.swift
//  Created by DaiPei on 2017/10/11.
//

import Foundation

func insertionSort(_ array: inout [Int]) {
    for i in 1..<array.count {
        var j = Int(i)
        let key = array[j]
        while j >= 1 && key < array[j - 1] {
            array[j] = array[j - 1]
            j -= 1
        }
        array[j] = key
    }
}
