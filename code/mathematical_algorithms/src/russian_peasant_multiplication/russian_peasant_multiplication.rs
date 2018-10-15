fn russian_peasant(mut a: u32, mut b: u32) -> u32 {
    let mut res = 0;

    while b > 0 {
        if (b & 1) != 0 {
            res += a;  
        }

        a = a << 1;
        b = b >> 1;
    }
    res
}

fn main() {
    println!("{}", russian_peasant(18, 24));
    println!("{}", russian_peasant(20, 12));
}