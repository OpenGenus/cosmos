#include<bits/stdc++.h>
using namespace std;
vector<int> grayCode(int A) {
    
            vector<int> result(1, 0);  
            for (int i = 0; i < A; i++) {
                int curSize = result.size();
                // push back all element in result in reverse order
                for (int j = curSize - 1; j >= 0; j--) {
                    result.push_back(result[j] + (1 << i));
                } 
            }
            return result;
}
int main()
{
	cout<<"Enter the array length: ";
	int n;
	cin>>n;
	vector<int> a(n);
	cout<<"Enter the array: ";
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	cout<"Enter the element to find: ";
	int b; cin>>b;
	cout<<"Sequence "<<grayCode(a,b)<<endl;
}

