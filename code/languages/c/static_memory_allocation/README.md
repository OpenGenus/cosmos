## Static Memory Allocatiom
It is allocated at compile time, and the lifetime of a variable in static memory is the lifetime of the program.

In C, static memory can be allocated using the static keyword. The scope is the compilation unit only.

Things get more interesting when the extern keyword is considered. When an extern variable is defined the compiler allocates memory for it. When an extern variable is declared, the compiler requires that the variable be defined elsewhere. Failure to declare/define extern variables will cause linking problems, while failure to declare/define static variables will cause compilation problems.

in file scope, the static keyword is optional (outside of a function):
``` c
int a = 32;
```
But not in function scope (inside of a function):
```c
static int a = 32;
```
Technically, extern and static are two separate classes of variables in C.

```c
extern int a; /* Declaration */
int a; /* Definition */
```

It's somewhat confusing to say that static memory is allocated at compile time, especially if we start considering that the compilation machine and the host machine might not be the same or might not even be on the same architecture.

It may be better to think that the allocation of static memory is handled by the compiler rather than allocated at compile time. For example the compiler may create a large data section in the compiled binary and when the program is loaded in memory, the address within the data segment of the program will be used as the location of the allocated memory. This has the marked disadvantage of making the compiled binary very large if uses a lot of static memory. It's possible to write a multi-gigabytes binary generated from less than half a dozen lines of code.

Another option is for the compiler to inject initialisation code that will allocate memory in some other way before the program is executed. This code will vary according to the target platform and OS. In practice, modern compilers use heuristics to decide which of these options to use. You can try this out yourself by writing a small C program that allocates a large static array of either 10k, 1m, 10m, 100m, 1G or 10G items. 