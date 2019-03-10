// Convert numbers higher than 9 (up to 15) to letters.
// Part of Cosmos by OpenGenus Foundation
function hex_val(value) {
  switch (value) {
    case 10:
      return "a";
    case 11:
      return "b";
    case 12:
      return "c";
    case 13:
      return "d";
    case 14:
      return "e";
    case 15:
      return "f";
    default:
      return value;
  }
}

// Convert a decimal number to any base, from 2 to 16.
function decimal_to_base(N, base) {
  if (base < 2 || base > 16) {
    throw new Error("Not implemented!");
  }
  var s = "";
  while (N > 0) {
    var val = N % base;
    s = hex_val(val) + s;
    N = Math.floor(N / base);
  }
  return s;
}

// Conversion from decimal to hexadecimal.
function decimal_to_hexadecimal(N) {
  return decimal_to_base(N, 16);
}

// Conversion from decimal to octal.
function decimal_to_octal(N) {
  return decimal_to_base(N, 8);
}

// Conversion from decimal to binary.
function decimal_to_binary(N) {
  return decimal_to_base(N, 2);
}
