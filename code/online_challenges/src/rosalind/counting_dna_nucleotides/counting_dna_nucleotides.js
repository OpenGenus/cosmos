function countDnaNucleotides(strand) {
  const nucleotides = {
    'A': 0,
    'C': 0,
    'G': 0,
    'T': 0
  };
  for(let i = 0; i < strand.length; i++) {
    nucleotides[strand[i]] += 1;
  }
  return nucleotides;
}
console.log(countDnaNucleotides(strand));