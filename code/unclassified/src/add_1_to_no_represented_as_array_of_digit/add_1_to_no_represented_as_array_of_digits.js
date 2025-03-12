// Algorithm: Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

const trimLeadingZeroes = (digits) => {
    let ans = []
    let m = digits.length
    let idx = 0
    for (let i = 0; i < m; i++) {
        if (digits[i] == 0)
            continue
        else {
            idx = i
            break
        }
    }
    for (let j = idx; j < m; j++)
        ans.push(digits[j])

    return ans
}

const plusOne = (digits) => {
    digits = trimLeadingZeroes(digits) // trim the unnecessary leading zeroes
    let sum = 0,
        dig = 0,
        carry = 1
    let n = digits.length
    let ans = []

    for (let i = n - 1; i >= 0; i--) {
        sum = digits[i] + carry
        carry = Math.floor(sum / 10) // carry forward
        dig = sum % 10 // place the digit
        ans.push(dig)
    }

    if (carry)
        ans.push(1)

    ans.reverse()
    return ans
}

// initiate
let digits = [0, 0, 0, 4, 5, 2, 0, 9, 7, 9, 9]
let plusOneNo = plusOne(digits)
console.log('The original no is: ', digits)
console.log('1 added to the number is: ', plusOneNo)

// Output:
// The original no is: [0, 0, 0, 4, 5, 2, 0, 9, 7, 9, 9]
// 1 added to the number is: [4, 5, 2, 0, 9, 8, 0, 0]

// Time Complexity: O(N)
