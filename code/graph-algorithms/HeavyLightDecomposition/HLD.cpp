#include <iostream>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <vector>
#include <cstring>
using namespace std;
#define pb push_back
class seg_tree
{
	vector<int> tree;
	int n;
	inline int get_size(int R)
	{
		R--;
		int Z=1;
		while(R)
		{
			Z<<=1;
			R>>=1;
		}
		return Z*2;
	}
/* 1 2  2 4  3 8  4 8  5 16  6 16  7 16  8 16 */
public:
	void construct(vector<int> &v)
	{
		tree.resize(get_size(v.size()));
		n=v.size()-1;
		make_tree(v,0,v.size()-1,1);
	}
	void make_tree(vector<int> &v,int L,int R,int curr)
	{
		if(L==R)
		{
			tree[curr]=v[L];
			return ;
		}
		int mid=(L+R)/2;
		make_tree(v,L,mid,2*curr);
		make_tree(v,mid+1,R,2*curr+1);
		tree[curr]=max(tree[2*curr],tree[2*curr+1]);
		return ;
	}
	int find_max(int l,int r)
	{
		return find_max2(l,r,0,n,1);
	}
	int find_max2(int l,int r,int L,int R,int curr)
	{
		if(r<L || l>R)
			return -1e9;
		if(L>=l && R<=r)
			return tree[curr];
		return max(find_max2(l,r,L,(L+R)/2,2*curr),find_max2(l,r,(L+R)/2+1,R,2*curr+1));
	}
	void update(int pos,int val)
	{
		update2(pos,val,1,0,n);
	}
	void update2(int pos,int val,int curr,int L,int R)
	{
		if(L==R)
		{
			tree[curr]=val;
			return;
		}
		int mid=(L+R)/2;
		if(pos>=L && pos<=mid)
			update2(pos,val,2*curr,L,mid);
		else
			update2(pos,val,2*curr+1,mid+1,R);
		tree[curr]=max(tree[2*curr],tree[2*curr+1]);
	}
};
class HLD
{
	int N;
	vector<seg_tree> S;
	vector<vector<int> > adj,W,LCA,chains;
	vector<int> sub_size,ch_no,head,chain_pos,Parent,level;
	vector<bool> can_visit;
	vector<int> W2;
	vector<pair<int,int>> edges;
	int chain;
	void decompose(int curr)
	{
		int to_visit=-1,val=-1,ind=-1,IN2=-1;
		for(auto &x:adj[curr])
		{
			++IN2;
			if(can_visit[x] && sub_size[x]>val)
			{
				val=sub_size[x];
				to_visit=x;
				ind=IN2;
			}
		}
		if(to_visit!=-1)
		{
			can_visit[to_visit]=false;
			chain_pos[to_visit]=chains[chain].size();
			chains[chain].push_back(W[curr][ind]);
			ch_no[to_visit]=chain;
			decompose(to_visit);
			int u=-1;
			for(auto &x:adj[curr])
			{
				++u;
				if(can_visit[x])
				{
					can_visit[x]=false;
					++chain;
					chain_pos[x]=0;
					chains.push_back(vector<int>(0));
					chains[chain].push_back(W[curr][u]);
					head.pb(x);
					ch_no[x]=chain;
					decompose(x);
				}
			}
		}
	}
	void update(int node,int val)
	{
		int p,q,v,u;
		p=edges[node].first,q=edges[node].second;
		if(Parent[p]==q)
			u=q,v=p;
		else
			u=p,v=q;
		int index=ch_no[v],in_seg_pos=chain_pos[v];
		S[index].update(in_seg_pos,val);
	}
	int query(int a,int b)
	{
		int d=find_lca(a,b);
		int cn=ch_no[d],idx=chain_pos[d];
		int ans=-1e9;
		while(cn!=ch_no[a])
		{
			ans=max(ans,S[ch_no[a]].find_max(0,chain_pos[a]));
			a=Parent[head[ch_no[a]]];
		}
		while(cn!=ch_no[b])
		{
			ans=max(ans,S[ch_no[b]].find_max(0,chain_pos[b]));
			b=Parent[head[ch_no[b]]];
		}
		ans=max(S[cn].find_max(idx+1,max(chain_pos[a],chain_pos[b])),ans);
		return ans;
	}
	int dfs1(int x,int r=0);
	int find_lca(int v,int u)
	{
		int p,q;
		if(level[u]>level[v])
			p=u,q=v;
		else
			p=v,q=u;
		int Z=level[p]-level[q];
		while(Z)
		{
			int d=__builtin_ctz(Z);
			p=LCA[p][d];
			Z^=Z&~(Z-1);
		}
		
		int y= find_lca2(p,q,LCA[p].size()-1);
		return y;
	}
	int find_lca2(int u,int v,int L)
	{
		if(u==v)
			return u;
		for(int i=L;i>=0;i--)
		{
			if(LCA[u].size()>i&&(LCA[u][i]!=LCA[v][i]))
				u=LCA[u][i],v=LCA[v][i];
		}
		return Parent[u];
	}
public:
	HLD(int n):N(n),adj(n),W(n),LCA(n),sub_size(n),can_visit(n,true),chain(0),Parent(n),level(n),ch_no(n),chain_pos(n),edges(n-1)
	{
		for(int i=0;i<N-1;i++)
		{
			int x,y,w;
			scanf("%d%d%d",&x,&y,&w);
			--x,--y;
			while(w<0);
			edges[i].first=x,edges[i].second=y;
			adj[x].pb(y),
			adj[y].pb(x),
			W[x].pb(w),W[y].pb(w);
		}
		can_visit[0]=false;
		dfs1(0);
		can_visit.clear();
		can_visit.resize(n,true);
		ch_no[0]=0;
		can_visit[0]=false;
		chains.push_back(vector<int>(0));
		chains[0].push_back(0);
		head.push_back(0);
		chain_pos[0]=0;
		decompose(0);
		int max_level=0;
		for(int i=0;i<n;i++)
		{
			max_level=max(level[i],max_level);
			LCA[i].push_back(Parent[i]);
		}
		for(int x=1,y=2;y<=max_level;y*=2,++x)
		{
			for(int i=0;i<n;i++)
			{
				if(y<=level[i])
					LCA[i].pb(LCA[LCA[i][x-1]][x-1]);
			}
		}
		/*
		for(int i=0;i<chains.size();i++)
		{
			cout <<i<<endl;
			for(auto &h:chains[i])
				cout << h <<" ";
			cout << endl;
			cout << endl;
		}*/
		S.resize(chains.size());
		for(int i=0;i<chains.size();i++)
			S[i].construct(chains[i]);
		char d[20];
		while(scanf("%s",d))
		{
			if(!strcmp(d,"DONE"))
			break;
			else
			{
				if(d[0]=='C')
				{
					int node,val;
					scanf("%d%d",&node,&val);
					while(val<0);
					--node;
					update(node,val);
				}
				else
				{
					int n1,n2;
					scanf("%d%d",&n1,&n2);
					--n1,--n2;
					while(n1==n2);
					printf("%d\n",query(n1,n2));
				}
			}
		}
	}
};
void solve()
{
	int N;
	scanf("%d",&N);
	new HLD(N);
	return ;
}
int main()
{
	int T=1;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		solve();
	}
	return 0;
}
int HLD::dfs1(int curr,int lvl)
{
	level[curr]=lvl;
	for(int i=0;i<adj[curr].size();i++)
	{
		if(can_visit[adj[curr][i]])
		{
			can_visit[adj[curr][i]]=false;
			Parent[adj[curr][i]]=curr;
			sub_size[curr]+=dfs1(adj[curr][i],lvl+1);
		}
	}
	sub_size[curr]++;
	return sub_size[curr];
}
