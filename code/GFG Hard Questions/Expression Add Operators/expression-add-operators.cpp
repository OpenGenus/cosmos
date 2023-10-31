//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int isoperand(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/')
    {
        return 0;
    }
    else{
        return 1;
    }
}
int precedent(char x)
{
    if(x=='+'||x=='-')
    {
        return 1;
    }
    else if(x=='*'||x=='/')
    {
        return 2;
    }
    return 0;
}
string convert(string infix)
{
    stack<char> st;
    string postfix=infix;
    // cout<<infix<<endl;
    // cout<<infix<<endl;
    // cout<<postfix<<endl;
    int i=0,j=0;
    // cout<<postfix<<endl;
    while(i<infix.size())
    {
    // cout<<postfix<<endl;
        if(isoperand(infix[i]))
        {
            postfix[j++]=infix[i++];
            // cout<<postfix<<endl;
        }
        else
        {
            if(st.empty()||precedent(infix[i])>precedent(st.top()))
            {
                // push(st,infix[i++]);
                st.push(infix[i]);
                i++;
            }
            else
            {
                postfix[j++]=st.top();
                st.pop();
            }
        }
    }
    // cout<<postfix<<endl;
    while(!st.empty())
    {
        postfix[j++]=st.top();
        st.pop();
        
    }
    // cout<<postfix<<endl;
    // postfix[j]='\0';
    return postfix;
}
int eval(string postfix,vector<int> &v)
{
    stack<int> st;
    int i,x1,x2,r;
    for(i=0;i<postfix.size();i++)
    {
        if(isoperand(postfix[i]))
        {
        // push(st,postfix[i]-'0');
        // cout<<v[postfix[i]-'a']<<endl;
        st.push(v[postfix[i]-'a']);
        }
        else
        {
            // x2=pop(st);
            x2=st.top();
            st.pop();
            // cout<<x2<<endl;

            x1=st.top();
            st.pop();
            // cout<<x1<<endl;
            switch (postfix[i])
            {
            case '+':
                    r=x1+x2;
                    st.push(r);
                    // push(st,r);

                break;
            case '-':
                    r=x1-x2;
                   st.push(r);
                break;
            case '*':
                    r=x1*x2;
                    st.push(r);
                break;
            case '/':
                    r=x1/x2;
                   st.push(r);
                break;
            }
        }
    }
    int kk=st.top();
    st.pop();
    return kk;
}
    void help(vector<string> &ans,string &s,int &target,int i,int sum,string temp){
        if(i==s.size()){
            // if(sum==target){
                ans.push_back(temp);
            // }
            return;
        }
        int x=sum*(s[i]-48);
        help(ans,s,target,i+1,x,temp+s[i]);
        
        help(ans,s,target,i+1,x,temp+'*'+s[i]);
        x=sum+(s[i]-48);
        help(ans,s,target,i+1,x,temp+'+'+s[i]);
        x=sum-(s[i]-48);
        help(ans,s,target,i+1,x,temp+'-'+s[i]);
    }
    vector<string> addOperators(string sp, int target) {
        vector<string> ans,fans;
        string check=to_string(target);
        if(check==sp ){
            return {sp};
        }
      
        int sum=sp[0]-48;
        string temp;
        temp.push_back(sp[0]);
        help(ans,sp,target,1,sum,temp);
        for(int i=0;i<ans.size();i++){
            vector<int> v(26,0);
            int num=0;
            int k=0;
            string s;
            string nn;
            int fff=0;
            for(int j=0;j<ans[i].size();j++){
                if(isoperand(ans[i][j])==0){
                    if(nn.size()>=2){
                        if(nn[0]=='0'){
                            
                            fff=1;
                            break;
                        }
                    }
                    nn="";
                    s.push_back(char('a'+k));
                    v[k]=num;
                    k++;
                    // s.push_back(num+'0');
                    num=0;
                    s.push_back(ans[i][j]);
                }
                else{
                    nn.push_back(ans[i][j]);
                    num=(num*10)+(ans[i][j]-'0');
                }
            }
             if(nn.size()>=2){
                        if(nn[0]=='0'){
                            
                            fff=1;
                            // break;
                        }
                    }
            if(fff==1){
                continue;
            }
            s.push_back(char('a'+k));
            v[k]=num;
            string t=convert(s);
            // cout<<t<<endl;
            // cout<<v[0]<<endl;
            if(eval(t,v)==target){
                // int f=0;
                // for(int kk=0;kk<ans[i].size();kk++){
                //     // if(isoperand(ans[i][kk])==0){
                //         if(ans[i][kk]=='0'&&(kk<ans[i].size()-1&&isoperand(ans[i][kk+1]))){
                //             f=1;
                //             break;
                //         }
                //     }
                
                // if(f==0)
                fans.push_back(ans[i]);
            }
            
        }
        return fans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends