/* Part of Cosmos by OpenGenus Foundation */

import Foundation

extension Array {
    mutating func mergeSort(compareWith less: (Element, Element) -> Bool) {
        mergeSort(compareWith: less, low: 0, high: self.count - 1)
    }

    private mutating func mergeSort(compareWith less: (Element, Element) -> Bool, low: Int, high: Int) {
        if low < high {
            let mid = (low + high) / 2
            mergeSort(compareWith: less, low: low, high: mid)
            mergeSort(compareWith: less, low: mid + 1, high: high)
            merge(compareWith: less, low: low, mid: mid, high: high)
        }
    }

    private mutating func merge(compareWith less: (Element, Element) -> Bool, low: Int, mid: Int, high: Int) {
        var tmpArray = self
        var i = low, j = mid + 1, k = low
        while i <= mid && j <= high {
            if less(tmpArray[i], tmpArray[j]) {
                self[k] = tmpArray[i]
                i += 1
            } else {
                self[k] = tmpArray[j]
                j += 1
            }
            k += 1
        }
        while i <= mid {
            self[k] = tmpArray[i]
            i += 1
            k += 1
        }
        while j <= mid {
            self[k] = tmpArray[j]
            j += 1
            k += 1
        }
    }
}
