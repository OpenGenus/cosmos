using System;
using System.Text.RegularExpressions;

namespace myApp
{
    public class RunningKey
    {
        private const int ALPHABET_SIZE = 26;
        private static Regex rx = new Regex(@"^[A-Za-z]+$", RegexOptions.Compiled | RegexOptions.IgnoreCase);

        public static void Main(string[] args)
        {
            bool canParse = false, validCode = false;
            do
            {
                println("Type '1' for encryption, '2' for decryption, 'exit' for exit program and press enter.");
                string input = Console.ReadLine();
                if (input.Equals("exit", StringComparison.OrdinalIgnoreCase))
                {
                    println("Exit program...");
                    return;
                }
                canParse = Int16.TryParse(input, out short type);
                if (canParse == false)
                {
                    println("Invalid code, please try again.");
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
                            println("Invalid code, please try again.");
                            break;
                    }
                }
            }
            while (canParse == false || validCode == false);
        }

        private static void print(string message)
        {
            Console.Write(message);
        }

        private static void println(string message)
        {
            Console.WriteLine(message);
        }

        private static void encryptionWrapper()
        {
            bool isValid = true;
            do
            {
                print("Enter plaintext which you want to encrypt >> ");
                string plainText = Console.ReadLine();
                print("Enter key with size equal plaintext >> ");
                string key = Console.ReadLine();

                // Validate
                MatchCollection matches1 = rx.Matches(plainText);
                MatchCollection matches2 = rx.Matches(key);

                if (matches1.Count <= 0 || matches2.Count <= 0)
                {
                    isValid = false;
                    println("** Plaintext/key invalid, must contain only alphabet, not number not punctuation, please try again **");
                }
                else if (plainText.Length != key.Length)
                {
                    isValid = false;
                    println("** Size of plaintext and key must equal, please try again **");
                }
                else
                {
                    isValid = true;
                    encrypt(plainText, key);
                }
            }
            while (isValid == false);
        }

        private static void encrypt(string plaintext, string key)
        {
            plaintext = plaintext.ToLower();
            key = key.ToLower();
            string cipherText = "";

            for (int i = 0; i < plaintext.Length; ++i)
            {
                char a = plaintext[i];
                char b = key[i];
                int result = ((Convert.ToByte(a) - 97) + (Convert.ToByte(b) - 97)) % ALPHABET_SIZE + 97;
                char cipherChar = Convert.ToChar((byte)result);
                cipherText += cipherChar;
            }
            print($"Ciphertext : {cipherText}");
        }

        private static void decryptionWrapper()
        {
            bool isValid = true;
            do
            {
                print("Enter ciphertext which you want to decrypt >> ");
                string ciphertext = Console.ReadLine();
                print("Enter key with size equal ciphertext >> ");
                string key = Console.ReadLine();

                // Validate
                MatchCollection matches1 = rx.Matches(ciphertext);
                MatchCollection matches2 = rx.Matches(key);

                if (matches1.Count <= 0 || matches2.Count <= 0)
                {
                    isValid = false;
                    println("** Ciphertext/key invalid, must contain only alphabet, not number not punctuation, please try again **");
                }
                else if (ciphertext.Length != key.Length)
                {
                    isValid = false;
                    println("** Size of ciphertext and key must equal, please try again **");
                }
                else
                {
                    isValid = true;
                    decrypt(ciphertext, key);
                }
            }
            while (isValid == false);
        }

        private static void decrypt(string ciphertext, string key)
        {
            ciphertext = ciphertext.ToLower();
            key = key.ToLower();
            string plaintext = "";

            for (int i = 0; i < ciphertext.Length; ++i)
            {
                char a = ciphertext[i];
                char b = key[i];
                int result = (ALPHABET_SIZE + (Convert.ToByte(a) - 97) - (Convert.ToByte(b) - 97)) % ALPHABET_SIZE + 97;
                char plainChar = Convert.ToChar((byte)result);
                plaintext += plainChar;
            }
            print($"Plaintext : {plaintext}");
        }
    }
}