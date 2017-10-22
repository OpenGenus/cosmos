/* Part of Cosmos by OpenGenus Foundation */

using System;
namespace CS
{
    public class MedianSort
    {

        static void swap(ref int a, ref int b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        static int SelectPivotIndex(int[] arr, int right, int left) {
            int mid = (left + right) / 2;

            if (arr[left] > arr[mid]) {
                if (arr[left] > arr[right]) {
                    if (arr[right] > arr[mid])
                        return right;
                    else
                        return mid;
                } else {
                    return left;
                }
            }
            else
            {
                if (arr[mid] > arr[right]) {
                    if (arr[left] > arr[right])
                        return left;
                    else 
                        return right;
                } else {
                    return mid;
                }
            }
        }

        static int Partition(ref int[] arr, int left, int right, int pivot) {
            swap(ref arr[pivot], ref arr[right]);
            int store = left;

            for (int i = left; i < right; i++) {
                if(arr[i] <= arr[right]) {
                    swap(ref arr[i], ref arr[store]);
                    store++;
                }
            }

            swap(ref arr[store], ref arr[right]);
            return store;
        }

        static int SelectKth(ref int[] arr, int k, int left, int right) {
            int idx = SelectPivotIndex(arr, left, right);
            int pivot = Partition(ref arr, left, right, idx);
            int kth = left + k - 1;

            if (kth == pivot)
                return pivot;

            if (kth < pivot)
                return SelectKth(ref arr, k, left, pivot - 1);
            else
                return SelectKth(ref arr, kth - pivot, pivot + 1, right);

        }

        static void Sort(ref int[] arr, int left, int right) {
            if (left >= right)
                return;

            int medianIdx = SelectKth(ref arr, 1 + (right - left) / 2, left, right);
            int mid = (right + left) / 2;
            swap(ref arr[mid], ref arr[medianIdx]);

            int k = mid + 1;
            for (int i = left; i < mid; i++)
            {
                if (arr[i] > arr[mid])
                {
                    while (arr[k] > arr[mid])
                        k++;
                    swap(ref arr[i], ref arr[k]);
                }
            }
            Sort(ref arr, left, mid - 1);
            Sort(ref arr, mid + 1, right);

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

            Sort(ref arr, 0, arr.Length-1);
            Console.WriteLine("\nSorted:");
            foreach (var num in arr)
            {
                Console.Write(num + " ");
            }
        }
    }
}

