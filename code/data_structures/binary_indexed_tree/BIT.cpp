#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 200005;

long long bit[MAXN];/*Array that represents the Data Structure*/
long long v[MAXN];
long long aux[MAXN];
long long n; /*The array size*/

/*Returns the sum of v[0..idx]*/
long  query(int idx)
{
	/*Initialize the result*/
	int sum = 0;
	/*Traverse the ancestors of bit[idx]*/
	while(idx)
	{
		/*Add the current element to sum*/
		sum += bit[idx];
		/*Move the index to parent node in query*/
		idx -= (idx & (-idx));
	}
	return sum;
}

/*This function update the BIT*/
/*The given value is added in the bit[idx] and in all of the ancestors*/
void update(int idx, int val)
{
	/*Traverse all ancestors*/
	while(idx < MAXN)
	{
		/*Add val to the node*/
		bit[idx] += val;
		/*Update the index*/
		idx += (idx & (-idx));
	}
}

long long search(long long x)
{
	int inf = 1;
	int sup = n;
	int mid;
	while(inf <= sup)
	{
		mid = (inf + sup)/2;
		if(x == aux[mid]) 
			return mid;
		if(x < aux[mid]) 
			sup = mid - 1;
		else
			inf = mid + 1;
	}
}
int main()
{	
	long long q;
	cin >> q;
	char blank;
	
	/*Reading a blank space to the input*/
	
	scanf("%c",&blank);
	
	while(q--)
	{
		long long sum = 0;
		cin >> n;
		/*Initializing the structure*/
		for(int i = 1; i <= n; i++)
		{
			bit[i] = 0;
		}
		/*Read the array*/
		/*Create another array to help the sorting*/
		for(int i = 1; i <= n; i++)
		{
			cin >> v[i];
			aux[i] = v[i];
		}
		/*Sort for the Binary Search*/
		sort(aux + 1, aux + n + 1);
		
		for(int i = 1; i <= n; i++)
		{

			long long pos = search(v[i]);
			sum += query(n) - query(pos);
			update(pos, 1);
		}

		cout << sum << endl;

		scanf("%c",&blank);
	}
	return 0;
}
