extern crate rand;
use rand::Rng;

fn swap(arr: &mut Vec<i64>, i: usize) {
    let temp = arr.clone();
    let a = &temp[i];
    let b = &temp[i + 1];
    arr.remove(i);
    arr.insert(i, *b);
    arr.remove(i + 1);
    arr.insert(i + 1, *a);
}

fn randomize(arr: &Vec<i64>) -> Vec<i64> {
    let mut rng = rand::thread_rng();
    let mut temp = arr.clone();
    for i in 0..arr.len() - 1 {
        let random_num = rng.gen::<u8>() % 2;
        if random_num == 1 {
            swap(&mut temp, i);
        }
    }
    return temp;
}

fn main() {
    println!("{:?}", randomize(&vec![1, 2, 3, 4, 5]));
}