class SegmentTree {
    private int seg_t[];        // An array to store the segment tree implementation
    
    /**
    * Constructor which takes the size of the array and the array as a parameter and constructs the segment tree
    * @author Kanakalatha Vemuru (https://github.com/KanakalathaVemuru)
    * @param n is the size of the array 
    * @param arr is the array on which segment tree has to be constructed
    */
    public SegmentTree(int n, int arr[]) {
        int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));
        int seg_size = 2 * (int) Math.pow(2, x) - 1;

        this.seg_t = new int[seg_size];
        constructTree(arr, 0, n - 1, 0);
    }
    
    /**  A function which will create the segment tree
    * @author Kanakalatha Vemuru (https://github.com/KanakalathaVemuru)
    * @param arr the array on which segment tree has to be constructed
    * @param start an integer representing the start of the segment represented by current node
    * @param end an integer representing the end of the segment represented by current node
    * @param index the integer representing the index of current node in segment tree
    * @return an integer representing the sum of the current segment 
    */
    public int constructTree(int[] arr, int start, int end, int index) {
        if (start == end) {
            this.seg_t[index] = arr[start];
            return arr[start];
        }
        
        int mid = start + (end - start) / 2;
        this.seg_t[index] = constructTree(arr, start, mid, index*2 + 1) +
            constructTree(arr, mid + 1, end, index*2 + 2);
        return this.seg_t[index];
    }
    
    
    /**  A function which will update the value at a index i. This will be called by the
    update function internally
    * @author Kanakalatha Vemuru (https://github.com/KanakalathaVemuru)
    * @param start an integer representing the start of the segment represented by current node
    * @param end an integer representing the end of the segment represented by current node
    * @param index an integer representing the index whose value has to be updated in the array
    * @param diff the difference between the value of previous value and updated value
    * @param seg_index the integer representing the index of current node in segment tree
    */
    private void updateValueUtil(int start, int end, int index, int diff, int seg_index) {
        if (index < start || index > end) {
            return;
        }
        
        this.seg_t[seg_index] += diff;
        if (start != end) {
            int mid = start + (end - start) / 2;
            updateValueUtil(start, mid, index, diff, seg_index*2 + 1);
            updateValueUtil(mid + 1, end, index, diff, seg_index*2 + 2);
        }
    }
    
    /** A function to update the value at a particular index
    * @author Kanakalatha Vemuru (https://github.com/KanakalathaVemuru)
    * @param n is the size of the array 
    * @param arr is the array on which segment tree has to be constructed
    * @param index the integer representing the index whose value to be updated
    * @param value the integer representing the updated value 
    */
    public void updateValue(int[] arr, int n, int index, int value) {
        if (index < 0 || index > n) {
            return;
        }
        
        int diff = value - arr[index];
        arr[index] = value;
        updateValueUtil(0, n - 1, index, diff, 0);
    }
    
    /** A function to get the sum of the elements from index q_start to index q_end. This will be called internally
    * @author Kanakalatha Vemuru (https://github.com/KanakalathaVemuru)
    * @param start an integer representing the start of the segment represented by current node
    * @param end an integer representing the end of the segment represented by current node
    * @param q_start an integer representing the start of the segment whose sum we are quering
    * @param q_end an integer representing the end of the segment whose sum we are quering
    * @param seg_index the integer representing the index of current node in segment tree
    * @return an integer representing the sum of the segment q_start to q_end
    */
    private int getSumUtil(int start, int end, int q_start, int q_end, int seg_index) {
        if (q_start <= start && q_end >= end) {
            return this.seg_t[seg_index];
        }
        
        if (q_start > end || q_end < start) {
            return 0;
        }
        
        int mid = start + (end - start)/2;
        return getSumUtil(start, mid, q_start, q_end, seg_index*2 + 1) + getSumUtil(mid + 1, end, q_start, q_end, seg_index*2 + 2);
    }
    
    /** A function to query the sum of the segment [start...end]
    * @author Kanakalatha Vemuru (https://github.com/KanakalathaVemuru)
    * @param n an integer representing the length of the array
    * @param start an integer representing the start of the segment whose sum we are quering
    * @param end an integer representing the end of the segment whose sum we are quering
    * @return an integer representing the sum of the segment start to end
    */
    public int getSum(int n, int start, int end) {
        if (start < 0 || end > n || start > end) {
            return 0;
        }
        return getSumUtil(0, n-1, start, end, 0);
    }

    // Driver program for testing
    public static void main(String args[])
    {
        int arr[] = {1, 3, 5, 7, 9, 11};
        int n = arr.length;
    
        SegmentTree st = new SegmentTree(n, arr);
    
        // Print sum of values in array from index 1 to 3
        System.out.println("Sum of values in given range = " + st.getSum(n, 1, 3) + ".\n");
    
        // Update: set arr[1] = 10 and update corresponding segment
        // tree nodes
        st.updateValue(arr, n, 1, 10);
    
        // Find sum after the value is updated
        System.out.println("Updated sum of values in given range = " + st.getSum(n, 1, 3) + ".\n");
    }

}