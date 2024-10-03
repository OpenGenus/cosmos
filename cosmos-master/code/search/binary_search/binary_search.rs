fn main() {
    let nums = vec![1, 3, 5, 7, 9];
    let find_me = 5;

    let index = binary_search(&nums, find_me, 0, nums.len())

    println!("Given Array: {:?}\n", nums);
    println!("Searched for {} and found index {}", find_me, index));
}

fn binary_search(nums: &Vec<i64>, search_value: i64, left: usize, right: usize) -> i64 {
    let mut left = left;
    let mut right = right;

    while left <= right {
        let middle = (left + right) / 2;

        if middle == nums.len() {
            break;
        }

        if nums[middle] == search_value {
            return middle as i64;
        } else if nums[middle] < search_value {
            left = middle + 1;
        } else if nums[middle] > search_value && middle != 0 {
            right = middle - 1;
        } else {
            break;
        }
    }

    -1
}
