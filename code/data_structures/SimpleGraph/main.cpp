#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "Graph.h"
#include <time.h>
using namespace std;


int main()
{
  Graph<char,int> ngraph;
  srand(time(NULL));

  ngraph.insert_node('a');
  ngraph.insert_node('b');
  ngraph.insert_node('c');
  ngraph.insert_node('d');
    ngraph.insert_node('e');
    ngraph.insert_node('f');
  ngraph.dir_ =0;

  ngraph.insert_edge('a','b',1);
  ngraph.insert_edge('a','e',20);
  ngraph.insert_edge('a','c',3);
  ngraph.insert_edge('c','b',4);
  ngraph.insert_edge('c','e',9);
  ngraph.insert_edge('b','d',6);
  ngraph.insert_edge('d','c',1);
  ngraph.insert_edge('d','e',3);
  ngraph.insert_edge('f','a',1);

  ngraph.dijkstra('a');
  ngraph.gen_dot_();

 system("dot graph.dot -o graph.png -Tpng");
 system("eog graph.png");

return 0;
}

