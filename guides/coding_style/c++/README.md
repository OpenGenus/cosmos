# Cosmos Guides
> Your personal library of every algorithm and data structure code that you will ever encounter

# C++ Style Guide
> All demonstrates are VALID version

## Index
- [Comments](#comments)
- [Code Width and Alignment](#code-width-and-alignment)
- [Spaces](#spaces)
- [Indentations](#indentations)
- [Newlines](#newlines)
- [Braces](#braces)
- [Naming](#naming)
  <details open>
    <summary>categories</summary>
    <ul>
        <li><a href="#file-names">File Names</a></li>
        <li><a href="#type-names">Type Names</a></li>
        <li><a href="#variable-names">Variable Names</a></li>
        <li><a href="#function-names">Function Names</a></li>
        <li><a href="#macro-names">Macro Names</a></li>
        <li><a href="#exceptions-to-naming-rules">Exceptions to Naming Rules</a></li>
    </ul>
  </details>
- [Including Header Files](#including-header-files)
- [Namespaces](#namespaces)
- [Functions](#functions)
- [Classes](#classes)
- [Enumerations](#enumerations)
- [Aliases](#aliases)

## Comments
Single line comments should use the standard style (`//`), and multi line comments should use multiline comments (`/* */`). There should be a space between the comment delimiter and the comment text.

```C++
// Example text

/*
 *
 * Multiline comment
 *
 */

/*
 *
 * Simple multiline comment
 *
 * vector synopsis
 *
 * template <class T, class Allocator = allocator<T> >
 * class vector
 * {
 * public:
 *     using value_type = T;
 *     using allocator_type = Allocator;
 * }
 */
```

## Code Width and Alignment
- Try to limit code width to 100 characters.

- Split lines as close to the code width as possible (if a parameter is split onto another line, then all of the parameters should be split).

- If the width is less than or equal to the maximum code width, then do not split the line (unless split at return type or for readability).

- Template definitions should be split.

```C++
// n <= 100 columns
bool operator==(Container<Type, Allocator> x, Container<T, Allocator> y);

bool
operator==(Container<Type, Allocator> x, Container<T, Allocator> y);

template<class OtherType, class OtherAllocator>
bool operator==(Container<OtherType, OtherAllocator> x, Container<OtherType, OtherAllocator> y);

template<class OtherType, class OtherAllocator>
bool
operator==(Container<OtherType, OtherAllocator> x, Container<OtherType, OtherAllocator> y);

// n > 100 columns
void cloneTwo(Container<Type, Allocator> foo,
              Container<Type, Allocator> bar,
              Container<Type, Allocator> baz);

template<class OtherType, class OtherAllocator>
void
cloneTwo(Container<OtherType, OtherAllocator> foo,
         Container<OtherType, OtherAllocator> bar,
         Container<OtherType, OtherAllocator> baz);
```

- The pointers `*` `**` and references `&` `&&` `*&` should be part of the variable/function name (even if variable name is not declared) or qualifier. Add a space between previous types or qualifiers (unless `**`, `&&`, and `*&`).

```C++
// pointers and references
int a = 0;

int *pa = &a;
int *&rpa = pa;
int **ppa = &pa;
int &&rr = 0;

bool operator==(int *x, int *y);

bool operator==(int *const *x, int *const *y);

bool operator==(const int **const x, const int **const y);

bool &getReference();

bool *&getPointer();

bool *const getConstPointer();

bool *const &getReferenceOfConstPointer();

// even if variable name is not declared
bool operator==(int *&, int *&);

bool operator==(int &&, int &&);
```

- The `const` qualifier should be on the right hand side of its target but to the left of the type.

```C++
class Dummy
{   
    const int value() const;

    void value(const int *const v);

    int *getPointer();

    const int *const *getOtherPointer() const;
};
```

- The logical operators should be placed after their conditions if there are many of them. If adding parentheses makes your intent clearer then go ahead and add them.

```C++
void foo()
{
    bool res = true;

    short i = 1;
    long sum_short = 1;
    while (i != 0 && ++i)
        sum_short += i;

    if (i == 0 && (0 == i))
        res &= true;
    else
        res &= false;

    if ((1 != 0) &&
        (1 == true || 0 == false))
        res &= true;
    else
        res &= false;

    if (res != true ||
        (!(res == true) ||
         (res == false)))
        cout << "wrong\n";
}
```

## Spaces
Put one space:

- After commas.

- Between operators.

- Between condition and its opening brace.

- Around initializer of class constructor;

Remove spaces:

- In whitespace-only line.

- After opening brace/parenthese, and before closing brace/parenthes.

- Between empty braces, and parentheses.

Be clear, the demo not follow the Newline rules:
```C++
while ()    // 1 space between while and '(', 0 space between parentheses.
{           // 0 space after opening brace-only line.

    if (true)                   // 1 space between if and '('.
    {
        ClassName obj{1, 2, 3}; // 0 space after '{', before '}'.

        int i = (1 + 1) * 1;    // 1 space around '=', '+', and '*'.

        doSomthing(obj, i, 1);  // 1 space after commas.
    }

}           // 0 space after closing brace-only line.
```

## Indentations
Use only spaces, and indent 4 spaces at a time.

We use spaces for indentation. Do not use tabs in our code.

```C++
bool predicateFunc(vector<int> vec) {
    for (; condition; )     //  4 spaces
        if (condition)      //  8 spaces
            return false;   // 12 spaces
                            // none space
    return true;            //  4 spaces
}
```

## Newlines
Add newline:

- Between two functions, classes, and conditions.

- After `#define`, `#include`.

- Between preconditions and its scope (ignore between preconditions).

```C++
#include <iostream>

#ifndef DDD     // no newline between #ifndef and #define line
#define DDD

int func1();

int func2()
{
    int a{1}, b{0};
    if (a == b)
        // ...

    while (a - b > 0)
        // ...
}

class A;

class B
{
public:
    int func1();

    int func2()
    {
        // ...
    }

private:
    int v1;
    bool v2;

    int func3();
}

#endif
```

## Braces
When using braces, put them on their own lines. When loops or `if` statements have only one statement, omit the braces (unless between `do` and `while` on do-while statements or to disambiguate a dangling else).

```C++
int main()
{
    if (condition) 
    {
        statement;
        statement;
    }
    else
        statement;

    if (condition)
    {
        if (condition)
            statement;
        else
            statement;
    }

    for (;condition;)
       statement;

    do
    {
        statement;
    } while (condition);
}
```

## Naming
Names should be descriptive and avoid abbreviations, unless the abbreviation is commonly known.
```C++
int errorFlag;
int currentIter;    // the certain universally-known abbrs ("Iter") are OK
int numberDnsConnections;    // ok, most people know what "DNS" stands for
```

### File Names
C++ file should end in .cpp and header file should end in .hpp (do not end in .h).

### Type Names
Types should be named like PascalCase.

```C++
using VecI = std::vector<int>;
template<typename _T>
using VecTwo = std::vector<std::vector<_T>>;

class PascalCase;
struct PascalCase;
union PascalCase;

enum PascalCase;
enum class PascalCase;
```

### Variable Names
Local variables should be named using standard camelCase.

```C++
int name;
int camelCase;
```

Global variables should be avoided for the most part. If they are necessary, then they should be named using prefix 'g\_' and standard camelCase.

```C++
int g_name;
int g_camelCase;
```

Class members should be _private_, add an underscore to the end of their name.

```C++
class PascalCase;
{
    int name_;
    int camelCase_;
};
```

Constant variables should be named using PascalCase.

```C++
const int Name;
constexpr int VariableName;

enum class ExampleEnum
{
    One,
    TwoTwo
};
```

### Function Names
Functions should be named using standard camelCase.

```C++
int name();
int camelCase();

class PascalCase
{
    int doSomething();
};
```

### Macro Names
When naming macros, use uppercase for all the letters, and separate words by underscores.

```C++
#define VALID
#define UPPERCASE_VALID
```

### Exceptions to Naming Rules
If you are naming something that is analogous to an existing C++ entity then you can follow the existing naming convention scheme.
```C++
sparse_hash_set<> ...  // STL-like entity; follows STL naming conventions
long BUFFER_MAX ...    // a constant, as in INT_MAX
using diff_t ...       // as in ptrdiff_t
```

## Including Header Files
When including header files, only include files that are _portable_ across all compilers (Unless where applicable). Do not include `<bits/stdc++.h>`.

Pay attention to whether the header is _not in use_, and do not include it if so. If only the implementation uses it, then include the file in .cpp, not .hpp.

```C++
// sample1.hpp
#include <vector>       // ok, return type is vector

template<typename Ty>
std::vector<Ty> toVector(Ty t[], size_t sz);


// sample2.hpp
class ListHelp
{
    void sort();
};

// sample2.cpp
#include "sample2.hpp"
#include <utility>      // ok, only use the swap function in implementation
using namespace std;

void ListHelp::sort()
{
    // use the swap function
}
```

## Namespaces
When using namespaces, pay attention to name collisions/name conflicts:

In header files, do not use a `using` directive or declaration.

```C++
// sample1.hpp
#include <vector>

// ok, if users include this file, they also need to declare std namespace to use member of vector
template<typename Ty>
std::vector<Ty> toVector(Ty t[], size_t sz);


// sample2.hpp
class ListHelp
{
    void sort();
}

// sample2.cpp
#include "sample2.hpp"
#include <utility>
using namespace std;    // ok, users will include .hpp not .cpp

void ListHelp::sort()
{
    // may use the swap function
}
```

## Functions
### Parameters
When listing POD (Plain Old Data) types, pass them by value. When listing user-defined types, pass them by `const` reference. When a function has to modify a variable, then, and only then pass the variable by reference.

```C++
void exampleFunction(int pod, const Example& object, char& modifiableChar)
{
    // ...
}
```

## Classes
### Order of Encapsulation
When listing members of a class, if possible list them in the order public, private, then protected. If using `using` for aliases, or using base class constructors, then the order can be broken. In this case, if possible, try and list the public interface of the class first.
Encapsulation labels should be indented to the same level as the class. Add a new line after the end of each label for readability.

```C++
class Example
{
private:
    using Int = int;

protected:
    using typename BaseClass::size_type;
    
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

* When possible, try to create a logical separation of member functions for clarity.
* If a class has all public members (not member functions), then use the `struct` keyword, otherwise use the `class` keyword.

```C++
class Example
{
public:
    Example() { }
    Example(int value) { }
    Example(const Example& other) { }
    ~Example()
    
    void memberFunction();

private:
    int value_;
};
```

### Member Initializer List
When declaring a constructor, use a member initializer list to initialize class members.

```C++
class Example
{
public:
    Example(int a, int b) : a_{a}, b_{b} { }

private:
    int a_, b_;
};
```

## Enumerations
### enum vs enum class
When dealing with enumerations, use `enum class`, not `enum` (Unless dealing with unnamed enumerations or C style code).

Warning: if you dealing with low-level operation, and need use explicit type convertion, you must be careful about underlying type (default is the `int` it at least 2-bytes).

## Aliases
### using vs typedef
When dealing with aliases, use `using`, not `typedef`.

Don't put alias in `public`, unless the aliases is guaranteed to always be the same as the type it's currently aliased to.

- The `using` declaration can be read almost as an English sentence.

- More easily declare an alias with template.

- [See more comparisons](http://www.stroustrup.com/C++11FAQ.html#template-alias)


---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
