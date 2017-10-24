# Java programming style guide

Braces
---
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

Comments
---
Comments should have a space following the double slashes. Any multiline comments should be created with the /\*\*/ delimiters.

```Java
// Single line comment, with space after slashes

/*
** Multi-line
** comment
*/
```

Control flow statements
---
The parentheses for control flow statements should be one space after the statement. There should be a newline between unrelated statements, i.e. between a `while` and `if` but not between an `if` and `else`. There should be no spaces in between a statement and its block of code. This goes for class declarations as well. The only case that a piece of code inside an if-statement can be on the same line is if the code is a return statement.
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

Whitespace
---
Tabs should be tab characters, and not spaces.

Naming
---
All names should be lowerCamelCase, except constants, which should be CAPITALIZED_AND-SEPARATED_BY_UNDERSCORES, and classes, which should be PascalCase.

Methods
---
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

Expressions
---
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

Variables
---
All variables should be declared at the top of their scope, in the order shown below. Each set of variables with the same visibility should be grouped together and separated from other variable groups by a single space. In each group, variables of the same data type should be adjacent to one another. The exception are constants, which should always be declared at the top.

Order of member modifiers, according to the Java Language Specification:
`public protected private abstract default static final transient volatile sychronized native strictfp`

```Java
public int x;
public int y;
public String str;

protected int num;
protected String foo;

private char c;

public static final int CONSTANT = 1;

// Code

public void bar() {
	int n;

	// More code
}
```

Source file structure
---
The structure of the file should comprise the following:
1. Import statements
2. Top-level class
3. Lower level classes

Each of the above components should be separated by exactly one line. All lines aside from the import statements must follow a length limit of 100 columns. Wildcard imports should **not** be used.

Annotations
---
Annotations should be on the line above the block they are applied to. Multiple annotations should be stacked atop one another.
```Java
@annotation
public void foo() {}

@annotation
@differentAnnotation
public void bar() {}
