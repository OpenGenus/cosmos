import java.util.*;

class flash_sort
{
    static void flashSort(int arr[])
    {
        int max = 0, min = arr[0], k, j, i, p;
        int m = (int)(0.43 * arr.length);
        int l[] = new int[m];

        for (i = 1; i < arr.length; ++i) 
        {
            if (arr[i] < min)
            {
                min = arr[i];
            }
            if (arr[i] > arr[max])
            {
                max = i;
            }
        }
        
        if (min == arr[max])
        {
            return;
        }

        int c1 = (int)(m - 1) / (arr[max] - min);
        
        for (k = 0; k < m; k++)
        {
            l[k] = 0;
        }

        for (j = 0; j < arr.length; ++j)
        {
            k =(int) (c1 * (arr[j] - min));
            ++l[k];
        }

        for (p = 1; p < m; ++p)
        {
            l[p] = l[p] + l[p - 1];
        }

        int temp = arr[max];
        arr[max] = arr[0];
        arr[0] = temp;

        int index = 0, t, flash;
        j = 0;
        k = m - 1;

        while (index < (arr.length - 1))
        {
            while (j > (l[k] - 1))
            {
                ++j;
                k = (int)(c1 * (arr[j] - min));
            }
            if (k < 0)
                break;
            
            flash = arr[j];
            while (j != l[k])
            {
                k = (int)(c1 * (flash - min));
                temp = arr[t = --l[k]];
                arr[t] = flash;
                flash = temp;
                ++index;
            }
        }
        
        for (j = 1; j < arr.length; j++) 
        {
            temp = arr[j];
            i = j - 1;
            while (i >= 0 && arr[i] > temp)
            {
                arr[i + 1] = arr[i--];
            }
            arr[i + 1] = temp;
        }

        for (i = 0; i < arr.length; ++i)
        {
            System.out.print(arr[i] +" ");
        }
    }

    public static void main(String args[])
    {
        int arr[] = new int[]{9, 1, 1, 8, 2, 2, 3, 6, 7, 12};
        flashSort(arr);
    }
}

/*
Sample Output:
1 1 2 2 3 6 7 8 9 12
*/