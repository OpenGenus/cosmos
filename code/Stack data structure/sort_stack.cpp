#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
// the escence of this function is that whenever we got the element lesser than given element we will insert it that will be our base case

void insert_in_sorted_way(stack<int>&s,int new_element){
 
    if(s.empty() ||(!s.empty() && s.top()<new_element)){
        s.push(new_element);
        return;
    }
    int element_already_present=s.top();
    s.pop();
        insert_in_sorted_way(s,new_element);
        s.push(element_already_present);

}
void sort_stack(stack<int>&s){
     // we cannot use loop to sort
if(s.empty())return;
int x=s.top();
s.pop();
sort_stack(s);
insert_in_sorted_way(s,x);

}
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  stack<int>s;
  int n;
  cin>>n;
  for (int q = 0; q < n; q++)
  {
    int x;
    cin>>x;
    s.push(x);
  }
  cout<<s.top();
  sort_stack(s);
  cout<<endl;
  cout<<s.top();
return 0;
}
