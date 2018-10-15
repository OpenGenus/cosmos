//
//  count_digits.swift
//  test
//
//  Created by Kajornsak Peerapathananont on 10/14/2560 BE.
//  Copyright © 2560 Kajornsak Peerapathananont. All rights reserved.
//
// Part of Cosmos by OpenGenus Foundation
import Foundation

func count_digits(n : Int) -> Int {
    if n == 0 {
        return 1
    }
    var num_digits = 0
    var integer = abs(n)
    while integer > 0 {
        integer = integer/10
        num_digits += 1
    }
    return num_digits
}


