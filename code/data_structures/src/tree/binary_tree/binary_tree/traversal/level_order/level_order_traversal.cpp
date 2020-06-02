#include <iostream>
#include <queue>
using namespace std;
struct Node {
  int data;
  Node * left;
  Node * right;
};
Node * createNewNode(int value) {
  Node * temp = new Node;
  temp-> data = value;
  temp-> left = temp-> right = NULL;
  return temp;
}
Node * newNode(Node * root, int data) {
  if (root == NULL)
    root = createNewNode(data);
  else if (data < root-> data)
    root-> left = newNode(root-> left, data);
  else
    root-> right = newNode(root-> right, data);
  return root;
}
void levelOrder(Node * root) {
  cout << "The nodes in level order traversal are " << endl;
  if (root == NULL) {
    return;
  }
  queue < Node * > q;
  q.push(root);
  while (q.empty() == false) {
    int count = q.size();
    for (int i = 0; i < count; i++) {
      Node * cur = q.front();
      q.pop();
      cout << (cur-> data) << " ";
      if (cur-> left != NULL) {
        q.push(cur-> left);
      }
      if (cur-> right != NULL) {
        q.push(cur-> right);
      }
    }
  }
}
int main() {
  int testcases;
  cout << "Enter the total number of testcases" << endl;
  cin >> testcases;
  while (testcases--) {
    Node * root = NULL;
    int sizeOfArray;
    cout << "Enter the total number of nodes in the binary tree" << endl;
    cin >> sizeOfArray;
    int arr[sizeOfArray];
    cout << "Enter the nodes in inorder traversal" << endl;
    for (int i = 0; i < sizeOfArray; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i < sizeOfArray; i++) {
      root = newNode(root, arr[i]);
    }
    levelOrder(root);
    cout << endl;
  }
  return 0;
}
