// c# program to reverse a Queue  
using System; 
using System.Collections.Generic; 
  
public class RONALDO 
{ 
  
public static LinkedList<int> queue; 
  
// Utility function to print the queue  
public static void Print() 
{ 
    while (queue.Count > 0) 
    { 
        Console.Write(queue.First.Value + ", "); 
        queue.RemoveFirst(); 
    } 
} 
  
// Function to reverse the queue  
public static void reversequeue() 
{ 
    Stack<int> stack = new Stack<int>(); 
    while (queue.Count > 0) 
    { 
        stack.Push(queue.First.Value); 
        queue.RemoveFirst(); 
    } 
    while (stack.Count > 0) 
    { 
        queue.AddLast(stack.Peek()); 
        stack.Pop(); 
    } 
} 
  
// Driver code  
public static void Main(string[] args) 
{ 
    queue = new LinkedList<int>(); 
    queue.AddLast(10); 
    queue.AddLast(20); 
    queue.AddLast(30); 
    queue.AddLast(40); 
    queue.AddLast(50); 
    queue.AddLast(60); 
    queue.AddLast(70); 
    queue.AddLast(80); 
    queue.AddLast(90); 
    queue.AddLast(100); 
  
    reversequeue(); 
    Print(); 
} 
} 
