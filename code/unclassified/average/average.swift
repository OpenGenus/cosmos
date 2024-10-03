func average(of numbers: [Double]) -> Double {
    return numbers.reduce(0, +) / Double(numbers.count)
}

let numbers = [3.14, 2.72, 1.41]
let averageNumber = average(of: numbers)
print(averageNumber)
