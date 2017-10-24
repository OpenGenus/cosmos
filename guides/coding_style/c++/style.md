# C++ Style Guide



### Naming Rules

#### Variables

Variables should be named using standard camel case.

```C++
int name = 0; // Valid
int camelCase = 0; // Valid
int PascalCase = 0; // Invalid
int underscore_case = 0; // Invalid
```

#### Functions
Functions should follow the same conventions as variables.

```C++
int name(); // Valid
int camelCase(); // Valid
int PascalCase(); // Invalid
int underscore_case(); // Invalid
```

#### Classes
When naming classes, follow the rules of pascal case.

```C++
class name(); // Invalid
struct camelCase; // Invalid
class PascalCase; // Valid
struct underscore_case; // Invalid
```

#### Macros
When naming macros, use uppercase for all the letters, and separate words by underscores.

```C++
#define VALID
#define UPPERCASE_VALID
#define invalid
#define lowercase_invalid
```

### Braces

When using braces, put them on their own lines. For if statements and loops that have one line statements, omit the braces.

```C++
int main()
{
    if (condition) 
    {
        statement1;
        statement2;
    }
    else
        statement3;
}
```

On a side note, for conditionals and loops, put a space between the keyword and the opening parentheses, and another space after the closing parentheses.

When using class initialization with braces, then place a space after the opening brace, and before the closing brace.

```C++
ClassName objectName{ 1, 4 };
```

### Comments
Single line comments should use the standard style (`//`), and multi line comments should use multiline comments (`/* */`). There should be a space between the comment delimiter and the comment text.

```C++
// Example text

/*
 *
 * Multiline comment
 *
 */
 
/*
 
 Simple multiline comment
 
*/
```

### Struct vs. Class
If a class has all public members (not member functions), then use the `struct` keyword. On the other hand, if it has all private variables, then use the `class` keyword.
When a class has both public and private members, then use the `class` keyword.

### Including Header Files
When including header files, only include files that are portable across all compilers (Unless where applicable). Do not include `<bits/stdc++.h>`.
