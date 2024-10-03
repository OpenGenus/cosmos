#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
    
    class Edge{
        public:
        int v=0;
        int w=0;
        Edge(int v,int w)
        {
            this->v=v;
            this->w=w;
        }
        Edge()
        {

        }
    };
   // vector<vector<Edge*>> dgraph(7,vector<Edge*>());
    vector<vector<Edge*>> graph(7,vector<Edge*>());
    void addedge(int u,int v,int w)
    {
        if(v<0||u<0||v>=graph.size()||u>=graph.size())
        {
            return;
        }
        graph[u].push_back(new Edge(v,w));
        //graph[v].push_back(new Edge(u,w));
    }
    vector<bool> vis(graph.size(),false);
    string ans="";
    /*void topologicalsort(int src)
    {
        for(int i=0;i<graph.size();i++)
        {
            if(!vis[i]){
                vis[i]=true;
                topologicalsort(i);
            }
        }
    }*/
     bool topologicalsort(int src,vector<int>& st,vector<bool>& vis,vector<bool>& cycle)
    {
        vis[src]=true;
        cycle[src]=true;
        for(Edge* e:graph[src])
        {
            if(!vis[e->v])
            {
                if(!topologicalsort(e->v,st,vis,cycle)) return false;
            }
            else if(cycle[e->v])
            {
                return false;
            }
        }
        st.push_back(src);
        cycle[src]=false;
        return true;
    }
    void topologicalsort1()
    {
        vector<int> st;
        vector<bool> vis(graph.size(),false);
        vector<bool> cycle(graph.size(),false);
        bool res=true;
        for(int i=0;i<graph.size() && res ;i++)
        {
            if(!vis[i])
            {
                if(!topologicalsort(i,st,vis,cycle)){
                   res=false;
                }
            }
        }


    // cout<<res;

        for(int i=st.size()-1;i>=0 && res;i--)
        {
            cout<<st[i]<<" ";
            
        }
        
    }
     class sort
    {
        public:
        int v=0;
        sort(int v)
        {
            this->v=v;
        }
        sort()
        {}
    };
    void toposortbfs()
    {
        list<sort> que;
        vector<int> val;
        int ctr=0;
         vector<int> count(graph.size(),0);
         for(int i=0;i<graph.size();i++)
         {
             for(Edge* e:graph[i])
             {
                count[e->v]++;
             }
             if(count[i]==0)
             {
                que.push_back(i); 
             }
         }
        while(que.size()>0)
        {
            sort rpair=que.front();
            que.pop_front();
            val.push_back(rpair.v);
            
            for(Edge* e:graph[rpair.v])
            {
                if(--count[e->v]==0)
                {
                    que.push_back(e->v);
                }
                ctr++;
            }
            /*if(ctr!=rpair.v)
            {
                cout<<"Cycle ";
                return;
            }*/
            
        }
        for(int i=0;i<val.size();i++)
            {
                cout<<val[i]<<" ";
            }
    }
    void display()
    {
        for(int i=0;i<graph.size();i++)
        {
            cout<<i<<"==> ";
            for(int j=0;j<graph[i].size();j++)
            {
                cout<<"("<<graph[i][j]->v<<","<<graph[i][j]->w<<")";
            }
            cout<<endl;
        }
    }
     void case1()
    {
       addedge(0,3,10);
        addedge(0,2,10);
        addedge(1,2,10);
        addedge(1,5,40);
        addedge(3,4,10);      
        //addedge(3,4,2);
        //addedge(4,5,2);
        addedge(4,6,8);
        addedge(5,6,3);
        
        /*addedge(0,3,10);
        addedge(0,1,10);
        //addedge(1,0,10);
        addedge(1,2,10);
       // addedge(2,1,10);
        addedge(2,3,40);
       // addedge(3,2,40);
        addedge(3,4,2);
      //  addedge(4,3,2);
        addedge(4,5,2);
        addedge(4,6,8);
     //   addedge(5,4,2);
        addedge(5,6,3);*/
    }
    
    int main(int args,char** argv)
    {
        case1();
        //display();
        //cout<<"----";
        //topologicalsort1();
        //cout<<ans;
         toposortbfs();

    }
