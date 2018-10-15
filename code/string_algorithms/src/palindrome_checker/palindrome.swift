/* Part of Cosmos by OpenGenus Foundation */

extension String {
 
    public func isPalindrome() -> Bool {
        return self == String(self.characters.reversed())
    }
    
}

func test() {
    
    print("opengenus".isPalindrome()) // false
    print("cosmos".isPalindrome())    // false
    print("level".isPalindrome())     // true
    print("rotator".isPalindrome())   // true
}

test()
