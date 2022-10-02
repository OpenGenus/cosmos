#include<bits/stdc++.h>
using namespace std;


// class Node 
class Node{
	public:
	int data;
	Node * left;
	Node * right;
};


// create Node 
Node* createNode(int val){
	Node * temp = new Node;
	if(!temp){
		cout<<"Error\n";
		return NULL;
	}
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

// build the tree from array 
Node * buildtree(vector<int>&arr){
	if(arr.empty()){
		return NULL;
	}
	Node * root = createNode(arr[0]);
	queue<Node*>q;
	q.push(root);
	int i = 1;
	while(!q.empty() && i < arr.size()){
		Node * temp = q.front();
		q.pop();
	  int val = arr[i];
	  if(val != 0){
	  	temp->left = createNode(val);
	  	q.push(temp->left);
	  }
	  i++;
	  if(i>=arr.size()){
	  	break;
	  }
	  val = arr[i];
	   if(val != 0){
	  	temp->right = createNode(val);
	  	q.push(temp->right);
	  }
	  i++;
	}
	return root;
}


// print all the left child elements in binary tree 
void print_all_left_child_elements(Node * root){
	queue<Node*>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node * temp = q.front();
		q.pop();
		if(temp == NULL && q.empty()){
			return;
		}else{
			q.push(NULL);
		}
		if(temp){
			if(temp->left){
				cout<<temp->left->data<<" ";
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
}
int main(){
     int testcase;
     cin>>testcase;
     while(testcase--){
     	int size ;
     	cin>>size;
     	vector<int>arr;
     	for(int i = 0;i<size;i++){
     		int val;
     		cin>>val;
     		arr.push_back(val);
		 }
		 Node * root = buildtree(arr);
		 
		 print_all_left_child_elements(root);
	 }
	return 0;
}
