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
	int value;

	BinaryTreeNode *Left;
	BinaryTreeNode *Right;

	BinaryTreeNode() : value(0), Left(nullptr), Right(nullptr) { }

	BinaryTreeNode(int value) : value(value), Left(nullptr), Right(nullptr) { }
};

class BST
{
public:
	BST() : Root_(nullptr), count_(0) {	}
	~BST() { Clear(Root_); }

	void Add(int);
	void Remove(int);
	int FindSmallest();
	void Clear(BinaryTreeNode *);
	bool Contains(int);
	int Count() { return count_; }

	BinaryTreeNode * Root() { return Root_; }

	void preOrder(BinaryTreeNode *);
	void postOrder(BinaryTreeNode *);
	void inOrder(BinaryTreeNode *);

private:
	int count_;
	BinaryTreeNode *Root_;
	void AddTo(BinaryTreeNode *, const int &);

	void RemoveFrom(BinaryTreeNode *, const int &);
	void RemoveRoot();
	void RemoveMatch(BinaryTreeNode *, BinaryTreeNode *, bool);

	int FindSmallestFrom(BinaryTreeNode *);
	
};

void BST::Add(int value)
{
	if (Root_ == nullptr)
	{
		Root_ = new BinaryTreeNode(value);
		++count_;
	}
	else
	{
		AddTo(Root_, value);
	}
}

void BST::AddTo(BinaryTreeNode *node, const int &value)
{
	if (value < node->value)
	{
		if (node->Left == nullptr)
		{
			node->Left = new BinaryTreeNode(value);
			++count_;
		}
		else
		{
			AddTo(node->Left, value);
		}
	}
	else
	{
		if (node->Right == nullptr)
		{
			node->Right = new BinaryTreeNode(value);
			++count_;
		}
		else
		{
			AddTo(node->Right, value);
		}
	}
}

void BST::Remove(int value)
{
	RemoveFrom(Root_, value);
}

void BST::RemoveFrom(BinaryTreeNode *current, const int &value)
{
	if (current != nullptr)
	{
		if (current->value == value)
			RemoveRoot();
		else
		{
			if (value < current->value && current->Left != nullptr)
			{
				current->Left->value == value ?
					RemoveMatch(current, current->Left, true) :
					RemoveFrom(current->Left, value);
			}
			else if (value > current->value && current->Right != nullptr)
			{
				current->Right->value == value ?
					RemoveMatch(current, current->Right, false) :
					RemoveFrom(current->Left, value);
			}
			else
				cout << "The value " << value << "wasn't found in the tree." << endl;
		}
	}
	else
		cout << "Tree is empty!" << endl;
}

void BST::RemoveRoot()
{
	if (Root_ != nullptr)
	{
		BinaryTreeNode *current = Root_;
		int rootValue = Root_->value;
		int smallestInRightSubtree = 0;

		// Case 0: The root has no children.
		if (Root_->Left == nullptr && Root_->Right == nullptr)
		{
			Root_ = nullptr;
			delete current;
			--count_;
		}

		// Case 1: The root has only one child.
		else if (Root_->Left != nullptr && Root_->Right == nullptr)
		{
			Root_ = Root_->Left;
			current->Left = nullptr;
			delete current;
			--count_;
			cout << "The root node with value " << rootValue << "was deleted." <<
					"The new root contains value - " << Root_->value << endl;
		}
		else if (Root_->Left == nullptr && Root_->Right != nullptr)
		{
			Root_ = Root_->Right;
			current->Right = nullptr;
			delete current;
			--count_;
			cout << "The root node with value " << rootValue << "was deleted." <<
					"The new root contains value - " << Root_->value << endl;
		}

		//Case 2: The root has two children.
		else 
		{
			smallestInRightSubtree = FindSmallestFrom(Root_->Right);
			RemoveFrom(Root_, smallestInRightSubtree);
			Root_->value = smallestInRightSubtree;
			--count_;
			cout << "The root containing value " << rootValue <<
					" was overwritten with " << Root_->value << endl;
		}
	}
	else
		cout << "The tree is empty!" << endl;
}

