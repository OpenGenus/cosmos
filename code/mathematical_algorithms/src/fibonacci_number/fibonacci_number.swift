// Part of Cosmos by OpenGenus Foundation
func fibonacciTerm(n: Int) -> Int {
    return calcFibonacci(a: n - 2, b: 1, c: 1)
}

func calcFibonacci(a: Int, b: Int, c: Int) -> Int {
    if a <= 0 {
        return c
    }
    return calcFibonacci(a: a - 1, b: c, c: c + b)
}
