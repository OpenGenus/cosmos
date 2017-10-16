/* Part of Cosmos by OpenGenus Foundation */
function factorial(n){
    if (n == 0) return 1;
    else return n * factorial(n-1);
}

num = 3;
console.log(factorial(num));