void BST::RemoveMatch(BinaryTreeNode *parent, BinaryTreeNode *match, bool left)
{
	if (Root_ != nullptr)
	{
		BinaryTreeNode *current = new BinaryTreeNode();
		int matchValue = match->value;
		int smallestInRightSubtree = 0;

		//Case 0 : The match node have no children.
		if (match->Left == nullptr && match->Right == nullptr)
		{
			current = match;
			left == true ? parent->Left == nullptr : 
						   parent->Right == nullptr;
			delete current;
			--count_;
			cout << "The node containing value " << matchValue <<
					" was removed" << endl;
		}

		// Case 1: Matching node has one child.
		else if (match->Left != nullptr && match->Right == nullptr)
		{
			left == true ? parent->Left = match->Left :
						   parent->Right = match->Left;
			match->Left = nullptr;
			current = match;
			delete current;
			--count_;
			cout << "The node containing value " << matchValue <<
				" was removed" << endl;
		}
		else if (match->Left == nullptr && match->Right != nullptr)
		{
			left == true ? parent->Left = match->Right :
						   parent->Right = match->Right;
			match->Right = nullptr;
			current = match;
			delete current;
			--count_;
			cout << "The node containing value " << matchValue <<
					" was removed" << endl;
		}

		// Case 2: The matching node has two children.
		else
		{
			smallestInRightSubtree = FindSmallestFrom(match->Right);
			RemoveFrom(match, smallestInRightSubtree);
			match->value = smallestInRightSubtree;
		}
	}
	else
		cout << "Can't remove match. The tree is empty!" << endl;
}

int BST::FindSmallest()
{
	return FindSmallestFrom(Root_);
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
		if (current->Left != nullptr)
			return FindSmallestFrom(current->Left);
		else
			return current->value;
	}

}

bool BST::Contains(int value)
{
	BinaryTreeNode *current = new BinaryTreeNode();
	current = Root_;
	while (current)
	{
		if (value < current->value)
			current = current->Left;
		else if (value > current->value)
			current = current->Right;
		else
			break;
	}
	return current ? true : false;
}

void BST::Clear(BinaryTreeNode *node)
{
	if (node != nullptr)
	{
		Clear(node->Left);
		Clear(node->Right);
		delete node;
	}
}

void BST::preOrder(BinaryTreeNode *node)
{
	if (node != nullptr)
	{
		cout << node->value << " ";
		preOrder(node->Left);
		preOrder(node->Right);
	}
}

void BST::postOrder(BinaryTreeNode *node)
{
	if (node != nullptr)
	{
		postOrder(node->Left);
		postOrder(node->Right);
		cout << node->value << " ";
	}
}

void BST::inOrder(BinaryTreeNode *node)
{
	if (node != nullptr)
	{
		inOrder(node->Left);
		cout << node->value << " ";
		inOrder(node->Right);
	}
}

int main()
{
	//	Let's create the following BST
	//			 4
	//          / \
	//		   2   5
	//		  / \   \
	//		 1   3	 7
	//				/ \
	//			   6   8

	BST tree;
	tree.Add(4);
	tree.Add(2);
	tree.Add(1);
	tree.Add(3);
	tree.Add(5);
	tree.Add(7);
	tree.Add(6);
	tree.Add(8);

	cout << "PreOrder Traversal: ";
	tree.preOrder(tree.Root());
	cout << endl;

	cout << "PostOrder Traversal: ";
	tree.postOrder(tree.Root());
	cout << endl;

	cout << "InOrder Traversal: ";
	tree.inOrder(tree.Root());
	cout << endl;

	cout << "The smallest value in the tree is " << 
			tree.FindSmallest() << endl;
	
	tree.Remove(5);
	//The tree after removing node with value 5
	//				  4
	//              /   \
	//			   2     7
	//			  / \   / \
	//			 1   3 6   8
	

	return 0;
}