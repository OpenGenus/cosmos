/* Part of Cosmos by OpenGenus Foundation */
/* Created by Luke Diamond on 13/10/2017 */

fn is_power_of_2(x: i32) -> bool {
	x != 0 && ((x & (x - 1)) == 0)
}

fn main() {
	let mut input_text = String::new();
	println!("Input Number:");
	std::io::stdin().read_line(&mut input_text);
	let number = input_text.trim().parse::<i32>().unwrap();

	if is_power_of_2(number) {
		println!("{} Is a power of 2", number);
	} else {
		println!("{} Is not a power of 2", number);
	}
}
