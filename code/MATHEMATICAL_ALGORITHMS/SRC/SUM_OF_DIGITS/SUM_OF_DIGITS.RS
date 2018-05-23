use std::io::{stdin, stdout, Write};

fn main() {
    stdout().write_all(b"Input your digits: ").unwrap();
    stdout().flush().unwrap();
    let mut input_text = String::new();
    stdin().read_line(&mut input_text).unwrap();
    let sum: u32 = input_text.chars().filter_map(|s| s.to_digit(10)).sum();
    println!("Sum of your digits is: {}", sum);
}
