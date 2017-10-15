public class binary_search_tree {
	private int value;
	private binary_search_tree left;
	private binary_search_tree right;

	public binary_search_tree(int value) {
		this.value = value;
		this.left = null;
		this.right = null;
	}

	public String printInorder(binary_search_tree root) {
		String result = "";
		
		if(root.left != null) {
			result = result + root.printInorder(root.left);
		}

		result = result + root.value;

		if(root.right != null) {
			result = result + root.printInorder(root.right);
		}

		return result;
	}

	public int height(binary_search_tree root) {
		if(root == null) {
			return 0;
		}

		int left = 1 + root.height(root.left);
		int right = 1 + root.height(root.right);

		if(left > right) {
			return left;
		} else {
			return right;
		}
	}

	public String printPreorder(binary_search_tree root) {
		String result = "";
		
		result = result + root.value;
		
		if(root.left != null) {
			result = result + root.printPreorder(root.left);
		}

		if(root.right != null) {
			result = result + root.printPreorder(root.right);
		}

		return result;
	}

	public String printPostorder(binary_search_tree root) {
		String result = "";
		
		if(root.left != null) {
			result = result + root.printPostorder(root.left);
		}

		if(root.right != null) {
			result = result + root.printPostorder(root.right);
		}

		result = result + root.value;
		
		return result;
	}

	public binary_search_tree makeNode(int value) {
		binary_search_tree node = new binary_search_tree(value);
		return node;
	}

	public binary_search_tree addNode(binary_search_tree root, int value) {
		if(root == null) {
			root = root.makeNode(value);
		} else if(root.value == value) {
			return root;
		} else if(root.value > value) {
			if(root.left == null) {
				root.left = root.makeNode(value);
			} else {
				root.left = root.addNode(root.left, value);
			}
		} else if(root.value < value) {
			if(root.right == null) {
				root.right = root.makeNode(value);
			} else {
				root.right = root.addNode(root.right, value);
			}
		}

		return root;
	}

	public static void main(String []args) {
		binary_search_tree tree = null;
		tree = new binary_search_tree(5);
		tree = tree.addNode(tree, 3);
		tree = tree.addNode(tree, 2);
		tree = tree.addNode(tree, 4);
		tree = tree.addNode(tree, 7);
		tree = tree.addNode(tree, 6);
		tree = tree.addNode(tree, 8);

		System.out.println("Inorder: " + tree.printInorder(tree));
		System.out.println("Postorder: " + tree.printPostorder(tree));
		System.out.println("Preorder: " + tree.printPreorder(tree));
		System.out.println("Height: " + tree.height(tree));
	}
}
