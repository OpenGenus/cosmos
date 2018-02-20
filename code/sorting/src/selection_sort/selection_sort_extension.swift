/* Part of Cosmos by OpenGenus Foundation */

import Foundation

private func swap<T>(_ array: inout [T], at indexA: Int, and indexB: Int) {
    let tmp = array[indexA]
    array[indexA] = array[indexB]
    array[indexB] = tmp
}

extension Array {
    mutating func selectionSort(compareWith less: (Element, Element) -> Bool) {
        for i in 0..<self.count {
            var min = i
            for j in i + 1..<self.count {
                if less(self[j], self[min]) {
                    min = j
                }
            }
            swap(&self, at: min, and: i)
        }
    }
}
