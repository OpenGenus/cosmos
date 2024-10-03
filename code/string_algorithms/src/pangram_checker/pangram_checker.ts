/* Part of Cosmos by OpenGenus Foundation */
/* Checker */
export function isPangram(str: string): boolean {
    const alphabet: Array<string> = [..."abcdefghijklmnopqrstuvwxyz"];

    return alphabet.every((char: string): boolean => {
        return str.toLowerCase().includes(char)
    });
}

/* Test */
isPangram("Totally not a panagram"); // should return false
isPangram("Still not a panagram"); // should return false
isPangram("The quick brown fox jumps over a lazy dog"); // should return true
isPangram("Pack my box with five dozen liquor jugs"); // should return true
isPangram("The five boxing wizards jump quickly"); // should return true
