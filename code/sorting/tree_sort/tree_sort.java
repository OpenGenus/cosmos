// Part of Cosmos by OpenGenus Foundation

public class Tree {

    public static void main(String[] args) {
        TreeSort myTree;
        myTree = new TreeSort(4);

        myTree.invert(new TreeSort(5));
        myTree.invert(new TreeSort(8));
        myTree.invert(new TreeSort(1));
        myTree.traverse(new KeyPrint());
    }
    
    static class TreeSort {
        private TreeSort left;
        private TreeSort right;
        private int key;

        public TreeSort(int key) {
            this.key = key;
        }

        private void invert(TreeSort node) {
            if (node.key < key) {
                if (left != null) left.invert(node);
                else {
                    left = node;
                }
            } else {
                if (right != null) right.invert(node);
                else {
                    right = node;
                }
            }
        }

        private void traverse(TreeVisitor visitor) {
            if (left != null)
                left.traverse(visitor);

            visitor.visit(this);

            if (right != null)
                right.traverse(visitor);
        }
    }

    interface TreeVisitor {
        void visit(TreeSort node);
    }

    static class KeyPrint implements TreeVisitor {
        public void visit(TreeSort node) {
            System.out.println(" " + node.key);
        }
    }
}
