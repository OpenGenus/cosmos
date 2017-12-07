use std::collections::HashMap;
// Part of Cosmos by OpenGenus Foundation

fn main() {
    // 2 results - for `7` and both `-3` numbers
    two_sum(vec![3, 5, 7, 0, -3, -2, -3], 4);
    // No results
    two_sum(vec![3, 5, 0, -3, -2, -3], 4);
}

fn two_sum(numbers: Vec<i32>, target: i32) {
    let mut indices: HashMap<i32, usize> = HashMap::new();

    println!("Numbers: {:?}", numbers);

    for (i, number) in numbers.iter().enumerate() {
        let hash_index = target - number;

        if indices.get(&hash_index).is_some() {
            println!("Found two indices that sum-up to {}: {} and {}", target, indices.get(&hash_index).unwrap(), i);
        }
        indices.insert(*number, i);
    }
}
