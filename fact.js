function fact(n,r)
{
	if(n==0) return r;
else{
	return (fact(n-1,r*n));
}
}
var u=fact(n,1);
console.log(u);