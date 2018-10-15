/* Part of Cosmos by OpenGenus Foundation */

import Foundation

extension Array {
    mutating func insertionSort(compareWith less: (Element, Element) -> Bool) {
        if self.count <= 1 {
            return
        }

        for i in 1..<self.count {
            var j = Int(i)
            let key = self[j]
            while j >= 1 && less(key, self[j - 1]) {
                self[j] = self[j - 1]
                j -= 1
            }
            self[j] = key
        }
    }
}
