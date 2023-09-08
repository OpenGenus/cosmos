#include <stdio.h>
const int N=1005; 			// maximum vertex
int n,m;					// vertex 0~n, m edges
int u,v,c;
const int INF=1000000009;	// infinite length
int dist[N],flag[N];
int mp[N][N];
int i,j,sml,sml_i;
void dijkstra ( int start ) {
	for ( i=0; i<N; i++ ) dist[i]=INF, flag[i]=0;
	dist[start]=0;			//start from "start"
	for ( i=0; i<n-1; i++ ) {
		sml=INF;
		for ( j=0; j<n; j++ ) 
			if ( flag[j]==0 && dist[j]<sml ) 
				sml=dist[j],sml_i=j;
		flag[sml_i]=1;
		for ( j=0; j<n; j++ ) {
			if ( !flag[j] && mp[sml_i][j] && dist[sml_i]!=INF && dist[sml_i]+mp[sml_i][j]<dist[j] )
				dist[j]=dist[sml_i]+mp[sml_i][j];
		}
	}
	for ( i=0; i<n; i++ ) printf("%d%c",dist[i],i==n-1?'\n':' ');
}
void input () {
	scanf("%d%d",&n,&m);
	for ( i=0; i<m; i++ ) {
		scanf("%d%d%d",&u,&v,&c);
		// assume its undirected graph
		mp[u][v]=c;
		mp[v][u]=c;
	}
}
int main () 
{
	return 0;
}
