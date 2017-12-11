#!/usr/bin/env swift
// Part of Cosmos by OpenGenus Foundation
func automorphic(num:Int)-> Bool{
    let strNum = String(num)
    let strSquaredNum = String(num*num)
    let check = strSquaredNum.hasSuffix(strNum)
    if(check){
        return true
    }
    else{
        return false
    }
}
let number = Int(readLine()!)
let result = automorphic(num:number!)
if(result == true){
    print("Automorphic number")
}
else{
    print("Not automorphic number")
}

