/*
 * Part of Cosmos by OpenGenus Foundation
 */
function unfactorial(num) {
  var d = 1;
  while (num > 1 && Math.round(num) === num) {
    d += 1;
    num /= d;
  }
  if (num === 1) return d + "!";
  else return "NONE";
}
