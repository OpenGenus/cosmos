/* Part of Cosmos by OpenGenus Foundation */

//Using built in functions:

function toBinary(val) {
  return val.toString(2);
}

function fromBinary(bitString) {
  return parseInt(bitString, 2);
}

//Using bitshifts

function toBinary_B(val) {
  let out = "";
  while (val > 0) {
    out = (val & 1) + out;
    val >>= 1;
  }
  return out;
}

function fromBinary_B(bitString) {
  let out = 0;
  let l = bitString.length;
  let i = 0;
  for (; i < l; i++) {
    out += +bitString[i] ? 1 << (l - i - 1) : 0;
  }
  return out;
}
