import java.io.*;
 // Brick sort is a similar to bubble sort in terms of sorting array. 
 // It sorts the array in terms of odd and even index places elements. 
public class BrickSort {
	void bricksort(int l[], int n) {
		 /* l is the arguement used that contains the unsorted element 
         ** n is the variable that contains the no. of elements in the array 
    	 ** sort variable is used to denote if array is sorted after the sorting process. 
    	 ** it is initialised 0 to check if array is sorted after every iteration.
    	 */
    	int sort = 0;
    	do {
    		 // sort is set to 1  when loop conditions is true 
        	sort = 1;
        	int temp = 0;
         	 // this for loop sorts the even indexed element in an array 
        	for (int i = 0; i <= n - 2; i = i + 2) {
            	if (l[i] > l[i + 1]) {
                	temp = l[i];
                	l[i] = l[i+1];
                	l[i+1] = temp;
                	sort = 0;
            	}
        	}
        	 // sort is set to 0 whenever loop is executed 
        	 // the next loop sorts the odd indexed element in the array 
        	for (int i = 1; i <= n - 2; i = i + 2) {
            	if (l[i] > l[i + 1]) {
                	temp = l[i];
                	l[i] = l[i+1];
                	l[i+1] = temp;
                	sort = 0;
            	}
        	}
    	}while (sort == 0);
    }

	void printArray(int l[]) { 
    	 // this funtion prints the sorted array elements.
        int n = l.length; 
        for (int i = 0; i < n; i++) 
            System.out.print(l[i] + " "); 
    } 

    public static void main(String[] args) { 
    	BrickSort ob = new BrickSort(); 
         // a denotes the unsorted array.
        int l[] = { 5, 1, 4, 2, 8, 0, 2 , 5, 3, 1}; 
         // n is the variable used to get the size of array.
        int n = l.length;
         // bricksort sort function is called to sort the array.
        ob.bricksort(l,n);
         // To print the sorted array, printarray is called with parameter a i.e. sorted array 
        ob.printArray(l); 
    } 
}