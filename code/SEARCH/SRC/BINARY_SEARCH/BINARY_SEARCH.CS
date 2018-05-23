using System;
namespace binary_search
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = new int[10]
                {1, 10, 14, 26, 39, 44, 68, 77, 81, 92};

            Console.WriteLine("Array: ");
            for(int i=0; i<10; i++)
            {
                Console.Write(arr[i] + "  ");
            }

            Console.WriteLine("\nInput -1 to terminate program");

            int find = 0;
            int res;
            while(find != -1)
            {
                Console.Write("Input number to search: ");
                find = Int32.Parse(Console.ReadLine());
                if ((res = binarySearch(arr, find)) != -1)
                    Console.WriteLine($" + Found number {find} at index {res}");     
                else
                    Console.WriteLine(" - Number not found!");
            }

        }

        static int binarySearch(int[] arr, int key)
        {
            int low = 0;
            int high = arr.Length - 1;
            while (low <= high)
            {
                int midIndex = low + (high - low) / 2;
                if (arr[midIndex] == key)
                    return midIndex;
                else if (key > arr[midIndex])
                    low = midIndex + 1;
                else
                    high = midIndex - 1;
            }
            return -1;
        }


    }
}
