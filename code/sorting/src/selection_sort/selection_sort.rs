// Part of Cosmos by OpenGenus Foundation
fn selection_sort(mut arr :Vec<i32>) -> Vec<i32> {
    let len = arr.len();
    
    for i in 0..len-1 {
        let mut min = i;
        for j in i+1..len {
            if arr[j] < arr[min] {
                min  = j;
            }
        }
        if min != i{
            arr.swap(i, min);
        }
    }

    arr
}

fn main() {
    let arr = vec![1, 3, 43, 2, 14, 53, 12, 87, 33];
    let arr = selection_sort(arr);
    println!("Sorted array: {:?}", arr);
}