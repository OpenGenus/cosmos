# Cosmos Guides
> Your personal library of every algorithm and data structures code that you will ever encounter

## C Code style

C is a general-purpose mid level, procedural computer programming language originally developed between 1969 and 1973 and founded by Dennis Ritchie in AT&T Labs in 1972.

# C Programming Style Guide

This code style is known as Kernel Normal Form (KNF).

## Index
- [Braces](#braces)
- [Indentation](#indentation)
- [Conditionals](#conditionals)
- [Functions](#functions)
- [Comments](#comments)

## Braces

All braces should go on the same line as whatever the braces are delimiting, with the only exception being functions. For if/else statements, braces should only be used as required.

```C
int
main(int argc, char *argv[])
{
	if (!some_function()) {
		puts("Something happened!");
		do_a_thing();
	} 
	else
	{
		some_other_thing();
        }
	return (0);
}
```

*argc stands for arguments count(ARGument count)
*argv stands for arguments values(ARGument values)
*argv[0] is the name of the program 


## Indentation

Indentation is done with a single tab character (Hard Tab). For code split across multiple lines a helper indent of 4 spaces is used.


```C
int
some_really_long_function(int a, int b, int c, int d,
    int e, int f)
{
	do_something();
```

## Conditionals

```C
if (a == 9) {
```

```C
for (;;)
```

Each case in a switch statement should not be indented but the code for each should be. Any case fallthroughs should be commented.
Every case should be terminated with a break statement.

```C
switch (ch) {
case 'a':
	a_count++;
	/* FALLTHROUGH */
case 'b':
	do_something();
	break;
case 'c'
	other_thing();
	break;
default:
	def_thing();
}
```

## Functions

Functions should have the type on a seperate line proceeding the rest of the function definition.

```C
int
main(int argc, char *argv[])
{
//Block of Code
//" " "
//" " "
}
```

Return statements should have the value wrapped in parenthesis.

```C
return (0);
```

## Comments

Always use C style comments (`/* */`) and not C++ style comments (`//`). A sample is shown below.

```C

/* One line comment */ 

/*
 * Multiline comment. Fill it out like it were
 * a paragraph.
 */

```


---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
