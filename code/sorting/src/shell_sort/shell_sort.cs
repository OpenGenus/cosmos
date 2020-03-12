// C# program of ShellSort 

using System; 

class ShellSort 
{ 
    //function to implement ShellSort
    int shellsort(int []arr) 
    { 
        int n = arr.Length; 
        // Beginning with a big gap, and then keep on reducing it. 
        for (int gap = n/2; gap > 0; gap /= 2) 
        { 
            // Performing a gapped insertion sort
            for (int i = gap; i < n; i += 1) 
            { 
                // Adding a[i] to the elements that have 
                // been gap sorted and 
                // make a hole at position i 
                int temp = arr[i]; 
             
                //Shift other elements until the correct location of a[i] is found 
                int j; 
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                    arr[j] = arr[j - gap]; 
                // put original a[i] in its correct location 
                arr[j] = temp; 
            } 
        } 
        return 0; 
    } 

     public static void Main() 
    { 
        int size;
        Console.Write("How many numbers do you want to sort : ");
        size = Convert.ToInt32(Console.ReadLine());  
        int[] array = new int[size];
        Console.Write("\nEnter the numbers : ");
        for (int i = 0; i < size; i++) 
              array[i] = Convert.ToInt32(Console.ReadLine());
        ShellSort ob = new ShellSort(); 
        ob.shellsort(array); 
        Console.Write("\nAfter sorting  : ");
        for (int i = 0; i < size; i++) 
                Console.Write(array[i] + " "); 
    }  
} 

//SAMPLE INPUT AND OUTPUT
/*SAMPLE 1
How many numbers do you want to sort : 7 
Enter the numbers : 
 4
 9 
 3
 9
 4
 7
 5
After sorting : 3 4 4 5 7 9 9 

//SAMPLE 2
How many numbers do you want to sort : 5 
Enter the numbers :
 5 
 1 
 7 
 3 
 2
After sorting : 1 2 3 5 7
*/ 
