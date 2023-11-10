#include <iostream>

using namespace std;

int tt,n,m,old,it,i,j,k,x[222],y[222],u[222];
bool g[222][222],q;
char r[222];

int main() 
{
  scanf("%d",&tt);
  while (tt--) 
  {
    scanf("%d%d",&n,&m);
    memset(u,0,sizeof(u));
    memset(g,0,sizeof(g));
    memset(r,0,sizeof(r));
    for (i=0; i<m; i++) 
    {
      scanf("%d%d",&x[i],&y[i]);
      g[x[i]][y[i]]=true;
      g[y[i]][x[i]]=true;
    }
    for (it=1; it<=n; )
    {
      old=it;
      for (i=1; i<=n; i++) if (u[i]==0) 
      {
        q=true;
        for (j=1; j<=n && q; j++) if (g[i][j]) for (k=1; k<j; k++) if (g[i][k]) 
        {
          if (!g[j][k]) { q=false; break; 
        }
      }
        if (q)
        {
          u[i]=it++;
          for (j=1; j<=n; j++) if (g[i][j]) g[i][j]=g[j][i]=0;
          break;
        }
      }
      if (old==it) break;
    }
    if (it<=n) { puts("No solution"); continue;
   }
    for (i=0; i<m; i++) r[i]=(u[x[i]]<u[y[i]])?'^':'v';
    puts(r);
  }
  return 0;
}
