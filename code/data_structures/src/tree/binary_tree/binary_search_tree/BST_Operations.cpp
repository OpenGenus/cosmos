#include<iostream>
#include<algorithm>
using namespace std;
class BST{
private:
    int data;
    BST *left,*right;
public:
    //Constructors:
    BST(){
        data=0;
        left=right=NULL;
    }
    BST(int val){
        data=val;
        left=right=NULL;
    }
    //Inserting a Node into BST:
    BST* InsertNode(BST*,int);
    //Delete a Node from BST:
    BST* DeletNode(BST*,int);
    //Traversals:
    void InOrder(BST*);
    void PreOrder(BST*);
    void PostOrder(BST*);
    //Searching
    BST* SearchNode(BST*,int);
};
BST* BST::InsertNode(BST *root,int key){
    if(root==NULL){
        root=new BST(key);
        return root;
    }
     else if(key<=root->data){
        if(root->left==NULL){
            root->left=new BST(key);
            return root;
        }
        else{
            root->left=InsertNode(root->left,key);
            return root;
        }
    }
    else{
        if(root->right==NULL){
            root->right=new BST(key);
            return root;
        }
        else {
            root->right=InsertNode(root->right,key);
            return root;
        }
    }
}
BST* BST::DeletNode(BST *root,int key){
    // Base case 
    if (root == NULL) 
        return root; 
    //If root->data is greater than k then we delete the root's subtree
    if(root->data > key){ 
        root->left = DeletNode(root->left, key); 
        return root; 
    } 
    else if(root->data < key){ 
        root->right = DeletNode(root->right, key); 
        return root; 
    } 
    // If one of the children is empty 
    if (root->left == NULL) { 
        BST* temp = root->right;
        delete root; 
        return temp; 
    } 
    else if (root->right == NULL) { 
        BST* temp = root->left; 
        delete root; 
        return temp; 
    } 
    else {
        BST* Parent = root;
        // Find successor of the Node
        BST *succ = root->right; 
        while (succ->left != NULL) { 
        Parent = succ; 
        succ = succ->left; 
        } 

        if (Parent != root) 
        Parent->left = succ->right; 
        else
        Parent->right = succ->right; 

        // Copy Successor Data  
        root->data = succ->data; 

        // Delete Successor and return root 
        delete succ;
        return root; 
    } 
}
BST* BST::SearchNode(BST *root,int key){
    //Base Case
    if(root==NULL||root->data==key)
        return root;
    if(root->data>key){
        return SearchNode(root->left,key);
    }
    return SearchNode(root->right,key);
}
void BST::InOrder(BST *root){
    //InOrder traversal of a Binary Search Tree gives sorted order.
    if(root==NULL)return;
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
void BST::PreOrder(BST *root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void BST::PostOrder(BST *root){
    if(root==NULL)return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}
int main(){
    int choice,element;
    BST B,*root=NULL;
    while(true){
        cout << "------------------\n";
        cout << "Operations on Binary Search Tree\n";
        cout << "------------------\n";
        cout << "1.Insert Element\n";
        cout << "2.Delete Element\n";
        cout << "3.Search Element\n";
        cout << "4.Traversals\n";
        cout << "5.Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
        case 1:
            cout << "Enter the element to be inserted: ";
            cin >> element;
            root=B.InsertNode(root,element);
            break;
        case 2:
            cout << "Enter the element to be deleted: ";
            cin >> element;
            root=B.DeletNode(root,element);
            break;
        case 3:
            cout << "Search Element: ";
            cout << "Enter the element to be Searched: ";
            cin >> element;
            if (B.SearchNode(root,element)){
                cout << "Element Found \n" ;
            }
            else
                cout << "Element Not Found\n";
            break;
        case 4:
            cout << "Displaying elements of BST:  ";
            cout <<"\nInORder: ";
            B.InOrder(root);
            cout <<"\nPreORder: ";
            B.PreOrder(root);
            cout <<"\nPostORder: ";
            B.PostOrder(root);
            cout<<endl;
            break;
        case 5:
            return 1;
        default:
            cout << "Enter Correct Choice \n";
        }
    }
}
