/*
 *Part of Cosmos by OpenGenus Foundation
 */
using System;

namespace FractionalKnapsack
{
    // Custom object for Item to store its weight and value
    public class Item
    {
        public int Value { get; set; }
        public int Weight { get; set; }

        public Item(int value,int weight)
        {
            this.Value = value;
            this.Weight = weight;
        }
    }


   public class FractionalKnapsack
    {

        // Custom comparison function to sort Items according to val/weight ratio
        private static int CompareItems(Item a, Item b)
        {
            double r1 = (double)a.Value / a.Weight;
            double r2 = (double)b.Value / b.Weight;

            //items are the same object or equal r
            if(a == b || r1 == r2)
            {
                return 0;

            }
            //a < b
            else if (r1 < r2)
            {
                return 1;
            }
            //b < a
            else
            {
                return -1;
            }

        }

        private static double FractionalKnapsack(int W, Item[] arr)
        {
            //sorting Item on basis of ratio value/weight
            Array.Sort(arr, CompareItems);

            int curWeight = 0;  // Current weight in knapsack
            double finalvalue = 0.0; // Result (value in Knapsack)

            // Looping through all Items
            for (int i = 0; i < arr.Length; i++)
            {
                // If adding Item won't overflow, add it completely
                if (curWeight + arr[i].Weight <= W)
                {
                    curWeight += arr[i].Weight;
                    finalvalue += arr[i].Value;
                }

                // If we can't add current Item, add a fraction of it
                else
                {
                    int remain = W - curWeight;
                    finalvalue += arr[i].Value * ((double)remain / arr[i].Weight);
                    break;
                }
            }

            // Returning final value
            return finalvalue;
        }

        public static void Main(string[] args)
        {
            int W = 50;   //    Weight of knapsack

            Item[] arr = {
                new Item(60,10),
                new Item(100,20),
                new Item(120,30)
            };

            Console.WriteLine("Maximum value we can obtain = " + FractionalKnapsack(W, arr));

        }

    }
}