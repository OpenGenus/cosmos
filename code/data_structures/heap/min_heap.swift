
public func pushHeap<T>(inout xs: [T], value: T, compare: (T, T) -> Bool) {
    xs.append(value)
    siftUp(&xs, xs.startIndex, xs.endIndex, compare, xs.count)
}
 

public func pushHeap<T: Comparable>(inout xs: [T], value: T) {
    pushHeap(&xs, value) {a, b in a < b}
}
 


public func popHeap<T>(inout xs: [T], comp: (T, T) -> Bool) -> T {
    precondition(!xs.isEmpty, "cannot pop an empty heap")
    swap(&xs[0], &xs[xs.endIndex - 1])
    siftDown(&xs, xs.startIndex, xs.endIndex, comp, xs.count - 1, xs.startIndex)
    let result = xs.removeLast()
    return result
}
 

public func popHeap<T: Comparable>(inout xs: [T]) -> T {
    return popHeap(&xs) {a, b in a < b}
}



// MARK: - Private


func siftDown<T>(inout xs: [T],
                 var first: Int,
                 var last: Int,
                 compare: (T, T) -> Bool,
                 var len: Int,
                 var start: Int)
{
    // left-child of start is at 2 * start + 1
    // right-child of start is at 2 * start + 2
    var child = start - first

    if (len < 2 || (len - 2) / 2 < child) {
        return
    }

    child = 2 * child + 1;
    var child_i = first + child

    if child + 1 < len && compare(xs[child_i + 1], xs[child_i]) {
        // right-child exists and is greater than left-child
        ++child_i
        ++child
    }

    // check if we are in heap-order
    if compare(xs[start], xs[child_i]) {
        // we are, start is larger than it's largest child
        return
    }

    let top = xs[start]
    do {
        // we are not in heap-order, swap the parent with it's largest child
        xs[start] = xs[child_i]
        start = child_i;

        if ((len - 2) / 2 < child) {
            break
        }

        // recompute the child based off of the updated parent
        child = 2 * child + 1
        child_i = first + child

        if child + 1 < len && compare(xs[child_i + 1], xs[child_i]) {
            // right-child exists and is greater than left-child
            ++child_i
            ++child
        }

        // check if we are in heap-order
    } while (!compare(top, xs[child_i]))
    xs[start] = top
}




private func siftUp<T>(inout xs: [T],
                       var first: Int,
                       var last: Int,
                       compare: (T, T) -> Bool,
                       var len: Int)
{
    if len <= 1 {
        return
    }
    len = (len - 2) / 2
    var index = first + len
    last -= 1
    if (compare(xs[last], xs[index])) {
        let t = xs[last]
        do {
            xs[last] = xs[index]
            last = index
            if len == 0 {
                break
            }
            len = (len - 1) / 2
            index = first + len
        } while (compare(t, xs[index]))
        xs[last] = t
    }
}
