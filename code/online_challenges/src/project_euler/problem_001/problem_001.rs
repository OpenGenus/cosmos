/*

// online challenges | project euler | problem 001 | problem 001 | RUST
// Part of Cosmos by OpenGenus Foundation

*/


fn main() {
    let mut sum = 0;
    for i in 1..1000 {
        if i % 3 == 0 || i % 5 == 0 {
            sum += i
        }
    }
    println!("{}", sum);
}
