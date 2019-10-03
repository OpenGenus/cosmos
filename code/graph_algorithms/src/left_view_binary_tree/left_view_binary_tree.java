// Part of Cosmos by OpenGenus Foundation
// This class prints the left nodes of a binary tree
class Node {
    int  data;
    Node left;
    Node right;  
    
    public Node(int node) {
        data = node;
        left = right = null;
    }
}

class BinaryTree {
    Node root; // Define root node
    int max_level = 0; // Define max level
 
    // Recursive function that prints left nodes of tree
    void printLeftView(Node node, int cur_level) {
        if (node == null) return;      

        if (max_level < cur_level) {
            System.out.print(node.data + " ");
            max_level = cur_level; 
        }
 
        // Recurisely traverse along the left and right nodes of child node
        printLeftView(node.left, cur_level + 1);
        printLeftView(node.right, cur_level + 1);
    }

    void leftView() {
        printLeftView(root, 1);
    }
 
    public static void main(String args[]) {
        // Binary tree test
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);
        tree.root.right.left = new Node(6);
        tree.root.right.right = new Node(7);
        tree.root.left.left.left = new Node(8);
        System.out.print("Left nodes of binary tree: ");
        tree.leftView();     
    }
}