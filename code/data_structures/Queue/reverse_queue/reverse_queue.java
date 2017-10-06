import java.util.*;

public class reverse_queue {
// Part of Cosmos by OpenGenus Foundation
    //method to print contents of queue
    public static void print(Queue<Integer> queue) {
      for(int x : queue) {
        System.out.print(x + " ");
      }
      System.out.print("\n");
    }

public static void main (String[] args) {
      Queue<Integer> queue = new LinkedList<Integer>();
      Stack<Integer> stack = new Stack<Integer>();

      //build the queue with 1..5
      for(int i=0; i<=5; i++) {
        queue.add(i);
      }
      //print the queue
      print(queue);

      //move queue contents to stack
      while(!queue.isEmpty()) {
        stack.push(queue.poll());
      }

      //move stack contents back to queue
      while(!stack.isEmpty()) {
        queue.add(stack.pop());
      }
      //reprint reversed queue
      print(queue);
    }
}
