// Part of Cosmos by OpenGenus Foundation

use std::{io::{self, Write}, process};

fn main() {
    // Print prompt
    print!("Enter an integer: ");
    io::stdout().flush().unwrap();

    // Read the input string and trim it (remove unnecessary spaces and newline
    // character)
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let input = input.trim();

    // Convert input string to a 64-bit integer. Print an error if it fails and
    // exit the program.
    let input = input.parse::<i64>().unwrap_or_else(|_| {
        println!("Error: Unable to convert input to decimal");
        process::exit(1);
    });

    // Store strings that contain the formatted/converted value
    let decimal = format!("{}", input);
    let binary = format!("{:b}", input);
    let hexadecimal = format!("{:X}", input);
    let octal = format!("{:o}", input);

    // Print
    println!("{:>11}: {}", "Hexadecimal", hexadecimal);
    println!("{:>11}: {}", "Decimal", decimal);
    println!("{:>11}: {}", "Octal", octal);
    println!("{:>11}: {}", "Binary", binary);
}
