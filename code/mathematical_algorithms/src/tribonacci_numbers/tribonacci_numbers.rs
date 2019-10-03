// Prints series of 'n' tribonacci numbers 

fn tribonacci(n: i32) {
    let mut a = 0;
    let mut b = 1;
    let mut c = 1;
    print!("{}, {}, {}, ", a, b, c);
    for _ in 3..n {
        let d = a + b + c;
        a = b;
        b = c;
        c = d;
        print!("{}, ", d);
    }
}

fn main() {
    tribonacci(15)
}