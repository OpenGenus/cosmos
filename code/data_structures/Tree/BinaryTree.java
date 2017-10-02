/* Part of Cosmos by OpenGenus Foundation */

class Node{
	public int data;
	public Node left;
	public Node right;
	public Node parent;

	public Node(int value){
		data = value;
		left = null;
		right = null;
		parent = null;
	}
}

class Tree{
	private Node root;

	public Tree(){
		root = null;
	}
	
	public Node find(int key){
		Node current = root;
		Node last = root;
		while(current != null){
			last = current;
			if(key < current.data)
				current = current.left;
			else if(key > current.data)
				current = current.right;
			//If you find the value return it
			else
				return current;
		}
		return last;
	}

	public void put(int value){
		Node newNode = new Node(value);
		if(root == null)
			root = newNode;
		else{
			//This will return the soon to be parent of the value you're inserting
			Node parent = find(value);

			//This if/else assigns the new node to be either the left or right child of the parent
			if(value < parent.data){
				parent.left = newNode;
				parent.left.parent = parent;
				return;
			}
			else{
				parent.right = newNode;
				parent.right.parent = parent;
				return;
			}
		}
	}

	public boolean remove(int value){
		//temp is the node to be deleted
		Node temp = find(value);

		//If the value doesn't exist
		if(temp.data != value)
			return false;

		//No children
		if(temp.right == null && temp.left == null){
			if(temp == root)
				root = null;

			//This if/else assigns the new node to be either the left or right child of the parent
			else if(temp.parent.data < temp.data)
				temp.parent.right = null;
			else
				temp.parent.left = null;
			return true;
		}

		//Two children
		else if(temp.left != null && temp.right != null){
			Node successor = findSuccessor(temp);

			//The left tree of temp is made the left tree of the successor
			successor.left = temp.left;
			successor.left.parent = successor;

			//If the successor has a right child, the child's grandparent is it's new parent
			if(successor.right != null && successor.parent != temp){
				successor.right.parent = successor.parent;
				successor.parent.left = successor.right;
				successor.right = temp.right;
				successor.right.parent = successor;
			}
			if(temp == root){
				successor.parent = null;
				root = successor;
				return true;
			}

			//If you're not deleting the root
			else{
				successor.parent = temp.parent;

				//This if/else assigns the new node to be either the left or right child of the parent
				if(temp.parent.data < temp.data)
					temp.parent.right = successor;
				else
					temp.parent.left = successor;
				return true;
			}
		}
		//One child
		else{
			//If it has a right child
			if(temp.right != null){
				if(temp == root){
					root = temp.right; return true;}

				temp.right.parent = temp.parent;

				//Assigns temp to left or right child
				if(temp.data < temp.parent.data)
					temp.parent.left = temp.right;
				else
					temp.parent.right = temp.right;
				return true;
			}
			//If it has a left child
			else{
				if(temp == root){
					root = temp.left; return true;}

				temp.left.parent = temp.parent;

				//Assigns temp to left or right side
				if(temp.data < temp.parent.data)
					temp.parent.left = temp.left;
				else
					temp.parent.right = temp.left;
				return true;
			}
		}
	}

	public Node findSuccessor(Node n){
		if(n.right == null)
			return n;
		Node current = n.right;
		Node parent = n.right;
		while(current != null){
			parent = current;
			current = current.left;
		}
		return parent;
	}

	public Node getRoot(){
			return root;
	}

	public void inOrder(Node localRoot){
		if(localRoot != null){
			inOrder(localRoot.left);
			System.out.print(localRoot.data + " ");
			inOrder(localRoot.right);
		}
	}
	
	public void preOrder(Node localRoot){
		if(localRoot != null){
			System.out.print(localRoot.data + " ");
			preOrder(localRoot.left);
			preOrder(localRoot.right);
		}
	}
	
	public void postOrder(Node localRoot){
		if(localRoot != null){
			postOrder(localRoot.left);
			postOrder(localRoot.right);
			System.out.print(localRoot.data + " ");
		}
	}
}
