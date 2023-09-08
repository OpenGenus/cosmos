#ifndef GNODE_H
#define GNODE_H
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>

using namespace std;
template <class GraphTypes>
class GNode{
public:
  typedef typename GraphTypes::NodeType N;
  typedef typename GraphTypes::Edge Edge;
  typedef typename GraphTypes::Node Node;

  GNode(N n);


  N data_;
  vector<Edge*> edges_;
  bool visited_;

  pair<int,Node*> label;

  string shortest_path_;

  /** GraphViz **/
  void get_node_and_edges(string &tmp);
  bool duplicate_edge(string tmp,string tmp2);

};


template <class GraphTypes>
GNode<GraphTypes>::GNode(N n){
  this->data_ = n;
  this->label.first = 0;
}


/** GraphViz **/

template <class GraphTypes>
bool GNode<GraphTypes>::duplicate_edge(string tmp,string tmp2){
  for(int i =0;i < tmp2.size();i++){
      if(tmp2[i] == tmp[0]){
          if(tmp2.substr(i,4) == tmp){
              return 1;
            }
        }
    }
  return 0;
}

template <class GraphTypes>
void GNode<GraphTypes>::get_node_and_edges(string &tmp){

  for(int i=0;i<this->edges_.size();i++){
    string tmp2;
    stringstream e,f,l;
    f<< this->data_;
    l<< this->edges_[i]->data_;
    e << this->edges_[i]->nodes_[1]->data_;
    tmp2 = e.str() + "--" + f.str();

    if(!this->edges_[i]->dir_){
      if(!duplicate_edge(tmp2,tmp))
        tmp += f.str() + "--" + e.str() +"[label =" + l.str() + "]" "\n";
    }
    else{
        tmp += f.str() + "->" + e.str() +"[label =" + l.str() + "]" "\n";
      }
  }
  return;
}

#endif // GNODE_H
