/* Part of Cosmos by OpenGenus Foundation */

//
//  bucket_sort.swift
//  Created by DaiPei on 2017/10/14.
//

import Foundation

private let defaultStep = 5

func bucketSort(_ array: inout [Int]) {
    bucketSort(&array, withStep: defaultStep)
}

func bucketSort(_ array: inout [Int], withStep step: Int) {
    // find the max and min value in array
    var max = Int.min
    var min = Int.max
    for val in array {
        if val > max {
            max = val
        }
        if val < min {
            min = val
        }
    }
    // calculate the buckets count
    let n = (max - min) / step + 1
    var buckets = [[Int]](repeatElement([Int](), count: n))
    // put value to buckets
    for val in array {
        let j = (val - min) / step
        buckets[j].append(val)
    }
    // sort value in buckets
    for i in 0..<buckets.count {
        sortCore(&buckets[i])
    }
    // put value back to origin array
    var index = 0
    for i in 0..<buckets.count {
        var bucket = buckets[i]
        for j in 0..<bucket.count {
            array[index] = bucket[j]
            index += 1
        }
    }
}

private func sortCore(_ array: inout [Int]) {
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
