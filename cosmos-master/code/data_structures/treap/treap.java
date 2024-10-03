/**
 *  Part of Cosmos by OpenGenus Foundation
 **/
 
 import java.util.Scanner;
 import java.util.Random;
 
 /** Class TreapNode **/
 class TreapNode
 {
     TreapNode left, right;
     int priority, element;
 
     /** Constructor **/    
     public TreapNode()
     {
         this.element = 0;
         this.left = this;
         this.right = this;
         this.priority = Integer.MAX_VALUE;
     }    
 
     /** Constructor **/    
     public TreapNode(int ele)
     {
         this(ele, null, null);
     } 
 
     /** Constructor **/
     public TreapNode(int ele, TreapNode left, TreapNode right)
     {
         this.element = ele;
         this.left = left;
         this.right = right;
         this.priority = new Random().nextInt( );
     }    
 }
 
 /** Class TreapTree **/
 class TreapTree
 {
     private TreapNode root;
     private static TreapNode nil = new TreapNode();
 
     /** Constructor **/
     public TreapTree()
     {
         root = nil;
     }
 
     /** Function to check if tree is empty **/
     public boolean isEmpty()
     {
         return root == nil;
     }
 
     /** Make the tree logically empty **/
     public void makeEmpty()
     {
         root = nil;
     }
 
     /** Functions to insert data **/
     public void insert(int X)
     {
         root = insert(X, root);
     }
     private TreapNode insert(int X, TreapNode T)
     {
         if (T == nil)
             return new TreapNode(X, nil, nil);
         else if (X < T.element)
         {
             T.left = insert(X, T.left);
             if (T.left.priority < T.priority)
             {
                  TreapNode L = T.left;
                  T.left = L.right;
                  L.right = T;
                  return L;
              }    
         }
         else if (X > T.element)
         {
             T.right = insert(X, T.right);
             if (T.right.priority < T.priority)
             {
                 TreapNode R = T.right;
                  T.right = R.left;
                  R.left = T;
                  return R;
             }
         }
         return T;
     }
 
     /** Functions to count number of nodes **/
     public int countNodes()
     {
         return countNodes(root);
     }
     private int countNodes(TreapNode r)
     {
         if (r == nil)
             return 0;
         else
         {
             int l = 1;
             l += countNodes(r.left);
             l += countNodes(r.right);
             return l;
         }
     }
 
     /** Functions to search for an element **/
     public boolean search(int val)
     {
         return search(root, val);
     }
     private boolean search(TreapNode r, int val)
     {
         boolean found = false;
         while ((r != nil) && !found)
         {
             int rval = r.element;
             if (val < rval)
                 r = r.left;
             else if (val > rval)
                 r = r.right;
             else
             {
                 found = true;
                 break;
             }
             found = search(r, val);
         }
         return found;
     }
 
     /** Function for inorder traversal **/
     public void inorder()
     {
         inorder(root);
     }
     private void inorder(TreapNode r)
     {
         if (r != nil)
         {
             inorder(r.left);
             System.out.print(r.element +" ");
             inorder(r.right);
         }
     }
 
     /** Function for preorder traversal **/
     public void preorder()
     {
         preorder(root);
     }
     private void preorder(TreapNode r)
     {
         if (r != nil)
         {
             System.out.print(r.element +" ");
             preorder(r.left);             
             preorder(r.right);
         }
     }
 
     /** Function for postorder traversal **/
     public void postorder()
     {
         postorder(root);
     }
     private void postorder(TreapNode r)
     {
         if (r != nil)
         {
             postorder(r.left);             
             postorder(r.right);
             System.out.print(r.element +" ");
         }
     }         
 }
 
/** Class TreapTest **/
public class Treap
{
    public static void main(String[] args)
    {            
        Scanner scan = new Scanner(System.in);
        /** Creating object of Treap **/
        TreapTree trpt = new TreapTree(); 
        System.out.println("Treap Test\n");          
        char ch;
        /**  Perform tree operations  **/
        do    
        {
            System.out.println("\nTreap Operations\n");
            System.out.println("1. insert ");
            System.out.println("2. search");
            System.out.println("3. count nodes");
            System.out.println("4. check empty");
            System.out.println("5. clear");
 
            int choice = scan.nextInt();            
            switch (choice)
            {
            case 1 : 
                System.out.println("Enter integer element to insert");
                trpt.insert( scan.nextInt() );                     
                break;                          
            case 2 : 
                System.out.println("Enter integer element to search");
                System.out.println("Search result : "+ trpt.search( scan.nextInt() ));
                break;                                          
            case 3 : 
                System.out.println("Nodes = "+ trpt.countNodes());
                break;     
            case 4 : 
                System.out.println("Empty status = "+ trpt.isEmpty());
                break;
            case 5 : 
                System.out.println("\nTreap Cleared");
                trpt.makeEmpty();
                break;            
            default : 
                System.out.println("Wrong Entry \n ");
                break;   
            }
            /**  Display tree  **/ 
            System.out.print("\nPost order : ");
            trpt.postorder();
            System.out.print("\nPre order : ");
            trpt.preorder();    
            System.out.print("\nIn order : ");
            trpt.inorder();
 
            System.out.println("\nDo you want to continue (Type y or n) \n");
            ch = scan.next().charAt(0);                        
        } while (ch == 'Y'|| ch == 'y');               
    }
}
