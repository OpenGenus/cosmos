/* Part of Cosmos by OpenGenus Foundation */
function factorial(n){
    if (n == 0) return 1;
    else return n * factorial(n-1);
}

num = 3;
console.log(factorial(num));

'use-strict';
function tailCallFactorial(n) {
    function tcoSubFunction(n, accumulator) {
        if (n <= 1) return accumulator;
        else return tcoSubFunction(n - 1, n * accumulator);
    };
    return tcoSubFunction(n, 1)
};

let n = 5;
console.log(tailCallFactorial(n));

