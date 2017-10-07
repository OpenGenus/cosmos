fn average(arr :&Vec<i32>) -> i32 {
    let mut sum = 0;
    for n in arr.iter() {
        sum += *n;
    }
    sum
}

fn main() {
    let vec = vec![1,2,3,4,5,6,7,8,9,10];
    print!("{}",average(&vec));
}