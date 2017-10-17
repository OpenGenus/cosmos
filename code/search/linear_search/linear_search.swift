//
//  linear_search.swift
//  test
//
//  Created by Kajornsak Peerapathananont on 10/14/2560 BE.
//  Copyright © 2560 Kajornsak Peerapathananont. All rights reserved.
//  Part of Cosmos by OpenGenus Foundation

import Foundation

/*
 Input : array of item and the element that want to be search
 Output : index of element (if found) or else -1
 
 
 */


func linear_search<T : Equatable>(array : [T], element : T) -> Int{
    for (index, item) in array.enumerated() {
        if(item == element){
            return index
        }
    }
    return -1
}
