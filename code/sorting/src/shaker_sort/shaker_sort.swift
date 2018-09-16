// Part of Cosmos by OpenGenus Foundation

import Foundation;

func shaker_sort(v: inout [UInt32]) {
    let size = v.count;
    var swap = false;
    
    for i in 0 ... size / 2 - 1 {
        for j in stride(from: i, to: size - i - 1, by: 1) {
            if v[j] > v[j + 1] {
                let tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
                swap = true;
            }
        }

        for j in stride(from: size - 2 - i, to: i, by: -1) {
            if v[j] < v[j - 1] {
                let tmp = v[j];
                v[j] = v[j - 1];
                v[j - 1] = tmp;
                swap = true;
            }
        }
        
        if (!swap) {
            break;
        }
    }
}

func test() {
    print("Size of array: ", terminator:"");
    let size = Int(readLine()!)!;
    var arr = [UInt32]();

    for _ in 1 ... size {
        arr.append(arc4random_uniform(100));
    }

    print("Original: ");
    print(arr);

    shaker_sort(v: &arr);

    print("Sorted: ");
    print(arr);
}

test();
