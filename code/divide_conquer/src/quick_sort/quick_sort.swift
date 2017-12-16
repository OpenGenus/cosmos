//  divide conquer | quick sort | Swift
//  Part of Cosmos by OpenGenus Foundation

import Foundation;

func partition(_ arr: inout [UInt32], _ begin: Int, _ end: Int) -> Int {
    var i = begin;
    var j = end;
    let pivot = arr[(i + j) / 2];

    while i <= j {
        while arr[i] < pivot {
            i += 1;
        }

        while arr[j] > pivot {
            j -= 1;
        }

        if i <= j {
            arr.swapAt(i, j);
            i += 1;
            j -= 1;
        }
    }
    arr.swapAt(i, end);

    return i;
}

func quick_sort(_ arr: inout [UInt32], begin: Int, end: Int) {
    if begin < end {
        let index = partition(&arr, begin, end);
        quick_sort(&arr, begin: begin, end: index - 1);
        quick_sort(&arr, begin: index, end: end);
    }
}

func test() {
    print("Size of array: ", terminator: "");
    let size = Int(readLine()!)!;
    var arr = [UInt32]();

    for _ in 1 ... size {
        arr.append(arc4random_uniform(100));
    }

    print("Original: ");
    print(arr);

    quick_sort(&arr, begin: 0, end: size - 1);

    print("Sorted: ");
    print(arr);
}

test();
