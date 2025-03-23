/**
 * Approximate using monte carlo Method
 */
extern crate rand;

use rand::{thread_rng, Rng};
use rand::distributions::{Distribution, Uniform};

use std::io;

fn pi_monte_carlo(points: u64) -> f64 {
    let mut circle_points = 0u64;

    let range = Uniform::new(-1.0f64, 1.0);
    let mut rng = rand::thread_rng();
    
    for i in 0..points {
        let x = range.sample(&mut rng);;
        let y = range.sample(&mut rng);

        if x * x + y * y < 1.0 {
            circle_points += 1;
        }
    }

    let pi = (circle_points as f64 / points as f64) * 4.0;

    pi
}

fn main() {
    let mut buffer = String::new();

    io::stdin()
        .read_line(&mut buffer)
        .expect("Failed to read stdin");

    let points = buffer.trim().parse::<u64>().expect("Not a float");

    let pi = pi_monte_carlo(points);

    println!("Pi = {}", pi);
}
