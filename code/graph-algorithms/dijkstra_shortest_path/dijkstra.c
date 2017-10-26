#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
const int N=1005; 			// maximum vertex
int n;						// vertex 0~n
const int INF=1000000009; 	// infinite length

void dijkstra ( int mp[N][N], int start ) {
	int dist[N];
	bool flag[N];
	for ( int i=0; i<N; i++ ) dist[i]=INF, flag[i]=0;
	dis[start]=0;			//start from "start"
	for ( int i=0; i<n-1; i++ ) {
		int sml=INF,sml_i;
		for ( int j=0; j<n; j++ ) 
			if ( flag[j]==0 && dist[j]<sml ) 
				sml=dist[j],sml_i=j;
		flag[sml_i]=1;
		for ( int j=0; j<n; j++ ) {
			if ( !flag[j] && mp[sml_i][j] && dist[sml_i]!=INF && dist[sml_i]+mp[sml_i][j]<dist[j] )
				dist[j]=dist[sml_i]+mp[sml_i][j];
		}
	}
	for ( int i=0; i<n; i++ ) printf("%d%c",dist[i],i==n-1?'\n':' ');
}
