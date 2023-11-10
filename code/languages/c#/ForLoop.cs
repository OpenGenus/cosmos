using System;

/* This explains and will show a demonstration behind for loops in C#.

The format of a for loop is as follows:
for (int i = 0; i < 5; i++)
{
    DoSomething();
}

The first part of the for loop is the initializer. This is only executed once and only once before
the rest of the statements are ran.
int i = 0;
Here, we set the variable i to 0. This variable is often referred to as the indexer.

Next, there is a termination condition. This condition, once false, will stop going through the loop.
i < 5;
In our example, as long as i is less than 5, the for loop will continue to execute.

Finally, the last statement is what is executed at the end of the loop. This will almost always be
an incrementing/decrementing statement.
i++
With our example, we increase i by 1 each time the loop is executed.

The body of the loop will execute if it passes the terminating conditional (running the theoretical
DoSomething method), then will run the third statement of the for loop (in our case i++), and
continue through the loop in this process until the terminating statement is no longer true.

So, knowing this, we can discern the loop will run 5 times. The first time the loop is executed,
i = 0. After the loop is executed the first time, i = 1. This repeats until i = 5, at which the loop
is terminated.
*/

// Counts from 1 to 100
for (int i = 1; i <= 100; i++)
{
    Console.WriteLine(i);   // This will print the value of i.
}