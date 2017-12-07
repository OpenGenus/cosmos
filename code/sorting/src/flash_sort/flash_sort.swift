/* Part of Cosmos by OpenGenus Foundation */

//
//  flash_sort.swift
//  Created by DaiPei on 2017/10/17.
//

import Foundation

func flashSort(_ array: inout [Int]) {
    // find the max and min item
    var max = Int.min
    var min = Int.max
    for item in array {
        if item > max {
            max = item
        }
        if item < min {
            min = item
        }
    }
    if max == min {
        return
    }
    
    // divide to m class
    let m = Int(0.43 * Double(array.count))
    let c = Double(m - 1) / Double(max - min)
    
    // save every class pointer
    var pClass = [Int](repeatElement(0, count: m + 1))
    for item in array {
        let k = Int(c * Double(item - min)) + 1
        pClass[k] += 1
    }
    for k in 1...m {
        pClass[k] += pClass[k - 1] // pClass[k]: point to upper bound of class k
    }
    
    // move every element to right class
    var move = 0
    var j = 0
    var k = m
    // after this loop pClass[k] point to under bound of class k, it means every element is moved to the right class
    while move < array.count {
        while j >= pClass[k] {
            j += 1
            k = Int(c * Double(array[j] - min)) + 1
        }
        var flash = array[j]
        while j < pClass[k] {
            k = Int(c * Double(flash - min)) + 1
            pClass[k] -= 1
            swap(&flash, &array[pClass[k]])
            move += 1
        }
    }
    
    // sort every class
    for i in 1..<m {
        sortCore(&array, from: pClass[i], to: pClass[i + 1])
    }
}

private func swap(_ array: inout [Int], at a: Int, and b: Int) {
    let tmp = array[a]
    array[a] = array[b]
    array[b] = tmp
}

private func sortCore(_ array: inout [Int], from a: Int, to b: Int) {
    if a >= b {
        return
    }
    for i in a..<b-1 {
        var p = i
        for j in i+1..<b {
            if array[j] < array[p] {
                p = j
            }
        }
        swap(&array, at: p, and: i)
    }
}
