#include<bits/stdc++.h>
using namespace std;
void call (vector<string>& ans, string st, int A,int cur){
   
    if(cur==0&&A==0){
        ans.push_back(st);
        return ;
    }
    if(cur==0){
        st+='(';
        call(ans,st,A-1,1);
        return ;
    }
    if(A){
         call(ans,st+'(',A-1,cur+1);
         call(ans,st+')',A,cur-1);
         return ;
    }
 while(cur){
    st= st+')';
    cur--;
 }
 ans.push_back(st);
 return ;
 
}
vector<string> generateParenthesis(int A) {
   
vector<string> ans;
string st;
call(ans, st, A,0);
    return ans;
}
int main()
{
	cout<<"Enter the number: ";
	int n;
	cin>>n;
vector<string> ans=generateParenthesis(n);

for(int i=0;i<ans.size();i++)
	cout<<"valid Parenthesis "<<ans[i]<<endl;
}

