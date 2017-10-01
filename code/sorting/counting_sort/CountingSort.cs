using System;
using System.Collections.Generic;

namespace CS
{
    class CountingSort
    {
        static int[] Sort(int[] arr)
        {
            SortedDictionary<int, int> frequency = new SortedDictionary<int, int>();
            foreach(var num in arr)
            {
                if(!frequency.ContainsKey(num))
                {
                    frequency.Add(num, 0);
                }
                frequency[num]++;
            }
            var sorted = new int[arr.Length];
            int index = 0;
            foreach(var entry in frequency)
            {
                for(int i = 0; i < entry.Value; i++)
                {
                    sorted[index++] = entry.Key;
                }
            }
            return sorted;
        }

        static void Main(string[] args)
        {
            int[] numbers = new int[10];
            var rand = new Random();
            for(int i = 0; i < 10; i++)
            {
                numbers[i] = rand.Next(10);
            }
            Console.WriteLine("Initial ordering:");
            foreach(var num in numbers)
            {
                Console.Write(num + " ");
            }

            var sorted = Sort(numbers);
            Console.WriteLine("\nSorted:");
            foreach(var num in sorted)
            {
                Console.Write(num + " ");
            }
        }
    }
}
