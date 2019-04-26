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
    cout << n << ", ";
    --n;
  }

  cout << "liftoff!\n";
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
// echo machine

int main ()
{
  string str;
  do {
    cout << "Enter text: ";
    getline (cin,str);
    cout << "You entered: " << str << '\n';
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
// countdown using a for loop

int main ()
{
  for (int n=10; n>0; n--) {
    cout << n << ", ";
  }
  cout << "liftoff!\n";
}
```

### Output
```
10, 9, 8, 7, 6, 5, 4, 3, 2, 1, liftoff!
```
## Decision
In this, we test a condition and based on whether the condition is true or false you execute a statement or set of statements. In C++ programming language, we can implement conditional branching using the following statements:

* If….Else Statement
* switch…case statement

### if-else Statement

When we use the **if-else** statement, you check a condition. If the condition is met (true), a piece of code is executed.  However if the condition is false, the else part of code in the loop body is executed.

The syntax for using the “if” statement is as follows:
```
if (condition)
{
        Statement 1;
}
else
{
        Statement 2;
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
        cout<<”Correct age”<<endl;
    }else
    {
        cout<<”Incorrect age”<<endl;
    }
     
    return 0;
}
```
### switch statement

The **switch-case** statement tests the value of an expression against a list of conditions. When a match is found, the statements associated with that condition are executed. In the case of a “switch…case” statement, the conditions are constants. Each constant is a “case” (in the body of the “switch….case” statement).

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
    cout<<”Enter a rainbow colour VIBGYOR”<<endl;
    cin>>i;
    switch(i)
    {
        case ‘V’:
            cout<<”Voilet”<<endl;
            break;
        case ‘I’:
            cout<<”Indigo”<<endl;
            break;
        case ‘B’:
            cout<<”Blue”<<endl;
            break;
        case ‘G’:
            cout<<”Green”<<endl;
            break;
        case ‘Y’:
            cout<<”Yellow”<<endl;
            break;
        case ‘O’:
            cout<<”Orange”<<endl;
            break;
        case ‘R’:
            cout<,”Red”<<endl;
            break;
        default:
            cout<<”You have entered the wrong color”<<endl;
    }
}
```


