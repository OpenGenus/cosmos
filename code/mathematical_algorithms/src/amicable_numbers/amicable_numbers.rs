fn sum_of_divisors(a: u64) -> u64 {
    let mut sum = 0;
    // let max = (a as f64).sqrt() as u64;
    
    // TODO: Optimize by checking up to sqrt of a and using iterators
    
    for i in 1..a {
        if a % i == 0 {
            sum += i;
        }
    }
    
    sum
}

fn is_amicable(a: u64, b: u64) -> bool {
    sum_of_divisors(a) == b && sum_of_divisors(b) == a
}

#[test]
fn test_amicable() {
    assert!(!is_amicable(23, 234));
    
    assert!(is_amicable(220, 284));
    assert!(is_amicable(1184, 1210));
    assert!(is_amicable(17296, 18416));
}   
