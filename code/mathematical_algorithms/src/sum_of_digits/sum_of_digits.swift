//
//  sum_of_digits.swift
//  test
//
//  Created by Kajornsak Peerapathananont on 10/14/2560 BE.
//  Copyright © 2560 Kajornsak Peerapathananont. All rights reserved.
//
//Part of Cosmos by OpenGenus Foundation

import Foundation

func sum_of_digits(number : String)->Int{
    return number.characters.map({ char in
        return Int(String(char))!
    }).reduce(0, +)
   
}


