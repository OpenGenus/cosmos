#include <iostream>

int main() 
{
	int n, k, rQ, cQ;

	std::cin >> n >> k >> rQ >> cQ;

  //Directions available for queen to move
	int N = n - rQ;
	int S = rQ - 1;
	int E = n - cQ;
	int W = cQ - 1;
	int NE = (n - rQ < n - cQ ? n - rQ : n - cQ);
	int SE = (rQ - 1 < n - cQ ? rQ - 1 : n - cQ);
	int NW = (n - rQ < cQ - 1 ? n - rQ : cQ - 1);
	int SW = (rQ - 1 < cQ - 1 ? rQ - 1 : cQ - 1);

	int rObj, cObj;

	for (int i = 0; i < k; ++i)
  	{
  		std::cin >> rObj >> cObj;
  		if (cQ == cObj) 
    	{
      		if ((rObj > rQ) && (rObj - rQ - 1 < N))
        		N = rObj - rQ - 1; //N
      		else if ((rObj < rQ) && (rQ - rObj - 1 < S)) 
        		S = rQ - rObj - 1; //S
    	}
    	else if (rQ == rObj) 
    	{
      		if ((cObj > cQ) && (cObj - cQ - 1 < E)) 
        		E = cObj - cQ - 1; //E        
      		else if ((cObj < cQ) && (cQ - cObj - 1 < W)) 
        		W = cQ - cObj - 1; //W
    	}    
    	else if (rObj - rQ == cObj - cQ) 
    	{
      		if ((rObj > rQ) && (rObj - rQ - 1 < NE)) 
        		NE = rObj - rQ - 1; //NE
      		else if ((rQ > rObj) && (rQ - rObj - 1 < SW)) 
        		SW = rQ - rObj - 1; //SW
    	} 
    	else if (abs(rObj - rQ) == abs(cObj - cQ)) 
    	{
      	if ((rObj > rQ) &&(rObj - rQ - 1 < NW)) 
        	NW = rObj - rQ - 1; //NW
      	else if ((rQ > rObj) && (rQ - rObj - 1 < SE)) 
        	SE = rQ - rObj - 1; //SE           
    	}
  	}

  	std::cout << N + S + E + W + NE + SE + NW + SW << "\n";

  	return 0;

}
