// Part of Cosmos by OpenGenus Foundation

fn median(arr: &[i32]) -> f64 {
    let len = arr.len();
    if len % 2 == 0 {
        (arr[len / 2] + arr[len / 2 - 1]) as f64 / 2.0
    } else {
        arr[(len - 1) / 2] as f64
    }
}

fn main() {
    let arr = vec![1, 3, 3, 4, 5, 6, 8, 9];
    let median = median(&arr); //Assuming input is sorted array
    println!("{}", median);
}
