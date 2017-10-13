func fibonnaci(_ n: Int) -> Int {
    guard n > 1 else { return n }
    return fibonnaci(n-2) + fibonnaci(n-1)
}

if let argument = Int(CommandLine.arguments[1]) {
    print(fibonnaci(n: argument))    
}