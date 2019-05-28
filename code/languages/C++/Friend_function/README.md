## Friend Function
## [Article explaining friend function in C++ at OpenGenus IQ](https://iq.opengenus.org/friend-function-cpp/)
A friend function of a class is defined outside the scope of that class but it has the right to access all private and protected members of the class. Even though the prototypes for friend functions appear in the class definition, friends are not member functions.
A friend can be a function, function template, or member function, or a class or class template, in which case the entire class and all of its members are friends.

To declare a function as a friend of a class, precede the function prototype in the class definition with keyword friend as follows −

Declaration of friend function in C++
``` C++
class class_name
{
    ... .. ...
    friend return_type function_name(argument/s);
    ... .. ...
}
```
Now, you can define the `friend` function as a normal function to access the data of the class. No friend keyword is used in the definition.

```C++
class ClassName
{
    ... .. ...
    friend return_type functionName(argument/s);
    ... .. ...
}

return_type functionName(argument/s)
{
    ... .. ...
    // Private and protected data of className can be accessed from
    // this function because it is a friend function of className.
    ... .. ...
}
```
### Working of friend Function
``` C++

#include <iostream>

class Distance
{
    private:
        int meter;
    public:
        Distance(): meter(0) { }
        //friend function
        friend int addFive(Distance);
};

// friend function definition
int addFive(Distance d)
{
    //accessing private data from non-member function
    d.meter += 5;
    return d.meter;
}

int main()
{
    Distance D;
    std::cout<<"Distance: "<< addFive(D);
    return 0;
}
```
### Output
```
Distance: 5
```

**EXPLANATION** Here, friend function `int addFive()` is declared inside Distance class. So, the private data member can be accessed from this function.

### Limitations of friend function
In C++, friendship is not inherited. If a base class has a friend function, then the function doesn’t become a friend of the derived class(es).
For example, following program prints error because show() which is a friend of base class A tries to access private data of derived class B.
```C++
#include <iostream> 


class A 
{ 
protected: 
	int x; 
public: 
	A() { x = 0;} 
friend void show(); 
}; 

class B: public A 
{ 
public: 
	B() : y (0) {} 
private: 
	int y; 

}; 

void show() 
{ 
B b; 
std::cout << "The default value of A::x = " << b.x; 

// Can't access private member declared in class 'B' 
std::cout << "The default value of B::y = " << b.y; 
} 

int main() 
{ 
show(); 
getchar(); 
return 0; 
} 
```




