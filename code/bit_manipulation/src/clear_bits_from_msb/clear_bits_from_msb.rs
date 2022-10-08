/*
Problem Statement :
Clear all MSB's except for the first i LSB's of a number n.
MSB -> Most Significant Bit
LSB -> Most Significant Bit 
*/

use std::io;

fn clear_bits_from_msb(n: i32, i: i32)->i32
{
  let mask:i32 = (1 << i) - 1;
  return n & mask;
}

fn main() 
{
  let n:i32; 
  let i:i32;
  let result:i32;
  
  println!("Enter n :");

  let mut input1 = String::new();

  io::stdin().read_line(&mut input1).expect("Couldn't read the input");

  n = input1.trim().parse().expect("Input isn't a number");

  println!("Enter i :");
  
  let mut input2 = String::new();
  
  io::stdin().read_line(&mut input2).expect("Couldn't read the input");

  i = input2.trim().parse().expect("Input isn't a number");

  result = clear_bits_from_msb(n, i);

  println!("Result : {}", result);
}

/*
Enter n :
14
Enter i :
3
Result : 6
*/
