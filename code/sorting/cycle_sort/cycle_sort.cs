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
			var array = Enumerable.Range(1, 20).Select(x => random.Next(1,40)).ToArray();

			Console.WriteLine("Unsorted");
			Console.WriteLine(string.Join(",", array));

			Console.WriteLine("\nSorted");
			
			var writes = CycleSort(array);
			Console.WriteLine(string.Join(",", array));
			Console.WriteLine($"\nNumber of writes: {writes}");

			Console.ReadLine();
		}

		// Adapted from Wikipedia CycleSort pseudocode
		private static int CycleSort(int[] array)
		{
			// Sort an array in place and return the number of writes.
			var writes = 0;
			var cycleStart = 0;
			var arrayLength = array.Length;

			// Loop through the array to find cycles to rotate.
			for (; cycleStart < arrayLength; cycleStart++) {
				var item = array[cycleStart];

				// Find where to put the item.
				var position = cycleStart;

				for (var i = cycleStart + 1; i < arrayLength; i++)
					if (array[i] < item)
						position++;

				// If the item is already there, this is not a cycle.
				if (position == cycleStart)
					continue;

				// Otherwise, put the item there or right after any duplicates.
				while (item == array[position])
					position++;

				var tempSwapItem = array[position];
				array[position] = item;
				item = tempSwapItem;

				writes++;

				// Rotate the rest of the cycle.
				while (position != cycleStart)
				{
					// Find where to put the item.
					position = cycleStart;

					for (var j = cycleStart + 1; j < arrayLength; j++)
						if (array[j] < item)
							position++;

					// Put the item there or right after any duplicates.
					while (item == array[position])
						position++;

					tempSwapItem = array[position];
					array[position] = item;
					item = tempSwapItem;

					writes++;
				}
			}

			return writes;
		}
	}
}
