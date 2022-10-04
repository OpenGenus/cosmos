#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
void push_element_end(stack<int>&s,int element){
// base case for the last element
if(s.size()==1){
    int x=s.top();
    s.pop();
    s.push(element);
    s.push(x);
    return;
}
int x=s.top();
s.pop();
push_element_end(s,element);
s.push(x);

}



void print_stack(stack<int>&s,int ct){
    if(ct==s.size()){
    cout<<s.top()<<" ";
     return;
    }

int x=s.top();
cout<<s.top()<<" ";  
s.pop();
print_stack(s,ct++);
s.push(x);
}

int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
stack<int>s;
int n;
cin>>n;
for (int i = 0; i < n; i++)
{
    int x;
    cin>>x;
    s.push(x);
}

int element;
cin>>element;
push_element_end(s,element);
print_stack(s,1); 
return 0;
}
