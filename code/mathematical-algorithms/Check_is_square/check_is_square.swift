#!/usr/bin/env swift
// Part of Cosmos by OpenGenus Foundation
import Darwin

func findingSquare(num : Int) -> Int {
    var res = 0
    let x = sqrt(Double(num))
    for i in 0...num {
        if(i*i == num){
            res = 1
            break
        }
        if(i > Int(x)){
            break
            }
    }
    return res
}
let number = Int(readLine()!)
let result = findingSquare(num: number!)

if(result == 0){
    print("\(number) is NOT a perfect square")
}
else{
    print("\(number) is a perfect square")
}
