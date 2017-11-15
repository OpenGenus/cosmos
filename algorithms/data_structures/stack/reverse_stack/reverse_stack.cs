using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
// Part of Cosmos by OpenGenus Foundation
namespace reversed_stack
{
    class Program
    {
        /// <summary>
        /// This will print all elements in stack 
        /// Format :: [element1] [element2] ... 
        /// </summary>
        /// <param name="STK">an object of Stack collection of type int is accepted</param>
        static void print(Stack<int> STK)
        {
            foreach(int val in STK)
            {
                Console.Write(val.ToString() + " ");
            }
            Console.WriteLine(); // printing new line
        }
        /// <summary>
        /// This will take a stack collection object of int type and returns the reverse of the same
        /// </summary>
        /// <param name="STK"></param>
        /// <returns></returns>
        static Stack<int> reverse(Stack<int> STK)
        {
            Stack<int> ret = new Stack<int>(); // a temp object of stack
            while(STK.Count > 0) // if stack has some value it will execute
            {
                ret.Push(STK.Pop()); // STK.pop() returns the top most value which we have to push in temp / reversed stack
            }
            return ret;
        }

        static void Main(string[] args)
        {
            Stack<int> stk = new Stack<int>();  // creating a object of inbuilt collection Stack
            
            // here i am pushing 5 numbers in stack for demo
            stk.Push(5);
            stk.Push(4);
            stk.Push(3);
            stk.Push(2);
            stk.Push(1);
            
            // printing original elements in stack 
            Console.WriteLine("ORIGINAL STACK");
            print(stk);

            // reversing the stack now
            stk = reverse(stk);

            // printing original elements in stack 
            Console.WriteLine("REVERSED STACK");
            print(stk);

            Console.ReadKey(); // It has stopped till key has not been pressed
        }
    }
}
