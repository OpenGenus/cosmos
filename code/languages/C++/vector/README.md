# Vector 
## [Article explaining vector in C++ at OpenGenus IQ](https://iq.opengenus.org/vector-cpp/)
We can think of **vectors** as smart arrays. They manage storage allocation for us, expanding
and contracting the size of the vector as we insert or erase data. We can use vectors much like
arrays, accessing elements with the [] operator. Such random access is very fast with vectors.
It’s also fast to add (or push) a new data item onto the end (the back) of the vector. When this
happens, the vector’s size is automatically increased to hold the new item. 

## Member Functions push_back() , size() , and operator[]

// demonstrates push_back(), operator[], size()

```C++
#include <iostream>
#include <vector>

int main()
{
  	vector<int> v;          //create a vector of ints
  	//put values at end of array
  	v.push_back(10);
  	v.push_back(11);
  	v.push_back(12);
  	v.push_back(13);
  	//replace with new values 
  	v[0] = 20;
  	v[3] = 23; 

  	for(int j=0; j<v.size(); j++)     //display vector contents
  	{
    		std::cout << v[j] <<' ';        //20 11 12 23
    		std::cout << endl;
  	}

   	return 0;
  
}
```


We use the vector’s default (no-argument) constructor to create a vector v . As with all STL containers, the template format is used to specify the type of variable the container will hold (in this case type int ). We don’t specify the container’s size, so it starts off at 0. 


The ```push_back()```  member function inserts the value of its argument at the back of the vector. (The back is where the element with the highest index number is.) The front of a vector (the element with index 0), unlike that of a list or queue, cannot be used for inserting new elements. Here we push the values 10, 11, 12, and 13, so that v[0] contains 10, v[1] contains 11, v[2] contains 12, and v[3] contains 13.
Once a vector has some data in it, this data can be accessed—both read and written to—using the overloaded [] operator, just as if it were in an array. We use this operator to change the first element from 10 to 20, and the last element from 13 to 23. Here’s the output from VECTOR :

```
20 11 12 23
```

The ```size()``` member function returns the number of elements currently in the container, which
in VECTOR is 4. We use this value in the for loop to print out the values of the elements in the
container.

Another member function, ```max_size()``` , returns the maximum size to which a container can be expanded. This number depends on the type of data being stored in the container (the bigger the elements, the fewer of them you can store), the type of container, and the operating system. For example, on our system max_size() returns ```1,073,741,823``` for a vector type int .


## Member Functions swap() , empty() , back() , pop_back()
```C++
#include <iostream>
#include <vector>

int main()
{
  //an array of doubles
 	double arr[] = { 1.1, 2.2, 3.3, 4.4 };
  	vector<double> v1(arr, arr+4); //initialize vector to array
  	vector<double> v2(4);   //empty vector of size 4

  	v1.swap(v2);       //swap contents of v1 and v2

  	while( !v2.empty() )
  	{                                      //until vector is empty,
  		std::cout << v2.back() << ‘ ‘;   //display the last element
  		v2.pop_back();                   //remove the last element
	}
  	std::cout << endl;                     //output: 4.4 3.3 2.2 1.1
 	return 0;
} 
```

We’ve used two new vector constructors in this program. The first initializes the vector v1 with the values of a normal C++ array passed to it as an argument. The arguments to this constructor are pointers to the start of the array and to the element one past the end. The second constructor sets v2 to an initial size of 4, but does not supply any initial values. Both vectors hold type ```double```. 
The ```swap()``` member function exchanges all the data in one vector with all the data in another, keeping the elements in the same order. In this program there is only garbage data in v2 , so it’s swapped with the data in v1 . We display v2 to show that it now contains the data that was inv1. The output is

```
4.4 3.3 2.2 1.1
```


The ```back()``` member function returns the value of the last element in the vector. We display this value with cout . ```The pop_back()``` member function removes the last element in the vector.

Thus each time through the loop there is a different last element. (It’s a little surprising that
pop_back() does not simultaneously return the value of the last element and remove it from
the vector, as we’ve seen pop() do in previous examples with stacks, but it doesn’t, so back()
must be used as well.)

Some member functions, such as swap() , also exist as algorithms. When this is the case, the
member function version is usually provided because it’s more efficient for that particular con-
tainer than the algorithm version. Sometimes you can use the algorithm as well. For example,
you can use it to swap elements in two different kinds of containers.

### Iterators in vector

* begin(): begin() function is used to return an iterator pointing to the first element of the vector container. begin() function returns a bidirectional iterator to the first element of the container.

**Example** 
```C++
#include <iostream> 
#include <vector> 

int main() 
{ 
    // declaration of vector container 
    vector<int> myvector{ 1, 2, 3, 4, 5 }; 
  
    // using begin() to print vector 
    for (auto it = myvector.begin(); 
         it != myvector.end(); ++it) 
        std::cout << ' ' << *it; 
    return 0; 
}
```
**Output**
``` 
1 2 3 4 5
```

* end(): end() function is used to return an iterator pointing to next to last element of the vector container. end() function returns a bidirectional iterator.

**Example**
```C++

#include <iostream> 
#include <vector> 

int main() 
{ 
	// declaration of vector container 
	vector<int> myvector{ 1, 2, 3, 4, 5 }; 

	// using end() to print vector 
	for (auto it = myvector.begin(); 
		it != myvector.end(); ++it) 
		std::cout << ' ' << *it; 
	return 0; 
}
```
**Output**
```
1 2 3 4 5
```

