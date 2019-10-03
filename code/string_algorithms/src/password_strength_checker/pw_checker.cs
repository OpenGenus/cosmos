using System;
using System.Linq;

/*
 * part of cosmos from opengenus foundation
 * */
namespace password_strength_check
{
    class Program
    {
        static bool chk_strength(string password)
        {
            return (password.Length > 8 && password.Any(ch => !char.IsLetterOrDigit(ch)) && password.Any(char.IsDigit) && password.Any(char.IsUpper));
        }
        static void Main(string[] args)
        {
            string passwd = "Gurkirat1337";

            if (chk_strength(passwd))
            {
                Console.WriteLine("Strong!!!");
            }
            else
            {
                Console.WriteLine("Weak :(");
            }

            Console.ReadKey();
        }
    }
}
