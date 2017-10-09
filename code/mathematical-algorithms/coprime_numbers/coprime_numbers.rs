fn gcd(mut a: i32, mut b: i32) -> i32 {
    while b != 0 {
        let temp = a % b;
        a = b;
        b =  temp;       
    }
    a
}

fn co_prime(a: i32, b: i32) -> bool {
    if a > b {
        gcd(a,b) == 1
    }else {
        gcd(b,a) == 1
    }
}

fn main() {
    let a = 15;
    let b = 14;
    println!("Are {} and {} coprime? {}",a,b,co_prime(a,b) )
}