/*

// string algorithms | reverse word string | reverse word string | JAVASCRIPT
// Part of Cosmos by OpenGenus Foundation

*/


function reverseString(string) {
    const reversedString = string.split(' ').reverse().join(' ');
    console.log(reversedString);
}

reverseString('I know what you did last summer'); // summer last did you what know I
reverseString('OpenGenus cosmos'); // cosmos OpenGenus
