//Author: Amit Kr. Singh
//Github: @amitsin6h
//Social: @amitsin6h
//OpenGenus Contributor

function checkPalindrome(str) {
       	var palindrome_str = str.split('').reverse().join('');
	if(palindrome_str == str){
	    console.log('True');
	}else{
	    console.log('False');
	}
}
checkPalindrome('malayalam')
