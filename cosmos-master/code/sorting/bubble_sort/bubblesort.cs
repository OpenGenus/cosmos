/* Part of Cosmos by OpenGenus Foundation */

namespace BubbleSortCSharp
{
    class bubblesort
    {
        static void Main(string[] args)
        {
            int[] a = { 0, 9, -4, 8, 3, 2};
            
            //bubble sort
            for (int i = a.Length - 1; i > 0; i--)
            {
                for (int j = 0; j <= i - 1; j++)
                {
                    if (a[j] > a[j + 1])
                    {
                        int temp = ay[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                    }
                }
            }
 
            Console.WriteLine("Sorted Array: ");
            for (int i = 0; i < a.Length; i++)
            {
                Console.WriteLine(a[i]);
            }
        }
    }
}
