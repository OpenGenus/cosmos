
function printMatrix(matrix, n) {
for (let i = 0; i < n; i++) {
	console.log(matrix[i]);
}
}


function checkHorizontal(x, y, matrix, currentWord) {
const n = currentWord.length;

for (let i = 0; i < n; i++) {
	if (matrix[x][y + i] === '#' || matrix[x][y + i] === currentWord[i]) {
	matrix[x] = matrix[x].slice(0, y + i) + currentWord[i] + matrix[x].slice(y + i + 1);
	} else {


	matrix[0] = "@";
	return matrix;
	}
}
return matrix;
}



function checkVertical(x, y, matrix, currentWord) {
const n = currentWord.length;

for (let i = 0; i < n; i++) {
	if (matrix[x + i][y] === '#' || matrix[x + i][y] === currentWord[i]) {
	matrix[x + i] = matrix[x + i].slice(0, y) + currentWord[i] + matrix[x + i].slice(y + 1);
	} else {

	
	matrix[0] = "@";
	return matrix;
	}
}
return matrix;
}



function solvePuzzle(words, matrix, index, n) {
if (index < words.length) {
	const currentWord = words[index];
	const maxLen = n - currentWord.length;

	for (let i = 0; i < n; i++) {
	for (let j = 0; j <= maxLen; j++) {
		const temp = checkVertical(j, i, [...matrix], currentWord);
		if (temp[0] !== "@") {
		solvePuzzle(words, temp, index + 1, n);
		}
	}
	}

	for (let i = 0; i < n; i++) {
	for (let j = 0; j <= maxLen; j++) {
		const temp = checkHorizontal(i, j, [...matrix], currentWord);
		if (temp[0] !== "@") {
		solvePuzzle(words, temp, index + 1, n);
		}
	}
	}
} else {

	
	console.log(`${ways + 1} way to solve the puzzle`);
	printMatrix(matrix, n);
	console.log();

	ways += 1;
	return;
}
}

const n1 = 10;

const matrix = [];


matrix.push("*#********");
matrix.push("*#********");
matrix.push("*#****#***");
matrix.push("*##***##**");
matrix.push("*#****#***");
matrix.push("*#****#***");
matrix.push("*#****#***");
matrix.push("*#*######*");
matrix.push("*#********");
matrix.push("***#######");


const words = [];
words.push("PUNJAB");
words.push("JHARKHAND");
words.push("MIZORAM");
words.push("MUMBAI");


ways = 0;
	


solvePuzzle(words, matrix, 0, n1);
console.log("Number of ways to fill the grid is " + ways);

