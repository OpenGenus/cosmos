/************************
  ROOPANSH BANSAL
  150101053
  CS210
 ************************/
#include <bits/stdc++.h>

using namespace std;

struct node
{
	int info;
	node *left , *right , *parent;
};

class BST
{
private:
	node* Root;

public:
	BST();
//	~BST();

	// basic functions :
	bool isEmpty();// returning true of the tree is empty otherwise false
	node * root();// return the pointer to the tree
	node * MakeNode(int x);// creating a node with value x

	//functions to modify tree
	void InsertNode(int x);// inserts the node in the binary search tree in it's right position
	
	// NOT IMPLEMENTED YET
	void DeleteNode(node * NodeToDelete);

	//traversals
	void InOrderTraversal(node * Node);
	void PreOrderTraversal(node * Node);
	void PostOrderTraversal(node * Node);

	//Searching the Tree
	node *Search(int x);
	node *Minimum(node * Node);
	node *Maximum(node * Node);
	node *Successor(node * Node);
	node *Predecessor(node * Node);

	//Speacial Applications
	void SearchDulpicate(int x);// prints duplicate entry of inserting a duplicate entry
	int LargestLevel(node * Node ,int Level);// largest level having leaf 
	int SmallestLevel(node * Node ,int Level);// smallest level having leaf 
	void Leaves(node* Node , int & Count);// counts the number of the leaves in the tree
	node * LCA(int n1 , int n2);// Returns the Lowest common ancestor node of n1 and n2 (n1 and n2 lie in the tree)
	bool PathToNode(node * Node , int x , vector<int> & v);//Returns the path to the node starting from the node to the root....returns false if the value is not found in the tree 
	int LCA_GENERALTREE(int v , int w);// calulates the Lowest Common Ancestor of the two nodes v and w
	int Diameter(node * Node ,int *Height);// Calculate the diameter of the tree in O(n) running time.
};

int main()
{
	BST Tree;
	return 0;
}


// Constructor of the BST
BST::BST()
{
	// set the root of the tree to null initially
	Root = NULL;
}

// creating a node with value x
node * BST::MakeNode(int x)
{
	// Allocating memory for the new node
	node * NewNode = new node;
	
	// Setting the value to store in that node to 'x'
	NewNode->info = x;
	
	// parent and children are set in the functino which calls this to function to create the node
	NewNode->left = NULL;
	NewNode->right = NULL;
	NewNode->parent = NULL;

	return NewNode;
}

// returning true of the tree is empty otherwise false
bool BST::isEmpty()
{
	if(Root == NULL)
		return true;
	else
		return false;
}

// return the pointer to the tree
node * BST::root()
{
	return Root;
}

// inserts the node in the binary search tree in it's right position
void BST::InsertNode(int x)
{
	// create a new node
	node * Node = MakeNode(x);
	
	// if the tree is empty then set the root to that node.
	if(isEmpty()) //Empty tree
	{
		Root = Node;
	}
	else //	non empty tree
	{
		// need two pointers to move along the tree and find the correct position
		node * p = Root;
		node *q = NULL;
		
		while(p != NULL)// when p is null , we have to insert the new node to that position
		{
			q = p;
			if(x >= p->info)
			{
				p = q->right;
			}
			else
			{
				p = q->left;
			}
		}
		
		// atleast one child of q is NULL , to which p points...and we need to insert to that node
		if(x >= q->info)
			q->right = Node;
		else
			q->left = Node;
		Node->parent = q;

		return ;
	}
}

// Count the number of leaves in the tree
void BST::Leaves(node* Node , int & Count)
{
	// node having no children is a leave
	if (Node->left == NULL && Node->right == NULL)
	{
		Count++;
	}

	// if there is a left child , recurse in the left subtree
	if(Node->left != NULL)
		Leaves(Node->left , Count);

	// if there is a right child , recurse in the right subtree
	if(Node->right != NULL)
		Leaves(Node->right , Count);

	return ;//return nothing because i've passed a reference to the variable storing the number of leaves as an argument to the function. 
}

// Generates a random binary search tree
void GenerateTree(BST * Tree , int NumOfNodes)
{
	//Generating 100 Numbers and Inserting in the binary tree
	for(int j=0;j<NumOfNodes;j++)
	{
		//random function to generate random integer to insert
		int ToInsert = rand()%5000 + 1;
		Tree->InsertNode(ToInsert);
	}
}

