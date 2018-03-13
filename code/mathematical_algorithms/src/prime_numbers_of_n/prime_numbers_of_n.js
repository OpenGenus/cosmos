function primeFactors(number)
{
    let factors = [];
    let sqrt = Math.sqrt;
    while (number % 2 == 0) {
        factors.push(2)
        number = number / 2;
    }

    for (let i = 3; i <= sqrt(number); i += 2)
    {
        while (number % i == 0) {
            factors.push(i)
            number = number / i;
        }
    }

    if (number > 2)
    {
        factors.push(number)
    }

    return factors;
}

// test cases
console.log(primeFactors(10))    // [2, 5]
console.log(primeFactors(100))   // [2, 2, 5, 5]
console.log(primeFactors(300))  // [2, 2, 3, 5, 5]
