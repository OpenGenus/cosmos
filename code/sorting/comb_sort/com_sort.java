// Part of Cosmos by OpenGenus Foundation

import java.util.Scanner;

public class CombSort
{
    public static void main(String[] args)
    {
        int i;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter no elements you want (Size):");
        int size = sc.nextInt();
        int[] a = new int[size];
        System.out.println("Please enter the " + size + " elements:");
        for (i = 0; i < size; i++)
        {
            a[i] = sc.nextInt();
        }
        System.out.println("Sorted array is :");
        CombSort cs = new CombSort(a);
        for (i = 0; i < size; i++)
        {
            System.out.printf("%d\t", a[i]);
        }
    }
    private final int[] a;

    private CombSort(int[] b)
    {
        this.a = b;
        combSort(a.length);
    }

    private void combSort(int size)
    {
        float shrink = 1.3f;
        int swap;
        int i, gap = size;
        boolean swapped = false;
        while ((gap > 1) || swapped)
        {
            if (gap > 1)
            {
                gap = (int) ((float) gap / shrink);
            }
            swapped = false;
            for (i = 0; gap + i < size; ++i)
            {
                if (a[i] - a[i + gap] > 0)
                {
                    swap = a[i];
                    a[i] = a[i + gap];
                    a[i + gap] = swap;
                    swapped = true;
                }
            }
        }
    }
}
