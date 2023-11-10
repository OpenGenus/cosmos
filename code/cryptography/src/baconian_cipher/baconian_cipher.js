function baconianEncrypt(plainText) {
  let baconianCodes = {
    a: "AAAAA",
    b: "AAAAB",
    c: "AAABA",
    d: "AAABB",
    e: "AABAA",
    f: "AABAB",
    g: "AABBA",
    h: "AABBB",
    i: "ABAAA",
    j: "BBBAA",
    k: "ABAAB",
    l: "ABABA",
    m: "ABABB",
    n: "ABBAA",
    o: "ABBAB",
    p: "ABBBA",
    q: "ABBBB",
    r: "BAAAA",
    s: "BAAAB",
    t: "BAABA",
    u: "BAABB",
    v: "BBBAB",
    w: "BABAA",
    x: "BABAB",
    y: "BABBA",
    z: "BABBB"
  };

  let cipherText = "";
  [...plainText].forEach(
    char => (cipherText += baconianCodes[char.toLowerCase()])
  );

  return cipherText;
}

console.log(baconianEncrypt("THISISASECRETTEST"));
console.log(baconianEncrypt("SAVETHECASTLE"));
