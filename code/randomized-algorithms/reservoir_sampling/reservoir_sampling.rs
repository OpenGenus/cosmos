extern crate rand;
use rand::Rng;
use std::io;

fn select_random_k(arr: &Vec<i64>, k: u64) -> Vec<i64> {
    let mut reservoir: Vec<i64> = vec![];
    // using variable length instead of k handles the case of when k > arr.len()
    let length: u64;
    if (arr.len() as u64) < k {
        length = arr.len() as u64;
    } else {
        length = k;
    }
    for i in 0..length {
        let val = &arr[i as usize];
        reservoir.push(*val);
    }
    let mut rng = rand::thread_rng();
    for i in length..(arr.len() as u64) {
        let r_num = rng.gen::<u64>() % (i as u64 + 1);
        if r_num < length {
            reservoir[r_num as usize] = arr[i as usize];
        }
    }
    return reservoir;
}

fn main() {
    let mut num_string = String::new();
    // Reads space seperated list of n numbers
    io::stdin().read_line(&mut num_string).expect("Failed to read the numbers");
    let mut num_arr: Vec<i64> = vec![];
    for num in num_string.split(" ") {
        num_arr.push(num.trim().parse().expect("Not a number"));
    }
    let mut k_string = String::new();
    // Reads k
    io::stdin().read_line(&mut k_string).expect("Failed to read value of k");
    let k: u64 = k_string.trim().parse().expect("Not a number");
    println!("{:?}", select_random_k(&num_arr, k));
}