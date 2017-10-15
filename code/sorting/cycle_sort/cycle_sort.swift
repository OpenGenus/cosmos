/* Part of Cosmos by OpenGenus Foundation */

//
//  cycle_sort.swift
//  Created by DaiPei on 2017/10/15.
//

import Foundation

func cycleSort(_ array: inout [Int]) {
    for cycleStart in 0..<array.count {
        var value = array[cycleStart]
        var pos = cycleStart
        
        // count all smaller elements on right side of item
        for i in cycleStart + 1..<array.count {
            if array[i] < value {
                pos += 1
            }
        }
        
        // if the value is already in right place
        if pos == cycleStart {
            continue
        }
        
        // ignore all duplicate elements
        while array[pos] == value {
            pos += 1
        }
        
        // put the value to the right place
        swap(&array, at: pos, and: cycleStart)

        // cycle again
        while pos != cycleStart {
            pos = cycleStart
            value = array[cycleStart]
            
            // count all smaller elements on right side of new value
            for i in cycleStart + 1..<array.count {
                if array[i] < value {
                    pos += 1
                }
            }
            
            // break when there is not a element smaller than the value
            if pos == cycleStart {
                break
            }
            
            // ignore all duplicate elements
            while array[pos] == value {
                pos += 1
            }
            
            // put the value to the right place
            swap(&array, at: pos, and: cycleStart)
        }
    }
}

private func swap(_ array: inout [Int], at indexA: Int, and indexB: Int) {
    let tmp = array[indexA]
    array[indexA] = array[indexB]
    array[indexB] = tmp
}
