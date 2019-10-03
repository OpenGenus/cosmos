/* Checker */
const alphabet = [..."abcdefghijklmnopqrstuvwxyz"];

const countUnused = str =>
  alphabet.reduce(
    (unused, char) => unused + !str.toLowerCase().includes(char),
    0
  );

const checkLipogram = str => {
  let unused = countUnused(str);

  return unused >= 2
    ? "Not a pangram but might a lipogram"
    : unused == 1
    ? "Pangrammatic lipogram"
    : "Pangram";
};

/* Test */
checkLipogram("The quick brown fox jumps over the lazy dog"); // should return 'Pangram'
checkLipogram("OpenGenus cosmos"); // should return 'Not a pangram but might a lipogram'
checkLipogram(
  `A jovial swain should not complain
  Of any buxom fair
  Who mocks his pain and thinks it gain
  To quiz his awkward air.
`
); // should return 'Pangrammatic lipogram'
