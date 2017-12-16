# Cosmos Guides
> Your personal library of every algorithm and data structure code that you will ever encounter

# Java Style Guide

## Index
- [Braces](#braces)
- [Comments](#comments)
- [Control Flow Statements](#control-flow-statements)
- [Whitespace](#whitespace)
- [Naming](#naming)
- [Methods](#methods)
- [Expressions](#expressions)
- [Variables](#variables)
- [Source File Structure](#source-file-structure)
- [Annotations](#annotations)
- [Switch Statements](#switch-statements)
- [Statements](#statements)

## Braces

All braces should start on the same line as the method they are delimiting. If a control flow statement contains only one line of code, it should not have any delimiting braces, unless using a multi-block control flow statement where at least one block is more than one line long. If using inline braces, there should be a space between the braces and the code in between. If a block of code is empty, the code may be made consise by putting everything on the same line, with no space in between the braces, unless part of a multi-block statement.

```Java
if (true) {
	/*
	** Multiple lines
	** of code
	*/
}

while (true)
	// Code

if (true || false) {
	// One line of code
} else {
	/*
	** More than one line of code,
	** so all blocks should be delimited.
	*/
}

if (false) {} // Do nothing, valid

if (true) {
	/*
	** Code
	*/
} else {} // Not acceptable

int[] arr = new int[] { 1, 2, 3 };
```

## Comments

Comments should have a space following the double slashes. Any multiline comments should be created with the /\*\*/ delimiters. A special type of comment, called Javadoc commenting, should be implemented using the /\*\* \*/ delimiters. Javadoc comments are used with tags like @author, @param, and @return to document the purpose of methods and classes in code.

```Java
// Single line comment, with space after slashes

/*
** Multi-line
** comment
*/

/**
* Documentation
* 
* @version 1.0
*/


/**
 *
 * This is a Javadoc comment that
 * is describing a method in a class
 * that will modify a string
 *
 * @author myName
 * @param word the string to be manipulated
 * @return the modified string
 *
 */
```

## Control Flow Statements

The parentheses for control flow statements should be one space after the statement. There should be a newline between unrelated statements, i.e. between a `while` and `if` but not between an `if` and `else`. There should be no spaces in between a statement and its block of code. This goes for class declarations as well. The only case that a piece of code inside an if-statement can be on the same line is if the code is a `return` statement.
```Java
if (true || false) {
	// Code
} else {
	// Else
}

while (true) {

	// Should be no spaces, unlike this

}

class Foo {
	// No space between declaration and code
}

// Incorrect
if (true) bar += foo;

// Correct
if (true) return bar;
```

## Whitespace

Tabs should be tab characters, and not spaces.

## Naming

All names should be lowerCamelCase, except constants, which should be CAPITALIZED_AND-SEPARATED_BY_UNDERSCORES, and classes, which should be PascalCase.

## Methods

Methods should have no whitespace in between the parentheses for parameters and the method signature. If a method contains only one line, it should be on the same line as the method declaration and follow the [inline brace delimiting](#braces) rule. Parameters should have no spaces between the parentheses, and one space after the comma.
```Java
public void foo(int a, int b) {
	/*
	** Multiple lines
	** of code
	*/
}

public void bar() { /* One line of code, with a space separating the braces */ }
```

## Expressions

All expressions, including boolean and arithmetic, should have a space between operators and operands.
```Java
// Incorrect
int a=b+c;

// Correct
int a = b + c;

// Incorrect
if (a==b && c<d)

// Correct
if (a == b && c < d)
```

## Variables

All variables should be declared at the top of their scope, in the order shown below. Each set of variables with the same visibility should be grouped together and separated from other variable groups by a single space. In each group, variables of the same data type should be adjacent to one another. The exception are constants, which should always be declared at the top. All variables declared at the `class` scope should have one of the below modifiers.

Order of member modifiers, according to the Java Language Specification:
`public protected private abstract default static final transient volatile sychronized native strictfp`

```Java
public static final int CONSTANT = 1;

public int x;
public int y;
public String str;

protected int num;
protected String foo;

private char c;

// Code

public void bar() {
	int n;

	// More code
}
```

## Source File Structure

The structure of the file should comprise the following:
1. Import statements
2. Top-level class
3. Lower level classes

Each of the above components should be separated by exactly one line. All lines aside from the import statements must follow a length limit of 100 columns. Wildcard imports should **not** be used.

## Annotations

Annotations should be on the line above the block they are applied to. Multiple annotations should be stacked atop one another.
```Java
@annotation
public void foo() {}

@annotation
@differentAnnotation
public void bar() {}
```

## Switch Statements

All switch cases should end with either a `break` or `return` keyword. Every switch statement should also contain a `default` case for when
the variable being checked does not match up with any of the cases in the statement.
```Java
/* Given a number, num, do something
 * different depending on what num is
 * (i.e. num is 1, 2, 3, or none)
 */
switch (num) {
	case 1:  // Do something
                 break;
	case 2:  // Do something
                 break;
	case 3:  // Do something
                 break;
	default: // Do something
                 break;
}
```

## Statements

There should only be one statement per line. A statement is defined as ending in a semicolon, so this does not include control flow statements. The exceptions are a single statement that are delimited with braces, including anonymous methods and array instantiation.
```Java
Runnable run = () -> {
	// Acceptable
};

int[][] arr = {
	{ 1, 2, 3 },
	{ 4, 5, 6 },
	{ 7, 8, 9 }
};
```


---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
