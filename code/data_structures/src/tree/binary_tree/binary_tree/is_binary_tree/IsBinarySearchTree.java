public class IsBinarySearchTree {
    public static void main(String[] args) {
        Node root = null;
        root = BinarySearchTreeUtilities.insertNode(root,20);
        root = BinarySearchTreeUtilities.insertNode(root,15);
        root = BinarySearchTreeUtilities.insertNode(root,25);
        root = BinarySearchTreeUtilities.insertNode(root,30);
        root = BinarySearchTreeUtilities.insertNode(root,2);
        root = BinarySearchTreeUtilities.insertNode(root,18);
        root = BinarySearchTreeUtilities.insertNode(root,22);
        System.out.println(isBST(root));
    }

    public static boolean isBST(Node root){
        return isBSTUtil(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    public static boolean isBSTUtil(Node root,int minValue,int maxValue){
        if(root==null){
            return true;
        }
        if(root.data>=minValue && root.data<maxValue && isBSTUtil(root.left,minValue,root.data) && isBSTUtil(root.right,root.data,maxValue)){
            return true;
        }
        return false;
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

class BinarySearchTreeUtilities{
    public static Node getNewNode(int data){
        Node node = new Node(data);
        return node;
    }

    public static Node insertNode(Node root, int data){
        if(root==null){
            root = getNewNode(data);
        }
        else if(data<=root.data){
            root.left = insertNode(root.left,data);
        }
        else{
            root.right = insertNode(root.right,data);
        }
        return root;
    }
}