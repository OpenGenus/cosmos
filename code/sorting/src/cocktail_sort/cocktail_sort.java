import java.util.*;

class cocktail_sort {
    static void cocktail_sort(int l[], int n)
    {
        int first = 0, temp = 0, last = n - 1;
        boolean p=true;
        while (p)
        {
            /* while loop checks the status of the array */
            p = false;
            for (int i = first; i < last; ++i)
            {
                /* for loop is used to do the forward sorting on the array */
                if (l[i] > l[i + 1])
                {
                    temp = l[i];
                    l[i] = l[i + 1];
                    l[i + 1] = temp;
                    p = true;
                }
                /* after every sorting, largest element is at the last index and value of p is set to 1 */
            }
            if (p == false)
                /* if value is not 1, it means the array is sorted already , so the control is sent out of while loop */
                break;
            else
            {
                p = false;
                last--;
            }
            for (int i = last; i >= first; --i)
            {
                if (l[i] > l[i + 1])
                {
                    temp = l[i];
                    l[i] = l[i + 1];
                    l[i + 1] = temp;
                    p = true;
                }
            }
            first++;
        }
        //Displaying
        for (int i = 0; i < n; ++i)
            System.out.print(l[i]+" ");
    }
    public static void main(String args[]) 
    {
        int []unsorted_array = new int[]{5, 1, 4, 2, 8, 0, 2};
        int n = unsorted_array.length;
        cocktail_sort(unsorted_array, n);
    }
}

/*
Sample Input:
5 1 4 2 8 0 2

Sample Output:
0 1 2 2 4 5 8
*/