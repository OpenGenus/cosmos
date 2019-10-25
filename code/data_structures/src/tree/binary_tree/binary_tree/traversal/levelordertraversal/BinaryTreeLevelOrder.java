import java.util.LinkedList;
import java.util.Queue;

public class BinaryTreeLevelOrder {
    BinaryTreeNode root;

    BinaryTreeLevelOrder() {
    }

    BinaryTreeLevelOrder(int d) {
        root = new BinaryTreeNode(d);
    }
    /* Height of Tree
     */
    int heightTree(BinaryTreeNode root) {
        if(root == null) return 0;
        int leftHeight = heightTree(root.left);
        int rightHeight = heightTree(root.right);
        if(leftHeight > rightHeight)
            return 1+leftHeight;
        else return 1+rightHeight;
    }

    /* levelOrderUtil
     */
    private void levelOrderUtil(BinaryTreeNode root, int level) {
        if(root == null) return;
        if(level == 1) System.out.print(root.data + " ");
        levelOrderUtil(root.left, level - 1);
        levelOrderUtil(root.right, level - 1);
    }

    /* levelOrder traversal with recursion
     */
    public void levelOrder(BinaryTreeNode root) {
        int heightOfTree = heightTree(root);
        for(int level = 1; level <= heightOfTree; level++)
            levelOrderUtil(root,level);
    }

    /* levelOrder traversal level by level with recursion
     */
    public void levelOrderLevelByLevel(BinaryTreeNode root) {

        int heightOfTree = heightTree(root);
        for(int level = 1; level <= heightOfTree; level++)
        {
            levelOrderUtil(root, level);
            System.out.println();
        }
    }

    /* Iterative levelOrder traversal using one queue
     */
    public void levelOrderIterativeOneQueue(BinaryTreeNode root) {
        Queue<BinaryTreeNode> queue = new LinkedList<BinaryTreeNode>();
        queue.add(root);
        while (!queue.isEmpty())
        {
            BinaryTreeNode temp = queue.poll();
            System.out.print(temp.data + " ");
            if(temp.left != null) queue.add(temp.left);
            if(temp.right != null) queue.add(temp.right);
        }
    }

    /* Iterative level-by-level levelOrder traversal util function using Two queue
     */
    private void levelOrderIterativeLevelByLevelUtil(Queue<BinaryTreeNode> queue1, Queue<BinaryTreeNode> queue2) {
        while (!queue1.isEmpty()) {
            BinaryTreeNode temp = queue1.poll();
            System.out.print(temp.data + " ");
            if (temp.left != null) queue2.add(temp.left);
            if (temp.right != null) queue2.add(temp.right);
        }
    }

    /* Iterative level-by-level levelOrder traversal using Two queue
     */
    public void levelOrderIterativeLevelByLevelTwoQueue(BinaryTreeNode root) {
        Queue<BinaryTreeNode>  queue1 = new LinkedList<BinaryTreeNode>();
        Queue<BinaryTreeNode>  queue2 = new LinkedList<BinaryTreeNode>();
        queue1.add(root);
        while (!queue1.isEmpty() || !queue2.isEmpty()) {
            levelOrderIterativeLevelByLevelUtil(queue1,queue2);
            System.out.println();
            levelOrderIterativeLevelByLevelUtil(queue2,queue1);
            System.out.println();
        }
    }

    /* Iterative level-by-level levelOrder traversal using Two queue
     */
    public void levelOrderIterativeLevelByLevelUsingOneQueue(BinaryTreeNode root) {
        Queue<BinaryTreeNode>  queue = new LinkedList<BinaryTreeNode>();
        queue.add(root);
        while (!queue.isEmpty()) {
            int levelNo = queue.size();
            while (levelNo > 0) {
                BinaryTreeNode temp = queue.poll();
                System.out.print(temp.data + " ");
                if (temp.left != null) queue.add(temp.left);
                if (temp.right != null) queue.add(temp.right);
                levelNo--;
            }
            System.out.println();
        }
    }
}
