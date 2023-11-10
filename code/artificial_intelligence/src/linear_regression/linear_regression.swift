import Foundation

let cosmos_size: [Double] = [1, 2, 10, 3, 20, 11]
let cosmos_contributors: [Double] = [500, 1000, 5000, 1500, 10000, 5500]

func average(_ input: [Double]) -> Double {
    return input.reduce(0, +) / Double(input.count)
}

func multiply(_ a: [Double], _ b: [Double]) -> [Double] {
    return zip(a, b).map(*)
}

func linearRegression(_ xs: [Double], _ ys: [Double]) -> (Double) -> Double {
    let sum1 = average(multiply(xs, ys)) - average(xs) * average(ys)
    let sum2 = average(multiply(xs, xs)) - pow(average(xs), 2)
    let slope = sum1 / sum2
    let intercept = average(ys) - slope * average(xs)
    return { x in intercept + slope * x }
}

let result = linearRegression(cosmos_size, cosmos_contributors)(4)

print("Perdicted £\(Int(result))")
