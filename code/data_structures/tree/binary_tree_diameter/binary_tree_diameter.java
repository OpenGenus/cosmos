//Diameter of binary tree using java
class Node
{
	int data;
	Node left, right;

	Node(int i)
	{
		data = i;
		left = right = null;
	}
}

class Height
{
	int h;
}

class BinaryTreeDiameter
{
	Node root;

	//Function to calculate diameter
	int calldiameter(Node root, Height height)
	{
		Height l = new Height();//height of left sub-tree
		Height r = new Height();//height of right sub-tree

		if (root == null)
		{
			height.h = 0;
			return 0; 
		}
	
		int ld = calldiameter(root.left, l);//diameter of left-subtree
		int rd = calldiameter(root.right, r);//diameter of right-subtree

		//Height of current node is max(left height,right height)+1
		height.h = Math.max(l.h,r.h) + 1;

		return Math.max(l.h + r.h + 1, Math.max(ld, rd));
	}


	int diameter()
	{
		Height height = new Height();
		return calldiameter(root, height);
	}

	//Function to calculate height of tree
	static int height(Node node)
	{
		//tree is empty
		if (node == null)
			return 0;

		//If  not empty then height = 1 + max(left height,right height)
		return (1 + Math.max(height(node.left), height(node.right)));
	}

	public static void main(String args[])
	{
		//Creating a binary tree
		BinaryTreeDiameter t = new BinaryTreeDiameter();
		t.root = new Node(1);
		t.root.left = new Node(3);
		t.root.right = new Node(2);
		t.root.left.left = new Node(7);
		t.root.left.right = new Node(6);
                        t.root.right.left = new Node(5);
		t.root.right.right = new Node(4);
		t.root.left.left.right = new Node(10);
                        t.root.right.left.left = new Node(9);
		t.root.right.left.right = new Node(8);
		

		System.out.println("The Diameter of given binary tree is : "+ t.diameter());
	}
}

/*Input:
             1
           /   \  
          3      2  
        /  \    /  \
       7    6  5   4
        \     / \
        10   9   8
*/
/*Output:
The Diameter of given binary tree is : 7
*/
