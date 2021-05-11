/*
 * C# Program to Perform Insertion Sort
 */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = new int[5] { 83, 12, 3, 34, 60 };
            int i;
            Console.WriteLine("The Array is :");
            for (i = 0; i < 5; i++)
            {
                Console.WriteLine(arr[i]);
            }
            InsertionSort(arr, 5);
            Console.WriteLine("The Sorted Array is :");
            
            for (i = 0; i < 5; i++)
                Console.WriteLine(arr[i]); 
            Console.ReadLine();
        }  
         
        static void InsertionSort(int[] data, int n)
        {
            int i, j;
            for (i = 1; i < n; i++)
            {
                int item = data[i];
                int ins = 0;
                /* Move elements of data[0..i-1], 
                that are greater than item, 
                to one position ahead of 
                their current position */
                for (j = i - 1; j >= 0 && ins != 1; )
                {
                    if (item < data[j])
                    {
                        data[j + 1] = data[j];
                        j--;
                        data[j + 1] = item;
                    }
                    else ins = 1;
                }
            }
        }
    }
}
