// Binary to Gray
function binaryToGray(n) {
    return n ^ (n >> 1);
}

// Gray to Binary
function grayToBinary(n) {
    let binary = n;
    while (n > 0) {
        n >>= 1;
        binary ^= n;
    }
    return binary;
}

let num = 7;
console.log("Gray Code:", binaryToGray(num));  // Output: 4
console.log("Binary Code:", grayToBinary(binaryToGray(num)));  // Output: 7
