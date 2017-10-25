using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
 
namespace InsertionSort
{
    class Program
    {
        static int InsertionSorting()
        {
            Console.Write("\nProgram for sorting a numeric array using Insertion Sorting");
            Console.Write("\n\nEnter number of elements: ");
            int max = Convert.ToInt32(Console.ReadLine());
 
            int[] numarray = new int[max];
 
            for (int i = 0; i < max; i++)
            {
                Console.Write("\nEnter [" + (i + 1).ToString() + "] element: ");
                numarray[i] = Convert.ToInt32(Console.ReadLine());
            }
 
            Console.Write("Input int array  : ");
            for (int k = 0; k < max; k++)
                Console.Write(numarray[k] + " ");
            Console.Write("\n");
 
            for (int i = 1; i < max; i++)
            {
                int j = i;
                while (j > 0)
                {
                    if (numarray[j - 1] > numarray[j])
                    {
                        int temp = numarray[j - 1];
                        numarray[j - 1] = numarray[j];
                        numarray[j] = temp;
                        j--;
                    }
                    else
                        break;
                }
                Console.Write("Iteration " + i.ToString() + ": ");
                for (int k = 0; k < max; k++)
                    Console.Write(numarray[k] + " ");
                Console.Write("\n");
                //Console.Write("/*** " + (i + 1).ToString() + " numbers from the begining of the array are input and they are sorted ***/\n");  
            }
 
            Console.Write("\n\nThe numbers in ascending orders are given below:\n\n");
            for (int i = 0; i < max; i++)
            {
                Console.Write("Sorted [" + (i + 1).ToString() + "] element: ");
                Console.Write(numarray[i]);
                Console.Write("\n");
            }
            return 0;
        }
        static void Main(string[] args)
        {
            InsertionSorting();
            Console.ReadLine();
        }
    }
}
