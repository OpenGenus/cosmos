using System;

namespace TernarySearch
{
    class Program
    {
        static void Main(string[] args)
        {
            var array = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            var numberToFind = 2;
            var index = TernarySearch(array, numberToFind, 0, array.Length - 1);
            Console.WriteLine($"Index of {numberToFind} is {index}");
        }

        public static int TernarySearch(int[] array, int numberToFind, int start, int end)
        {
            if (start > end)
            {
                return -1;
            }

            var midpoint1 = start + (end - start) / 3;
            var midpoint2 = start + 2 * (end - start) / 3;

            if (array[midpoint1] == numberToFind)
            {
                return midpoint1;
            }
            else if (array[midpoint2] == numberToFind)
            {
                return midpoint2;
            }

            if (numberToFind < array[midpoint1])
            {
                return TernarySearch(array, numberToFind, start, midpoint1 - 1);
            }
            else if (numberToFind > array[midpoint2])
            {
                return TernarySearch(array, numberToFind, midpoint2 + 1, end);
            }
            else
            {
                return TernarySearch(array, numberToFind, midpoint1 + 1, midpoint2 - 1);
            }
        }
    }
}
