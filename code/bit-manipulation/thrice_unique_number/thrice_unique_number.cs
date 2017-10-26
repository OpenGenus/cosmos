using System;

class Program
    {
        static void Main(string[] args)
        {
            int[] arr = new int[] { 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 10, 10, 22, 11, 34, 34, 34, 11, 11, 10 };

            //Check bits coming in for first time, second time and third time
            int first = 0, second = 0, third = 0;

            //New bits coming in for the corresponding number of times
            int firstNew = 0, secondNew = 0, thirdNew = 0;

            for (int i = 0; i < arr.Length; i++)
            {
                //Get new bits by checking that they are already not there in the other bits
                //Exception: if bits are alread there in third time, they can be counted for the first time as bits coming in for the 4th, 7th.. time are to be considered for the first time variable.
                //The equivalent of applying mod operation, i.e: 4%3 is 1
                firstNew = arr[i] & ~first & ~second;
                secondNew = (arr[i] & first) & ~second & ~third;
                thirdNew = arr[i] & ~first & second & ~third;

                first ^= firstNew;
                first &= ~secondNew;
                first &= ~thirdNew;

                second ^= secondNew;
                second &= ~firstNew;
                second &= ~thirdNew;

                third ^= thirdNew;
                third &= ~secondNew;
                third &= ~firstNew;
            }

            Console.WriteLine(first);
        }
    }