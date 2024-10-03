//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
    unordered_map<Node*,int> visited;
    unordered_map<Node*,Node*> m;
public:
    
    void recurssion(Node *root,vector<int> &ans,int d,int k){
        if(root==NULL){
            return;
        }
        if(d>k) return;
        if(visited[root]==true) return;
        if(k==d){
            ans.push_back(root->data);
            return;
        }
        visited[root]=true;
        if(m[root])
       {
           recurssion(m[root],ans,d+1,k);
       }
        recurssion(root->left,ans,d+1,k);
        recurssion(root->right,ans,d+1,k);
        return ;
    }
    Node * findmyNode(Node *root,int target,vector<Node*> &bhai){
        if(root==NULL)
        return NULL;
        if(root->data==target){ bhai.push_back(root);return root;}
        Node *temp1=findmyNode(root->left,target,bhai);
        Node *temp2=findmyNode(root->right,target,bhai);
        if(temp1!=NULL) return temp1;
        else temp2;
        return NULL;
    }
    void pre(Node *root){
        if(root==NULL) return;
        if(root->left){
            m[root->left]=root;
        }
        if(root->right){
            m[root->right]=root;
        }
        pre(root->left);
        pre(root->right);
        return ;
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        vector<Node*> bhai;
        Node *p=findmyNode(root,target,bhai);
        if(bhai.size()>0)p=bhai[0];
        if(p==NULL)
        return {};
        vector<int> ans;
        pre(root);
        recurssion(p,ans,0,k);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends