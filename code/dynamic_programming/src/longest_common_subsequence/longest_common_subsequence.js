const longestCommonSubsequence = (arr1, arr2) => {

    let LCS_def = Array.from({ length: arr1.length + 1 },
        () => Array.from({ length: arr2.length + 1 },
            () => 0));
    
    for (let i = 0; i < arr1.length + 1; i++){
        for (let j = 0; j < arr2.length+1; j++){
            
            if (i == 0 || j == 0) {
                LCS_def[i][j] = 0;
            }

            // when the last character of both match, increase length of lcs by 1
            else if (arr1[i - 1] == arr2[j - 1]) {
                LCS_def[i][j] = LCS_def[i - 1][j - 1] + 1;
            }
                
            /* 
            when the last character is not same, take maximum obtained by adding 
            one character to one of the subsequences.
            */
            else {
                LCS_def[i][j] = Math.max(LCS_def[i - 1][j], LCS_def[i][j - 1])
            }
        }
    }
    
    return `The length of longest subsequence is: ${LCS_def[arr1.length][arr2.length]}`;
    
}


// I/P and O/P Examples

const inputSet1 = [10, 15, 20, 25, 30, 35, 40];
const inputSet2 = [10, 12, 23, 25, 28, 30, 32, 40];
const result = longestCommonSubsequence(inputSet1, inputSet2);

// The length of longest subsequence is: 4
console.log(result);
