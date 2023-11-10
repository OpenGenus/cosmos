/*  
      Path of Cosmos by OpenGenus
      
      To find the longest palindromic substring in JavaScript

      Example : Input String : "agbdcdbty" the palindromic substring is "bdcdb"
*/

// A utility function to check if a substring is a palindrome
function isPalindrome(str){
      var rev = str.split("").reverse().join("");
      return str == rev;
}
 
// The main function to find the longest palindromic substring
function longestPalindromicSubstring(str){
      var maxL=0;
      maxp = ' ';
    
     // loop to check each and every substring
      for(var i=0; i < str1.length; i++) {
            var subs = str1.substr(i, str1.length);

            for(var j=subs.length; j>=0; j--) {
                  var sub_subs_str = subs.substr(0, j);
                  if (sub_subs_str.length <= 1){
                        continue;
                  }
                 // to check if the substring is a palindrome
                  if (is_Palindrome(sub_subs_str)){
                        // if length of palindromic substring is greater than the current maximum length 
                       // then change the value of maximum length and store the corresponding value 
                       // of the substring
                        if (sub_subs_str.length > max_length) {
                              max_length = sub_subs_str.length;
                              maxp = sub_subs_str;
                       }
                  }
            }
      }
      return maxp; // return the answer
}
console.log(longest_palindrome("abccbatry")); // print the solution
}

/*
 Output String : abccba
*/
