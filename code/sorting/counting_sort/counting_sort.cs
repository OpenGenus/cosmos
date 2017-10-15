using System;
using System.Collections.Generic;

namespace CS
{
    /* Part of Cosmos by OpenGenus Foundation */
    class CountingSort
    {
        static int[] Sort(int[] arr)
        {
            // Count the frequency of each number in the array
            // The keys in this dictionary are the items themselves, the values are their frequencies
            SortedDictionary<int, int> frequency = new SortedDictionary<int, int>();
            foreach(var num in arr)
            {
                if(!frequency.ContainsKey(num))
                {
                    frequency.Add(num, 0);
                }
                frequency[num]++;
            }
            // Create a new array for the output
            var sorted = new int[arr.Length];
            int index = 0;
            foreach(var entry in frequency)
            {
                // Put each item (the key) from the dictionary into the new array as many times, as was the frequency (the value) of the item
                for(int i = 0; i < entry.Value; i++)
                {
                    sorted[index++] = entry.Key;
                }
            }
            // Return the constructed array
            return sorted;
        }

        static void Main(string[] args)
        {
            // Create an array of 10 random numbers
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

            // Store the sorted result in a separate variable and print it out
            var sorted = Sort(numbers);
            Console.WriteLine("\nSorted:");
            foreach(var num in sorted)
            {
                Console.Write(num + " ");
            }
        }
    }
}
