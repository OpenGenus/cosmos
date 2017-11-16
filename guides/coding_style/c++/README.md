# Cosmos Guides
> Your personal library of every algorithm and data structure code that you will ever encounter

# C++ Style Guide
> All demonstrates are VALID version

## Index
- [Code width and alignment](#code-width-and-alignment)
- [Including Header Files](#including-header-files)
- [Comments](#comments)
- [Namespaces](#namespaces)
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
- [Braces](#braces)
- [Functions](#functions)
- [Classes](#classes)
- [Enumerations](#enumerations)
- [Alias](#alias)

## Code width and alignment
- Try to limit code width to 100 characters.

- Split lines as close to the code width as possible (if a parameter is split onto another line, then all of the parameters should be split).

- If the width is less than or equal to the maximum code width, then do not split the line (unless split at return type or for readability).

- Template definitions should be split.

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

## Comments
Single line comments should use the standard style (`//`), and multi line comments should use multiline comments (`/* */`). There should be a space between the comment delimiter and the comment text (unless pure-code synopsis).

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
    using value_type = T;
    using allocator_type = Allocator;
}
*/
```

## Namespaces
When using namespace, pay attention to name collisions/name conflicts:

In header files, do not use `using` directive or declaration.

```C++
// sample1.hpp
#include <vector>

// ok, if users include this file, they also need declare std namespace to use member of vector
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

## Naming
Names should be descriptive and avoid abbreviation (unless that most people know what mean for), and abbreviation should like .
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

## Braces
When using braces, put them on their own lines. `for`s, `if`s and loops that have one line statements, omit the braces (unless 1. between `do` and `while` on do-while statements, 2. dangling else).

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

On a side note, for conditionals and loops, put a space between the keyword and the opening parentheses, and another space after the closing parentheses.

When using class initialization with braces, then place a space after the opening brace, and before the closing brace.

```C++
ClassName objectName{ 1, 4 };
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

## Enumerations
### enum vs enum class
When dealing with enumerations, use `enum class`, not `enum` (Unless dealing with unnamed enumerations or C style code).

Warning: if you dealing with low-level operation, and need use explicit type convertion, you must be careful about underlying type (default is the `int` it at least 2-bytes).

## Alias
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
