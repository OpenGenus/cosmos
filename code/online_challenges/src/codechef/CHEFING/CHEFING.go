using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;

namespace ChefAndIngredients
{
    public class Program
    {
        private static TextReader Reader;
        public static bool Debug = false;
        public static List<string> Answer;

        public static void Main(string[] args)
        {
            if (Debug)
            {
                Reader = File.OpenText(args[0]);
            }
            else
            {
                Reader = Console.In;
            }
            var output = new List<string>();
            var testCount = ReadLineAsInt();
            for (var i = 0; i < testCount; i++)
            {
                var data = ReadLineAsLongArray();
                var n = data[0];
                var k = data[1];
                var result = Solve(n, k);

                if (Debug)
                {
                    output.Add(result.ToString());
                }
                else
                {
                    Console.WriteLine(result);
                }
            }

            Answer = output;
        }


        const long Modulo = 1000000007;
        
        public static long Solve(long n, long k)
        {
            if (n == 2)
            {
                var res = new BigInteger(k-1) * new BigInteger(k);
                res = res / 2;
                res = res % Modulo;
                return (long)res;
            }
            var reste = (k-1)%(n-1);
            var newK = (k - 1) / (n - 1);
            if (reste != 0)
            {
                newK++;
                reste++;
                //reste = (n - 1) - reste;
            }
            var result = new BigInteger(newK) * new BigInteger(newK+1);
            result = result / 2;
            result = result * (n - 1);
            result = result - (newK *(n-1)- k+1) * newK;//new BigInteger(reste) * (n - 1);
            result = result % Modulo;
            return (long)result;


            /*
            long missing = k - 1;
            long result = missing;
            while (missing > 0)
            {
                missing -= n - 1;
                if (missing > 0) result = (result + missing) % Modulo;
            }
            return result;*/
        }
        public static long SlowSolve(long n, long k)
        {
            long missing = k - 1;
            long result = missing;
            while (missing > 0)
            {
                missing -= n - 1;
                if (missing > 0) result = (result + missing) % Modulo;
            }
            return result;
        }

        static int ReadLineAsInt()
        {
            return int.Parse(Reader.ReadLine());
        }

        static string ReadLineAsString()
        {
            return Reader.ReadLine();
        }

        static long[] ReadLineAsLongArray()
        {
            return Reader.ReadLine().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(long.Parse).ToArray();
        }
    }

}