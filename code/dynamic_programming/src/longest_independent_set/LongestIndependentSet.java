
public class LongestIndependentSet {

  static class node { 
    int data, liss; 
    node left, right; 

    public node(int data)  
    { 
      this.data = data; 
      this.liss = 0; 
    } 
  } 

  static int longestIndependentSet(node root) { 
    
    if (root == null) 
      return 0; 
    
    if (root.liss != 0) 
      return root.liss; 
    
    if (root.left == null && root.right == null) 
      return root.liss = 1; 

    int liss_excl = liss(root.left) + liss(root.right); 

    int liss_incl = 1; 
    if (root.left != null){ 
      liss_incl += (liss(root.left.left) + liss(root.left.right)); 
    } 

    if (root.right != null){ 
      liss_incl += (liss(root.right.left) + liss(root.right.right)); 
    } 

    return root.liss = Math.max(liss_excl, liss_incl); 
  } 
}
