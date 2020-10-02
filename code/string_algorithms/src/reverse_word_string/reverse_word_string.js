function reverseString(string) {
    const reversedString = string.split(' ').reverse().join(' ');
    console.log(reversedString);
}

reverseString('I know what you did last summer'); // summer last did you what know I
reverseString('OpenGenus cosmos'); // cosmos OpenGenus
