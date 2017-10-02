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
  			var numbers = Enumerable.Range(0, n + 1).Select(x => x).ToArray();
  			var lenRoot = Math.Sqrt(n);

  			for (var i = 2; i <= lenRoot; i++)
  			{
  				if (numbers[i] == 0)
  					continue;

  				for (int j = i * i; j < numbers.Length; j += i)
  				{
  					if (numbers[j] != 0)
  						numbers[j] = 0;
  				}
  			}

  			return numbers.Where(x => x > 1).ToArray();
  		}
    }
}
