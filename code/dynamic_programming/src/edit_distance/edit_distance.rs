// dynamic programming | edit distance | Rust
// Part of Cosmos by OpenGenus Foundation

use std::cmp;
fn edit_distance(str1: &String, str2: &String) -> usize {
    let len_str1 = str1.len();
    let len_str2 = str2.len();

    if len_str1 == 0 {
    	return len_str2;
    }

    if len_str2 == 0 {
    	return len_str1;
    }

    let mut distance_vector_init = vec![0; len_str1+1];
    let mut distance_vector_final = vec![0; len_str1+1];

    for i in 0..len_str1+1 {
		distance_vector_init[i] = i;
	}
	

	for i in 0..len_str2 {
		distance_vector_final[0] = i+1;
		// use formula to fill in the rest of the row
        for j in 0..len_str1 {
            let mut substitution_cost;
            let mut iter1 = str1.chars();
            let mut iter2 = str2.chars();

            let e1 = iter1.nth(j);
            let e2 = iter2.nth(i);
			
            if e1.is_some() && e2.is_some() && e1.unwrap() == e2.unwrap() {
                substitution_cost = distance_vector_init[j];
            } else {
                substitution_cost = distance_vector_init[j] + 1
            };

            distance_vector_final[j + 1] = cmp::min(distance_vector_init[j+1] + 1, cmp::min(distance_vector_final[j] + 1, substitution_cost));
        }

        distance_vector_init = distance_vector_final.clone();
	}

	distance_vector_final[len_str1]
}

fn main() {
    println!("edit_distance(saturday, sunday) = {}", edit_distance(&String::from("sunday"), &String::from("saturday")));
    println!("edit_distance(sitten, kitten) = {}", edit_distance(&String::from("kitten"), &String::from("sitten")));
    println!("edit_distance(gumbo, gambol) = {}", edit_distance(&String::from("gambol"), &String::from("gumbo")));
}