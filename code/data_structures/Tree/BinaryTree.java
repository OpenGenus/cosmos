/* Part of Cosmos by OpenGenus Foundation */
import java.util.ArrayList;

class BinaryTree<T extends Comparable<T>>{
	private Node<T> root;

	public BinaryTree(){
		root = null;
	}
	
	private Node<T> find(T key){
		Node<T> current = root;
		Node<T> last = root;
		while(current != null){
			last = current;
			if(key.compareTo(current.data) < 0)
				current = current.left;
			else if(key.compareTo(current.data) > 0)
				current = current.right;
			//If you find the value return it
			else
				return current;
		}
		return last;
	}

	public void put(T value){
		Node<T> newNode = new Node<>(value);
		if(root == null)
			root = newNode;
		else{
			//This will return the soon to be parent of the value you're inserting
			Node<T> parent = find(value);

			//This if/else assigns the new node to be either the left or right child of the parent
			if(value.compareTo(parent.data) < 0){
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

	public boolean remove(T value){
		//temp is the node to be deleted
		Node<T> temp = find(value);

		//If the value doesn't exist
		if(temp.data != value)
			return false;

		//No children
		if(temp.right == null && temp.left == null){
			if(temp == root)
				root = null;

			//This if/else assigns the new node to be either the left or right child of the parent
			else if(temp.parent.data.compareTo(temp.data) < 0)
				temp.parent.right = null;
			else
				temp.parent.left = null;
			return true;
		}

		//Two children
		else if(temp.left != null && temp.right != null){
			Node<T> successor = findSuccessor(temp);

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
				if(temp.parent.data.compareTo(temp.data) < 0)
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
				if(temp.data.compareTo(temp.parent.data) < 0)
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
				if(temp.data.compareTo(temp.parent.data) < 0)
					temp.parent.left = temp.left;
				else
					temp.parent.right = temp.left;
				return true;
			}
		}
	}

	private Node<T> findSuccessor(Node<T> n){
		if(n.right == null)
			return n;
		Node<T> current = n.right;
		Node<T> parent = n.right;
		while(current != null){
			parent = current;
			current = current.left;
		}
		return parent;
	}

	public T getRoot(){
			return root.data;
	}

	public String toString()
	{
		return inOrder(root).toString();
	}

	private ArrayList<T> inOrder(Node<T> localRoot){
		ArrayList<T> temp = new ArrayList<>();
		if(localRoot != null){
			inOrder(localRoot.left);
			temp.add(localRoot.data);
			//System.out.print(localRoot.data + " ");
			inOrder(localRoot.right);
		}
		return temp;
	}
	
	private void preOrder(Node<T> localRoot){
		if(localRoot != null){
			System.out.print(localRoot.data + " ");
			preOrder(localRoot.left);
			preOrder(localRoot.right);
		}
	}
	
	private void postOrder(Node<T> localRoot){
		if(localRoot != null){
			postOrder(localRoot.left);
			postOrder(localRoot.right);
			System.out.print(localRoot.data + " ");
		}
	}

	private class Node<T extends Comparable<T>>{
		public T data;
		public Node<T> left;
		public Node<T> right;
		public Node<T> parent;

		public Node(T value){
			data = value;
			left = null;
			right = null;
			parent = null;
		}
	}
}
