use std::io;

fn search(string: &str, pattern: &str, start: u64, prev_match: bool) -> (bool, u64) {
    // Returns if start index is `ge` string length
    if start >= string.len() as u64 {
        return (false, start);
    }
    // Checks whether the char at string[start] equals the first char of pattern
    if string.chars().nth(start as usize).unwrap() == pattern.chars().nth(0).unwrap() {
        // Returns true if pattern's length is 1
        if pattern.len() == 1 {
            return (true, start);
        }
        // Creates a new pattern which consists of all the chars of pattern except the first char
        let new_pattern = &pattern[pattern.char_indices().nth(1).unwrap().0..];
        /*
        Returns only if the both the previous and next char match.
        Suppose the string is `hello` and the pattern is `ef`.
        It will initially match `e`, but since the next char in the pattern
        does not match, it should again start checking for an `e` from index 2 of
        the string. If we do not check for truthy prev_match, then a string
        of the likes of `helfo` will be matched by the pattern `ef`.
        */
        if prev_match && search(&string, &new_pattern, start + 1, true).0 {
            return (true, start);
        }
    }
    // Passing a falsy prev_match value since the previous char did not match.
    return search(&string, &pattern, start + 1, false);
}

fn main() {
    println!("Enter a string");
    let mut string = String::new();
    io::stdin().read_line(&mut string).expect("Error reading string");
    println!("Enter a pattern");
    let mut pattern = String::new();
    io::stdin().read_line(&mut pattern).expect("Error reading pattern");
    println!("{:?}", search(&string, &pattern, 0, false));
}