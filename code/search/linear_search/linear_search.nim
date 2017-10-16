proc linear_search[T](collection: seq[T], item: T): T =
    for i in 0..(collection.len() - 1):
        if collection[i] == item:
            return i
    return -1

let s = @[42, 393, 273, 1239, 32]
echo linear_search(s, 273) # prints "2"
echo linear_search(s, 32)  # prints "4"
echo linear_search(s, 1)   # prints "-1"
