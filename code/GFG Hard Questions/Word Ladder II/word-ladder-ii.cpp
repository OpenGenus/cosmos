//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int mini;
    void dfs(vector<vector<string>> &ans,vector<string> &temp,string str, unordered_map<string,int> &m, unordered_map<int,string> &m2,string &target,vector<int> &distance,int count)
    {
       
        if(str==target){
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            reverse(temp.begin(),temp.end());
            return;
        }
        int node=m[str];
        for(int i=0;i<str.size();i++){
                char ch=str[i];
                for(char c='a';c<='z';c++){
                    if(c==ch) continue;
                    str[i]=c;
                    if(m[str]>0&&count==distance[m[str]]){
                        temp.push_back(str);
                        dfs(ans,temp,str,m,m2,target,distance,count-1);
                        temp.pop_back();
                    }
                }
                str[i]=ch;
            }
        return;
    }
    vector<vector<string>> findSequences(string startWord, string targetWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_map<string,int> m;
        unordered_map<int,string> m2;
        int start=1;
        int num=2;
        int end=-1;
        mini=INT_MAX;
        m[startWord]=start;
        m2[start]=startWord;
        for(auto &str: wordList ){
            if(str==startWord)continue;
            m[str]=num;
            m2[num]=str;
            if(str==targetWord) end=num;
            num++;
        }
        if(end==-1) return ans;
        vector<string> temp;
        vector<int> distance(num,INT_MAX);
        queue<int> q;
        q.push(start);
        distance[start]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            string str=m2[node];
            for(int i=0;i<str.size();i++){
                char ch=str[i];
                for(char c='a';c<='z';c++){
                    str[i]=c;
                    if(m[str]>0&&distance[m[str]]>distance[node]+1){
                        distance[m[str]]=distance[node]+1;
                        q.push(m[str]);
                        if(str==targetWord){
                            mini=distance[m[str]];
                            break;
                        }
                    }
                }
                if(mini!=INT_MAX) break;
                str[i]=ch;
            }
            if(mini!=INT_MAX) break;
        }
        int count=distance[m[targetWord]]-1;
        temp.push_back(targetWord);
        dfs(ans,temp,targetWord,m,m2,startWord,distance,count);
        return ans;
    }
};


//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends