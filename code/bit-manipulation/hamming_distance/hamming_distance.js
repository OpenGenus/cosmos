function HammingDistance(string1, string2) {

    if (string1.length == string2.length) {

        var dist = 0;

        for (var i = 0; i<string1.length; i++) {

            if ((string1[i] == '0' && string2[i] == '1') || (string1[i] == '1' && string2[i] == '0'))
                dist++;

        }

        return dist;

    }

    return 0;

}

module.exports = HammingDistance;