/* Part of Cosmos by OpenGenus Foundation */

import Foundation

private func swap<T>(_ array: inout [T], at indexA: Int, and indexB: Int) {
    let tmp = array[indexA]
    array[indexA] = array[indexB]
    array[indexB] = tmp
}

extension Array {
    mutating func bubbleSort(compareWith less: (Element, Element) -> Bool) {
        let n: Int = self.count
        for i in stride(from: 0, to: n - 1, by: 1) {
            var swapped = false
            for j in stride(from: 0, to: n - i - 1, by: 1) {
                if less(self[j + 1], self[j]) {
                    swapped = true
                    swap(&self, at: j, and: j + 1)
                }
            }
            if !swapped {
                break
            }
        }
    }
}
