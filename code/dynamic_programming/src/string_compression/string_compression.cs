using System;
using System.IO;
using System.Text;

class MainClass
{
    public static void Main(string[] args)
    {
        string userInput = "wwwcosmoos";
        strCompress(userInput);
    }

    public static void strCompress(string userInput)
    {
        int n = userInput.Length;
        for (int i = 0; i < n; i++)
        {
            int count = 1;
            string newStr;
            while (i < n - 1 && userInput[i] == userInput[i + 1])
            {
                count++;
                i++;
            }
            newStr = $"{userInput[i]}{count}";

            Console.Write(newStr.Length < n ? $"{userInput[i]}{count}" : userInput);
        }
    }
}