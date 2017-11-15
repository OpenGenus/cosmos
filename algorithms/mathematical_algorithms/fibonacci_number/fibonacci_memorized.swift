func fibonnaci(_ n: Int) -> Int {
    guard n > 1 else { return n }
    return fibonnaci(n-2) + fibonnaci(n-1)
}

func fibonnaciMemoized(_ n: Int) -> Int {
    var cache = [0: 0, 1: 1]
    func fib(_ n: Int) -> Int {
        if let number = cache[n] {
            return number
        }
        cache[n] = fib(n-2) + fib(n-1)
        return cache[n]!
    }
    return fib(n)
}

if let argument = Int(CommandLine.arguments[1]) {
    print(fibonnaci(n: argument))
    print(fibonnaciMemoized(n: argument))
}
