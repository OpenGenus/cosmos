using System;
using System.Collections.Generic;
using System.Linq;
// Part of Cosmos by OpenGenus Foundation
namespace OpenGenus
{
	class Program
	{
		static void Main(string[] args)
		{
			var random = new Random();

			// generate randomly sized array (length 1-100) with random values
			var inputSize = random.Next(1, 100);
			var unsorted = Enumerable.Range(1, inputSize).Select(x => random.Next()).ToArray();

			Console.WriteLine("Unsorted");
			Console.WriteLine(string.Join(",", unsorted));
			Console.WriteLine("\nSorted");

			var sorted = BucketSort(unsorted, 10);

			Console.WriteLine(string.Join(",", sorted));
			Console.ReadLine();
		}

		private static int[] BucketSort(int[] unsorted, int bucketCount)
		{
			// create bucket list
			var buckets = new List<List<int>>();

			// find min/max values
			var max = unsorted.Max();
			var min = unsorted.Min();

			// determine bucket size (max + 1 used to ensure bucketIndex stays in range)
			var bucketSize = (int)Math.Ceiling(( (max + 1) - min ) / (decimal)bucketCount);

			// add empty buckets
			for (var i = 0; i < bucketCount; i++)
				buckets.Add(new List<int>());

			// distribute numbers to buckets
			for (var i = 0; i < unsorted.Length; i++)
			{
				var number = unsorted[i];
				var bucketIndex = (number - min) / bucketSize;
				buckets[bucketIndex].Add(number);
			}

			// sort each bucket
			foreach (var bucket in buckets)
			{
				// use sort method of choice here
				bucket.Sort();
			}

			// return concatenated buckets as sorted array
			return buckets.SelectMany(x => x).ToArray();
		}
	}
}
