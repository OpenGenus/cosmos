//Part of Cosmos by OpenGenus Foundation 

function isSquare(n){
	a = Math.sqrt(n);
	if(Number.isInteger(a)){
		console.log(n + ' is a perfect square of '+ a);
	}else{
		console.log(n+" is not a perfect square");
	}
}

console.log(isSquare(91));