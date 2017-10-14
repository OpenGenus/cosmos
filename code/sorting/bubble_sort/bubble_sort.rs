// Part of Cosmos by OpenGenus Foundation
fn bubble_sort(mut arr: Vec<i32>) -> Vec<i32> {
    for _ in 0..arr.len() {
        let mut flag = false;
        for j in 0..arr.len() - 1 {
            if arr[j] > arr[j + 1] {
                let temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = true
            }
        }
        if !flag {
            break;
        }
    }
    arr
}

fn main() {
    let arr = vec![4, 5, 9, 1, 3, 0, 7, 2, 8];
    let arr = bubble_sort(arr);
    println!("Sorted array: {:?}", arr)
}