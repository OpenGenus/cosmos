//  divide conquer | quick sort | Rust
//  Part of Cosmos by OpenGenus Foundation

fn quick_sort(mut arr :Vec<i32>,low :usize, high :usize) -> Vec<i32> {

    if low < high {
        let mid = partition(&mut arr, low, high);

        let arr = quick_sort(arr.clone(),low,mid);
        let arr = quick_sort(arr,mid+1,high);
        return arr
    }
    arr
}

fn partition(arr : &mut Vec<i32>, low :usize, high :usize) -> usize {
    let pivot = arr[low];
    let mut i = low ;
    let mut j = high;

    loop {
        while arr[i] < pivot && arr[i] != pivot {
            i += 1;
        }
        while arr[j] > pivot && arr[j] != pivot {
            j -= 1;
        }
        if i < j {
           arr.swap(i,j);
        }else{
            return j
        }
    }
}

fn main() {
    let arr = vec![10, 7, 8, 9, 1, 5];
    let len = arr.len();
    let sorted = quick_sort(arr,0,len-1);
    println!("Sorted array is {:?}", sorted);
}
