#!/usr/bin/env swift
// Part of Cosmos by OpenGenus Foundation
import Darwin

func findingSquare(num : Int) -> Bool {
    let x = Int(sqrt(Double(num)))
    for i in 0...x{
        if(i*i == num){
            return true
        }
    }
    return false
}
let number = Int(readLine()!)
let result = findingSquare(num: number!)

if(result){
    print("A perfect square")
}
else{
    print("Not a perfect square")
}
