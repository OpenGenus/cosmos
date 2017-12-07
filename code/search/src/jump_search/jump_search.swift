import Foundation

func jumpSearch<T: Comparable>(_ a: [T], for key: T) -> Int? {
    let count = a.count
    var step = Int(sqrt(Double(count)))
    var previous = 0

    while a[min(step, count) - 1] < key {
        previous = step
        step += Int(sqrt(Double(count)))
        if previous >= count {
            return nil
        }
    }

    while a[previous] < key {
        previous += 1
        if previous == min(step, count) {
            return nil
        }
    }

    return a[previous] == key ? previous : nil
}


if let position = jumpSearch([7, 11, 13, 33, 66], for: 33) {
    print("Found 33 in [7, 11, 13, 33, 66] at position \(position)")
} else {
    print("Can't find 33 in [7, 11, 13, 33, 66]")
}
