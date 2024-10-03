process.stdin.setEncoding('utf8');

//#region Boilerplate to read input line by line
let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
  inputString += inputStdin;
});

process.stdin.on('end', _ => {
  inputString = inputString
    .trim()
    .split('\n')
    .map(str => str.trim());

  main();
});

function readLine() {
  return inputString[currentLine++];
}
//#endregion

function intersection(setA, setB) {
  var _intersection = new Set();
  for (var elem of setB) {
    if (setA.has(elem)) {
      _intersection.add(elem);
    }
  }
  return _intersection;
}

function solve(testNum) {
  resultList = [];
  for (var testIdx = 0; testIdx < testNum; testIdx++) {
    dishesNum = Number(readLine());
    let result = new Set(readLine());

    for (var dishIdx = 0; dishIdx < dishesNum - 1; dishIdx++) {
      result = intersection(result, readLine());
    }
    resultList.push(result);
  }
  return resultList;
}

function main() {
  const ws = process.stdout;

  const s = Number(readLine());

  let resultList = solve(s);
  for (var idx = 0; idx < resultList.length; idx++) {
    ws.write(resultList[idx].size + '\n');
  }
}
