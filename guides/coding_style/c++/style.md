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

#### Member Variables
When naming the member variables of a class that are _private_, then add an underscore to the end of their name.

```C++
class Example
{
public:
    Example();
private:
    int exampleVariable_; // Valid
    int badVariable; // Invalid
};
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
class name; // Invalid
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

### Functions

#### Parameters
When listing POD (Plain Old Data) types, then pass them by value. When listing user-defined types, then pass them by const reference. When a function has to modify a variable, then, and only then pass the variable by reference.

```C++
void exampleFunction(int pod, const Example& object, char& modifiableChar)
{
    // ...
}
```

### Classes

#### Order of Encapsulation
When listing members of a class, list them in the order public, private, then protected.
Encapsulation labels should be indented to the same level as the class. Add a space after the end of each label for readability.

```C++
class Example
{
public:
    // ...
    
private:
    // ...
    
protected:
    // ...
    
};
```

### Order of Member Functions
When listing member functions of a class, first list the main constructor, then secondary constructors, and then copy assignment/copy construction/move assignment/move construction functions.
After this, add the destructor. Then, add a new line, and then list all members of the class.

```C++
class Example
{
private:
    int value_;
    
public:
    Example() {  }
    Example(int value) { }
    Example(const Example& other) { }
    ~Example()
    
    void memberFunction();
    
};
```

When possible, try to create a logical separation of member functions for clarity.