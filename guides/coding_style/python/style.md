# Python programming style guide

General guidelines
---
One statement per line

Use Python3! Check the [current time until deactivation of Python2 here](https://pythonclock.org/)

Use concise, pythonic, but **readable** code

Variables
---
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

Code Blocks
---
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


Conditionals
---
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


Functions
---
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

Classes
---
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

Constants
---
Constant variable names should be all uppercase, with words separated by underscores

**WRONG**
```Python
max_length, total
```

**RIGHT**
```Python
MAX_LENGTH, TOTAL
```
