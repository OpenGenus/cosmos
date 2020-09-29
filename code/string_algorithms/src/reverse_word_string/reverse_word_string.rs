use std::io::*;

fn reverse_words(words: String) -> Vec<String> {
    words
        .split_whitespace()
        .map(|s| s.to_string())
        .rev()
        .collect()
}

fn main() {
    print!("Enter the sentence: ");

    stdout().flush().unwrap();
    let mut sentence = String::new();
    stdin()
        .read_line(&mut sentence)
        .expect("Cannot read user input");

    let result = reverse_words(sentence);
    println!("{}", result.join(" "));
}
