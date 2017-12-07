fn search(vec: &[i32], n: i32) -> i32 {
    for i in 0..vec.len() {
        if vec[i] == n {
            return i as i32; // Element found return index
        }
    }
    return -1; // If element not found return -1
}

fn main() {
    let arr = vec![1, 3, 45, 56, 8, 21, 7, 69, 12];
    let num = 56;
    let index =  search(&arr, num);
    if index != -1 {
        println!("Found {}, at index {}", num, index);
    }else {
        println!("{} not found!", num)
    }
}