/* Part of Cosmos by OpenGenus Foundation */
public class Bogo_Sort
{
    // Sorts array a[0..n-1] using Bogo sort
    void bogoSort(int[] a)
    {
        // if array is not sorted then shuffle the
        // array again
        while (isSorted(a) == false)
            shuffle(a);
    }
 
    // To generate permuatation of the array
    void shuffle(int[] a)
    {
         // Math.random() returns a double positive
         // value, greater than or equal to 0.0 and
         // less than 1.0.
         for (int i=1; i <= n; i++)
             swap(a, i, (int)(Math.random()*i));
    }
 
    // Swapping 2 elements
    void swap(int[] a, int i, int j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
 
    // To check if array is sorted or not
    boolean isSorted(int[] a)
    {
        for (int i=1; i<a.length; i++)
            if (a[i] < a[i-1])
                return false;
        return true;
    }
 
    // Prints the array
    void printArray(int[] arr)
    {
        for (int i=0; i<arr.length; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
 
    public static void main(String[] args)
    {
        //Enter array to be sorted here
        int[] a = {3, 2, 5, 1, 0, 4};
        Bogo_Sort ob = new Bogo_Sort();
 
        ob.bogoSort(a);
 
        System.out.print("Sorted array: ");
        ob.printArray(a);
    }
}
