// Code for problem PALPROB on CodeChef, example usage of Palindromic Tree
#include <bits/stdc++.h>
using namespace std;
 
#define sd(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
#define sl(a) scanf("%lld",&a)
#define clr(a) memset(a,0,sizeof(a))
#define debug(a) printf("check%d\n",a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long

struct node
{
	int en,l;//ending pos in s[] of first occurence of palindrome
	vector<int> rev;//list of reverse suffix links
	int cnt;//number of times this palindrome has occured
	int suff;//suff. link
	int f[30];//list of outlinks
	node(int e,int len,int sl)
	{
		cnt=1;
		en=e;
		l=len;
		suff=sl;
		rev.clear();
		for(int i=0;i<26;++i)
			f[i]=0;
	}
	node()
	{
		cnt=1;
		en=0;
		l=0;
		suff=0;
		rev.clear();
		for(int i=0;i<26;++i)
			f[i]=0;
	}
};
vector<node> tree;
char s[100010];
int first[30];
int p[100010];
void buildtree()
{
	tree.clear();
	tree.PB(node(0,-1,0));
	tree.PB(node(0,0,0));
	tree[0].rev.PB(1);
	int cur,next=0;//id of largest palindrome ending at pos, and next value of cur
	int pos=-1;//pos of last character added into pal. tree
	int l=strlen(s);
	for(pos=-1;pos<l-1;++pos)
	{
		cur=next;
		while(!(pos-tree[cur].l>=0&&s[pos+1]==s[pos-tree[cur].l]))
		{
			cur=tree[cur].suff;
		}
		if(tree[cur].f[s[pos+1]-'a']==0)
		{
			next=tree.size();
			tree.PB(node(pos+1,tree[cur].l+2,-1));
			tree[cur].f[s[pos+1]-'a']=next;
			tree[next].en=pos+1;
			cur=tree[cur].suff;
			while(!(pos-tree[cur].l>=0&&s[pos+1]==s[pos-tree[cur].l]))
			{
				cur=tree[cur].suff;
			}
			cur=tree[cur].f[s[pos+1]-'a'];
			if(cur==next)
			{
				tree[next].suff=1;
				tree[1].rev.PB(next);
			}
			else	
			{
				tree[next].suff=cur;
				tree[cur].rev.PB(next);
			}
		}
		else
		{
			next=tree[cur].f[s[pos+1]-'a'];
			tree[next].cnt++;
		}
	}
}
int go(int cur)//calculates count
{
	int i;
	for(i=0;i<tree[cur].rev.size();++i)
	{
		tree[cur].cnt=tree[cur].cnt+go(tree[cur].rev[i]);
	}
	return tree[cur].cnt;
}
int ans;
void calc(int cur)//calculates answer for problem
{
	int i;
	if(tree[cur].l==1)
	{
		p[tree[cur].l]=1;
		ans=ans+tree[cur].cnt;
	}
	else if(tree[cur].l>1)
	{
		p[tree[cur].l]=1+p[(tree[cur].l)/2];
		ans=ans+(1+p[(tree[cur].l)/2])*tree[cur].cnt;
	}
	for(i=0;i<tree[cur].rev.size();++i)
	{
		calc(tree[cur].rev[i]);
	}
	p[tree[cur].l]=0;
}
int main()
{
	int t,i;
	sd(t);
	while(t--)
	{
		ans=0;
		scanf("%s",s);
		buildtree();
		go(0);
		int l=strlen(s);
		for(i=0;i<l;++i)
			p[i]=0;
		calc(0);
		printf("%d\n",ans);
	}
}
