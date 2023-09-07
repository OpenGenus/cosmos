import Foundation

let nums = [10.0,20,30,40,50]
let average = nums.reduce(0.0, +) / Double(nums.count)
print(average)
