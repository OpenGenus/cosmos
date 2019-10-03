/* Part of Cosmos by OpenGenus Foundation */

//
//  shell_sort.swift
//  Created by DaiPei on 2017/10/11.
//

import Foundation

func shellSort(_ array: inout [Int]) {
    var h = array.count / 2
    while h > 0 {
        for i in h..<array.count {
            let key = array[i]
            var j = i
            while j >= h && key < array[j - h] {
                array[j] = array[j - h]
                j -= h
            }
            array[j] = key
        }
        h /= 2
    }
}
