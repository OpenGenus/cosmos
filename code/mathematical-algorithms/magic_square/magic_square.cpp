#include <iostream>
// Part of Cosmos by OpenGenus Foundation
using namespace std;
	int main()
{
	int n,m;
	cout<<"Input Size of Square"<<endl;
	cin>>n;
	m=n;
	n*=n;
	if(n==2)
	{
		cout<<"Magic Square Can't Be Created"<<endl;
		return 0;
	}	
	cout<<"Sum of each row or column"<<((n*(1+n))/2)/m<<endl;
	if(n%2==0)return 0;
	int magicSquare[n][n];
 	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			magicSquare[i][j]=0;
  	 int i = n/2;
   	 int j = n-1;
   	 for (int num=1; num <= n*n; )
   	 {
        	if (i==-1 && j==n)//3rd condition
        	{
            		j = n-2;
            		i = 0;
       		 }
        	else
        	{
			//1st condition helper if next number 
          		// goes to out of square's right side
            		if (j == n)
                	j = 0;
			      j = 0;
            		//1st condition helper if next number 
            		// is goes to out of square's upper side
            		if (i < 0)
               		i=n-1;
        	}
        	if (magicSquare[i][j]) //2nd condition
        	{
            		j -= 2;
            		i++;
            		continue;
       		}
        	else
            	magicSquare[i][j] = num++; //set number
 
        	j++; i--; //1st condition
    	}
	for(i=0; i<n; i++)
    	{
        for(j=0; j<n; j++)
        cout<<magicSquare[i][j]<<' ';
        cout<<endl;
	}	
}
