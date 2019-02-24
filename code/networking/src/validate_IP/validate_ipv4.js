function verify_ipv4(ip) {
  const rx = /^(?!0)(?!.*\.$)((1?\d?\d|25[0-5]|2[0-4]\d)(\.|$)){4}$/;
  return ip.match(rx);
}
/*

Regex explanation:

^ start of string
  (?!0)         Assume IP cannot start with 0
  (?!.*\.$)     Make sure string does not end with a dot
  (
    (
    1?\d?\d|   A single digit, two digits, or 100-199
    25[0-5]|   The numbers 250-255
    2[0-4]\d   The numbers 200-249
    )
  \.|$ the number must be followed by either a dot or end-of-string - to match the last number
  ){4}         Expect exactly four of these
$ end of string

*/

// testing
let ips = [
  "1.2.3.4",
  "11.11.11.11",
  "123.123.123.123",
  "255.250.249.0",
  "1.12.123.255",
  "127.0.0.1",
  "1.0.0.0",
  "0.1.1.1",
  "01.1.1.1",
  "012.1.1.1",
  "1.2.3.4.",
  "1.2.3\n4",
  "1.2.3.4\n",
  "259.0.0.1",
  "123.",
  "1.2.3.4.5",
  ".1.2.3.4",
  "1,2,3,4",
  "1.2.333.4",
  "1.299.3.4"
];
ips.forEach(function(s) {
  if (verify_ipv4(s)) {
    console.log("valid: " + s);
  } else {
    console.log("invalid: " + s);
  }
});
