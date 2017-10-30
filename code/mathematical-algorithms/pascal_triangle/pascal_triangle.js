/* Part of Cosmos by OpenGenus Foundation */

// Prints Pascal's Triangle line by line
const printTriangleByLine = function(numRows) {
  console.log(1);
  
  let previousRow = [1];
  
  for(let n = 1; n < numRows; ++n) {
    let currentRow = new Array(n + 1);
    currentRow[0] = currentRow[n] = 1;
    for(let k = 1; k < n; ++k) {
      currentRow[k] = previousRow[k - 1] + previousRow[k];
    }
    console.log(currentRow.join(" "));
    previousRow = currentRow;
  }
}

// Returns a 2D array of Pascal's Triangle
const pascalTriangle = function(numRows) {
  let triangleArray = [...Array(numRows).keys()].map(i => Array(numRows));
  
  for(let n = 0; n < numRows; ++n) {
    triangleArray[n][0] = triangleArray[n][n] = 1;
    for(let k = 1; k < n; ++k) {
      triangleArray[n][k] = triangleArray[n - 1][k - 1] + triangleArray[n - 1][k];
    }
  }
  
  return triangleArray;
}

// Tests the printTriangleByLine function
printTriangleByLine(10);

// Tests the pascalTriangle function
console.log(pascalTriangle(10).map(r => r.join(" ")).join("\n"));
