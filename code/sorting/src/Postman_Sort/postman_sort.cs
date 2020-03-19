// C Program to Implement Postman Sort Algorithm

using System;


namespace Declaring_Method
{
    public class Sort
    {
        public static int[] a = new int[100];
        public static int[] a1 = new int[100];
        public int temp, max, count, maxdigits = 0, c = 0;
        public static void Main(string[] args)
        {

            Sort p = new Sort();
            int t1, t, n = 1, i, j;
            Console.WriteLine("Enter the Size of the a ");
            p.count = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter the elements of the a :-");
            for (i = 0; i < p.count; i++)
            {
                Console.Write("element - {0} : ", i);
                a[i] = Convert.ToInt32(Console.ReadLine());
                a1[i] = a[i];
            }

            //Finding the longest digits in the array and no of elements in that digit
            for (i = 0; i < p.count; i++)
            {
                t = a[i]; 
                while (t > 0)
                {
                    p.c++;          //Counting the no of elements of a digit
                    t = t / 10; 
                }
                if (p.maxdigits < p.c)
                    p.maxdigits = p.c;        //Storing the length of longest digit
                p.c = 0;
            }
            for (i = 1; i < p.maxdigits; i++)
            {
                n = n * 10;
            }

            for (i = 0; i < p.count; i++)
            {
                p.max = a[i] / n;           //Dividing by a particular base
                t = i;
                for (j = i + 1; j < p.count; j++)
                {
                    if (p.max > (a[j] / n))
                    {
                        p.max = a[j] / n;   
                        t = j;
                    }
                }
                p.temp = a1[t];
                a1[t] = a1[i];
                a1[i] = p.temp;
                p.temp = a[t];
                a[t] = a[i];
                a[i] = p.temp;
            }
            while (n >= 1)
            {
                for (i = 0; i < p.count;)
                {
                    t1 = a[i] / n;
                    for (j = i + 1; t1 == (a[j] / n); j++) ;
                    arrange(i, j);
                    i = j;
                }
                n = n / 10;
            }
            Console.WriteLine("Sorted a");
            for (i = 0; i < p.count; i++)
                Console.Write("{0}  ", a1[i]);
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
                    if (a1[i] > a1[j])
                    {
                        p.temp = a1[i];
                        a1[i] = a1[j];
                        a1[j] = p.temp;
                        p.temp = (a[i] % 10);
                        a[i] = (a[j] % 10);
                        a[j] = p.temp;
                    }
                }
            }
        }
    }
}
/* Enter the Size of the array
6
Enter the elements of the array
Element - 0 : 43
Element - 1 : 35
Element - 2 : 75
Element - 3 : 1
Element - 4 : 68
Element - 5 : 453
Sorted Array
1  35  43  68  75  453  */