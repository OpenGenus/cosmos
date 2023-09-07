#include <iostream>
#include<vector>
#include<queue>
using namespace std;

void createEdge( int a , int b , vector<int> graph[] ){
    // creating directed edge between nodes of the graph
     graph[a].push_back(b) ;

}

vector<int> levelOrderTraversal( int root , vector<int> graph[] , int n ){

      // creating a level vector for storing the data of level of each node 
      // compared to the root node
      vector<int> level(n) ;
      queue<int> q ;
      
      // initially pushing the root in the queue and setting it's level as 0      
      q.push(root) ;
      level[root] = 0 ;


      // continuing this process uptill queue is empty
      while( !q.empty() ){

          int x = q.front() ;
          q.pop() ;

          // popping the first element and setting up the level of all the connected
          // nodes to the current node
          for(  auto node : graph[x] ){
              // setting up the level of node to 1 more then the current level              
              q.push(node) ;
              level[node] = level[x] + 1 ;
          }


      }
      
      return level ;

}

int main()
{


    // first creating the graph
    vector<int> graph[8] ;

    for( int i = 0 ; i<8 ; i++ )
       graph[i].clear() ;

    // we are creating a unidirected graph here
    createEdge( 0 , 1 , graph ) ;
    createEdge( 0 , 2 , graph ) ;
    createEdge( 0 , 3 , graph ) ;
    createEdge( 1 , 4 , graph ) ;
    createEdge( 1 , 5 , graph ) ;
    createEdge( 2 , 6 , graph ) ;
    createEdge( 3 , 7 , graph ) ;


     
   
    // applying the algorithm to find the level of all the nodes
    vector<int> level = levelOrderTraversal( 0 , graph , 8 ) ;

    
    // displaying each node and it's level in tabular format
    cout<<"node "<<"  level"<<endl;
    cout<<"***************\n" ;

     for( int i = 0 ; i<8 ; i++ ){
         cout<<" "<<i<<"\t "<<level[i]<<endl;
     }





    return 0;
}