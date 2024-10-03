#include<bits/stdc++.h>
using namespace std;
int l=0;
void ans(int input[],int startindex,int size,int index,int output[],int osize,int k)
{
if(startindex==size)
	{
		int sum=0;
	 for(int i=0;i<index;i++)
	{
	  
	 sum+= output[i];
    
	}
	if(sum==k)
	{
	for(int i=0;i<index;i++)
	{
	  
//	cout<<output[i]<<" ";
    
	}
	cout<<endl;	
	}
	 l++;
	 return;
	}
	
	ans(input,startindex+1,size,index,output,osize,k);
	cout<<startindex<<endl;
	output[index++]=input[startindex];
	
	ans(input,startindex+1,size,index,output,osize+1,k);
}
int main()
{
	int input[]={5 ,12, 3, 17, 1, 18, 15, 3, 17 };
	int n=9;
	int output[1000];
	int index=0;
	ans(input,0,n,index,output,0,6);
//	cout<<l;
	
}
