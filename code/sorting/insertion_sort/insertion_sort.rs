// Part of Cosmos by OpenGenus Foundation
fn insertion_sort(array_A: &mut [int, ..6]) {
	// Implementation of the traditional insertion sort algorithm in Rust
	// The idea is to both learn the language and re visit classic (and not so much) 
	// algorithms.
	// This algorithm source has been extracted from "Introduction to Algorithms" - Cormen
	let mut i: int;

	//utility variable. Ugly hack to avoid casting back and forward from int to uint
	let mut i_u: uint; 
	let mut key: int;


	// It is not necessary to explicitly declare j
	for j in range(1u, array_A.len()) { //arrays only work with uint (unsigned)
		key = array_A[j];
		i_u = j - 1;
		i = i_u as int;

		while i >= 0 && array_A[i_u] > key {
			array_A[i_u + 1] = array_A[i_u];

			i = i - 1;
			i_u = i as uint;
		};
		array_A[i_u + 1]  = key;
		
	};

}


fn main() {
	//This should be replaced eventually by the unit test framework.

	let mut array_A = [31i, 41, 59, 26, 41, 58];
	// let mut array_A = [5i,2,4,6,1,3];
	

	// Need to pass a reference, so the sorting function can modify the
	// array being sorted (this is very similar to C lang).
	insertion_sort(&mut array_A);

	//Just for printing purposes
	for j in range(0u, array_A.len()) {
		println!("{}", array_A[j]);
	};

    
}
