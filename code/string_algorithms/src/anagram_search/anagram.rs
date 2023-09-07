fn is_anagram(a: &str ,b : &str) ->  bool {
    let mut a:Vec<char> = a.chars().filter(|&c| c != ' ').collect();
    a.sort();
    let mut b:Vec<char> = b.chars().filter(|&c| c != ' ').collect();
    b.sort();
    if a == b {
        return true
    }
    false
}

#[test]
fn simple_test() {
    assert!(is_anagram("god", "dog"));
    assert!(is_anagram("anagram", "nag a ram"));
    assert!(is_anagram("god", "dog"));
    assert!(is_anagram("a b a", "aab"));
    assert!(!is_anagram("cat", "dog"));
}
