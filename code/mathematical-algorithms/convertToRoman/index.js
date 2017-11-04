const {convertToRoman} = require('./convertToRoman');

var stdin = process.openStdin();

stdin.addListener("data", function(d) {
  let myStr = d.toString().trim();
  console.log(convertToRoman(parseInt(myStr)));
});
