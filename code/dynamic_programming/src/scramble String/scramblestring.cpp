#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
unordered_map<string,bool>mp;
bool solve(string a,string b)
{
   if(a==b)
    return true;
   if(a.length()<=1)
    return false;

   string temp=a;
   temp+=' ';
   temp.append(b);
   if(mp.find(temp)!=mp.end())
    return mp[temp];

   int n=a.length();
   bool flag=false;

   for(int i=1;i<n;i++)
   {
       if( (solve(a.substr(0,i), b.substr(n-i,i)) &&
             solve(a.substr(i,n-i), b.substr(0,n-i)))
          || (solve(a.substr(0,i), b.substr(0,i))
              &&
              solve(a.substr(i,n-i), b.substr(i,n-i))))
       {
           flag=true;
           break;
       }
   }
   return mp[temp]=flag;

}
int isScramble(string a,  string b) {
    if(a.length()!=b.length())
       return 0;
    else if(a.length()==0 && b.length()==0)
        return 1;
        else{
    if(solve(a,b))
        return 1;
    else
        return 0;
    }

}
int main()
{
    mp.clear();
    string a,b;
    cin>>a>>b;
    if(a.length()!=b.length())
        cout<<"no"<<endl;
    else if(a.length()==0 && b.length()==0)
        cout<<"yes"<<endl;
    else{
    if(isScramble(a,b))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    }
    return 0;
}
