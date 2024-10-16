// Part of Cosmos by OpenGenus Foundation

function xorSwap(a, b) {
    console.log(`Before swap: a = ${a}, b = ${b}`);
    
    a = a ^ b; // Step 1: a now contains the XOR of both
    b = a ^ b; // Step 2: b gets the original value of a
    a = a ^ b; // Step 3: a gets the original value of b

    console.log(`After swap: a = ${a}, b = ${b}`);
}

// Example usage:
let x = 5;
let y = 10;
xorSwap(x, y);
