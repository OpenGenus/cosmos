---
title: On a Chess Board, find minimum steps a knight would take to reach a target location
---
## Knight Minimum Steps to Target

The magic formula is:
~~~~
function distance(x,y){
     // axes symmetry 
     x = Math.abs(x);
     y = Math.abs(y);
     // diagonal symmetry 
     if (x < y) {
        t = x;x = y; y = t;
     }
     // 2 corner cases
     if(x==1 && y == 0){
        return 3;
     }
     if(x==2 && y == 2){
        return 4;
     }
    // main formula
    var delta = x-y;
		if(y>delta){
  		return delta - 2*Math.floor((delta-y)/3);
  	}
  	else{
  		return delta - 2*Math.floor((delta-y)/4);
  	}
}
~~~~
