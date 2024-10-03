using System;
using System.Collections.Generic;

namespace CS
{
    /* Part of Cosmos by OpenGenus Foundation */
    class MergeSort
    {
        private static int[] SortInternal(int[] arr, int start, int count)
        {
            // Base case - 0 or 1 elements
            if (count == 1)
            {
                return new int[] { arr[start] };
            }
            if (count == 0)
            {
                return new int[0];
            }
            // Split
            int[] part1 = SortInternal(arr, start, count / 2);
            int[] part2 = SortInternal(arr, start + count / 2, count - count / 2);
            // Assemble stage output
            int[] result = new int[count];
            for (int i1 = 0, i2 = 0, j = 0; j < count; j++)
            {
                if (i1 < part1.Length && i2 < part2.Length)
                {
                    if (part1[i1] < part2[i2])
                    {
                        result[j] = part1[i1];
                        i1++;
                    }
                    else
                    {
                        result[j] = part2[i2];
                        i2++;
                    }
                }
                else if (i1 < part1.Length)
                {
                    result[j] = part1[i1];
                    i1++;
                }
                else
                {
                    result[j] = part2[i2];
                    i2++;
                }
            }
            // Return result
            return result;
        }

        static int[] Sort(int[] arr)
        {
            return SortInternal(arr, 0, arr.Length);
        }

        static void Main(string[] args)
        {
            // Create an array of 10 random numbers
            int[] numbers = new int[10];
            var rand = new Random();
            for (int i = 0; i < 10; i++)
            {
                numbers[i] = rand.Next(10);
            }
            Console.WriteLine("Initial ordering:");
            foreach (var num in numbers)
            {
                Console.Write(num + " ");
            }

            // Store the sorted result in a separate variable and print it out
            var sorted = Sort(numbers);
            Console.WriteLine("\nSorted:");
            foreach (var num in sorted)
            {
                Console.Write(num + " ");
            }
        }
    }
}
