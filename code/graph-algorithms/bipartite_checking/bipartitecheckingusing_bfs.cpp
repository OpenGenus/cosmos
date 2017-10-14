/*this is the code snippet 
take the matrix in adjlist and then just use the following algorithm*
*/
//graph stored in adj  i.e.  vector<vector<int> > adj
queue<int> q;
q.push(s);

int colour[100000];
int visited[100000];
color[s]=0; // 0-> red color 1-> blue color

memset(visited,0,sizeof(visited));
visited[s]=1;
bool isbipartite=true;

while(!q.empty()&&isbipartite)
{

int u= q.front();
q.pop();

  for(int i=0;i<adj[u].size();++i)
  {
    int v= adj[u][i];
    
    if(visited[v]==0)
    {
      visited[v]=1;
      color[v]=1-color[u];
      
      q.push(v);    
    }
    else{
    if(color[v]==color[u])
    {
    isbipartite=false;
    break;
    }
    
    
    
    }
    
    
    
    }


}


//now check the bipartiteness by cheking boolean variable isbipartite 
//you can get colors assigned by checking colour array 

