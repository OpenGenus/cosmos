// Part of OpenGenus Cosmos
using System.IO;
using System;
using System.Linq;
using System.Collections.Generic;

class PigeonHoleSort
{

    static void InsertValuesInPigeonHoles(int[] unsortedArray, List<int>[] pigeonHoles){
        var minValue = unsortedArray.Min();
        foreach(var item in unsortedArray){
            var i = item - minValue;
            if(pigeonHoles[i] == null){
                pigeonHoles[i] = new List<int>();
            }
            pigeonHoles[i].Add(item);
        }
    }

    static int[] ExtractSortedValuesFromPigeonHoles(List<int>[] pigeonHoles){
        var sortedList = new List<int>();
        foreach (var hole in pigeonHoles)
        {
            foreach (var holeItem in hole)
            {
                sortedList.Add(holeItem);
            }
        }
        return sortedList.ToArray();
    }

    static int[] sortUsingPigeonHole(int[] unsortedArray){
        var rangeOfNumbers = unsortedArray.Max() - unsortedArray.Min() + 1;
        var pigeonHoles = new List<int>[rangeOfNumbers];
        InsertValuesInPigeonHoles(unsortedArray, pigeonHoles);
        return ExtractSortedValuesFromPigeonHoles(pigeonHoles);
    }

    static void DisplaySortedItems(int[] sortedArray){
        Console.WriteLine("Sorted array");
        foreach (var item in sortedArray)
        {
            Console.Write($"{item} ");
        }
    }

    static int[] ConvertToIntArray(string[] arr){
        var length = arr.Length;
        var intArray = new int[length];
        for(int i=0;i<length;i++){
            intArray[i] = int.Parse(arr[i]);
        }
        return intArray;
    }

    static void Main()
    {
        Console.WriteLine("Enter the unsorted elements separated by space");
        var unsortedArray = Console.ReadLine().Split(' ');
        var sortedArray = sortUsingPigeonHole(ConvertToIntArray(unsortedArray));
        DisplaySortedItems(sortedArray);
    }
}
