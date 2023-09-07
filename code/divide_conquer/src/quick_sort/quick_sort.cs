// Part of Cosmos (OpenGenus)
using System;
public class Quick_Sort
{
    // Conquer
    public static int Parition(int[] array, int left, int right)
    {
        int pivot = array[left];
        int index = right;
        int temp;

        for(int j = right; j > left; j--)
        {
            if(array[j] > pivot)
            {
                temp = array[j];
                array[j] = array[index];
                array[index] = temp;
                index--;
            }
        }

        array[left] = array[index];
        array[index] = pivot;
        return index;
    }

    // Divide array into halves
    public static void Quick(int[] array, int left, int right)
    {
        if(left < right)
        {
            int pivot = Parition(array, left, right);

            Quick(array, left, pivot - 1);
            Quick(array, pivot + 1, right);
        }
    }

    public static void QuickSort(int[] array, int size)
    {
        Quick(array, 0, size - 1);
    }

    // function ro print array
    public static void Print_Array(int[] array, int size)
    {
        for(int i = 0; i < size; i++)
            Console.Write(array[i] + " ");

        Console.Write("");
    }

    public static void Main()
    {
        int[] array = {2, 4, 3, 1, 6, 8, 4};
        QuickSort(array, 7);
        Print_Array(array, 7);
    }
}

// Output
// 1 2 3 4 4 6 8
