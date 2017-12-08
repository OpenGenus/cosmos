/* Part of Cosmos by OpenGenus Foundation */

using System;

namespace CircleSort
{
    public class CircleSort
    {
        public static void Main()
        {
            var sortedArray = Sort(new int[]{2, 14, 4, 6, 8, 1, 5, 3, 7, 11, 0, 13, 20, -1});
            Console.WriteLine(String.Join(", ", sortedArray));
        }

        public static int[] Sort(int[] array)
        {
            if (array.Length > 0)
            {
                while (Sort(array, 0, array.Length - 1, 0) != 0);
            }

            return array;
        }

        private static int Sort(int[] array, int lo, int hi, int numberOfSwaps)
        {
            if (lo == hi)
            {
                return numberOfSwaps;
            }
    
            int high = hi;
            int low = lo;
            int mid = (hi - lo) / 2;
    
            while (lo < hi) 
            {
                if (array[lo] > array[hi])
                {
                    Swap(array, lo, hi);
                    numberOfSwaps++;
                }
                lo++;
                hi--;
            }
    
            if (lo == hi && array[lo] > array[hi + 1])
            {
                Swap(array, lo, hi + 1);
                numberOfSwaps++;
            }
    
            numberOfSwaps = Sort(array, low, low + mid, numberOfSwaps);
            numberOfSwaps = Sort(array, low + mid + 1, high, numberOfSwaps);
    
            return numberOfSwaps;
        }
    
        private static void Swap(int[] array, int index1, int index2)
        {
            int tmp = array[index1];
            array[index1] = array[index2];
            array[index2] = tmp;
        }
    }
}
