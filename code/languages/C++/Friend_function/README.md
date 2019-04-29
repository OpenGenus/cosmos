## friend Function

A friend function of a class is defined outside that class' scope but it has the right to access all private and protected members of the class. Even though the prototypes for friend functions appear in the class definition, friends are not member functions.
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

```
class className
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
/* C++ program to demonstrate the working of friend function.*/
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

**EXPLANATION** Here, friend function `addFive()` is declared inside Distance class. So, the private data meter can be accessed from this function.



