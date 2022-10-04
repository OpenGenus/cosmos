#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
bool check_operator_between(stack<char>&st,char ch){
  if(st.top()!=ch)return true;
  return false;
}
bool is_redundant(string &s){
stack<char>st;
for (int i = 0; i < s.length(); i++)
{
   char ch=s[i];
   if(ch=='['||ch=='('||ch=='{'|| ch=='+'||ch=='-'||ch=='*'||ch=='/'){

    // for opening brackets
   st.push(ch);
   }

   else{
    // for closing brackets
    if(ch==']'||ch=='}'||ch==')'){
      if(check_operator_between(st,ch))
      return false;
      
    }
  st.pop();
   }
   return false;
}




}

int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);

string str;
cin>>str;
str.pop_back();
// if(is_redundant(str)){
//     cout<<"true";
// }
// else
// return false;

return 0;
}
