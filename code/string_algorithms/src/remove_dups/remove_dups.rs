fn remove_dup(string: &str) -> String {
    let mut chars: Vec<char> = string.chars().collect();
    chars.dedup();
    chars
        .iter()
        .map(|c| c.to_string())
        .collect::<Vec<String>>()
        .join("")
}

// rustc --test remove_dups.rs
// ./remove_dups OR remove_dups.exe
#[test]
fn simple_test() {
    assert_eq!("abcd", remove_dup("abbcccdddd"));
    assert_eq!(
        "lol",
        remove_dup("llllllloooooooooooooooooolllllllllllllll")
    );
}
