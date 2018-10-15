/// Perfect number is a positive integer that is equal to the sum of its proper divisors.
 
fn is_perfect(num: i32) -> bool {
    let mut sum = 0;
    for i in 1..num {
        if num % i == 0 {
            sum += i;
        }
    }

    if sum == num {
        true
    } else {
        false
    }
}

fn main() {
    for i in 1..100 {
        println!("{} is perfect: {}", i, is_perfect(i));
    }
    println!("{} is perfect: {}", 496, is_perfect(496));
}
