/* Part of Cosmos by OpenGenus Foundation */

import Foundation

extension String {
    
    /*
     *  Checks if two strings are anagrams of each other,
     *  ignoring case and whitespaces.
     */
    func isAnagram(of other: String) -> Bool {
        
        let selfChars = self.removingWhitespaces().lowercased().characters.sorted()
        let otherChars = other.removingWhitespaces().lowercased().characters.sorted()
        
        return selfChars == otherChars;
    }
    
    func removingWhitespaces() -> String {
        return components(separatedBy: .whitespaces).joined()
    }
    
}

func test() {
    
    print("anagram".isAnagram(of: "not a gram")) // false
    print("anagram".isAnagram(of: "na a marg")) // true
    print("William Shakespeare".isAnagram(of: "I am \t a weakish speller")) // true
    print("Madam Curie".isAnagram(of: "Radium came")) // true
    print("notagram".isAnagram(of: "notaflam")) // false
}

test()
