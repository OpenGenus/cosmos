// Part of Cosmos by OpenGenus Foundation

use std::{io::{self, Write}, process};

/// Invert a bit at a given place
///
/// # Arguments
///
/// * `bits` - The value/bits you want to modify
///
/// * `place` - The position of the bit you want to invert
///
/// # Examples
/// ```
/// let value = 50;                           //   110010
/// let place = 2;                            // ^ 000100
/// let new_value = invert_bit(value, place); // = 110110
/// ```
fn invert_bit(bits: u32, place: u8) -> u32 {
    bits ^ 1 << place
}

fn main() {
    // Get value
    print!("enter a value: ");
    io::stdout().flush().unwrap();

    let mut value = String::new();
    io::stdin().read_line(&mut value).unwrap_or_else(|_| {
        eprintln!("error: unable to read input (value)");
        process::exit(1);
    });
    let value = value.trim();

    let value = value.parse::<u32>().unwrap_or_else(|_| {
        eprintln!("error: invalid input (value must be unsigned 32-bit integer)");
        process::exit(1);
    });

    // Get place
    print!("enter a place: ");
    io::stdout().flush().unwrap();

    let mut place = String::new();
    io::stdin().read_line(&mut place).unwrap_or_else(|_| {
        eprintln!("error: unable to read input (place)");
        process::exit(1);
    });
    let place = place.trim();

    let place = place.parse::<u8>().unwrap_or_else(|_| {
        eprintln!("error: invalid input (place must be unsigned 8-bit integer)");
        process::exit(1);
    });

    if place > 31 {
        eprintln!("error: left bit shift overflow (place must be between 0 inclusive and 31 inclusive)");
        process::exit(1);
    }

    // Invert bit
    let new_value = invert_bit(value, place);
    println!("{:>8}: {:032b}", "input", value);
    println!("{:>8}: {:032b}", "output", new_value);
}
