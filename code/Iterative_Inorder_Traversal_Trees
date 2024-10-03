class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> inorder = new ArrayList<Integer>(); 
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode node = root;
        while(true){
            if(node != null){
                stack.push(node);
                node = node.left;
            }
            else{
                if(stack.isEmpty()){
                    break;
                }
                node = stack.pop();
                inorder.add(node.val);
                node = node.right;
            }
        }
        return inorder; 
    }
}
