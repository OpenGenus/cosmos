/* Part of Cosmos by OpenGenus Foundation */

//
//  sleep_sort.swift
//  Created by DaiPei on 2017/10/12.
//

import Foundation
import Dispatch

func sleepSort(_ array: [Int]) {
    let group = DispatchGroup()
    for i in 0..<array.count {
        let queue = DispatchQueue(label: "com.my.queue")
        queue.async(group: group, execute: {
            usleep(UInt32(array[i]))
            print(array[i])
        })
    }
    group.wait()
}
