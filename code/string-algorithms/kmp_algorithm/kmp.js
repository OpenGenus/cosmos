/*
Part of Cosmos by OpenGenus Foundation 
the Knuth-Morris-Pratt string searching algorithm (or KMP algorithm) 
*/



//first step is to generate lps array i.e. longest prefix suffix array
function getLPS(pattern){

	var m = pattern.length,lps = Array(m+1),i=0,j=-1;
	lps.fill(0);
	lps[i]=j;
	while(i<m){

		while(j>=0 && pattern[i] != pattern[j])
			j = lps[j];
		
		i+=1; j+=1;
		lps[i] = j;
	}
	return lps;
}

//pattern matching
function kmp(text,pattern){

	var lps = getLPS(pattern);
	var i=0,j=0,n=text.length,m=pattern.length;
	while(i<n){

		while (j>=0 && text[i] != pattern[j])
			j = lps[j];
		i+=1; j+=1;
		if(j == m){
			console.log("Match found at index: " + (i-j))
			j = lps[j]
		}
	}
}