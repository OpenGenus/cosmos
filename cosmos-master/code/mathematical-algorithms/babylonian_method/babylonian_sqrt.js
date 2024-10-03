function b_sqrt(n,e=1e-5){
	var x = n;
	while(x-(n/x) > e){
	      	x = ((n/x)+x)/2;
	}
	return x;
}


console.log(b_sqrt(90));
