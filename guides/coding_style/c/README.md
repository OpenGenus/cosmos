# Cosmos Guides
> Your personal library of every algorithm and data structure code that you will ever encounter

## C Code style

C is a general-purpose middle language programming language developed by Dennis Ritchie in AT and T labs in 1972, procedural computer programming language which means people write their code as a series of step-by-step instructions. C language was basically developed to do system programming for the operating system UNIX.
C language is case sensetive language.

# C Programming Style Guide

This code style is known as Kernel Normal Form (KNF).

## Index
- [Braces](#braces)
- [Indentation](#indentation)
- [Conditionals](#conditionals)
- [Functions](#functions)
- [Comments](#comments)

## Braces

All braces should go on the same line as whatever the braces are delimiting, with the only exception being functions. For if/else statements, braces should only be used as required. For only one statement after if or else no braces are required but for more than one statement braces are compulsary. If there is a semicolon(;) after if or else statement it is treated as NULL statement.

```C
int
main(int argc, char *argv[])
{
	if (!some_function()) {
		puts("Something happened!");
		do_a_thing();
	} else
		some_other_thing();

	return (0);
}
```

## Indentation

Indentation is done with a single tab character (Hard Tab). For code split across multiple lines a helper indent of 4 spaces is used.
At time of printing escape sequence of (\t) can be used for providing indent of 4 spaces.

```C
int
some_really_long_function(int a, int b, int c, int d,
    int e, int f)
{
	do_something();
	printf ("\t did domething");
```

## Conditionals

if, else, for, while, and switch statements should be followed by a space.

```C
if (a == 9) {
```}

```C
for (;;){
```

Each case in a switch statement should not be indented but the code for each should be. Any case falthroughs should be commented.
There should not be any duplicate cases. Default case can be used anywhere within the switch statement block.
Switch statement cannot have any floating point numbers. Variable expressions are not allowed in case labels although macros are allowed.

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
