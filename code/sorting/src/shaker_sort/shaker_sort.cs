using System;
using System.Linq;

/* Part of Cosmos by OpenGenus Foundation */
namespace OpenGenus
{
	class Program
	{
		static void Main(string[] args)
		{
			var random = new Random();
			var unsorted = Enumerable.Range(1, 20).Select(x => random.Next(1,40)).ToArray();

			Console.WriteLine("Unsorted");
			Console.WriteLine(string.Join(",", unsorted));

			Console.WriteLine("\nSorted");

			var sorted = ShakerSort(unsorted);
			Console.WriteLine(string.Join(",", sorted));

			Console.ReadLine();
		}

		private static int[] ShakerSort(int[] array)
		{
			var swap = false;
			int tempSwap;
			var arrayLen = array.Length;

			for (var i = 0; i < arrayLen / 2; ++i)
			{
				// pass to right pushing the largest value along
				for (var j = i; j < arrayLen - i - 1; ++j)
				{
					if (array[j] > array[j + 1])
					{
						tempSwap = array[j];
						array[j] = array[j + 1];
						array[j + 1] = tempSwap;
						swap = true;
					}
				}

				// pass back to left pushing the smallest down
				for (var j = arrayLen - i - 2; j > i; j--)
				{
					if (array[j] < array[j - 1])
					{
						tempSwap = array[j];
						array[j] = array[j - 1];
						array[j - 1] = tempSwap;
						swap = true;
					}
				}

				// if nothing was swapped, then the array is sorted
				if (!swap)
					break;
			}

			return array;
		}
	}
}
