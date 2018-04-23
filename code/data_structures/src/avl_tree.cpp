//implemention of an AVL tree data structure
#include <iostream>

#include <algorithm>

struct Node 
{
    int _data;
    Node *left;
    Node *right;
    int _height;
};
class AvlTree
{
	private:
	  static Node *root;
	   
	public:

    Node *NewNode (int key) 
{
    Node *temp=(Node*) malloc (sizeof(Node));
    temp->_data=key;
    temp->left=temp->right=nullptr;
    return temp;
}

int Height (Node*node) 
{
    if (node==nullptr) 
	return 0;
	
    int lh=Height(node->left);
    int rh=Height(node->right);
    
    if (lh > rh)
	 return lh+1;
    else 
	return rh+1;
}

int getBalance (Node *node) 
{
    if (node==nullptr)
	 return 0;
	 
    return Height(node->left) - Height(node->right);
}

Node *getRightRotate (Node *y) 
{
     Node *x=y->left;
     Node *T2=x->right;
    
    x->right=y;
    y->left=T2;
    
    y->_height=std::max(Height(y->left) , Height(y->right))+1;
    x->_height=std::max(Height(x->left) , Height(x->right))+1;
    
    return x;
    
}

Node *getLeftRotate (Node *x)
{
    Node *y=x->right;
    Node *T2=y->left;
    
    y->left=x;
    x->right=T2;
    
    x->_height=std::max(Height(x->left),Height(x->right))+1;
    y->_height=std::max(Height(y->left),Height(y->right))+1;
    
    return y; 
}


Node* insertToAVL (Node*node, int _data)
{
    if(node==NULL) 
	return NewNode(_data);
	
    if(_data < node->_data)
    {
        node->left=insertToAVL(node->left,_data);
    }
    else if(_data > node->_data)
    {
        node->right=insertToAVL(node->right,_data);
    }
    else
    {
        return node;
    }
    
    node->_height=1+std::max(Height(node->left),Height(node->right));
    int balance = getBalance(node);
    
    //left left rotation
    if(balance > 1 && _data < node->left->_data)
    {
        return getRightRotate(node);
    }
    
   // right right rotation
    if(balance < -1 && _data > node->right->_data)
    {
        return getLeftRotate(node);
    }
    
    //left Right Rotation
    if(balance > 1 && _data > node->left->_data)
    {
        node->left=getLeftRotate(node->left);
        return getRightRotate(node);
    }
    
    //Right Left Rotation
    if(balance < -1 && _data < node->right->_data)
    {
        node->right=getRightRotate(node->right);
        return getLeftRotate(node);
    }
    
    return node;
}

void InOrder (Node *root)
{
    if(root != NULL)
    {
         InOrder(root->left);
        std::cout<<root->_data<<" ";
        InOrder(root->right);
    }
}
 
};

int main()
{
	int Choice , Key;
	AvlTree T;
	static Node *root;
	 while (1)
    {
       
        std::cout<<"AVL Tree Implementation"<<std::endl;
        std::cout<<"1.Insert Element into the tree"<<std::endl;
        std::cout<<"2.InOrder traversal"<<std::endl;
		std::cout<<"3.Exit"<<std::endl;
        std::cout<<"Enter your Choice: ";
        std::cin>>Choice;
        switch(Choice)
        {
        case 1:
            std::cout<<"Enter value to be inserted: ";
            std::cin>>Key;
            root = T.insertToAVL(root,Key);
            break;
        case 2:
            if (root == nullptr)
            {
                std::cout<<"Tree is Empty"<<std::endl;
                continue;
            }
            std::cout<<"Inorder Traversal:"<<std::endl;
            T.InOrder(root);
            std::cout<<std::endl;
            break;
        case 3:
            std::exit(1);
            break;
        default:
            std::cout<<"Wrong Choice"<<std::endl;
        }
    }
    return 0;
}
