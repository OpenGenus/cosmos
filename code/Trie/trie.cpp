#include <bits/stdc++.h>
using namespace std;
#define fio			std::ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll 			long long
#define vi			vector<int>
#define vvi			vector< vi >
#define vll 		vector< long long >
#define vvll 		vector< vll >
#define vd 			vector< double >
#define vs			vector< string > 
#define ford(i,x,a) for(int i=x;i<a;++i)
#define fore(i,x,a) for(int i=x;i>=a;--i)
#define pii 		pair<int,int>
#define pll 		pair<ll,ll>
#define ff 			first
#define ss 			second
#define all(a) 		a.begin(), a.end()
#define pb 			push_back 
#define gi(n) 		scanf("%d",&n)
#define gll(n) 		scanf("%lld",&n)
#define gstr(n) 	scanf("%s",n)
const ll mod = 1e9+7;
const ll N = 1e5;
const ll MAX = 1e18;
// A trie node which uses unordered_map and boolean variable to mark end of word
typedef struct node{
	bool isleaf;
	unordered_map<char,node*> mp;
}node;
node *newnode()
{
	node *fresh=new node;
	fresh->isleaf=false;
	return fresh;
}
node *root=newnode();
void insert(string s)
{
	node *temp=root;
	for(int i=0;i<s.length();i++)
	{
		if(temp->mp.find(s[i])==temp->mp.end())
		{
			temp->mp[s[i]]=newnode();
		}
		temp=temp->mp[s[i]];
	}
	temp->isleaf=true;
}
bool isThere(string str)
{
	node *temp=root;
	for(int i=0;i<str.length();i++)
	{
		if(temp->mp.find(str[i])==temp->mp.end())
			return false;
		temp=temp->mp[str[i]];
	}
	return temp->isleaf;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	int num,query,num_query;
	cout<<"Enter number of string to add\n";
	cin>>num;
	string s;
	for(int i=0;i<num;i++)
	{
		cout<<"Enter string\n";
		cin>>s;
		insert(s);
	}
	cout<<"Enter number of query string\n";
	cin>>query;
	for(int i=0;i<query;i++)
	{
		string q;
		cin>>q;
		if(isThere(q))
			cout<<"Exists\n";
		else
			cout<<"Does Not Exists\n";
	}
	return 0;
}