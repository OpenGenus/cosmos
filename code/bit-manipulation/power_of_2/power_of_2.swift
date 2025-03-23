/*

    Part of Cosmos by OpenGenus Foundation
    Created by Jiraphapa Jiravaraphan on 15/10/2017 
    Check if a number is a power of 2 - Swift implementation

*/

func isPowerOfTwo(num: Int) -> Bool {
    
    return (num != 0) && ((num & (num - 1)) == 0)
}

print(isPowerOfTwo(num: 64))