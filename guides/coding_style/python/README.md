# Cosmos Guides
> Your personal library of every algorithm and data structure code that you will ever encounter

## Python
Python is a high-level programming language by Guido van Rossum released on 20 February 1991. There are now two main versions of Python, namely Python2 and Python3, with Python2 being gradually phased out.

___Latest Releases (last edited: 10/20/17):___
 - 3.6.3 / 3 October 2017
 - 2.7.14 / 16 September 2017

# Python programming style guide

General guidelines
---
One statement per line

Use Python3! Check the [current time until deactivation of Python2 here](https://pythonclock.org/)

Use concise, pythonic, but **readable** code

## Index
- [Variables](#variables)
- [Code Blocks](#code-blocks)
- [Conditionals](#conditionals)
- [Functions](#functions)
- [Classes](#classes)
- [Constants](#constants)
- [Additional Information](#additional-information)

## Variables

When creating variables, use lowercase letters throughout the names. When
creating a variable with more than one word in its name, use an underscore to
separate the words. There is no need for type declaration in Python.

**WRONG**
```Python
# variable declaration statement here more reminiscent of Java
int i = 0
```

**RIGHT**
```Python
# variable declaration and initialization
number = 25

# variable assignment
number = 0

# variables with more than one word in their name
anagram_count = 0
amount_of_pies = 200
our_keyword = 'HelloWorld'
```

## Code Blocks

Use tabs as indents (and remember, in Python, whitespace is important)

**WRONG(1/2)**
```Python
if one==1:
  # This
    # is
      # will
 # not
       # work
```

**WRONG(2/2)**
```Python
if one==1:
                    # This
                    # is
                    # bad
                    # code
```
**RIGHT**
```Python
if one==1:
  # This
  # is
  # a
  # code
  # block
```


## Conditionals

Don't use parentheses unless necessary

**WRONG**
```Python
if (a == 4):
  # do something
```

**RIGHT**
```Python
if a == 4:
  # do something
```

If testing for a boolean case, use the "if ```var```" notation.

**WRONG**
```Python
if b == True:
  # do something
```

**RIGHT**
```Python
if b:
  # do something
```


## Functions

Function names should be lowercase, with words separated by underscores as necessary

**WRONG**
```Python
def WrongFunc(*args):
  pass
```

**WRONG**
```Python
def Wrongfunc(*args):
  pass
```

**RIGHT**
```Python
def right_func(*args):
  pass
```

## Classes

- Class names should use upper camel case
- Always use *self* for the first argument to instance methods

**WRONG**
```Python
class wrong_class_name(object):
    def __init__(self, *args):
        pass
```

**RIGHT**
```Python
class RightClassName(object):
    def __init__(self, *args):
        pass
```

## Constants

Constant variable names should be all uppercase, with words separated by underscores

**WRONG**
```Python
max_length, total
```

**RIGHT**
```Python
MAX_LENGTH, TOTAL
```

## Additional Information
<a href='https://www.python.org/dev/peps/pep-0008/'>PEP 8 -- Style Guide for Python Code</a>
PEP is Python Enhancement Proposal.


---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
