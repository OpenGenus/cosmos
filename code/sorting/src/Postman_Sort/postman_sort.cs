//Program to Sort the array using Postman Sort

using System;
namespace Declaring_Method
{
    public class Sort
    {
        public static int[] arr = new int[100];
        public static int[] arr1 = new int[100];
        public int temp, max, count, maxdigits = 0, c = 0;
        public static void Main(string[] args)
        {

            Sort p = new Sort();
            int t1, t, n = 1, i, j;
            Console.WriteLine("Enter the Size of the array ");
            p.count = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter the elements of the array :-");
            for (i = 0; i < p.count; i++)
            {
                Console.Write("Element - {0} : ", i);
                arr[i] = Convert.ToInt32(Console.ReadLine());
                arr1[i] = arr[i];
            }

            //Finding the longest digits in the array and no of elements in that digit
            for (i = 0; i < p.count; i++)
            {
                t = arr[i]; 
                while (t > 0)
                {
                    p.c++; //Counting the no of elements of a digit
                    t = t / 10; 
                }
                if (p.maxdigits < p.c)
                    p.maxdigits = p.c; //Storing the length of longest digit
                p.c = 0;
            }
            for(i=1;i<p.maxdigits;i++)
            {
                n = n * 10;
            }

            for (i = 0; i < p.count; i++)
            {
                p.max = arr[i] / n; //Dividing by a particular base
                t = i;
                for (j = i + 1; j < p.count; j++)
                {
                    if (p.max > (arr[j] / n))
                    {
                        p.max = arr[j] / n;
                        t = j;
                    }
                }
                p.temp = arr1[t];
                arr1[t] = arr1[i];
                arr1[i] = p.temp;
                p.temp = arr[t];
                arr[t] = arr[i];
                arr[i] = p.temp;
            }
            while (n >= 1)
            {
                for (i = 0; i < p.count;)
                {
                    t1 = arr[i] / n;
                    for (j = i + 1; t1 == (arr[j] / n); j++) ;
                    arrange(i, j);
                    i = j;
                }
                n = n / 10;
            }
            Console.WriteLine("Sorted Array");
            for (i = 0; i < p.count; i++)
                Console.Write("{0}  ", arr1[i]); //Displaying the Sorted array
        }

        //Arranging the elements
        public static void arrange(int k, int n)
        {
            Sort p = new Sort();
            int i, j;
            for (i = k; i < (n - 1); i++)
            {
                for (j = i + 1; j < n; j++)
                {
                    if (arr1[i] > arr1[j])
                    {
                        p.temp = arr1[i];
                        arr1[i] = arr1[j];
                        arr1[j] = p.temp;
                        p.temp = (arr[i] % 10);
                        arr[i] = (arr[j] % 10);
                        arr[j] = p.temp;
                    }
                }
            }
        }
    }
}
/* Enter the Size of the array
6
Enter the elements of the array :-
Element - 0 : 43
Element - 1 : 35
Element - 2 : 75
Element - 3 : 1
Element - 4 : 68
Element - 5 : 453
Sorted Array
1  35  43  68  75  453  */