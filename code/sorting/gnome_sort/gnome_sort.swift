/* Part of Cosmos by OpenGenus Foundation */

//
//  gnome_sort.swift
//  Created by DaiPei on 2017/10/16.
//

import Foundation

func gnomeSort(_ array: inout [Int]) {
    if array.count <= 1 {
        return
    }
    var index = 1
    while index < array.count {
        if index == 0 {
            index += 1
        }
        if array[index] >= array[index - 1] {
            index += 1
        } else {
            swap(&array, at: index, and: index - 1)
            index -= 1
        }
    }
}

private func swap(_ array: inout [Int], at indexA: Int, and indexB: Int) {
    let tmp = array[indexA]
    array[indexA] = array[indexB]
    array[indexB] = tmp
}
