//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
int N=1e5;
unordered_map<Node*,Node*> parent;


class Solution {
  public:
    Node * DFS(Node *p,int target){
        if(p==NULL) return NULL;
        if(p->left){
            parent[p->left]=p;
        }
        if(p->right){
            parent[p->right]=p;
        }
        Node *q=DFS(p->left,target);
        Node *r=DFS(p->right,target);
        if(p->data==target){
            return p; 
        }
        return q!=NULL?q:r;
    }
    
    int minTime(Node* root, int target) 
    {
      Node *temp=DFS(root,target);
      int  visited[N]={0};
      int count=0;
      queue<Node*> q;
      q.push(temp);
    //   cout<<(parent[root->left]->data);
      while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node * p=q.front();
                q.pop();
                visited[p->data]=1;
                int x=0;
                if(parent[p]!=NULL)
                  x=parent[p]->data;
                if(parent[p]!=NULL&&visited[x]!=1){
                    q.push(parent[p]);
                    // cout<<parent[p]->data<<" ";
                    parent[p]=NULL;
                   if(parent[p]!=NULL)
                    visited[x]=1;
                }
                if(p->left&&visited[p->left->data]!=1){
                    q.push(p->left);
                    visited[p->left->data]=1;
                    // cout<<p->left->data<<" ";
                }
                if(p->right&&visited[p->right->data]!=1){
                    q.push(p->right);
                    visited[p->right->data]=1;
                    // cout<<p->right->data<<" ";
                }
                // cout<<endl;
            }
            count++;
      }
      return count-1;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends