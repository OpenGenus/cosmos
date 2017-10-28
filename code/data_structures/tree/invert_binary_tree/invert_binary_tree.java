/* Part of Cosmos by OpenGenus Foundation */

import java.util.LinkedList;
import java.util.Queue;

/**
 * Java program to invert a Binary Tree
 */
class Node<T>{
    T val;
    Node left;
    Node right;
    Node(T x) { val = x; }
}

class InvertBinaryTree {

    public Node root;

    public void invert() {
        invertTree(root);
    }

    /**
     * Invert BinaryTree by DFS
     * @param root
     */
    private void invertTree(Node root) {
        if (root == null || (root.left == null && root.right == null)) return;
        Node t = root.left;
        root.left = root.right;
        root.right = t;
        invertTree(root.left);
        invertTree(root.right);
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        Queue<Node> que = new LinkedList<>();
        que.add(root);
        int count = 0;
        while (!que.isEmpty()){
            count++;
            Node node = que.poll();
            builder.append(node.val + " ");
            if ((count + 1 & (count)) == 0) builder.append("\n");
            if (node.left != null) que.add(node.left);
            if (node.right != null) que.add(node.right);
        }
        return builder.toString();
    }

    public static void main(String[] args) {
        /* Example
        
        *      4
        *    /   \
        *   2     7
        *  / \   / \
        * 1   3 6   9
        *
        * to
        *
        *      4
        *    /   \
        *   7     2
        *  / \   / \
        * 9   6 3   1
        *
        * */
        InvertBinaryTree tree = new InvertBinaryTree();
        tree.root = new Node(4);
        tree.root.left = new Node(2);
        tree.root.left.left = new Node(1);
        tree.root.left.right = new Node(3);
        tree.root.right = new Node(7);
        tree.root.right.left = new Node(6);
        tree.root.right.right = new Node(9);

        System.out.println("revert:");
        System.out.println(tree);

        tree.invert(); //The tree will be inverted

        System.out.println("to:");
        System.out.println(tree);
    }
}
