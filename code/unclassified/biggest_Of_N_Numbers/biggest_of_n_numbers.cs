using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        Console.Write("Enter numbers, separated by commas: ");
        var numbers = Console.ReadLine();
        var listOfNumbers = numbers.Split(',').Select(int.Parse);

        Console.Write("The largest number is: ");
        var max = listOfNumbers.Max();
        Console.WriteLine(max);
    }
}
