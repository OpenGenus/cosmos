#ifndef GRAPH_H
#define GRAPH_H
#include "GNode.h"
#include "GEdge.h"
#include <vector>
#include <fstream>
using namespace std;
template <class N,class E>
class Graph{
public:
  typedef N NodeType;
  typedef E EdgeType;
  typedef Graph<NodeType,EdgeType> self;
  typedef GNode<self> Node;
  typedef GEdge<self> Edge;

  vector<Node*> nodes_;
  bool dir_;
  bool insert_node(N x);
  bool find_node(N x,Node** &p);
  void insert_edge(N a,N b,E data);
  void remove_edge(N x,N y);
  void remove_edge(E x,E y);

  void insert_edge_by_nodes(Node* a,Node* b,E data,bool dir);
  Edge * find_edge_by_nodes(Node* a,Node* b);

  void finding_node(N i);
  Node * find_in_vector(N a);

  void dijkstra(N a);
  bool is_already_labeled(Node *a,vector<Node*> x,int &index);
  void evaluate_labels(Node *a,Node* b);
  Node * find_the_minor_unvisited(vector<Node*> x);
  bool find_labeled_unvisited(vector<Node*> labeled_nodes_,Node * &p);

  void gen_dot_();
  void delete_double_edge(string tmp,string &tmp1);
};
template <class N,class E>
void Graph<N,E>::finding_node(N i){
  Node** p;

  cout << find_node(i,p);
  return;
}

template <class N,class E>
bool Graph<N,E>::insert_node(N x){
  Node* n = new Node(x);
  nodes_.push_back(n);
  return 1;
}

template <class N,class E>
bool Graph<N,E>::find_node(N x,Node** &p){
  for(int i=0; i < this->nodes_.size() ; i++){
    p = &(this->nodes_[i]);
    if((*p)->data_ == x){
      return 1;
    }
    if(!(*p)->edges_.empty()){
      for (int j=0; j < (*p)->edges_.size(); j++){
          while(!(*p)->visited_){
              //cout << (*p)->data_;
              if((*p)->data_ == x){
                return 1;
              }
              (*p)->visited_ = 1;
              if((*p)->edges_.empty()){
                  break;
              }
              (*p) = (*p)->edges_[j]->nodes_[1];
          }
      }
    }
  }
  return 0;
}



template <class N,class E>
void Graph<N,E>::insert_edge(N a,N b,E data){
  insert_edge_by_nodes(find_in_vector(a),find_in_vector(b),data,this->dir_);
  if(!this->dir_)
    insert_edge_by_nodes(find_in_vector(b),find_in_vector(a),data,this->dir_);
  return;
}


template <class N,class E>
typename Graph<N,E>::Node* Graph<N,E>::find_in_vector(N a){
  for(int i =0;i < this->nodes_.size(); i++){
      if (this->nodes_[i]->data_== a ){
        return this->nodes_[i];
      }
    }
}

template <class N,class E>
void Graph<N,E>::insert_edge_by_nodes(Node* a,Node* b,E data,bool dir){
  Edge* n = new Edge(b,data);
  n->dir_ = dir;
  a->edges_.push_back(n);
  return;
}
template <class N,class E>
typename Graph<N,E>::Edge * Graph<N,E>::find_edge_by_nodes(Node* a,Node* b){
  Edge * ret;
  Node * p = find_in_vector(a->data_);
  for(int i=0;i<p->edges_.size();i++){
      if(p->edges_[i]->nodes_[1]->data_ == b->data_)
        ret = p->edges_[i];
    }
  return ret;
}
template <class N,class E>
void Graph<N,E>::delete_double_edge(string tmp,string &tmp1){
  for(int i=0;i<tmp1.size();i=i+4){
    cout << tmp.find(tmp1.substr(i,4));
  }
}
template <class N,class E>
void Graph<N,E>::remove_edge(N x,N y){
  Node * a = find_in_vector(x);

  for(int i = 0;i < a->edges_.size(); i++){
      if(a->edges_[i]->nodes_[1]->data_ == y)
        a->edges_.erase();
    }
  Node * b = find_in_vector(y);
  for(int i = 0;i < b->edges_.size(); i++){
      if(b->edges_[i]->nodes_[1]->data_ == a)
        b->edges_.erase(i);
    }
}


/** DIJKSTRA **/

template <class N,class E>
void Graph<N,E>::dijkstra(N a){
  Node * p;
  Node * q;
  vector<Node*> label_nodes_;
  p = find_in_vector(a);
  p->label.second = p;
  while(p){

    for(int i=0;i<p->edges_.size();i++){
      if(!p->edges_[i]->nodes_[1]->visited_){
        int index;
        if(is_already_labeled(p->edges_[i]->nodes_[1],label_nodes_,index)){ //evaluar , comparar etiquetas y escoger la menor, no acumula.
          Edge * tmp = find_edge_by_nodes(p,label_nodes_[index]);
          if(tmp->data_ + p->label.first < label_nodes_[index]->label.first){
            label_nodes_[index]->label.first = tmp->data_ + p->label.first;
            label_nodes_[index]->label.second = p;
          }
        }
        else{
          p->edges_[i]->nodes_[1]->label.first = p->label.first+p->edges_[i]->data_;
          p->edges_[i]->nodes_[1]->label.second = p;
          label_nodes_.push_back(p->edges_[i]->nodes_[1]);
        }
      }
    }
    p->visited_ = 1;
    p = find_the_minor_unvisited(label_nodes_);//p->edges_[0]->nodes_[1]; // evaluar el menor no visitado en label_nodes_
    }
  for(int i=0;i<label_nodes_.size();i++){
      cout << label_nodes_[i]->data_<<" : "<< label_nodes_[i]->label.first<<", from: "<< label_nodes_[i]->label.second->data_<<endl;
    }
}


/** if( this->node_[i]->is_already_labeled());
 *    pop that node from the vector, replace with the same
 *    but with the new shortest path.
 *  otherwise
 *    do nothing
 *  end;
 **/
template <class N,class E>
bool Graph<N,E>::is_already_labeled(Node * a,vector<Node*> x,int &index){
  for(index =0;index < x.size(); index++){
      if (x[index]->data_== a->data_ ){
        return 1;
      }
    }
  return 0;
}

template <class N,class E>
bool Graph<N,E>::find_labeled_unvisited(vector<Node*> labeled_nodes_,Node * &p){
  for(int i=0;i < labeled_nodes_.size(); i++){
      if(!labeled_nodes_[i]->visited_){
          p = labeled_nodes_[i];
          return 1;
      }
  }
  return 0;
}


template <class N,class E>
typename Graph<N,E>::Node* Graph<N,E>::find_the_minor_unvisited(vector<Node*> labeled_nodes_){
  int minor_ = 1000;
  Node * q = NULL;
  for(int i=0;i < labeled_nodes_.size();i++){
    if(!labeled_nodes_[i]->visited_){
      if(labeled_nodes_[i]->label.first < minor_)
        q = labeled_nodes_[i];
    }
  }
  return q;
}
/** ********************/

/** GraphViz **/

template <class N,class E>
void Graph<N,E>::gen_dot_(){
  string tmp;
  if(this->nodes_[0]->edges_[0]->dir_)
    tmp += "di";
  tmp += "graph{\n\n";
  for(int i=0;i<this->nodes_.size();i++){
    this->nodes_[i]->get_node_and_edges(tmp);
    tmp += "\n";
  }
  tmp += "}\n";
  //cout << tmp;
  ofstream graph("graph.dot");
  graph<<tmp;
  return ;
}







#endif // GRAPH_H
