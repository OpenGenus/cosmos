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
            bool special_char = password.Any(ch => !char.IsLetterOrDigit(ch));
            bool digit = password.Any(char.IsDigit);
            bool uppercase = password.Any(char.IsUpper);
            
            if (password.Length < 8)
                return false;

            if (!special_char || !digit || !uppercase)
                return false;

            return true;
        }
        static void Main(string[] args)
        {
            string passwd = "Gurk!rat1337";

            if (chk_strength(passwd))
            {
                Console.WriteLine("Strong!!!");
            }
            else {
                Console.WriteLine("Weak :(");
            }

            Console.ReadKey();
        }
    }
}
