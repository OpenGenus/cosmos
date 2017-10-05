fn main() {
    tower_of_hanoi(5,"A","C","B");
}

fn tower_of_hanoi(n:u32, from: &str, to: &str, aux: &str) {
    if n >= 1 {
        tower_of_hanoi(n-1, from, aux, to);
        println!("Move {}, from: {} to from {}",n,from,to );
        tower_of_hanoi(n-1,aux,to,from);
    }
}