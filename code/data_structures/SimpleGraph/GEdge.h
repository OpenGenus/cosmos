#ifndef GEDGE_H
#define GEDGE_H
#include <iostream>
using namespace std;

template <class GraphTypes>
class GEdge{
public:
  typedef typename GraphTypes::EdgeType E;
  typedef typename GraphTypes::Node Node;

  GEdge(Node* a,Node* b,E x);
  GEdge(Node* b,E x);
  E data_;
  Node* nodes_[2];
  bool dir_;
};

template <class GraphTypes>
GEdge<GraphTypes>::GEdge(Node* a,Node* b,E x){
  data_ = x;
  nodes_[0] = a;
  nodes_[1] = b;
}

template <class GraphTypes>
GEdge<GraphTypes>::GEdge(Node* b,E x){
  data_ = x;
  nodes_[0] = NULL;
  nodes_[1] = b;
}
#endif // GEDGE_H
