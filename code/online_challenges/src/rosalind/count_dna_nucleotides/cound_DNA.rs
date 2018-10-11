use std::collections::HashMap;

fn count_dna(dna: &str) -> String {
    let mut map = HashMap::new();
    for c in dna.chars() {
        match c {
            'A' => {
                let count = map.entry("A").or_insert(0);
                *count += 1;
            }
            'C' => {
                let count = map.entry("C").or_insert(0);
                *count += 1;
            }
            'G' => {
                let count = map.entry("G").or_insert(0);
                *count += 1;
            }
            'T' => {
                let count = map.entry("T").or_insert(0);
                *count += 1;
            }
            _ => (),
        }
    }

    format!(
        "{} {} {} {}",
        map.get("A").unwrap_or(&0),
        map.get("C").unwrap_or(&0),
        map.get("G").unwrap_or(&0),
        map.get("T").unwrap_or(&0),
    )
}

#[test]
fn sample_test() {
    assert_eq!(
        count_dna("AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC"),
        "20 12 17 21"
    );
}
