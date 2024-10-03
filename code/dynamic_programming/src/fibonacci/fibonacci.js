// Problem Statement(1): Find the nth Fibonacci number 

// 1.a.Using Recusrion to find the nth fibonacci number
const FibonacciNumberRec = (num) => {
    if (num <= 1)
        return num;
    return FibonacciNumberRec(num - 1) + FibonacciNumberRec(num - 2);
}

// 1.b.Using DP to find the nth fibonacci number
// fib[n] = fib[n - 1] + fib[n - 2]
const FibonacciNumberDP = (num) => {
    let fib = [0, 1] // fib[0] = 0, fib[1] = 1
    for (let i = 2; i <= num; i++) {
        fib.push(fib[i - 1] + fib[i - 2]);
    }

    return fib[num]; // return num'th fib number
}

// 2.Print the fibonacci series upto nth Fibonacci number
const FibonacciSeries = (num) => {
    let fib = [0, 1] // fib[0] = 0, fib[1] = 1
    for (let i = 2; i <= num; i++) {
        fib.push(fib[i - 1] + fib[i - 2]);
    }

    return fib;
}


// Call the functions
let n = 6
console.log(`The ${n}th Fibonacci Number is ${FibonacciNumberRec(n)}`);
n = 8
console.log(`The ${n}th Fibonacci Number is ${FibonacciNumberDP(n)}`);
n = 10
console.log(`The Fibonacci Series upto ${n}th term is ${FibonacciSeries(n)}`);

// I/O:
// 1.a) n = 6
// Output :
// The 6th Fibonacci Number is 8
// 1.b) n = 8
// The 8th Fibonacci Number is 21
// 2. n = 10
// The Fibonacci Series upto 10th term is 0,1,1,2,3,5,8,13,21,34,55

// Note:This is 0-based i.e, fib[0] = 0, fib[1] = 1, fib[2] = 0 + 1 = 1, fib[3] = 1 + 1 = 2
