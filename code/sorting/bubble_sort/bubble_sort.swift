#!/usr/bin/env swift

/* Part of Cosmos by OpenGenus Foundation */
import Foundation

func sort(_ list: [Int]) -> [Int] {
    let sortedList = NSMutableArray(array: list)
    var sortedAboveIndex = list.count
    var swaps = 0

    repeat {
        var lastSwapIndex = 0
        
        for i in 1..<sortedAboveIndex {
            if (sortedList[i - 1] as! Int) > (sortedList[i] as! Int) {
                sortedList.exchangeObject(at: i, withObjectAt: i-1)
                lastSwapIndex = i
                swaps += 1
            }
        }

        sortedAboveIndex = lastSwapIndex
    } while (sortedAboveIndex != 0)

    return sortedList as! [Int]
}

let list = [1, 6, 2, 4, 9, 0, 5, 3, 7, 8]
print("Before: ", list)
let sortedList = sort(list)
print("After: ", sortedList)