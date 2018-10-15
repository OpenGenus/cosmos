fn main() {
    let nums = vec![1, 3, 5, 7, 9];
    let find_me = 5;

    let result = binary_search(&nums, find_me, 0, nums.len());

    println!("Given Array: {:?}", nums);
    match result {
        Some(index) => println!("Searched for {} and found index {}.", find_me, index),
        None => println!("Searched for {} but found no occurrence.", find_me),
    }
}

fn binary_search(nums: &[i64], search_value: i64, left: usize, right: usize) -> Option<usize> {
    let mut left: usize = left;
    let mut right: usize = right;

    while left <= right {
        let middle = (left + right) / 2;

        if middle == nums.len() {
            break;
        }

        if nums[middle] == search_value {
            return Some(middle);
        } else if nums[middle] < search_value {
            left = middle + 1;
        } else if nums[middle] > search_value && middle != 0 {
            right = middle - 1;
        } else {
            break;
        }
    }

    None
}
