using System;
using System.Numerics; // Add this reference to the project to use BigInteger

namespace FibonacciNumber {
	class Program {
		static void Main(string[] args) {
			Console.WriteLine(Fibonacci(1)); // 0
			Console.WriteLine(Fibonacci(17)); // 987
			Console.WriteLine(Fibonacci(33)); // 2178309
			Console.WriteLine(Fibonacci(42)); // 165580141
			Console.WriteLine(Fibonacci(123)); // 14028366653498915298923761
			Console.WriteLine(Fibonacci(777)); // 668226711200301698374224176558256700160458774333255425461900331623619273605518323137569702870357755802337031006361339094239227806499153841600804020665750176206357
			Console.WriteLine(Fibonacci(1001)); // 43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875
		}

		static BigInteger Fibonacci(int n) {
			int i = 0;
			BigInteger a = 0, b = 1;
			while(++i < n) {
				b += a;
				a = b - a;
			}
			return a;
		}
	}
}
