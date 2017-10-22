class TreeNode<T>
{
	T data;
	TreeNode<T> left,right;
	public TreeNode(T data)
	{
		this.data = data;
	}
}

public class BinaryTree {

	public static <T> int minHeight(TreeNode<T> root)
	{
		if(root == null)
			return 0;
		
		return Math.min(minHeight(root.left), minHeight(root.right)) + 1;
	}
	
	public static void main(String[] args) {
		TreeNode<Integer> root = new TreeNode<Integer>(1);
		root.left = new TreeNode<Integer>(2);
		root.right = new TreeNode<Integer>(3);
		root.left.left = new TreeNode<Integer>(4);
		root.left.right = new TreeNode<Integer>(5);
		root.right.left = new TreeNode<Integer>(6);
		
		System.out.println(minHeight(root));

	}

}
