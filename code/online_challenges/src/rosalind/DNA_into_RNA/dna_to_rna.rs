fn to_rna(dna: &str) -> String {
    dna.chars()
        .map(|c| if c == 'T' { 'U' } else { c })
        .collect()
}

#[test]
fn sample_test() {
    assert_eq!(to_rna("GATGGAACTTGACTACGTAAATT"), "GAUGGAACUUGACUACGUAAAUU");
}
