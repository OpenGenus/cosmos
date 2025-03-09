/*

    Part of Cosmos by OpenGenus Foundation
    Created by Jiraphapa Jiravaraphan on 14/10/2017 
    Check if a number is a power of 2 - C# implementation

*/

using System;

namespace Application1
{
public static class Program
{
    public static bool isPowerOfTwo(ulong num)
    {
    return (num != 0) && ((num & (num - 1)) == 0);
    }

    public static void Main(string[] args)
    {
        bool result = isPowerOfTwo(64);
        Console.WriteLine(result);
    }
}
}
