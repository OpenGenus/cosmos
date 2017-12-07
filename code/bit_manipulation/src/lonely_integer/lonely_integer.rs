/*
* Part of Cosmos by OpenGenus Foundation
*/
fn lonely_integer(a: &[i64]) -> i64 {
    let mut lonely = 0;
    
    for i in a {
        lonely ^= *i;
    }
    
    lonely
}

fn main() {
    let a = [2, 3, 4, 5, 3, 2, 4];
    println!("{}", lonely_integer(&a));
}
