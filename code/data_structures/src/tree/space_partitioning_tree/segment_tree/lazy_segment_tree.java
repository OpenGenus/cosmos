// Java program to demonstrate lazy propagation in segment tree
// Part of Cosmos by OpenGenus Foundation
class LazySegmentTree
{
    final int MAX = 1000;        // Max tree size
    int tree[] = new int[MAX];  // To store segment tree
    int lazy[] = new int[MAX];  // To store pending updates
 
    /*  index -> index of current node in segment tree
        sstart and send -> Starting and ending indexes of elements for
                     which current nodes stores sum.
        ustart and uend -> starting and ending indexes of update query
        val -> which we need to add in the range ustart to uend */
    void updateRangeUtil(int index, int sstart, int send, int ustart, int uend, int val)
    {
        // If lazy value is non-zero for current node of segment
        // tree, then there are some pending updates. So we need
        // to make sure that the pending updates are done before
        // making new updates. Because this value may be used by
        // parent after recursive calls (See last line of this
        // function)
        if (lazy[index] != 0)
        {
            // Make pending updates using value stored in lazy array
            tree[index] += (send - sstart + 1) * lazy[index];
 
            // checking if it is not leaf node because if
            // it is leaf node then we cannot go further
            if (sstart != send)
            {
                // We can postpone updating children we don't
                // need their new values now.
                // Since we are not yet updating children of index,
                // we need to set lazy flags for the children
                lazy[index * 2 + 1] += lazy[index];     //left child
                lazy[index * 2 + 2] += lazy[index];     //right child
            }
 
            // Set the lazy value for current node as 0 as it
            // has been updated
            lazy[index] = 0;
        }
 
        // out of range
        if (sstart > send || sstart > uend || send < ustart)
            return;
 
        // Current segment is fully in range
        if (sstart >= ustart && send <= uend)
        {
            // Add val to current node
            tree[index] += (send - sstart + 1) * val;
 
            // same logic for checking leaf node or not
            if (sstart != send)
            {
                // This is where we store values in lazy nodes,
                // rather than updating the segment tree itelf
                // Since we don't need these updated values now
                // we postpone updates by storing values in lazy[]
                lazy[index * 2 + 1] += val;
                lazy[index * 2 + 2] += val;
            }
            return;
        }
 
        // If not completely in range, but overlaps, recur for children,
        int mid = (sstart + send) / 2;
        updateRangeUtil(index * 2 + 1, sstart, mid, ustart, uend, val);
        updateRangeUtil(index * 2 + 2, mid + 1, send, ustart, uend, val);
 
        // Use the result of children calls to update this node
        tree[index] = tree[index * 2 + 1] + tree[index * 2 + 2];
    }
 
    // Function to update a range of values in segment tree
    void updateRange(int n, int ustart, int uend, int val)  {
        updateRangeUtil(0, 0, n - 1, ustart, uend, val);
    }
 
    /*  A recursive function to get the sum of values in given
        range of the array. The following are parameters for
        this function.
        index --> Index of current node in the segment tree.
               Initially 0 is passed as root is always at'
               index 0
        sstart & send  --> Starting and ending indexes of the
                     segment represented by current node,
                     i.e., tree[index]
        qstart & qend  --> Starting and ending indexes of query
                     range */
    int getSumUtil(int sstart, int send, int qstart, int qend, int index)
    {
        // If lazy flag is set for current node of segment tree,
        // then there are some pending updates. So we need to
        // make sure that the pending updates are done before
        // processing the sub sum query
        if (lazy[index] != 0)
        {
            // Make pending updates to this node. Note that this
            // node represents sum of elements in arr[sstart..send] and
            // all these elements must be increased by lazy[index]
            tree[index] += (send - sstart + 1) * lazy[index];
 
            // checking if it is not leaf node because if
            // it is leaf node then we cannot go further
            if (sstart != send)
            {
                // Since we are not yet updating children of index,
                // we need to set lazy values for the children
                lazy[index * 2 + 1] += lazy[index];
                lazy[index * 2 + 2] += lazy[index];
            }
 
            // update the lazy value for current node as it has
            // been updated
            lazy[index] = 0;
        }
 
        // Out of range
        if (sstart > send || sstart > qend || send < qstart)
            return 0;
 
        // At this point, pending lazy updates are done
        // for current node. So we can return value
 
        // If this segment lies in range
        if (sstart >= qstart && send <= qend)
            return tree[index];
 
        // If a part of this segment overlaps with the given range
        int mid = (sstart + send) / 2;
        return getSumUtil(sstart, mid, qstart, qend, 2 * index + 1) + getSumUtil(mid + 1, send, qstart, qend, 2 * index + 2);
    }
 
    // Return sum of elements in range from index qstart (query start)
    // to qend (query end).  It mainly uses getSumUtil()
    int getSum(int n, int qstart, int qend)
    {
        // Check for erroneous input values
        if (qstart < 0 || qend > n - 1 || qstart > qend)
        {
            System.out.println("Invalid Input");
            return -1;
        }
 
        return getSumUtil(0, n - 1, qstart, qend, 0);
    }
 
    /* A recursive function that constructs Segment Tree for
      array[sstart..send]. index is index of current node in segment
      tree st. */
    void constructSTUtil(int arr[], int sstart, int send, int index)
    {
        // out of range as sstart can never be greater than send
        if (sstart > send)
            return;
 
        /* If there is one element in array, store it in
         current node of segment tree and return */
        if (sstart == send)
        {
            tree[index] = arr[sstart];
            return;
        }
 
        /* If there are more than one elements, then recur
           for left and right subtrees and store the sum
           of values in this node */
        int mid = (sstart + send) / 2;
        constructSTUtil(arr, sstart, mid, index * 2 + 1);
        constructSTUtil(arr, mid + 1, send, index * 2 + 2);
 
        tree[index] = tree[index * 2 + 1] + tree[index * 2 + 2];
    }
 
    /* Function to construct segment tree from given array.
       This function allocates memory for segment tree and
       calls constructSTUtil() to fill the allocated memory */
    void constructST(int arr[], int n)
    {
        // Fill the allocated memory st
        constructSTUtil(arr, 0, n - 1, 0);
    }
 
 
    // The Main function
    public static void main(String args[])
    {
        int arr[] = {1, 3, 5, 7, 9, 11};
        int n = arr.length;
        LazySegmentTree tree = new LazySegmentTree();
 
        // Build segment tree from given array
        tree.constructST(arr, n);
 
        // Print sum of values in array from index 1 to 3
        System.out.println("Sum of values in given range = " + tree.getSum(n, 1, 3));
 
        // Add 10 to all nodes at indexes from 1 to 5.
        tree.updateRange(n, 1, 5, 10);
 
        // Find sum after the value is updated
        System.out.println("Updated sum of values in given range = " + tree.getSum(n, 1, 3));
    }
}
