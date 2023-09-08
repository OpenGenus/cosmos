fn main() {
    let nums = vec![1, 3, 5, 7, 9, 11, 13, 15, 17, 19];
    let find_me = 13;

    let index = exponential_search(&nums, find_me);

    println!("Given Array: {:?}\n", nums);
    println!("Searched for {} and found index {}", find_me, index);
}

fn exponential_search(nums: &Vec<i64>, search_value: i64) -> i64 {
    let size: usize = nums.len();

    if size == 0 {
        return -1;
    }

    let mut bound: usize = 1;
    while bound < size && nums[bound] < search_value {
        bound *= 2;
    }

    return binary_search(&nums, search_value, bound/2, min(bound, size))

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

fn min(x: usize, y: usize) -> usize {
    if x < y {
        x
    } else {
        y
    }
}
