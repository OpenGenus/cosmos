/*
 * @author: Ryan Lanese <github:ryanml>
 * Cosmos by OpenGenus Foundation
 */

class PangramChecker {

    constructor() {
        this.charBank = 'abcdefghijklmopqrstuvwxyz';
    }

    checkPangram(str) {
        var tempList = [...this.charBank];
        var charList = str.replace(/ /g, '');

        if (charList.length < 26)
            return false;

        for (var i = 0; i < charList.length; i++) {
            if (tempList.length === 0) 
                return true;

            var index = tempList.indexOf(charList[i].toLowerCase());

            if (index > -1)
                tempList.splice(index, 1);
        }

        return false;
    }

}

function test() {
    var checker = new PangramChecker();
    console.log(checker.checkPangram("Totally not a panagram."));
    console.log(checker.checkPangram("Still not a panagram."));
    console.log(checker.checkPangram("The quick brown fox jumps over a lazy dog."));
    console.log(checker.checkPangram("Pack my box with five dozen liquor jugs."));
}

test();
