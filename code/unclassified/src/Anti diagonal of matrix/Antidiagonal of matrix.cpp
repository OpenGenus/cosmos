#include<bits/stdc++.h>
using namespace std;

//C++ program to print anti diagonals in a N*N square matrix
int main()
{
	int n;
	cin>>n;								//input size of square atrix
	int a[n][n];
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	cin>>a[i][j];
	// Anti Diagonals starting from first row 
		for(int c=0;c<n;c++)				
	{
		int r=0,col=c;
		while(r<=c && col>=0)
			{
				cout<<a[r][col] <<" ";
				r++;
				col--;
			}
			cout<<endl;
	}
	//Anti Diagonals starting from last column 
	for(int c=1;c<n;c++)
	{
		int r=c,col=n-1;
		while(r<n && col>=c)
			{
				cout<<a[r][col]<<" ";
				r++;
				col--;
			}
			cout<<endl;
	}	
}
