public class ConvertToMirrorTree {
    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.left.right.right = new Node(6);
        root.right.right = new Node(7);
        root.right.right.right = new Node(8);
        //doing inorder traversal because
        //inorder traversal of two mirror trees is reverse of each other.
        inOrderTraversal(root);
        System.out.println();
        convertToMirror(root);
        inOrderTraversal(root);
    }

    public static void inOrderTraversal(Node root){
        //doing postorder traversal of tree
        if(root == null){
            return;
        }
        inOrderTraversal(root.left);
        System.out.print(root.data+" ");
        inOrderTraversal(root.right);
    }

    public static void convertToMirror(Node node){
        if(node == null){
            return;
        }
        convertToMirror(node.left);
        convertToMirror(node.right);
        Node temp = node.left;
        node.left = node.right;
        node.right = temp;
    }
}

class Node{
    int data;
    Node left;
    Node right;

    Node(int data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}
