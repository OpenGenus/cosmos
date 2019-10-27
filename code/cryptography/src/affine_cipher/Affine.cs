using System;
using System.Text;

namespace myApp
{
    public class Affine
    {
        private const int ALPHABET_SIZE = 26;

        public static void Main(string[] args)
        {
            bool canParse = false;
            bool validCode = false;
            do
            {
                Console.WriteLine("Type '1' for encryption, '2' for decryption, 'exit' for exit program and press enter.");
                string input = Console.ReadLine();
                if (input.Equals("exit", StringComparison.OrdinalIgnoreCase))
                {
                    Console.WriteLine("Exit program...");
                    return;
                }
                canParse = Int16.TryParse(input, out short type);
                if (canParse == false)
                {
                    Console.WriteLine("Invalid code, please try again.");
                }
                else
                {
                    validCode = true;
                    switch (type)
                    {
                        case 1:
                            encryptionWrapper();
                            break;
                        case 2:
                            decryptionWrapper();
                            break;
                        default:
                            validCode = false;
                            Console.WriteLine("Invalid code, please try again.");
                            break;
                    }
                }
            }
            while (canParse == false || validCode == false);
        }

        private static void encryptionWrapper()
        {
            bool isAOk = false, isBOk = false;
            int a = 0, b = 0;

            Console.Write("Enter plaintext which want to encryption >> ");
            string plaintext = Console.ReadLine();

            do
            {
                Console.Write("Choose 'a' but gcd (a,26) must equal 1\n" +
                        "'a' might be {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25} >> ");
                bool canParse = Int32.TryParse(Console.ReadLine(), out a);
                if (canParse == true)
                {
                    if (gcd(a, ALPHABET_SIZE) == 1)
                    {
                        isAOk = true;
                    }
                }
                if (isAOk == false)
                {
                    Console.WriteLine("'a' is not ok, please try agian.");
                }
            }
            while (isAOk == false);

            do
            {
                Console.Write("Choose 'b' which number you want but not equal 1 >> ");
                bool canParse = Int32.TryParse(Console.ReadLine(), out b);
                if (canParse == true)
                {
                    if (b != 1)
                    {
                        isBOk = true;
                    }
                }
                if (isBOk == false)
                {
                    Console.WriteLine("'b' is not ok, please try again.");
                }
            }
            while (isBOk == false);
            encrypt(a, b, plaintext);
        }

        private static void encrypt(int a, int b, String plaintext)
        {
            if (plaintext == null || plaintext.Length <= 0)
            {
                Console.WriteLine("Plaintext has a problem. Bye bye :)");
                return;
            }

            plaintext = plaintext.ToLower();
            StringBuilder ciphertext = new StringBuilder();

            for (int i = 0; i < plaintext.Length; i++)
            {
                char agent = plaintext[i];
                int value = ((a * (agent - 97) + b) % ALPHABET_SIZE);
                ciphertext.Append((char)(value + 97));
            }
            Console.WriteLine($"Ciphertext: {ciphertext}");
        }

        private static void decryptionWrapper()
        {
            int a, aInverse = 0, b;
            bool isAOk = false;
            bool isBOk = false;

            Console.Write("Enter ciphertext which want to decryption >> ");
            string ciphertext = Console.ReadLine();

            do
            {
                Console.Write("Enter key 'a' >> ");
                bool canParse = Int32.TryParse(Console.ReadLine(), out a);
                if (canParse)
                {
                    if (gcd(a, ALPHABET_SIZE) == 1)
                    {
                        isAOk = true;
                        aInverse = findInverse(a, ALPHABET_SIZE);
                    }
                }
                if (isAOk == false)
                {
                    Console.WriteLine("'a' is not ok, please try again.");
                }
            }
            while (isAOk == false);

            do
            {
                Console.Write("Enter key 'b' >> ");
                bool canParse = Int32.TryParse(Console.ReadLine(), out b);
                if (canParse == true)
                {
                    isBOk = true;
                    decrypt(aInverse, b, ciphertext);
                }
                else
                {
                    Console.WriteLine("'b' is not integer, please try again.");
                }
            }
            while (isBOk == false);
        }

        private static void decrypt(int aInverse, int b, String ciphertext)
        {
            if (ciphertext == null || ciphertext.Length <= 0)
            {
                Console.WriteLine("Plaintext has a problem. Bye bye :)");
                return;
            }

            ciphertext = ciphertext.ToLower();
            StringBuilder plaintext = new StringBuilder();
            int z, j;

            for (int i = 0; i < ciphertext.Length; i++)
            {
                char agent = ciphertext[i];
                z = aInverse * ((agent - 97) - b);
                j = z < 0 ? minusMod(z, ALPHABET_SIZE) : z % ALPHABET_SIZE;
                plaintext.Append((char)('A' + j));
            }
            Console.WriteLine($"Plaintext: {plaintext}");
        }

        #region Utility

        private static int gcd(int a, int b)
        {
            return b == 0 ? a : gcd(b, a % b);
        }

        private static int minusMod(int minus, int mod)
        {
            int a = Math.Abs(minus);
            return (mod * ((a / mod) + 1)) - a;
        }

        private static int findInverse(double firstNumber, double anotherNumber)
        {
            int a1, b1, a2, b2, r, q, temp_a2, temp_b2, n1, n2, max;

            if (firstNumber > anotherNumber)
            {
                max = (int)firstNumber;
                n1 = (int)firstNumber;
                n2 = (int)anotherNumber;
            }
            else
            {
                max = (int)anotherNumber;
                n1 = (int)anotherNumber;
                n2 = (int)firstNumber;
            }

            a1 = b2 = 1;
            b1 = a2 = 0;
            temp_a2 = a2;
            temp_b2 = b2;

            r = n1 % n2;
            q = n1 / n2;

            while (r != 0)
            {
                n1 = n2;
                n2 = r;
                a2 = a1 - q * a2;
                b2 = b1 - q * b2;
                a1 = temp_a2;
                b1 = temp_b2;
                temp_a2 = a2;
                temp_b2 = b2;
                r = n1 % n2;
                q = n1 / n2;
            }

            int result;
            if (firstNumber == max)
            {
                if (a2 < 0)
                {
                    result = (int)(a2 - anotherNumber * Math.Floor(a2 / anotherNumber));
                }
                else
                {
                    result = a2;
                }
            }
            else
            {
                if (b2 < 0)
                {
                    result = (int)(b2 - anotherNumber * Math.Floor(b2 / anotherNumber));
                }
                else
                    result = b2;
            }
            return result;
        }

        #endregion
    }
}