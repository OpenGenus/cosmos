// Part of Cosmos by OpenGenus Foundation

fn is_palindrome(input: &str) -> bool {
    let reversed: String = input.chars().rev().collect();
    reversed == input
}

fn main() {
    println!("{:?}", is_palindrome("test"));
    println!("{:?}", is_palindrome("hahah"));
}