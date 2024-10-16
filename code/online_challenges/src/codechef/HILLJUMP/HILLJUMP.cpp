#include<iostream>

using namespace std;

void jump(int[], int);
void inc(int[], int);

int main()
{
	std::ios::sync_with_stdio(false);
	//int j;for(j=0;j<100;j++)printf("1 ");
	int n, q;	cin>>n>>q;
	int arr[n]; arr[0]=0;
	int i; for(i=0;i<n;i++)
	{ 
		int temp; cin>>temp; arr[i]+=temp; arr[i+1]=-temp;
	}

	while(q--)
	{
		int a;
		cin>>a;
		if(a==1) jump(arr, n);
		else inc(arr, n);
	}
return 0;
}

 
void jump(int arr[], int n)
{
int start, num, curr;
cin>>start>>num;
curr = start-1;
int i; int sum=0;

int f=1;
while(num-- && f==1)
{
	int i; f=0; int sum=0;
	for(i = curr+1; i<(n<curr+101?n:curr+101); i++)
	{
	sum+=arr[i];
	if(sum>0){curr = i;f=1;break;} 
	}	
}
cout<<curr+1<<endl;
}
 
void inc(int arr[], int n)
{
int start, end, lol;
cin>>start>>end>>lol;
arr[start-1]+=lol; if(end<n)arr[end]-=lol;
} 
