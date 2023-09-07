public class Tree {
    Node root;
    Tree() {
        root = null;
    }
    class Node {
        int key;
        Node left, right;

        public Node(int k) {
            key = k;
            right = left = null;
        }

        public void displayData() {
            System.out.print(key +" ");
        }
    }

    public void insert(int i) {
        root = insert(root,i);
    }

    public Node insert(Node node, int val) {
        if(node == null)
            return new Node(val);

        if(val < node.key)
            node.left = insert(node.left, val);
        else if(val > node.key)
            node.right = insert(node.right, val);

        return node;
    }

    public Node find(int searchVal) {
        Node current = root;
        while(current.key!=searchVal) {
            if(searchVal < current.key)
                current = current.left;
            else
                current = current.right;

            if(current == null)
                return null;
        }
        return current;
    }

    public void inOrder(Node node) {
        if(node != null) {
            inOrder(node.left);
            node.displayData();
            inOrder(node.right);
        }
    }

    public void preOrder(Node node) {
        if(node != null) {
            node.displayData();
            preOrder(node.left);
            preOrder(node.right);
        }
    }

    public void postOrder(Node node){
        if(node != null){
            postOrder(node.left);
            postOrder(node.right);
            node.displayData();
        }
    }

    public static void main(String[] args) {
        Tree bt = new Tree();
        bt.insert(50);
        bt.insert(70);
        bt.insert(15);
        bt.insert(35);
        bt.insert(30);
        bt.insert(31);

        System.out.println("Inorder traversal of Binary Tree:");
        bt.inOrder(bt.root);
        System.out.println();

        System.out.println("PreOrder traversal of Binary Tree:");
        bt.preOrder(bt.root);
        System.out.println();

        System.out.println("PostOrder traversal of Binary Tree:");
        bt.postOrder(bt.root);
    }
}
