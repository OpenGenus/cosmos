import Foundation

let dimension = 5 // this should be an odd number

var magicSquare = Array<Array<Int>>()

for _ in 0..<dimension
{
    magicSquare.append(Array<Int>(repeating: 0, count: dimension))
}

var i = dimension / 2
var j = dimension - 1
var num = 1

while num < dimension * dimension
{
    if i == -1 && j == dimension
    {
        j = dimension - 2
        i = 0
    }
    else
    {
        // if next number goes to out of square's right side
        if j == dimension
        {
            j = 0
        }
        // if next number goes to out of square's upper side
        if i < 0
        {
            i = dimension - 1
        }
    }
    if magicSquare[i][j] != 0
    {
        j = j - 2
        i = i + 1
        continue
    }
    else
    {
        magicSquare[i][j] = num // set number
        num = num + 1
    }
    
    j = j + 1
    i = i - 1
}

for row in magicSquare
{
    print(row)
}
