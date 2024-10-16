#include <bits/stdc++.h>
using namespace std;
int main()
{
        int n; // no. of elements in array
        int k; // new GCD
        cout << "Enter number of elements in array: ";
        cin >> n;
        cout << "\nEnter the array: ";
        int arr[n]; // array
        for(int i = 0 ; i < n ; i++)
        	cin >> arr[i];
        cout << "\nEnter value of k: ";    
		cin >> k;
        if(k == 0)
        {
            cout << "\nInvalid value for gcd";
            return 0;
        }
        sort(arr, arr + n);
        int min_operation = 0;
        for(int i = 1 ; i < n ; i++)
        	min_operation += min(arr[i] % k, k - (arr[i] % k)); 
			//shift towards closest multiple
        if(arr[0] > k)
            min_operation += arr[0] - k;
        else
            min_operation += k - arr[0];
        cout << "\nMinimum Number of Operations: " << min_operation;
        return 0;
}
