// delete middle element form stack
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
void delete_middle_element(stack<int>&s,int ct,int size){
    if(ct==size/2){
        s.pop();
        return; 
    }
    int x=s.top();
    s.pop();
    ct++;
    delete_middle_element(s,ct,size);
    s.push(x);

}
void delete_last_element(stack<int>&s,int ct,int n){
    // condition for the last element
    if(ct==n){
        s.pop();
        return;
    }
    int x=s.top();
    ct++;
    delete_last_element(s,ct,n);
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
fi(0,n){
    int x;
    cin>>x;
    s.push(x);
}
// delete middle
int size=s.size();
int ct=1;
 print_stack(s,ct);

return 0;
}
