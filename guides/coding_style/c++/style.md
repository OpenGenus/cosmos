# C++ Style Guide

Code width and align
===
Try to limit code width to 100 number of columns.

To split lines as close to code width as possible of groupings (if a parameter is split, then all of parameters need split).

If width less than or equal to _code width_, then shold not split (unless split at return type), otherwise should split at comma.

Template definition should be split.

**Valid:**
```C++
// n <= 100 columns
bool operator==(container<T,Allocator> x, container<T,Allocator> y);

bool
operator==(container<T,Allocator> x, container<T,Allocator> y);

template<class T, class Allocator>
bool operator==(container<T,Allocator> x, container<T,Allocator> y);

template<class T, class Allocator>
bool
operator==(container<T,Allocator> x, container<T,Allocator> y);

// n > 100 columns
void cloneTwo(const container<T,Allocator>& x,
              const container<T,Allocator>& y,
              const container<T,Allocator>& z);

void
cloneTwo(const container<T,Allocator>& x,
         const container<T,Allocator>& y,
         const container<T,Allocator>& z);
```

Including Header Files
===
When including header files, only include files that are _portable_ across all compilers (Unless where applicable). Do not include `<bits/stdc++.h>`.

Comments
===
Single line comments should use the standard style (`//`), and multi line comments should use multiline comments (`/* */`). There should be a space between the comment delimiter and the comment text (unless pure-code synopsis).

**Valid:**
```C++
// Example text

/*
 *
 * Multiline comment
 *
 */
 
/*
 
 Simple multiline comment
 
 vector synopsis
 
template <class T, class Allocator = allocator<T> >
class vector
{
public:
    typedef T                                        value_type;
    typedef Allocator                                allocator_type;
}
*/
```

Macros
===
When naming macros, use uppercase for all the letters, and separate words by underscores.

**Valid:**
```C++
#define VALID
#define UPPERCASE_VALID
```

Variables
===
Local Variables
---
Local variables should be named using standard camel case.

**Valid:**
```C++
int name;
int camelCase;
```

Global Variables
---
Global variables should be named using prefix 'g\_' and standard camel case.

**Valid:**
```C++
int g_name;
int g_camelCase;
```

Constant Variables
---
Constant variables should be named using upper case and separate by underscore.

**Valid:**
```C++
int NAME;
int CONSTANT_NAME;
```

Braces
===
When using braces, put them on their own lines. For if statements and loops that have one line statements, omit the braces (unless between '}' and 'while' on do-while).

**Valid:**
```C++
int main()
{
    if (condition) 
    {
        statement;
        statement;
    }
    else if (condition)
    {
        statement;
        statement;
    }
    else
        statement;

    while (condition)
    {
        statement;
        statement;
    }

    for (;condition;)
       statement

    do
    {
        statement
    } while (condition);
}
```

On a side note, for conditionals and loops, put a space between the keyword and the opening parentheses, and another space after the closing parentheses.

When using class initialization with braces, then place a space after the opening brace, and before the closing brace.

```C++
ClassName objectName{ 1, 4 };
```

Functions
===
Functions should be named using standard camel case.
Names
---
**Valid:**
```C++
int name();
int camelCase();
```

Parameters
---
When listing POD (Plain Old Data) types, then pass them by value. When listing user-defined types, then pass them by const reference. When a function has to modify a variable, then, and only then pass the variable by reference.

**Valid:**
```C++
void exampleFunction(int pod, const Example& object, char& modifiableChar)
{
    // ...
}
```

Classes
===
Names
---
When naming classes, follow the rules of pascal case.

**Valid:**
```C++
class PascalCase;
struct PascalCase;
```

When naming the member variables of a class that shold be _private_, and add an underscore to the end of their name.

**Valid:**
```C++
class Example
{
    int name_;
    int camelCase_;
};
```

Order of Encapsulation
---
When listing members of a class, list them in the order public, private, then protected.
Encapsulation labels should be indented to the same level as the class. Add a space after the end of each label for readability.

**Valid:**
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

Order of Member Functions
---
When listing member functions of a class, first list the main constructor, then secondary constructors, and then copy assignment/copy construction/move assignment/move construction functions.
After this, add the destructor. Then, add a new line, and then list all members of the class.

* When possible, try to create a logical separation of member functions for clarity.
* If a class has all public members (not member functions), then use the `struct` keyword, otherwise use the `class` keyword.

**Valid:**
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
