fn main() {
    let nums = vec![1, 3, 5, 7, 9];
    let find_me = 5;

    let result = binary_search(&nums, &find_me, 0, nums.len());

    println!("Given Array: {:?}", nums);
    match result {
        Some(index) => println!("Searched for {} and found index {}.", find_me, index),
        None => println!("Searched for {} but found no occurrence.", find_me),
    }
}

fn binary_search<T>(arr: &[T], search_value: &T, left: usize, right: usize) -> Option<usize> where T: PartialOrd, T: PartialEq {
    let mut left: usize = left;
    let mut right: usize = right;

    while left <= right {
        let middle = (left + right) / 2;

        if middle == arr.len() {
            break;
        }

        if arr[middle] == *search_value {
            return Some(middle);
        } else if arr[middle] < *search_value {
            left = middle + 1;
        } else if arr[middle] > *search_value && middle != 0 {
            right = middle - 1;
        } else {
            break;
        }
    }

    None
}

