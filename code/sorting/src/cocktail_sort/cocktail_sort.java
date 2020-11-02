 import java.io.*;
 // Cocktail sort function sorts the unsorted array similar to bubble sort.
 // Cocktail sort algorithm has less complexity as compared to bubble sort.
 public class Cocktailsort {
	void cocktailsort(int l[], int n) {
		 /*
		 ** cocktail sort function takes two arguments-
		 ** l is the list of elements that is unsorted and n is the length of the array.
		 */
		 // k is the variable used to check if the array contains sorted elements after sorting process. 
	    int k = 1;
	     // first is the variable that denotes the first index in the array.
	    int first = 0;
	     // last denotes the last index in the array.
	    int last = n;
	    do {
	    	 // do-while loop is used to sort the array for the first time and next check the condition.
		    k = 0;
		    for (int i = first; i < last - 1; i++) {
		     	 // for loop performs the forward sort on the array.
			    if (l[ i ] > l[ i + 1 ]) {
			    	int temp = l[i];
				    l[i] = l[i+1];
				    l[i+1] = temp;
				    k = 1;
			    }
		    }
		     // To check the array status if it is sorted the k is 0 and controls moves out of loop.
		    if (k == 0) {
			    break;
		    } else {
		    	k = 1;
		    	 // the last index is decreased by 1 as largets element in array is sorted in each try.
		    	last--;
	    	}
		    for (int i = last - 1; i >= first; i--) {
		    	 // for loop performs the backward sort on the array
			    if (l[ i ] > l[ i + 1 ]) {
				    int temp = l[i];
			        l[i] = l[i+1];
				    l[i+1] = temp;
				    k = 1;
			    }
		    }
		     // the first index is increased by 1 after backward sort.
		    first++;
	    }while (k == 1);
	}

	void printArray(int a[]) { 
    	 // this funtion prints the sorted array elements.
        int n = a.length; 
        for (int i = 0; i < n; i++) 
            System.out.print(a[i] + " "); 
    } 

    public static void main(String[] args) { 
    	Cocktailsort ob = new Cocktailsort(); 
         // a denotes the unsorted array.
        int a[] = { 5, 1, 4, 2, 8, 0, 2 , 5, 3, 1}; 
         // n is the variable used to get the size of array.
        int n = a.length;
         // cocktail sort function is called to sort the array.
        ob.cocktailsort(a,n);
         // To print the sorted array, printarray is called with parameter a i.e. sorted array 
        ob.printArray(a); 
    } 
}

