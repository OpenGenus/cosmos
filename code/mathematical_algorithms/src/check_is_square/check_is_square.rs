// Part of Cosmos by OpenGenus Foundation 
//-- Function to check if a number is square
//-- Accepts integers, and converts it internally to float
use std::f64;

fn check_square(n: i64 ) -> bool {
    if n < 0 { return false; }
    let nc = n as f64;
    let r = nc.sqrt().round();
    if r * r == nc { return true; }
    false
}

fn main() {
    let test = vec!(1,2,3,4,5,6,7,8,9,10);
    for t in test { println!("{}: {}", t, check_square(t)); }
}
