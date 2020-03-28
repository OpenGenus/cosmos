#include <stdio.h> 
#include <string.h> 
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n1, i,n ;
	cout<<"\nEnter the number of element";
	cin>>n1;
	n=n1;//to store the number of elements
	int a[n];
	cout<<"\nEnter the element";
	for(i = 0; i < n; i++)
		{
			cin>>a[i];
		}
 	
	int  j, k,temp;
	
	for(i = 0; i < n; i++)
		{
		
			// iterate through every element from left to right 
			for(j = i+1; j < n; j++)
			{          
       
				// Move the bigger element to the right most position as in bubble sort
				if(a[j] < a[j-1])
					{    
				                temp=a[j];
						a[j]=a[j-1];
						a[j-1]=temp;
					}
			}
		n--;
		
    
		// moving the smaller elements to left part of the array which is modification over bubble sort
		for(k = n-1; k > i; k--)
			{
				if(a[k] < a[k-1])
					{
					
						temp=a[k];
						a[k]=a[k-1];
						a[k-1]=temp;
					}
			}
		i++;
	}
 
	
	cout<<"\nSorted Data ";
	for (i = 0; i < n1; i++)
	cout<<" "<<a[i];
 
	return 0;
}
