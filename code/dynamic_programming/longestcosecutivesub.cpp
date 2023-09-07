#include <bits/stdc++.h>
using namespace std;
int findLongestConseqSubseq(int [], int );
int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int a[n];
		
		// input array elements
		for(int i=0;i<n;i++)
		    cin>>a[i];
		
		cout<< findLongestConseqSubseq(a, n)<<endl;
		
	}
	return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/

// function to find longest consecutive subsequence
// n : size of array
// arr[] : input array
int findLongestConseqSubseq(int arr[], int n)
{
//Your code here
    if(n==1)
    return 1;
    int count = 1, total = INT_MIN;
    std::sort(arr, arr+n);
    for(int i=0;i<n-1;i++)
    { 
        if(arr[i]== arr[i+1])
            continue;
        else if(arr[i]+1 == arr[i+1])
                count++;
            else 
                count=1; 
            if(count >= total)
                total = count;
    }
    return total;
}
