use std::env;

// Part of Cosmos by OpenGenus Foundation

fn factorial(n: i64) -> i64 {
    if n == 0 {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

fn main() {
    if let Some(arg) = env::args().nth(1) {
        if let Ok(x) = arg.parse::<i64>() {
            println!("{}", factorial(x));
        }
    }
}
