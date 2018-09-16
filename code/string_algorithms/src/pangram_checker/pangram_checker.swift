//
//  pangram_checker.swift
//  test
//
//  Created by Kajornsak Peerapathananont on 10/15/2560 BE.
//  Copyright © 2560 Kajornsak Peerapathananont. All rights reserved.
//
// Part of Cosmos by OpenGenus Foundation

import Foundation

let alphabet = "abcdefghijklmnopqrstuvwxyz"

func pangram_checker(string : String) -> Bool {
    return alphabet.characters.map({string.lowercased().contains($0)}).reduce(true, {$0 && $1})
}

func testPangramChecker(){
    print(pangram_checker(string: "Totally not a pangram"))
    print(pangram_checker(string: "The quick brown fox jumps over a lazy dog"))
    print(pangram_checker(string: "Pack my box with five dozen liquor jugs"))
    print(pangram_checker(string: "This is not a pangram"))
}
