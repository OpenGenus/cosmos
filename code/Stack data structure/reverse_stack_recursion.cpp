#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
list<int>l;
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
// void push_element_at_bottom(stack<int>&s,int x){
//     if(s.empty())
//     {s.push(x);
//         return;}
// int y=s.top();
// s.pop();
// push_element_at_bottom(s,x);
// s.push(x);
// }


void reverse_using_recursion(stack<int>&s){
if(s.empty()){
    return;
}
int x=s.top();
s.pop();
reverse_using_recursion(s);
push_element_end(s,x);

}


void print(stack<int>s,int ct){
    if(ct==s.size()){
        cout<<s.top()<<" ";
        return;
    }
    int x=s.top();
    cout<<x<<" ";
    s.pop();
    print(s,ct++);
    s.push(x);
}
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
stack<int>s;
fi(0,5){
int x;
cin>>x;
s.push(x);
}

reverse_using_recursion(s);

print(s,1);
return 0;
}
