
//This Algorithm gives you  wheather given vertices belong to the same component in a undirected graph or not

// Same Algorithm can be modified to  find loop in a undirected graph ,used to find minimum spanning tree as well

//I would like to use Disjoint sets DS for this

#include<bits/stdc++.h>
using namespace std;


void Arrange_Parents(vector<int>&Parent,vector<vector<int>>adjacency_list){


  for(vector<int>edges:adjacency_list){

 // If parent for both vertices are same then there exists a loop 
int replace=Parent[edges[1]];
    for(int i=0;i<Parent.size();++i)
      if(Parent[i]==replace)Parent[i]=Parent[edges[0]];
  }
   
}
main(){

int vertices,edges;
  
  cin>>vertices>>edges;  //if vertices are 5 only 1~5  are allowed
vector<vector<int>>adjacency_list;
    vector<int>Parent(vertices+1);
  for(int i=1;i<=vertices;++i)
  Parent[i]=i;   // Initially Each vertex is the parent to itself
  
  while(edges--){
  
    int vertex1,vertex2;
  
    cin>>vertex1>>vertex2;
   
    adjacency_list.push_back({vertex1,vertex2});  //Arranging Undirected Graph though it looks like Directed graph it is an undirecetd graph
    
  }

cout<<"Enter the Vertices";
  
  int vertex1,vertex2;
  cin>>vertex1>>vertex2;
  
Arrange_Parents(Parent,adjacency_list); //Arranges the Parent Array
  
 int valid=Parent[vertex1]==Parent[vertex2];
  
  if(valid)cout<<"Yes Both Vertices present in same component";
  
  else cout<<"No Both  Vertices are not present in same component";
}
  
  
