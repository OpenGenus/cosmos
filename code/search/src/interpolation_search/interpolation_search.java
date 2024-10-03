

public class Interpolation {

	    static int arr[] = new int[]{10, 12, 13, 15, 17, 19, 20, 21, 22, 23,
	                                         24, 33, 35, 42, 49};
	     
	public  static int interpolationSearch(int x)
	    {
	        // Find indexes of two corners
	        int lo = 0, hi = (arr.length - 1);
	      
	        // Since array is sorted, an element present
	        // in array must be in range defined by corner
	        while (lo <= hi && x >= arr[lo] && x <= arr[hi])
	        {
				// Estimate the position of the target element
	            int pos = lo + (((hi-lo) /
	                  (arr[hi]-arr[lo]))*(x - arr[lo]));
	      
				// If the element at the current position is equal to the target element,
				// return the current position
	            if (arr[pos] == x)
	                return pos;
	      
				// If the element at the current position is smaller than the target element,
				// discard the elements at indexes smaller or equal to the current position
	            if (arr[pos] < x)
	                lo = pos + 1;
	      
		  		// If the element at the current position is bigger than the target element,
				// discard the elements at indexes bigger or equal to the current position
	            else
	                hi = pos - 1;
	        }
			
			// Return -1 if the target element was not found
	        return -1;
	    }
	   
	    public static void main(String[] args) 
	    {
	         int x = 20; 
	         int index = interpolationSearch(x);
	          
	         // If element was found
	         if (index != -1)
	            System.out.println("Element found at index " + index);
	         else
	            System.out.println("Element not found.");
	    }
	}


