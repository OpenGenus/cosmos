// dynamic programming | edit distance | Javascript
// Part of Cosmos by OpenGenus Foundation

editDistance = function(str1, str2) {
    var lenStr1 = str1.length;
    var lenStr2 = str2.length;
    

    if (lenStr1 == 0) {
        return lenStr2;
    }

    if (lenStr2 == 0) {
        return lenStr1;
    }

    var distanceVectorInit = [];
    var distanceVectorFinal = [];
    for(var i=0; i<lenStr1+1; i++) {
       distanceVectorInit.push(0);
       distanceVectorFinal.push(0);
    }

    for(var i=0; i<lenStr1+1; i++) {
        distanceVectorInit[i] = i;
    }

    for(var i=0; i<lenStr2; i++) {
        distanceVectorFinal[0] = i+1;
        // use formula to fill in the rest of the row
        for (var j = 0; j < lenStr1; j++) {
            var substitutionCost = 0;
            if (str1[j] == str2[i]) {
                substitutionCost = distanceVectorInit[j];
            } else {
                substitutionCost = distanceVectorInit[j] + 1
            }

            distanceVectorFinal[j+1] = Math.min(distanceVectorInit[j+1] + 1, distanceVectorFinal[j] + 1, substitutionCost);
        }

        distanceVectorInit = distanceVectorFinal.slice(0);
    }

    return distanceVectorFinal[lenStr1];
}

console.log(editDistance("saturday", "sunday")); //Should be equal to 3