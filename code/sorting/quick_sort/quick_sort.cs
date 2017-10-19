using System;
using System.Collections.Generic;
/*
 * Part of Cosmos by OpenGenus Foundation
 */
namespace ConsoleApplicationQSort
{
	class Program
	{
		static void Main(string[] args)
		{
			var A = new int[] { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
			var sorter = new QSort<int>(A);
			sorter.Sort();
			foreach (var i in sorter.A)
				Console.WriteLine(i);

			Console.Read();
		}
	}

	class QSort<T> where T:IComparable
	{
		public IList<T> A;
		public QSort(IList<T> A)
		{
			this.A = A;
		}
		public int Partition(int L, int U)
		{
			int s = U;
			int p = L;
			while (s != p)
			{
				if (A[p].CompareTo(A[s]) <= 0)
				{
					p++;
				}
				else
				{
					Swap(p, s);
					Swap(p, s - 1);
					s--;
				}
			}
			return p;
		}

		private void Swap(int p, int s)
		{
			T tmp = A[p];
			A[p] = A[s];
			A[s] = tmp;
		}

		public void Sort(int L, int U)
		{
			if (L >= U) return;
			int p = Partition(L, U);
			Sort(L, p-1);
			Sort(p + 1, U);
		}

		public void Sort()
		{
			Sort(0, A.Count - 1);
		}
	}
}
