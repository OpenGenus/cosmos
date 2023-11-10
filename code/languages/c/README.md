# Introduction to C
C is a general-purpose, imperative computer programming language, supporting structured programming, lexical variable scope and recursion, while a static type system prevents many unintended operations. By design, C provides constructs that map efficiently to typical machine instructions, and it has therefore found lasting use in applications that were previously coded in assembly language. Such applications include operating systems, as well as various application software for computers ranging from supercomputers to embedded systems. **It is a Turing-Complete Language**

## Overview
Like most imperative languages in the ALGOL tradition, C has facilities for structured programming and allows lexical variable scope and recursion. Its static type system prevents unintended operations. In C, all executable code is contained within subroutines(also called "functions", though not strictly the same as in the sense of functional programming). Function parameters are always passed by value. Pass-by-reference is simulated in C by explicitly passing pointer values. C program source text is free-format, using the semicolon as a statement terminator and curly braces for grouping blocks of statements.

### The C language also exhibits the following characteristics:

* There is a small, fixed number of keywords, including a full set of control flow primitives: for, if/else,      while, switch, and do/while. User-defined names are not distinguished from keywords by any kind of sigil.
* There are a large number of arithmetic and logic operators: +, +=, ++, &, ~, etc.
* More than one assignment may be performed in a single statement.
* Function return values can be ignored when not needed.
* Typing is static, but weakly enforced; all data has a type, but implicit conversions are possible.
* Declaration syntax mimics usage context. C has no "define" keyword; instead, a statement beginning with the     name of a type is taken as a declaration. There is no "function" keyword; instead, a function is indicated by   the parentheses of an argument list.
* User-defined (typedef) and compound types are possible.
* Union is a structure with overlapping members; only the last member stored is valid.
* Array indexing is a secondary notation, defined in terms of pointer arithmetic. Unlike structs, arrays are      not first-class objects: they cannot be assigned or compared using single built-in operators. There is no       "array" keyword in use or definition; instead, square brackets indicate arrays syntactically, for example       month[11].
* Strings are not a distinct data type, but are conventionally implemented as null-terminated character arrays.
* While C does not include certain features found in other languages (such as object orientation and garbage collection), these can be implemented or emulated, often through the use of external libraries (e.g., the GLib Object System or the Boehm garbage collector).

### Historical Background
The origin of C is closely tied to the development of the Unix operating system, originally implemented in assembly language on a PDP-7 by Dennis Ritchie and Ken Thompson, incorporating several ideas from colleagues. Eventually, 

In 1972, Ritchie started to improve B, which resulted in creating a new language C. C compiler and some utilities made by C were included in Version 2 Unix. At Version 4 Unix released at Nov. 1973, the Unix kernel was extensively re-implemented by C. By this time, the C language had acquired some powerful features such as struct types.

| Year        | Version           |
| ------------- |:-------------:| 
| 1972      | Birth | 
| 1978      | K&R C      | 
| 1989/1990 |ANSI C and ISO C      | 
| 1999|C 99      |
| 2011 |C 11      |
| 2017/2018 |C 18      |   

### Hello World Program 
``` c
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```
The first line of the program contains a preprocessing directive, indicated by **#include**. This causes the compiler to replace that line with the entire text of the stdio.h standard header, which contains declarations for standard input and output functions such as printf. The angle brackets surrounding stdio.h indicate that stdio.h is located using a search strategy that prefers headers provided with the compiler to other headers having the same name, as opposed to double quotes which typically include local or project-specific header files.

The next line indicates that a function named main is being defined. The main function serves a special purpose in C programs; the run-time environment calls the main function to begin program execution. The type specifier int indicates that the value that is returned to the invoker (in this case the run-time environment) as a result of evaluating the main function, is an integer. The keyword void as a parameter list indicates that this function takes no arguments.

The opening curly brace indicates the beginning of the definition of the main function.

The next line calls (diverts execution to) a function named printf, which in this case is supplied from a system library. In this call, the printf function is passed (provided with) a single argument, the address of the first character in the string literal "hello, world\n". The string literal is an unnamed array with elements of type char, set up automatically by the compiler with a final 0-valued character to mark the end of the array (printf needs to know this). The \n is an escape sequence that C translates to a newline character, which on output signifies the end of the current line. The return value of the printf function is of type int, but it is silently discarded since it is not used. (A more careful program might test the return value to determine whether or not the printf function succeeded.) The semicolon ; terminates the statement.

The closing curly brace indicates the end of the code for the main function. According to the C99 specification and newer, the main function, unlike any other function, will implicitly return a value of 0 upon reaching the } that terminates the function. (Formerly an explicit return 0; statement was required.) This is interpreted by the run-time system as an exit code indicating successful execution.

**Source - Wikipedia, Programming in ANSI C- E Balagurusamy.**
