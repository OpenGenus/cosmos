/**
 * Translate a string to a morse code in the american morse code standard
 *
 * Input    :   A string
 * Output   :   The input string converted to morse code. If the given character
 *              cannot be produced in morse code it will be ommitted. The case
 *              of the input string does not matter.
 * Example  :   const morse = encrypt('sos'); // => ... --- ...
 *              const str = dencrypt('... --- ...'); // => SOS
 */

const CHAR_MAP = {
	A: '.-',
	B: '-...',
	C: '-.-.',
	D: '-..',
	E: '.',
	F: '..-.',
	G: '--.',
	H: '....',
	I: '..',
	J: '.---',
	K: '-.-',
	L: '.-..',
	M: '--',
	N: '-.',
	O: '---',
	P: '.--.',
	Q: '--.-',
	R: '.-.',
	S: '...',
	T: '-',
	U: '..-',
	V: '...-',
	W: '.--',
	X: '-..-',
	Y: '-.--',
	Z: '--..',
	0: '-----',
	1: '.----',
	2: '..---',
	3: '...--',
	4: '....-',
	5: '.....',
	6: '-....',
	7: '--...',
	8: '---..',
	9: '----.',
	'.': '.-.-.-',
	'?': '..--..',
	'!': '-.-.--',
	'(': '-.--.',
	')': '-.--.-',
	':': '---...',
	';': '-.-.-.',
	',': '--..--',
	"'": '.----.',
	'/': '-..-.',
	'&': '.-...',
	'-': '-....-'
};

const PATTERN_MAP = Object.keys(CHAR_MAP).reduce(
	(obj, key) => Object.assign({}, obj, { [CHAR_MAP[key]]: key }),
	{}
);

function encrypt(string) {
	return (
		string.length &&
		string
			.toUpperCase()
			.split('')
			.map(c => `${CHAR_MAP[c] || ''} `)
			.join('')
	);
}

function decrypt(string) {
	return (
		string.length &&
		string
			.toUpperCase()
			.split(' ')
			.map(p => `${PATTERN_MAP[p] || ''}`)
			.join('')
	);
}
