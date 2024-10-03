// Part of Cosmos by OpenGenus Foundation
#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int t;
    cout<<"Enter no of test cases";
    cin>>t;
    string s=" ";

    while(t--)
    {
         stack<char> st;
         cout<<"\nEnter the string\n";
         cin>>s;
         int flag=0;
         for(int i=0;i<s.size();i++)
         {
            // cout<<s.size();
             if(s[i]=='(' || s[i]=='{'|| s[i]=='[')
                    st.push(s[i]);
             else if(s[i]==']' || s[i]=='}' || s[i]==')')
             {  if((!st.empty()) && ((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='[')))
                st.pop();
                else
                {
                    //cout<<"NO"<<endl;
                    flag=1;
                    break;
                }
             }
         }
         if(st.empty() && flag==0) cout<<"YES"<<endl;
         else if(!st.empty() || flag==1) cout<<"NO"<<endl;
    }
    return 0;
}
