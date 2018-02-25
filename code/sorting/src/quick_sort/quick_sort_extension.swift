/* Part of Cosmos by OpenGenus Foundation */

import Foundation

private func swap<T>(_ array: inout [T], at indexA: Int, and indexB: Int) {
    let tmp = array[indexA]
    array[indexA] = array[indexB]
    array[indexB] = tmp
}

extension Array {
    mutating func quickSort(compareWith less: (Element, Element) -> Bool) {
        quickSort(compareWith: less, low: 0, high: self.count - 1)
    }

    private mutating func quickSort(compareWith less: (Element, Element) -> Bool, low: Int, high: Int) {
        if low < high {
            let div = partition(compareWith: less, low: low, high: high)
            quickSort(compareWith: less, low: low, high: div - 1)
            quickSort(compareWith: less, low: div + 1, high: high)
        }
    }

    private mutating func partition(compareWith less: (Element, Element) -> Bool, low: Int, high: Int) -> Int {
        var div = low
        var p = low
        let mid = (low + high) / 2
        swap(&self, at: mid, and: high)
        while p < high {
            if less(self[p], self[high]) {
                swap(&self, at: p, and: div)
                div += 1
            }
            p += 1
        }
        swap(&self, at: high, and: div)
        return div
    }
}
