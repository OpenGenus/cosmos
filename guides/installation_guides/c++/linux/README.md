# Install C++ in Linux

This is the basic guide to install and run C++ program in Linux

### Prerequisite: Install build-essential

```
sudo apt install build-essential
```


### Check whether GCC is installed on your system 

```
$ g++ -v
```

Create a sample hello.cpp
```
#include<iostream>
using namespace std;
int main()
{
            cout << “\nHello World, Welcome to my first C ++ program on Ubuntu Linux\n\n”;
	    cout << endl;
            return (0);
}
```

Save the file and exit.

Compiling C++ program.

```
$ sudo g++ hello.cpp (or)
$ sudo g++ -o hello hello.cpp
```
