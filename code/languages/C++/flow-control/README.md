# Flow Control
A simple C++ statement is each of the individual instructions of a program, like the variable declarations and expressions seen in previous sections. They always end with a semicolon (;), and are executed in the same order in which they appear in a program. But programs are not limited to a linear sequence of statements. During its process, a program may repeat segments of code, or take decisions and bifurcate. For that purpose, C++ provides flow control statements that serve to specify what has to be done by our program, when, and under which circumstances.

Program statements that cause such jumps are called control statements. There are two major categories:

* Loops
* Decisions

## Loops
Loops repeat a statement a certain number of times, or while a condition is fulfilled. They are introduced by the keywords while, do, and for.

### The while loop
Its syntax is:

``` 
while (expression) statement
```

The while-loop simply repeats statement while expression is true. If, after any execution of statement, expression is no longer true, the loop ends, and the program continues right after the loop. For example, let's have a look at a countdown using a while-loop:
``` C++
// custom countdown using while

int main ()
{
  int n = 10;

  while (n>0) {
    std::cout << n << ", ";
    --n;
  }

  std::cout << "liftoff!\n";
}
```
### Output
```
10, 9, 8, 7, 6, 5, 4, 3, 2, 1, liftoff!
```
### The do-while loop

A very similar loop is the do-while loop, whose syntax is:
```
do statement while (condition);
```

It behaves like a while-loop, except that condition is evaluated after the execution of statement instead of before, guaranteeing at least one execution of statement, even if condition is never fulfilled. For example, the following example program echoes any text the user introduces until the user enters goodbye:

``` C++
int main ()
{
  string str;
  do {
    std::cout << "Enter text: ";
    getline (cin,str);
    std::cout << "You entered: " << str << '\n';
  } while (str != "goodbye");
}
```
### Output
```
Enter text: hello
You entered: hello
Enter text: who's there?
You entered: who's there?
Enter text: goodbye
You entered: goodbye
```
## The for loop
The for loop is designed to iterate a number of times. Its syntax is:
```
for (initialization; condition; increase) statement;
```

Like the while-loop, this loop repeats statement while condition is true. But, in addition, the for loop provides specific locations to contain an initialization and an increase expression, executed before the loop begins the first time, and after each iteration, respectively. Therefore, it is especially useful to use counter variables as condition.

```C++
int main ()
{
  for (int n=10; n>0; n--) {
    std::cout << n << ", ";
  }
  std::cout << "liftoff!\n";
}
```

### Output
```
10, 9, 8, 7, 6, 5, 4, 3, 2, 1, liftoff!
```
## Decision
In this, we test a condition and based on whether the condition is true or false you execute a statement or set of statements. In C++ programming language, we can implement conditional branching using the following statements:

* if-else Statement
* if-else-if statement
* switch…case statement

### if-else Statement

When we use the **if-else** statement, you check a condition. If the condition is met (true), a piece of code is executed.  However if the condition is false, the else part of code in the loop body is executed.

The syntax for using the “if” statement is as follows:
```
if (condition)
{
        Statement 1;
}
else if
{
        Statement 2;
}
else
{
        Statement 3;
}
Statement 3;
```
### Sample

```C++
int main()
{
    int age;
    age = 70;
    if (age<=60)
    {
        std::cout<<”Correct age”<<endl;
    }else
    {
        std::cout<<”Incorrect age”<<endl;
    }
     
    return 0;
}
```
### if-else-if statement

An if statement can be followed by an optional else if...else statement, which is very usefull to test various conditions using single if...else if statement.
When using if , else if , else statements there are few points to keep in mind.

* An if can have zero or one else's and it must come after any else if's.
* An if can have zero to many else if's and they must come before the else.
* Once an else if succeeds, none of he remaining else if's or else's will be tested.

**Syntax**

```C++
if(boolean_expression 1) {
   // Executes when the boolean expression 1 is true
} else if( boolean_expression 2) {
   // Executes when the boolean expression 2 is true
} else if( boolean_expression 3) {
   // Executes when the boolean expression 3 is true
} else {
   // executes when the none of the above condition is true.
}
```
**Sample Program**
```C++
#include <iostream>

int main () {
   // local variable declaration:
   int a = 100;
 
   // check the boolean condition
   if( a == 10 ) {
      // if condition is true then print the following
      std::cout << "Value of a is 10" << endl;
   } else if( a == 20 ) {
      // if else if condition is true
      std::cout << "Value of a is 20" << endl;
   } else if( a == 30 ) {
      // if else if condition is true 
      std::cout << "Value of a is 30" << endl;
   } else {
      // if none of the conditions is true
      std::cout << "Value of a is not matching" << endl;
   }
   std::cout << "Exact value of a is : " << a << endl;
 
   return 0;
}
```
**Output**
```
Value of a is not matching
Exact value of a is : 100
```

### switch statement

The **switch-case** statement tests the value of an expression against a list of conditions. When a match is found, the statements associated with that condition are executed. In the case of a “switch…case” statement, the conditions are constants. Each constant is a “case” (in the body of the “switch….case” statement).
**Note -** Comparing two strings is not the same as expected.

The Syntax for using the “switch…case” statement is as follows:
```
switch(expression)
{
        case1;
 
               Block-of Statements1;
 
        case2:
  
               Block-of Statements2;
 
        case3:
 
               Block-of Statements3;
 
        default:
 
               Block-of Statements4;
}
    Statement5;
```
### Sample
```C++
void  main()
{
    char i;
    std::cout<<”Enter a rainbow colour VIBGYOR”<<endl;
    cin>>i;
    switch(i)
    {
        case 'V':
            std::cout<<"Voilet"<<endl;
            break;
        case 'I':
            std::cout<<"Indigo"<<endl;
            break;
        case 'B':
            std::cout<<"Blue"<<endl;
            break;
        case 'G':
            std::cout<<"Green"<<endl;
            break;
        case 'Y':
            std::cout<<"Yellow"<<endl;
            break;
        case 'O':
            std::cout<<"Orange"<<endl;
            break;
        case 'R':
            std::cout<<"Red"<<endl;
            break;
        default:
            std::cout<<"You have entered the wrong color"<<endl;
    }
}
```
