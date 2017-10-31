/* Part of Cosmos by OpenGenus Foundation */

//
//  median_sort.swift
//  Created by DaiPei on 2017/10/25.
//

import Foundation

func medianSort(_ array: inout [Int]) {
    recursiveMediaSort(&array, left: 0, right: array.count - 1)
}

private func recursiveMediaSort(_ array: inout [Int], left: Int, right: Int) {
    if left < right {
        var piv = pivot(&array, left: left, right: right)
        piv = partition(&array, left: left, right: right, pivot: piv)
        recursiveMediaSort(&array, left: left, right: piv - 1)
        recursiveMediaSort(&array, left: piv + 1, right: right)
    }
}

// find a good pivot for quick sort
private func pivot(_ array: inout [Int], left: Int, right: Int) -> Int {
    let range = right - left + 1
    if range < 6 {
        return median5(&array, left: left, right: right)
    }
    for subLeft in stride(from: left, to: right + 1, by: 5) {
        var subRight = subLeft + 4
        if subRight > right {
            subRight = right
        }
        let medianIndex = median5(&array, left: subLeft, right: subRight)
        swap(&array, at: medianIndex, and: Int(floor(Double(subLeft - left) / 5)) + left)
    }
    return select(&array, left: left, right: left + (range - 1) / 5, of: left + range / 10)
}

// find median in 5 number
private func median5(_ array: inout [Int], left: Int, right: Int) -> Int {
    let mid = (left + right) / 2
    if left < right {
        for i in left..<right {
            var p = i
            for j in i + 1...right {
                if array[j] < array[p] {
                    p = j
                }
            }
            swap(&array, at: p, and: i)
            if i >= mid {
                break
            }
        }
    }
    return mid
}

// select the rank k number in array
private func select(_ array: inout [Int], left: Int, right: Int, of k: Int) -> Int {
    if (left == right) {
        return left
    }
    var piv: Int
    var r = right
    var l = left
    repeat {
        piv = pivot(&array, left: l, right: r)
        piv = partition(&array, left: l, right: r, pivot: piv)
        if piv == k {
            break
        } else if piv > k {
            r = piv - 1
        } else {
            l = piv + 1
        }
    } while piv != k

    return k
}

// normal partition method in quick sort
private func partition(_ array: inout [Int], left: Int, right: Int, pivot: Int) -> Int {
    var p1 = left
    var p2 = left
    swap(&array, at: pivot, and: right)
    while p2 < right {
        if array[p2] < array[right] {
            swap(&array, at: p2, and: p1)
            p1 += 1
        }
        p2 += 1
    }
    swap(&array, at: right, and: p1)
    return p1
}

private func swap(_ array: inout [Int], at indexA: Int, and indexB: Int) {
    let tmp = array[indexA]
    array[indexA] = array[indexB]
    array[indexB] = tmp
}
