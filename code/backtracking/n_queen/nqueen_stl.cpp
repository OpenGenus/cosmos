// Part of Cosmos by OpenGenus Foundation
#include<iostream>
#include <vector>
using namespace std;

vector<vector<string> > g_ans;
void nq(int n,int c,vector<string> chess)
{
    //cout<<c<<" ";
    if(c==n)
    {
        g_ans.push_back(chess);
        return;
    }
    for(int i=0;i<n;i++)
    {
        chess[c][i]='.';
        bool check=true;
        for (int k=c-1;k>=0;k--)
        {
            if(chess[k][i]=='Q')
                check=false;
            if(i-k+c<n && chess[k][i-k+c]=='Q')
                check=false;
            if(i+k-c>=0 && chess[k][i+k-c]=='Q')
                check=false;
        }
        if(check)
        {
            chess[c][i]='Q';
            nq(n,c+1,chess);
            chess[c][i]='.';
        }

    }
}
vector<vector<string> > fun(int n)
{

    string s(n,'.');
    vector<string> c(n,s);

    g_ans.clear();
    nq(n,0,c);
    return g_ans;
}


int main()
{

    vector<vector<string> > v = fun(8);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
            cout<<v[i][j]<<endl;
        cout<<endl;
    }
    return 0;
}
