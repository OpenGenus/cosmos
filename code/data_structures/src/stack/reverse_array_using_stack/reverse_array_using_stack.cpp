#include<bits/stdc++.h>
using namespace std; 
int main(){
  int n; 
  cin>>n; 
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
    }
  stack<int>s;
  for(int i=0;i<n;i++){
    s.push(arr[i]);
    }
  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
    }
  cout<<endl; 
  return 0;
  }
