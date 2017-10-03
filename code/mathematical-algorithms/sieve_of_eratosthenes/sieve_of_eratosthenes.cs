using System;
using System.Linq;

namespace OpenGenus
{
	// Part of Cosmos by OpenGenus Foundation
	class Program
   	{
  		public static void Main(string[] args)
  		{
  			var random = new Random();
  			var n = random.Next(1, 1000);
  			var primes = SieveOfEratosthenes(n);

  			Console.WriteLine($"Primes up to {n}\n");
  			Console.WriteLine(string.Join(",", primes));
  			Console.ReadLine();
  		}

  		private static int[] SieveOfEratosthenes(int n)
  		{
			// create number list from 0 to n
  			var numbers = Enumerable.Range(0, n + 1).Select(x => x).ToArray();
  			var lenRoot = Math.Sqrt(n);
			
			// go through all possible factors of numbers in the range bound inclusive by 2 and n
  			for (var i = 2; i <= lenRoot; i++)
  			{
				// skip numbers already blanked by a prime factor
  				if (numbers[i] == 0)
  					continue;

  				for (int j = i * i; j < numbers.Length; j += i)
  				{
					// blank out any multiple of i
					numbers[j] = 0;
  				}
  			}
			
			// return all numbers between 2 and n
			// these will be all primes in the range
  			return numbers.Where(x => x > 1).ToArray();
  		}
    }
}
