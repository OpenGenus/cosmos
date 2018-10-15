using System;
using System.Collections.Generic;

namespace CS
{
    /* Part of Cosmos by OpenGenus Foundation */
    class MergeSort
    {
        private static int ParentIndex(int index)
        {
            return (index - 1) / 2;
        }

        private static int LeftChildIndex(int index)
        {
            return 2 * index + 1;
        }

        private static int RightChildIndex(int index)
        {
            return 2 * index + 2;
        }

        private static void SiftDown(int[] arr, int start, int end)
        {
            int root = start;
            int child;
            while ((child = LeftChildIndex(root)) <= end)
            {
                int swap = root;
                if (arr[swap] < arr[child])
                {
                    swap = child;
                }
                if (child + 1 <= end && arr[swap] < arr[child + 1])
                {
                    swap = child + 1;
                }
                if (swap == root)
                {
                    return;
                }
                else
                {
                    int temp = arr[root];
                    arr[root] = arr[swap];
                    arr[swap] = temp;
                    root = swap;
                }
            }
        }

        static int[] Sort(int[] arr)
        {
            // Heapify
            for (int i = ParentIndex(arr.Length - 1); i >= 0; i--)
            {
                SiftDown(arr, i, arr.Length - 1);
            }
            // Sort
            int end = arr.Length - 1;
            while (end >= 0)
            {
                int temp = arr[end];
                arr[end] = arr[0];
                arr[0] = temp;
                end--;
                SiftDown(arr, 0, end);
            }
            return arr;
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
