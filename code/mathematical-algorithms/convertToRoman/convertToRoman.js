const romanCharacters = {
  "1000":"M",
  "500":"D",
  "100":"C",
  "50":"L",
  "10":"X",
  "5":"V",
  "1":"I",
}

function cnv2roman(num, pos) { // 1:U, 10:D, 100:C, 1000:M
  let myNum = parseInt(num);

  if (myNum === 4 && pos === 1000) return "MMMM";

  switch (myNum) {
    case 0: //
      return "";
    case 1: // I
      return romanCharacters[String(1 * pos)];
    case 2: // II
      let x = romanCharacters[String(1 * pos)];
      return x + x;
    case 3: // III
      let y = romanCharacters[String(1 * pos)];
      return y + y + y;
    case 4: // IV
      return (romanCharacters[String(1*pos)] + romanCharacters[String(5*pos)]);
    case 5: // V
      return romanCharacters[String(5*pos)];
    case 6: // VI
      return (romanCharacters[String(5*pos)] + romanCharacters[String(1*pos)]);
    case 7: // VII
      let z = romanCharacters[String(1*pos)];
      return (romanCharacters[String(5*pos)] + z + z);
    case 8: // VIII
      let w = romanCharacters[String(1*pos)];
      return (romanCharacters[String(5*pos)] + w + w + w);
    case 9: // IX
      return (romanCharacters[String(1*pos)] + romanCharacters[String(10*pos)]);
  }
}

function convertToRoman(value) {
  const maxValue = 5000;
  let result = "";
  let valueString = String(value).split("").reverse().join("");

  if (!Number.isInteger(value) || value === 0 || value >= maxValue || value <= 0) {
    return;
  }

  for (let i = 0, len = valueString.length; i < len; i++) {
    result = cnv2roman(valueString.charAt(i), Math.pow(10, i)) + result;
  }

  return result;

}

module.exports.convertToRoman = convertToRoman;
