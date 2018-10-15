/* Part of Cosmos by OpenGenus Foundation */
using System;
using System.Linq;

namespace BubbleSortCSharp
{
	class BubbleSort
	{

		static void sort(int[] a){
			for (int i = a.Length - 1; i > 0; i--)
			{
				for (int j = 0; j <= i - 1; j++)
				{
					if (a[j] > a[j + 1])
					{
						int temp = a[j];
						a[j] = a[j + 1];
						a[j + 1] = temp;
					}
				}
			}
		}

		static void Main(string[] args)
		{
			Console.WriteLine("Enter values to sort separated by space");
			var a = Console.ReadLine().Split(' ')
				.Select(i => int.Parse(i))
				.ToArray();

			sort(a);

			Console.WriteLine("Sorted Array: ");
			foreach(int item in a)
			{
				Console.WriteLine(item);
			}
		}
	}
}
