#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct BST{
    int data;
    BST *left = NULL;
    BST *right = NULL;
};
struct BST *root = NULL;

void insert(int element){
    BST *current = new BST;
    current->data = element;

    BST *p1;
    BST *p2;

    if(root==NULL){
        root = current;
    }else{
        p1 = root;
        while(p1!=NULL){
            p2 = p1;
            if(p1->data == current->data) {
                return;
            }
            if(p1->data>current->data){
                p1 = p1->left;
            }else if(p1->data<current->data){
                p1 = p1->right;
            }
        }
        if(current->data<p2->data){
            p2->left = current;
        }else{
            p2->right = current;
        }
    }
}
bool searchInBST(int element){
    BST *p = root;

    while(p!=NULL){
        if(p->data==element){
            return true;
        }else{
            if(p->data>element){
                p = p->left;
            }else{
                p = p->right;
            }
        }
    }
    return false;
}
BST search(int key,BST *p){
    if(p==NULL){
        cout<<"Not FOund"<<endl;
    }else if(p->data==key){
        cout<<"Found"<<endl;
    }else if(p->data>key){
        search(key,p->left);
    }else {
        search(key, p->right);
    }
}
void inorderDisplay(BST *p){
    if(p!=NULL){
        inorderDisplay(p->left);
        cout<<p->data<<" ";
        inorderDisplay(p->right);
    }
}
void preOrderDisplay(BST *p){
    if(p!=NULL){
        cout<<p->data<<" ";
        preOrderDisplay(p->left);
        preOrderDisplay(p->right);
    }
}
void postOrderDisplay(BST *p){
    if(p!=NULL){
        postOrderDisplay(p->left);
        postOrderDisplay(p->right);
        cout<<p->data<<" ";
    }
}
void levelOrder(BST* p) {

    vector<int> ans;

    if(p == NULL) {
        cout << "NO ANY ELEMENT FOUND";
    }
    queue<BST*> q;
    q.push(root);

    while(!q.empty()) {

        BST *temp = q.front();
        q.pop();

        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);

        ans.push_back(temp->data);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
int maximumHeightOfBST(BST *p){
    if(p==NULL){
        return 0;
    }
    return max(maximumHeightOfBST(p->left),maximumHeightOfBST(p->right))+1;
}
int minimumHeightOfBST(BST* p) {
    if(p == NULL){
        return 0;
    }
    if(p->left == NULL || p->right == NULL){
        return max(minimumHeightOfBST(p->left), minimumHeightOfBST(p->right)) + 1;
    }else{
        return min(minimumHeightOfBST(p->left), minimumHeightOfBST(p->right)) + 1;
    }
}
int minimumElementInBST(BST* p){
    if(p==NULL){
        return -1;
    }else{
        int minimum = 0;
        while (p->left!=NULL)
        {
            minimum  = p->left->data;
            p = p->left;
        }
        return minimum;
    }
}
int maximumElementInBST(BST* p){
    if(p==NULL){
        return -1;
    }else{
        int maximum = 0;
        while (p->right!=NULL)
        {
            maximum  = p->right->data;
            p = p->right;
        }
        return maximum;
    }
}
int myMax(BST *p){
    if(p->right!=NULL){
        return myMax(p->right);
    } else{
        return p->data;
    }
}
BST* deletionInBST(BST* node,int element){
    if(node == NULL){
        return NULL;
    }
    if(element > node->data){
        node->right = deletionInBST(node->right,element);
    }else if(element < node->data){
        node->left = deletionInBST(node->left,element);
    }else{
        //When data is equal to the node value
        if(node->left!=NULL && node->right!=NULL){
            int leftMax = myMax(node->left);
            node->data = leftMax;
            node->left = deletionInBST(node->left,leftMax);
            return node;
        }else if(node->left!=NULL){
            return node->left;
        }else if(node->right!=NULL){
            return node->right;
        }else {
            return NULL;
        }
    }
   return node;
}
int numberOfNodesInBST(BST *p){
    if(p==NULL){
        return 0;
    }
    return (numberOfNodesInBST(p->left)+ (numberOfNodesInBST(p->right)))+1;
}
int sumOfAllNodesInBST(BST *p){
    if(p==NULL){
        return 0;
    }
    int sum =  p->data+sumOfAllNodesInBST(p->left)+ sumOfAllNodesInBST(p->right);
    return sum;
}
int check = 0;
void countLeafNodes(BST *p){
    if(p!=NULL) {
        if (p->left == NULL && p->right == NULL) {
            check++;
        }else {
            if (p->left != NULL) {
                countLeafNodes(p->left);
            }
            if (p->right != NULL) {
                countLeafNodes(p->right);
            }
        }
    }
}
void displayLeafNodes(BST *p){
    if(p!=NULL) {
        if (p->left == NULL && p->right == NULL) {
            cout<<p->data<<" ";
        }else {
            if (p->left != NULL) {
                displayLeafNodes(p->left);
            }
            if (p->right != NULL) {
                displayLeafNodes(p->right);
            }
        }
    }
}

//Given a Binary Tree, find the maximum sum path from a leaf to root.
int maxPathSum(Node* root)
    {
        if(root == NULL){
            return 0;
        }
        return root->data + max(maxPathSum(root->left),maxPathSum(root->right));
    }

void mainMenu(){
    cout<<"\nWhich task you want to perform"<<endl;
    cout<<"0  -  Exit \n";
    cout<<"1  -  Insert In BST \n";
    cout<<"2  -  Pre-Order Traversal \n";
    cout<<"3  -  Post-Order Traversal \n";
    cout<<"4  -  In-Order Traversal \n";
    cout<<"5  -  Level-Order Traversal \n";
    cout<<"6  -  Search Boolean Return \n";
    cout<<"7  -  Search Void \n";
    cout<<"8  -  Delete In BST \n";
    cout<<"9  -  Maximum Height of BST \n";
    cout<<"10 -  Minimum Height of BST \n";
    cout<<"11 -  Minimum Element In BST \n";
    cout<<"12 -  Maximum Element In BST \n";
    cout<<"13 -  Number of Nodes In BST \n";
    cout<<"14 -  Sum of all Nodes In BST \n";
    cout<<"15 -  Count Leaf Nodes In BST \n";
    cout<<"16 -  Display Leaf Nodes In BST \n";
    cout<<"17 -  Display the Path Equal to Given Sum: \n";
    cout<<"18 -  Display the Path Equal to Given Sum: \n";

    cout<<"Enter Your Option: ";
    int option;
    cin>>option;

    switch(option) {
        case 0:
            break;
        case 1:
            cout<<"Enter the Element to Insert: ";
            int element;
            cin>>element;
            insert(element);
            mainMenu();
        case 2:
            cout<<"PRE-ORDER TRAVERSAL: ";
            preOrderDisplay(root);
            cout<<endl;
            mainMenu();
        case 3:
            cout<<"POST-ORDER TRAVERSAL: ";
            postOrderDisplay(root);
            cout<<endl;
            mainMenu();
        case 4:
            cout<<"IN-ORDER TRAVERSAL: ";
            inorderDisplay(root);
            cout<<endl;
            mainMenu();
        case 5:
            cout<<"LEVEL-ORDER TRAVERSAL: ";
            levelOrder(root);
            cout<<endl;
            mainMenu();

        case 6:
            cout << "Enter the Element to Search: ";
            int key;
            cin >> key;
            int toCheck;
            toCheck = searchInBST(key);
            if (toCheck == 1) {
                cout << "Element Exits? : True";
                cout << endl;
            } else {
                cout << "Element Exits? : False";
                cout << endl;
            }
            mainMenu();

        case 7:
            cout<<"Enter the Element to Search: ";
            cin>>key;
            if (key==root->data){
                cout<<"Found";
            }
            else if (key>root->data) {
                search(key,root->right);
            } else{
                search(key,root->left);
            }
            mainMenu();
        case 8:
             cout<<"\nEnter the Element to Delete: ";
             int element;
             cin>>element;
             deletionInBST(root,element);
             mainMenu();
        case 9:
            cout<<"\nMaximum Height of BST Is: "<<maximumHeightOfBST(root)<<endl;
            mainMenu();
        case 10:
            //for this case {2,3,4,5,6,9}
            cout<<"\nMinimum Height of BST Is: "<<minimumHeightOfBST(root)<<endl;
            mainMenu();
        case 11:
            cout<<"\nMinimum Element Is: "<<minimumElementInBST(root)<<endl;
            mainMenu();
        case 12:
            cout<<endl;
            cout<<"\nMaximum Element Is: "<<maximumElementInBST(root);
            cout<<endl;
            mainMenu();
        case 13:
            cout<<"\nThe Number of Nodes are: "<<numberOfNodesInBST(root)<<endl;
            mainMenu();
        case 14:
            cout<<"\nThe Sum of All Nodes Is: "<<sumOfAllNodesInBST(root)<<endl;
            mainMenu();
        case 15:
            countLeafNodes(root);
            cout << "\nThe Number Leaf Nodes are: " << check << endl;
            mainMenu();
        case 16:
            cout << "\nLeaf Nodes are: ";
            displayLeafNodes(root);
            cout<<endl;
            mainMenu();
        default:
            cout<<"Wrong Option Enter Again";
            mainMenu();
    }
}
int main(){
    mainMenu();
}