void BST::DeleteNode(node * NodeToDelete)
{
	/***********************	************************
	************************	************************
						TO	BE	IMPLEMENTED
	************************	************************	
	************************	***********************/
}

//Return the node which has it's key = x
node* BST::Search(int x)
{
	if(isEmpty())
		return NULL;
	node *NodePtr = Root;
	while( NodePtr != NULL && NodePtr->info != x)
	{
		if(NodePtr->info == x)	break;
		else if(NodePtr->info <= x)	NodePtr=NodePtr->right;
		else if(NodePtr->info >= x)	NodePtr=NodePtr->left;
	}
	return NodePtr;
}

node * BST::Minimum(node * Node)
{
	node * NodePtr = Node;
	while(NodePtr->left != NULL)	NodePtr = NodePtr->left;
	return NodePtr;
}

node * BST::Maximum(node * Node)
{
	node * NodePtr = Node;
	while(NodePtr->right != NULL)	NodePtr = NodePtr->right;
	return NodePtr;
}

node * BST::Successor(node * Node)
{
	if(Node->right != NULL)
		return Minimum(Node->right);
	else
	{
		node *Parent = Node->parent;
		node *Child = Node;
		while(Parent != NULL && Parent->right == Child)
		{
			Child = Parent;
			Parent = Parent->parent;
		}
		return Parent;
	}
}

node *BST::Predecessor(node * Node)
{
	if(Node->left != NULL)
		return Minimum(Node->left);
	else
	{
		node *Parent = Node->parent;
		node *Child = Node;
		while(Parent != NULL && Parent->left == Child)
		{
			Child = Parent;
			Parent = Parent->parent;
		}
		return Parent;
	}

}

void BST::InOrderTraversal(node * Node)
{
	if(Node == NULL)
		return;
	InOrderTraversal(Node->left);
	cout<<Node->info<<"\t";
	InOrderTraversal(Node->right);
}

void BST::PreOrderTraversal(node * Node)
{
	if(Node == NULL)
		return ;
	cout<<Node->info<<"\t";
	PreOrderTraversal(Node->left);
	PreOrderTraversal(Node->right);
}

void BST::PostOrderTraversal(node * Node)
{
	if(Node == NULL)
		return ;
	PostOrderTraversal(Node->left);
	PostOrderTraversal(Node->right);
	cout<<Node->info<<"\t";
}

void BST::SearchDulpicate(int x)
{
	node * Node = MakeNode(x);
	if(isEmpty())
	{
		Root = Node;
	}
	else
	{
		node * p = Root;
		node *q = NULL;
		while(p != NULL)
		{
			q = p;
			if(x == p->info)
			{
				cout<<"DUPLICATE ENTRY FOUND\t----\t"<<x<<endl;
				return;
			}
			else if(x > p->info)
			{
				p = q->right;
			}
			else
			{
				p = q->left;
			}
		}
		if(x > q->info)
			q->right = Node;
		else
			q->left = Node;
		Node->parent = q;
		return ;
	}
}

int BST::LargestLevel(node * Node ,int Level)
{
	if(Node->left == NULL && Node->right == NULL)
	{
		return Level;
	}
	else if (Node->left == NULL)
	{
		return LargestLevel( Node->right , Level+1 );
	}
	else if (Node->right == NULL)
	{
		return LargestLevel( Node->left , Level+1 );
	}
	else
	{
		return max(LargestLevel( Node->right , Level+1 ) , LargestLevel( Node->left , Level+1 ));
	}
}

int BST::SmallestLevel(node * Node ,int Level)
{
	if(Node->left == NULL && Node->right == NULL)
	{
		return Level;
	}
	else if (Node->left == NULL)
	{
		return SmallestLevel( Node->right , Level+1 );
	}
	else if (Node->right == NULL)
	{
		return SmallestLevel( Node->left , Level+1 );
	}
	else
	{
		return min(SmallestLevel( Node->right , Level+1 ) , SmallestLevel( Node->left , Level+1 ));
	}
}

node * BST::LCA(int n1 , int n2)
{
	if(isEmpty())
	{
		cout<<"Tree is Empty."<<endl;
		return NULL;
	}
	if(Root->info == n1 || Root->info==n2 )
	{
		return Root;
	}
	node * NodePtr = Root;
	while(NodePtr)
	{
		if( NodePtr->info <= n2 && NodePtr->info >= n1 )
		{
			return NodePtr;
		}
		else if ( NodePtr->info <= n1 && NodePtr->info <= n2 )
		{
			NodePtr = NodePtr->right;
		}
		else //  NodePtr->info >= n1 && NodePtr->info >= n2
		{
			NodePtr = NodePtr->left;
		}
	}

	return NULL;
}

//Returns the path to the node starting from the node to the root....returns false if the value is not found in the tree 
bool PathToNode(node * Node , int x , vector<int> & v)
{
	if(Node->info == x)
	{
		v.push_back(Node->info);
		return true;
	}

	if(Node->left != NULL)
	{
		if( PathToNode( Node->left , x , v ) )
		{
			v.push_back( Node->info );
			return true;
		}
	}

	if(Node->right != NULL)
	{
		if( PathToNode( Node->right , x , v ) )
		{
			v.push_back( Node->info );
			return true;
		}
	}

	return false;
}

int diameterOpt(struct node *root, int* height)
{
 
  int lh = 0, rh = 0;
  
  int ldiameter = 0, rdiameter = 0;
  
  if(root == NULL)
  {
    *height = 0;
     return 0; 
  }
  
  /* Get the heights of left and right subtrees in lh and rh
    And store the returned values in ldiameter and ldiameter */
  ldiameter = diameterOpt(root->left, &lh);
  rdiameter = diameterOpt(root->right, &rh);
  
  /* Height of current node is max of heights of left and
     right subtrees plus 1*/
  *height = max(lh, rh) + 1;
  
  return max(lh + rh + 1, max(ldiameter, rdiameter));
}


// Printing LCA on the screen
int BST::LCA_GENERALTREE(int v , int w)
{
	// define two vectors for storing the paths from the node v and w to the root
	vector<int> v_Path; 
	vector<int> w_Path;

	if( !PathToNode(Root , v , v_Path) ) // if there is no path from the root to the node 'v'
	{
		cout<<v<<" Not Found in the Tree."<<endl<<"Please Try Again"<<endl;
		return 0;
	}
	if( !PathToNode(Root , w , w_Path) ) // if there is no path from the root to the node 'w'
	{
		cout<<w<<" Not Found in the Tree."<<endl<<"Please Try Again"<<endl;
		return 0;
	}

	// NOTE :- path is stored from starting from the node to the root
	// we'll reverse that path so that the vectors now store the path from the root to the required node
	reverse(v_Path.begin() , v_Path.end());
	reverse(w_Path.begin() , w_Path.end());

	// Define vector iterators for these vector(paths)
	vector<int>::iterator v_it = v_Path.begin(), w_it = w_Path.begin();
	
	// FOR DEBUGGING PURPOSE ONLY
	/*
	for(v_it;v_it!=v.end();v_it++)
		cout<<" "<<*v_it;
	for(w_it;w_it!=w.end();w_it++)
		cout<<" "<<*w_it;
	v_it = v.begin();
	w_it = w.begin();
	*/

	// LCA is the last common node in the two paths from root to 'v' and from root to 'w'

	// while both the vectors contain the same node , we can move to the next node
	while(*v_it == *w_it)
	{
		v_it++;
		w_it++;
	}

	//return the last node which is common
	return *(--v_it);
}

int BST::Diameter(node * Node , int *Height)
{
	// If the node is null , then the dia will be zero around that node
	if(Node == NULL)
	{
		*Height = 0;
		return 0;
	}

	// To store the diameter of left subtree and right subtree
	int LeftDia = 0 , RightDia = 0;

	//to store the heights of the left and right subtree while recursing
	int LeftHeight = 0 , RightHeight = 0;

	//	Recursion updates the left and right heights of the left and right subtrees of the node and returns the diameter of left and right subtree 
	LeftDia = Diameter(Node->left , &LeftHeight);
	RightDia = Diameter(Node->right , &RightHeight);

	// Height is the max of height of the left and right subtree
	*Height = max(LeftHeight , RightHeight) +1;

	// Diameter is the max of the diameter of left subtree , right subtree and the diameter which passes through the current node(i.e. left height + right height + 1 )
	return max(LeftHeight+RightHeight+1 , max(LeftDia , RightDia));
}