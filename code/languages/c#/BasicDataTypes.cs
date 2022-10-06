using System;

/* This code demonstrates the various basic data types that C# provides */

// Char is used to store a character.
char character = 'K'; // Note we have to single quotes.
Console.WriteLine(character); // Outputs: K 


// Strings are used to store text
string message = "Hello there!";
Console.WriteLine(message); // Outputs: Hello there!


// int represents integer numbers (no fractions).
int integer = 16;
Console.WriteLine(integer); // Outputs: 16


// float is a floating point number
float floatNumber = 15.254f; // Note that we use f here.
float anotherFloatNumber = 14.365F; // F is also acceptable.
Console.WriteLine(floatNumber); // Outputs: 15.254


// double is used for greater precision (more decimal places can be stored.)
double doubleNumber = 12.8888446d; // Note that we use d here.
double anotherDoubleNumber = 15.447893323D; // D is also acceptable.
Console.WriteLine(anotherDoubleNumber); // Outputs: 15.447893323


// decimal is typically only used for monetary transactions and provides 
// the greatest precision.
decimal decimalNumber = 12.65m; // Note that we use m here.
decimal anotherDecimalNumber = 19.19M; // M is also acceptable.
Console.WriteLine(decimalNumber);  // Outputs: 12.65
