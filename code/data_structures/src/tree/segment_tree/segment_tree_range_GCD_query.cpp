#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int tree[100005];

int gcd(int a, int b) 
{ 
    if(b == 0)
    { 
        return a; 
    }
    return gcd(b, a % b);   
} 

void build(int *ar, int idx, int start, int end)
{
	if(start == end)
	{
		tree[idx] = ar[start];
	}
	else
	{
		int mid = (start + end) / 2;
		build(ar, 2 * idx, start, mid);
		build(ar, 2 * idx + 1, mid + 1, end);
		tree[idx] = gcd(tree[2*idx], tree[2*idx+1]);
	}
}

int query(int idx, int start, int end, int qs, int qe)
{
	if(qe < start || end < qs)
	{
		return 0;
	}
	
	if(qs <= start && end <= qe)
	{
		return tree[idx];
	}
	
	int mid = (start + end) / 2;
	return gcd(query(2 * idx, start, mid, qs, qe), query(2 * idx + 1, mid + 1, end, qs, qe));
}

void updateRange(int idx, int start, int end, int rs, int re, int val)
{
	if(start > re || end < rs)
	{
		return;
	}
	
	if(start == end)
	{
		tree[idx] += val;
	}
	else
	{
		int mid = (start + end) / 2;
		updateRange(2 * idx, start, mid, rs, re, val);
		updateRange(2 * idx + 1, mid + 1, end, rs, re, val);
		tree[idx] = gcd(tree[2*idx], tree[2*idx+1]);
	}
}

int main()
{
	int ar[6] = {0, -4, 3, -6, 5, 7};
	build(ar, 1, 1, 5);
	cout<<query(1, 1, 5, 1, 5)<<endl;
	updateRange(1, 1, 5, 4, 5, -10);
	cout<<query(1, 1, 5, 1, 5)<<endl;
	return 0;
}


