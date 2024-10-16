using System;

/* This demonstrates the use of if/else if/else flow conditionals. 

Why do we use these?
Simple! It's a way to 'make a decision' and have code based on that decision execute. An example
would be if you wanted to check if the user's age is under 21, you want to print an error message.
With if/else if/else statements, this is possible!

Let's look at some examples.
*/

Console.Write("Enter your age: ");
int age = Console.ReadLine();


// Here, we will check if the age is less than 21
if (age < 21)
{
    Console.WriteLine("You are too young to access this!"); // This executes if age is less than 21.
}


// Note we do not need an else if/else; these are optional. Let's see an if/else in action!
if (age < 21)
{
    Console.WriteLine("You are too young to access this!"); // This executes if age is less than 21.
}
else
{
    Console.WriteLine("Welcome to the storefront."); // This will execute if age is above 20.
}


// Finally, we can use as many 'else if' statements as we want, as shown here
if (age < 21)
{
    Console.WriteLine("You are too young to access this!"); // This executes if age is less than 21.
}
// These else if statements are then checked in the order they appear.
else if (age > 20 && age < 30)
{
    Console.WriteLine("Enjoy your 20's!"); // This executes when the age is between 21 and 29
}
else if (age >= 65)
{
    Console.WriteLine("You get a senior citizen discount!"); // This executes if age is at least 65.
}
// This will only execute if none of the other checks trigger.
else
{
    Console.WriteLine("Welcome to the storefront."); 
}
