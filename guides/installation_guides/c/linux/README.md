# Install C in Linux



### Install GCC

```
sudo apt install gcc
```


### Install build-essential

```
sudo apt install build-essential
```

### Check GCC version

```
gcc --version
```

GCC is installed in Linux Machine

Create a sample hello.c
```
#include <stdio.h>
int main()
{
   printf("Hello, World!");
   return 0;
}
```

To Test
```
$ gcc -o hello hello.c 
$ ./hello 
Hello, World!
```
