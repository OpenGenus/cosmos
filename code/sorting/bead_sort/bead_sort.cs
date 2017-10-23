/* Part of Cosmos by OpenGenus Foundation */

using System;
using System.Linq;

namespace CS
{
    public class BeadSort
    {
        public BeadSort()
        {
        }

        static int[] Sort(int[] arr) {
            int max = arr.Max();

            var grid = new bool[arr.Length, max];

            int[] levelCount = new int[max];
            
            for(int i = 0; i < max; i++) {
                levelCount[i] = 0;
                for(int j = 0; j < arr.Length; j++) {
                    grid[j, i] = false;
                }
            }

            foreach (var num in arr)
            {
                var tmpNum = num;
                for (int j = 0; tmpNum > 0; j++, tmpNum--)
                {
                    grid[levelCount[j]++, j] = true;
                }
            }

            var sorted = new int[arr.Length];
            for (int i = 0; i < arr.Length; i++)
            {
                int putt = 0;
                for (int j = 0; j < max && grid[arr.Length - 1 - i, j] == true; j++)
                {
                    putt++;
                }
                sorted[i] = putt;
            }

            return sorted;

        }

        static void Main(string[] args)
        {
            const int numbers = 25;
            int[] arr = new int[numbers];

            var rand = new Random();
            for (int i = 0; i < numbers; i++)
            {
                arr[i] = rand.Next(99);
            }


            Console.WriteLine("Before Sorting");
            foreach (var num in arr)
            {
                Console.Write(num + " ");
            }

            var sorted = Sort(arr);
            Console.WriteLine("\nSorted:");
            foreach (var num in sorted)
            {
                Console.Write(num + " ");
            }
        }
    }
}

