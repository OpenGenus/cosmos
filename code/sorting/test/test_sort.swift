/* Part of Cosmos by OpenGenus Foundation */

import Foundation

let maxSize = 100

class TestSort {
    func test() {
        let less = { (a: UInt32, b: UInt32) -> Bool in
            return a < b
        }

        var origin = [UInt32](),
            expect = origin,
            actual = expect

        // test with given size
        for size in 0..<maxSize {
            for duplicate in 0...1 {
                if duplicate == 0 {
                    origin = getRandomElements(UInt32(size), limitBy: UInt32(size * 2))
                } else {
                    // force generate duplicate elements
                    origin = getRandomElements(UInt32(size), limitBy: UInt32(size / 2))
                }

                // test with all sort functions
                for funcIndex in 0...4 {
                    expect = origin
                    actual = expect

                    switch funcIndex {
                    case 0:
                        expect.selectionSort(compareWith: less)
                    case 1:
                        expect.insertionSort(compareWith: less)
                    case 2:
                        expect.bubbleSort(compareWith: less)
                    case 3:
                        expect.mergeSort(compareWith: less)
                    default:
                        expect.quickSort(compareWith: less)
                    }

                    actual.sort()
                    assert(expect == actual)
                }
            }
        }

        print(0)
    }
}

private func countDigit(_ value: UInt32) -> UInt32 {
    var v = value
    var count = UInt32(1)

    while v > 9 {
        count += 1
        v >>= 1
    }

    return count
}

private func getRandomElements(_ size: UInt32 = 0, limitBy upperBound: UInt32) -> [UInt32] {
    var array = [UInt32]()

    for _ in 0..<size {
        array.append(arc4random_uniform(upperBound))
    }

    return array
}
