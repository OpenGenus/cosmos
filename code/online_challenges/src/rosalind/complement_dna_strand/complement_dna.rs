fn complement_dna(dna: &str) -> String {
    dna.chars()
        .rev()
        .map(|c| match c {
            'A' => 'T',
            'T' => 'A',
            'C' => 'G',
            'G' => 'C',
            _ => ' ',
        })
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn sample_test() {
        assert_eq!(complement_dna("AAAACCCGGT"), "ACCGGGTTTT");
    }
}
