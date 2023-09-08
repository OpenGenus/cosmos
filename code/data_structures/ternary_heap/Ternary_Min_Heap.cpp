
/*--------------CONCEPTS-------------------*/

/*----FOR K MINIMU ELEMENTS----*/

	/*----FOR K SMALLESET ELEMENTS WE WILL USE ANOTHER ARRAY AND WILL INSERT 'Z' ELEMENTS ONE BY ONE INTO IT 
	      ( Z IS THE POWER OF 3 WHICH IS JUST GREATER THAN K) SO THAT MIN HEAP PROPERTY IS MAINTAINED ----*/

	     /*--FOR Z INSERTIONS O(ZlogZ) TIME IS REQIURED--*/
	
	/*----NEXT WE WILL EXTRACT K ELEMENTS ONE BY ONE FROM THIS NEWLY CREATED HEAP----*/
	
		/*--FOR K EXTRACTIONS O(Klogz) TIME IS REQUIRED--*/

	/*----OVERALL COMPLEXITY IS O(KlogN)----*/

/*----FOR PRINTING ELEMENTS WHICH ARE SMALLER THAN a FROM HEAP----*/

	/*----FOR THIS WE WILL DEFINE A RECURSIVE FUNCTION WHICH WILL KEEP TRAVERSING ONE PATH TILL IT FINDS A NUMBER
		WHICH IS GREATER THAN a----*/

#include <bits/stdc++.h>

using namespace std;

//FUNCTION RETURNS MINIMUM OF THREE ELEMENTS
int min3(int a, int b, int c)
{
	int min;
	if(a<b)min = a;
	else min = b;
	if(c<min)min = c;
	return min;
}

//FUNCTION RETURNS MINIMUM OF FOUR ELEMENTS
int min4(int a,int b, int c, int d)
{
	int mi = min3(a,b,c);
	if(d<mi)mi = d;
	return mi;
}

//COMPARE TWO ELEMENTS
int min2(int a, int b)
{
	if(a<b)return a;
	else return b;
}

//FUNCTION TO SWAP TWO INTEGERS
void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//RETURNS PARENT INDEX 
int parent(int i)
{
	return i/3;
}

//RETURNS LEFTCHILD INDEX
int leftchild(int i)
{
	return 3*i+1;
}

//RETURNS MIDDLECHILD INDEX
int middlechild(int i)
{
	return 3*i+2;
}

//RETURNS RIGHTCHILD INDEX
int rightchild(int i)
{
	return 3*i+3;
}

//FUNCTION TO MAKE AN ARRAY A MIN HEAP
void minheapify(int *a, int i, int n)
{
	int l = leftchild(i);
	int m = middlechild(i);
	int r = rightchild(i);
	int min = a[i];
	int k,index;
	int dummy = 99999;

	if( l >= n && m >= n && r >= n)min = min4(a[i],dummy,dummy,dummy);

	else if( l < n && m >= n && r >= n)min = min4(a[i],a[l],dummy,dummy);

	else if( l < n && m < n && r >= n)min = min4(a[i],a[l],a[m],dummy);

	else if( l < n && m < n && r < n)min = min4(a[i],a[l],a[m],a[r]);

	if(min == a[i])index = i;

	else if(l<n && min == a[l])
	{
		index = l;
		swap(&a[l], &a[i]);
		minheapify(a, l, n);
	}

	else if(m<n && min == a[m])
	{
		index = m;
		swap(&a[m], &a[i]);
		minheapify(a, m, n);
	}

	else if(r<n && min == a[r])
	{
		index = r;
		swap(&a[r], &a[i]);
		minheapify(a, r, n);
	}

}

//FUNCTION TO CALL MIN HEAPIFY FOR MAKING WHOLE ARRAY MIN-HEAP
void buildheap(int *a, int n)
{
	int i;
	for(i=n/3-1 ; i >= 0; i--)
	{
		minheapify(a,i,n);
	}
}

//FUNCTION TO INSERT AN ELEMENT INTO A MIN-HEAP
void insert(int *a, int x, int n)
{
	int i;
	a[n] = x;
	i = n;
	while(i != 0 && a[parent(i)] > a[i])
	{
		swap(&a[i], &a[parent(i)]);
		i = parent(i);
	}	
}

//FUNCTION TO DELETE AN ELEMENT FROM THE MIN HEAP
int deletemin(int *a, int n)
{
	int i,min = a[0];
	a[0] = a[n-1];
	buildheap(a,n-1);
	return min;
}

//FUNCTION TO PRINT ELEMENTS LESS THAN X 
void printless(int *a, int i,int x, int n)
{
	if(i < n && a[i] <= x)
	{
		cout<<a[i]<<" ";
		int l = leftchild(i);
		int m = middlechild(i);
		int r = rightchild(i);
		printless(a,l,x,n);
		printless(a,m,x,n);
		printless(a,r,x,n);
	}
}

int main()
{
	//MAIN HEAP ARRAY
	int num[100];

	//AUXILLIARY ARRAY 
	int aux[100];


	int heapsize = 0;
	int i,n,x;
	cout<<"ENTER NUMBER OF ELEMENTS IN THE HEAP:"<<endl;
	cin>>n;
	cout<<endl<<"NOW PLEASE ENTER "<<n<<" ELEMENTS: "<<endl;
	for(i=0;i<n;i++)
	{
		cin>>num[i];
		heapsize++;
	}
	buildheap(num,heapsize);

	cout<<endl<<endl<<"MAIN HEAP:"<<endl<<endl;
	for(i=0;i<heapsize;i++)
	{
		cout<<num[i]<<" ";
	}
	cout<<endl;

	int v=1,max,hsize=0,c=0,k;
	cout<<endl<<"ENTER THE NUMBER OF MINIMUM ELEMENTS WANTED:"<<endl;
	cin>>k;
	cout<<endl<<"ENTER THE NUMBER LESS THAN WHICH OUTPUT IS DESIRED:"<<endl;
	cin>>max;
	while(v <= k)
	{
		v *= 3;
	}
	for(i=0;i<v;i++)
	{
		if(i<n)
		{
			insert(aux,num[i],hsize);
			hsize++;
		}
	}
	
	cout<<endl<<k<<" MINIMUM ELEMENTS: "<<endl<<endl;
	for(i=0;i<k;i++)
	{
		if(i<hsize)
		{
			cout<<deletemin(aux,hsize)<<" ";
			hsize--;
		}
	}
	cout<<endl;

	cout<<endl<<"MAIN HEAP:"<<endl<<endl;
	for(i=0;i<heapsize;i++)
	{
		cout<<num[i]<<" ";
	}
	cout<<endl;

	cout<<endl<<"ELEMENTS IN HEAP LESS THAN OR EQUAL TO "<<max<<" :"<<endl<<endl;

	printless(num,0,max,n);
	cout<<endl;

	cout<<endl<<"MAIN HEAP:"<<endl<<endl;
	for(i=0;i<heapsize;i++)
	{
		cout<<num[i]<<" ";
	}
	cout<<endl;

	return 0;
}