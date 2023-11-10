//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++
//User function Template for C++
// vector<pair<int,int>> v;
// unordered_map<int,int> mp;
int m=INT_MAX;
int t;
class Solution {
public:
    void check(Node *p,vector<int> &v){
        if(p==NULL) return;
        check(p->left,v);
        v.push_back(p->data);
        check(p->right,v);
    }
    pair<int,int> fun(Node *p){
        if(p==NULL){
            return {0,0};
        }
        pair<int,int> p1=fun(p->left);
        pair<int,int> q=fun(p->right);
        int sum=p1.second+q.second+p->data;
        int count=1+p1.first+q.first;
        if(sum==t){
            int flag=0;
            vector<int> v,a;
            check(p,v);
            a=v;
            sort(a.begin(),a.end());
            unordered_map<int,int> mp;
            for(int i=0;i<v.size();i++){
                mp[v[i]]++;
                if(v[i]!=a[i]||mp[v[i]]>1){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                m=min(m,count);
            }
        }
        return {count,sum};
    }
    int minSubtreeSumBST(int target, Node *root) {
        // cout<<m<<endl;
        // mp.clear();
        m=INT_MAX;
        t=target;
        fun(root);
        if(m==INT_MAX) return -1;
        return m;
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends