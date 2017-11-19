/*
** The C++ Implementation of Binary Search Tree
**
** Binary Search Tree, is a node-based binary tree data 
** structure which has the following properties:
**
** - The left subtree of a node contains only nodes with 
** keys less than the node’s key.
** - The right subtree of a node contains only nodes with 
** keys greater than the node’s key.
** - The left and right subtree each must also be a binary 
** search tree.
*/

#include <iostream>

using std::cout;
using std::endl;

struct BinaryTreeNode
{
	int _value;

	BinaryTreeNode *_Left;
	BinaryTreeNode *_Right;

	BinaryTreeNode() : _value(0), _Left(nullptr), _Right(nullptr)
	{	}

	BinaryTreeNode(int value) : _value(value), _Left(nullptr), _Right(nullptr)
	{	}
};

class BST
{
public:
	BST() : _Root(nullptr), _count(0) {	}
	~BST() { Clear(_Root); }

	void Add(int);
	void Remove(int);
	int FindSmallest(void);
	void Clear(BinaryTreeNode *);
	bool Contains(int);
	int Count(void) { return _count; }

	BinaryTreeNode * Root(void) { return _Root; }

	void preOrder(BinaryTreeNode *);
	void postOrder(BinaryTreeNode *);
	void inOrder(BinaryTreeNode *);

private:
	int _count;
	BinaryTreeNode *_Root;

	void AddTo(BinaryTreeNode *, const int &);

	void RemoveFrom(BinaryTreeNode *, const int &);
	void RemoveRoot(void);
	void RemoveMatch(BinaryTreeNode *, BinaryTreeNode *, bool);

	int FindSmallestFrom(BinaryTreeNode *);
	
};

void BST::Add(int value)
{
	if (_Root == nullptr)
	{
		_Root = new BinaryTreeNode(value);
		_count++;
	}
	else
	{
		AddTo(_Root, value);
	}
}

void BST::AddTo(BinaryTreeNode *node, const int &value)
{
	if (value < node->_value)
	{
		if (node->_Left == nullptr)
		{
			node->_Left = new BinaryTreeNode(value);
			_count++;
		}
		else
		{
			AddTo(node->_Left, value);
		}
	}
	else
	{
		if (node->_Right == nullptr)
		{
			node->_Right = new BinaryTreeNode(value);
			_count++;
		}
		else
		{
			AddTo(node->_Right, value);
		}
	}
}

void BST::Remove(int value)
{
	RemoveFrom(_Root, value);
}

void BST::RemoveFrom(BinaryTreeNode *current, const int &value)
{
	if (current != nullptr)
	{
		if (current->_value == value)
			RemoveRoot();
		else
		{
			if (value < current->_value && current->_Left != nullptr)
			{
				current->_Left->_value == value ?
					RemoveMatch(current, current->_Left, true) :
					RemoveFrom(current->_Left, value);
			}
			else if (value > current->_value && current->_Right != nullptr)
			{
				current->_Right->_value == value ?
					RemoveMatch(current, current->_Right, false) :
					RemoveFrom(current->_Left, value);
			}
			else
				cout << "The value " << value << "wasn't found in the tree." << endl;
		}
	}
	else
		cout << "Tree is empty!" << endl;
}

void BST::RemoveRoot(void)
{
	if (_Root != nullptr)
	{
		BinaryTreeNode *current = _Root;
		int rootValue = _Root->_value;
		int smallestInRightSubtree = 0;

		// Case 0: The root has no children.
		if (_Root->_Left == nullptr && _Root->_Right == nullptr)
		{
			_Root = nullptr;
			delete current;
			--_count;
		}

		// Case 1: The root has only one child.
		else if (_Root->_Left != nullptr && _Root->_Right == nullptr)
		{
			_Root = _Root->_Left;
			current->_Left = nullptr;
			delete current;
			--_count;
			cout << "The root node with value " << rootValue << "was deleted." <<
					"The new root contains value - " << _Root->_value << endl;
		}
		else if (_Root->_Left == nullptr && _Root->_Right != nullptr)
		{
			_Root = _Root->_Right;
			current->_Right = nullptr;
			delete current;
			--_count;
			cout << "The root node with value " << rootValue << "was deleted." <<
					"The new root contains value - " << _Root->_value << endl;
		}

		//Case 2: The root has two children.
		else 
		{
			smallestInRightSubtree = FindSmallestFrom(_Root->_Right);
			RemoveFrom(_Root, smallestInRightSubtree);
			_Root->_value = smallestInRightSubtree;
			--_count;
			cout << "The root containing value " << rootValue <<
					" was overwritten with " << _Root->_value << endl;
		}
	}
	else
	{
		cout << "The tree is empty!" << endl;
	}
}

void BST::RemoveMatch(BinaryTreeNode *parent, BinaryTreeNode *match, bool left)
{
	if (_Root != nullptr)
	{
		BinaryTreeNode *current = new BinaryTreeNode();
		int matchValue = match->_value;
		int smallestInRightSubtree = 0;

		//Case 0 : The match node have no children.
		if (match->_Left == nullptr && match->_Right == nullptr)
		{
			current = match;
			left == true ? parent->_Left == nullptr : 
						   parent->_Right == nullptr;
			delete current;
			--_count;
			cout << "The node containing value " << matchValue <<
					" was removed" << endl;
		}

		// Case 1: Matching node has one child.
		else if (match->_Left != nullptr && match->_Right == nullptr)
		{
			left == true ? parent->_Left = match->_Left :
				parent->_Right = match->_Left;
			match->_Left = nullptr;
			current = match;
			delete current;
			--_count;
			cout << "The node containing value " << matchValue <<
				" was removed" << endl;
		}
		else if (match->_Left == nullptr && match->_Right != nullptr)
		{
			left == true ? parent->_Left = match->_Right :
						   parent->_Right = match->_Right;
			match->_Right = nullptr;
			current = match;
			delete current;
			--_count;
			cout << "The node containing value " << matchValue <<
					" was removed" << endl;
		}

		// Case 2: The matching node has two children.
		else
		{
			smallestInRightSubtree = FindSmallestFrom(match->_Right);
			RemoveFrom(match, smallestInRightSubtree);
			match->_value = smallestInRightSubtree;
		}
	}
	else
	{
		cout << "Can't remove match. The tree is empty!" << endl;
	}
}

int BST::FindSmallest(void)
{
	return FindSmallestFrom(_Root);
}

int BST::FindSmallestFrom(BinaryTreeNode *current)
{
	if (current == nullptr)
	{
		cout << "The tree is empty!" << endl;
		return -1;
	}
	else
	{
		if (current->_Left != nullptr)
			return FindSmallestFrom(current->_Left);
		else
			return current->_value;
	}

}

bool BST::Contains(int value)
{
	BinaryTreeNode *current = new BinaryTreeNode();
	current = _Root;
	while (current != nullptr)
	{
		if (value < current->_value)
			current = current->_Left;
		else if (value > current->_value)
			current = current->_Right;
		else
			break;
	}
	return current == nullptr ? false : true;
}

void BST::Clear(BinaryTreeNode *node)
{
	if (node != nullptr)
	{
		Clear(node->_Left);
		Clear(node->_Right);
		delete node;
	}
}

void BST::preOrder(BinaryTreeNode *node)
{
	if (node != nullptr)
	{
		cout << node->_value << " ";
		preOrder(node->_Left);
		preOrder(node->_Right);
	}
}

void BST::postOrder(BinaryTreeNode *node)
{
	if (node != nullptr)
	{
		postOrder(node->_Left);
		postOrder(node->_Right);
		cout << node->_value << " ";
	}
}

void BST::inOrder(BinaryTreeNode *node)
{
	if (node != nullptr)
	{
		inOrder(node->_Left);
		cout << node->_value << " ";
		inOrder(node->_Right);
	}
}

int main()
{
/* Let's create the following BST
**				 4
**              / \
**			   2   5
**			  / \   \
**			 1   3	 7
**					/ \
**				   6   8
*/
	BST *tree = new BST();
	tree->Add(4);
	tree->Add(2);
	tree->Add(1);
	tree->Add(3);
	tree->Add(5);
	tree->Add(7);
	tree->Add(6);
	tree->Add(8);

	cout << "PreOrder Traversal: ";
	tree->preOrder(tree->Root());
	cout << endl;

	cout << "PostOrder Traversal: ";
	tree->postOrder(tree->Root());
	cout << endl;

	cout << "InOrder Traversal: ";
	tree->inOrder(tree->Root());
	cout << endl;

	cout << "The smallest value in the tree is " << 
			tree->FindSmallest() << endl;
	
	tree->Remove(5);
	/* The tree after removing node with value 5
	**				  4
	**              /   \
	**			   2     7
	**			  / \   / \
	**			 1   3 6   8
	*/

	delete tree;
	return 0;
}