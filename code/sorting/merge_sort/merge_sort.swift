/* Part of Cosmos by OpenGenus Foundation */

//
//  merge_sort.swift
//  Created by DaiPei on 2017/10/11.
//

import Foundation

func mergeSort(_ array: inout [Int]) {
    mergeSort(&array, low:0, high: array.count - 1)
}

private func mergeSort(_ array: inout [Int], low: Int, high: Int) {
    if low < high {
        let mid = (low + high) / 2
        mergeSort(&array, low:low, high:mid)
        mergeSort(&array, low:mid + 1, high:high)
        merge(&array, low:low, mid:mid, high:high)
    }
}

private func merge(_ array: inout [Int], low: Int, mid: Int, high: Int) {
    var tmpArray = [Int](array)
    var i = low, j = mid + 1, k = low
    while i <= mid && j <= high {
        if tmpArray[i] < tmpArray[j] {
            array[k] = tmpArray[i]
            i += 1
        } else {
            array[k] = tmpArray[j]
            j += 1
        }
        k += 1
    }
    while i <= mid {
        array[k] = tmpArray[i]
        i += 1
        k += 1
    }
    while j <= mid {
        array[k] = tmpArray[j]
        j += 1
        k += 1
    }
}

