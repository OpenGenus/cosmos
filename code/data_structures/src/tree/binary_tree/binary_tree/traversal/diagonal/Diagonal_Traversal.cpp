#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};
void diagonalPrint(Node *root);
/* program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     if(n==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
     
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     diagonalPrint(root);
     cout<<endl;
  }
  }
  return 0;
}


//function to print tree in diagonal order
void diagonalPrint(Node *root)
{  
  //using queue from stl 

  queue<Node*> q; 
  q.push(root);
  q.push(NULL);
  
  while(!q.empty()){
      struct Node* tmp=q.front();
      q.pop();
      if(tmp==NULL){
          q.push(NULL);
          tmp=q.front();
          q.pop();
          if(tmp==NULL)
          break;
      }
     
      while(tmp!=NULL){
          cout<<tmp->data<<" ";
          if(tmp->left)
            q.push(tmp->left);
          tmp=tmp->right;
      }
}
}