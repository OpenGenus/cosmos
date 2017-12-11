/*
 * Bailey Thompson
 * github.com/bkthomps
 *
 * Simple implementation of RSA Encryption.
 */

using System;
using System.Numerics;
using System.Collections.Generic;

namespace rsa
{
    /*
     * Entry point of the program, display information to user on console.
     */
    internal static class Program
    {
        private static void Main()
        {
            var primeGen = new Primes();
            var key = primeGen.GetKey();
            const string message = "Hello World!";
            Console.WriteLine("Original Text: \"" + message + "\"");
            var cypherText = key.Encrypt(message);
            Console.Write("Cypher Text: ");
            var isFirstLetter = true;
            foreach (var place in cypherText)
            {
                if (isFirstLetter)
                {
                    isFirstLetter = false;
                    Console.Write(place);
                    continue;
                }
                Console.Write(", " + place);
            }
            Console.WriteLine();
            var decryptedText = key.Decrypt(cypherText);
            Console.WriteLine("Decrypted Text: \"" + decryptedText + "\"");
        }
    }

    /*
     * Create a list of primes, with ability to create keys using the list.
     */
    internal class Primes
    {
        private const int MaxValue = 25000;
        private readonly bool[] isPrime = new bool[MaxValue + 1];
        private readonly List<int> primes = new List<int>();

        internal Primes()
        {
            for (var i = 2; i <= MaxValue; i++)
            {
                if (!isPrime[i])
                {
                    primes.Add(i);
                    for (var j = i * i; j <= MaxValue; j += i)
                    {
                        isPrime[j] = true;
                    }
                }
            }
        }

        internal Key GetKey()
        {
            var end = primes.Count - 1;
            var start = end / 4;
            var random = new Random();
            var primeOne = primes[random.Next(start, end)];
            var primeTwo = primes[random.Next(start, end)];
            while (primeTwo == primeOne)
            {
                primeTwo = primes[random.Next(start, end)];
            }
            return new Key(primeOne, primeTwo, primes);
        }
    }

    /*
     * Create a key using two primes. The variable n is both primes multiplied, phi is each prime minus one multiplied
     * together. The variable e has to satisfy gcd(e, phi) = 1, so just another prime. The variable d has to satisfy
     * ed = 1 mod phi. The public key is (e, n) and the private key is (d, n).
     */
    internal class Key
    {
        private readonly int n;
        private readonly int e;
        private int d;

        internal Key(int primeOne, int primeTwo, List<int> primes)
        {
            n = primeOne * primeTwo;
            var phi = (primeOne - 1) * (primeTwo - 1);
            var end = primes.Count - 1;
            var start = end / 4;
            var random = new Random();
            do
            {
                do
                {
                    e = primes[random.Next(start, end)];
                } while (e == primeOne || e == primeTwo);
            } while (!IsFoundD(phi));
            Console.WriteLine("Public Key: (e, n) = (" + e + ", " + n + ")");
        }

        private bool IsFoundD(int phi)
        {
            for (var i = phi - 1; i > 1; i--)
            {
                var mul = BigInteger.Multiply(e, i);
                var result = BigInteger.Remainder(mul, phi);
                if (result.Equals(1))
                {
                    d = i;
                    Console.WriteLine("Private Key: (d, n) = (" + d + ", " + n + ")");
                    return true;
                }
            }
            return false;
        }

        internal int[] Encrypt(string message)
        {
            var charArray = message.ToCharArray();
            var array = new int[charArray.Length];
            for (var i = 0; i < array.Length; i++)
            {
                array[i] = (int) BigInteger.ModPow(charArray[i], e, n);
            }
            return array;
        }

        internal string Decrypt(int[] cyphertext)
        {
            var array = new char[cyphertext.Length];
            for (var i = 0; i < array.Length; i++)
            {
                array[i] = (char) BigInteger.ModPow(cyphertext[i], d, n);
            }
            return new string(array);
        }
    }
}
