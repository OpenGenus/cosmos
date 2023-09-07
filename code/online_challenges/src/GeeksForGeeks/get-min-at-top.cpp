
#include <bits/stdc++.h>
using namespace std;
stack<int>_push(int arr[],int n);
void _getMinAtPop(stack<int>s);
//Position this line where user code will be pasted.
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    stack<int>mys=_push(arr,n);
	    _getMinAtPop(mys);
	    cout<<endl;
	}
	return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/* inserts elements of the array into 
   stack and return the stack
*/
stack<int>_push(int arr[],int n)
{
    int top = arr[0];
   stack <int> st;
   st.push(top);
   for(int i=1;i<n;i++)
   {
       if(top > arr[i])
       {
           top=arr[i];
           st.push(top);
       }
       else
       st.push(top);
   }
   return st;
}

void _getMinAtPop(stack<int>s)
{
    while(!s.empty())
    {
    cout<<s.top()<<" ";
    s.pop();
    }
    
}
