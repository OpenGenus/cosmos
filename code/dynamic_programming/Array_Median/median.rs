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
    let arr1 = vec![1, 3, 3, 4, 5, 6, 8, 9];
    let median1 = median(&arr1); //Assuming input is sorted array
    println!("{}", median1);

    let mut arr2 = vec![5, 6, 1, 3, 8, 9, 3, 4];
    arr2.sort_by(|a, b| a.cmp(b));
    let median2 = median(&arr2); //Assuming input is not sorted array

    assert_eq!(median1, median2);
}
