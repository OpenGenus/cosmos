fn search(vec: &[i32], n: i32) -> Option<usize> {
    for i in 0..vec.len() {
        if vec[i] == n {
            return Some(i); // Element found
        }
    }
    None
}

fn main() {
    let arr = vec![1, 3, 45, 56, 8, 21, 7, 69, 12];
    let num = 56;
    let index =  search(&arr, num);
    match index {
        None => println!("{} not found!", num),
        Some(i) => println!("Found {}, at index {}", num, i)
    }
}
