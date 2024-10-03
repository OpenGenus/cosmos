use std::io;

fn binomial_coef(n: i32, k: i32) -> i32 {
    let mut c = vec![0; k as usize + 1];

    c[0] = 1;

    for i in 1..(n + 1) {
        let mut j = i.min(k);
        
        while j > 0 {
            c[j as usize] = c[j as usize] + c[(j - 1) as usize];
            j -= 1;
        }
    }

    c[k as usize]
}

fn main() {
    let mut buffer = String::new();

    io::stdin()
        .read_line(&mut buffer)
        .expect("Failed to read from stdin");

    let inputs = buffer.split_whitespace()
        .map(|x| x.parse::<i32>().expect("Not an int"))
        .collect::<Vec<i32>>();

    let n = inputs[0];
    let k = inputs[1];

    println!("Binomial coef of n={}, k={} is {}", n, k, binomial_coef(n, k));
}
