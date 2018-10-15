#[macro_use]
extern crate text_io;

fn main() {
    let n: usize = read!();
    let mut s: usize = 0;
    let mut solution: Vec<usize> = Vec::new();
    solution.push(1);
    for _ in 0..n {
        solution.push(0);
    }
    backtrack(&mut solution, n, &mut s, 1);
}
fn backtrack(vec: &mut Vec<usize>, n: usize, s: &mut usize, level: usize) {
    //println!("{:?}", vec);
    if n == *s {
        printsol(vec, n, level - 1);
    } else {
        let mut i = vec[level - 1];
        while i <= n - *s {
            if let Some(elem) = vec.get_mut(level) {
                *elem = i;
            }
            *s += i;
            backtrack(vec, n, s, level + 1);
            *s -= i;
            i += 1;
        }
    }
}
fn printsol(map: &Vec<usize>, num: usize, level: usize) {
    println!("Solution");
    print!("{} = ", num);
    for idx in 1..level + 1 {
        if idx == 1 {
            print!("{:?}", map[idx]);
        } else {
            print!(" + {:?}", map[idx]);
        }
    }
    println!();
}
