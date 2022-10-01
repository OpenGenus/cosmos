 #### Basic implementation
 <p>begin() – Returns an iterator pointing to the first element in the vector.</p>
 <p>end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector.</p>

> ```
>#include <iostream>
> #include<vector> //required header file
> using namespace std;
>int main()
> {vector<int> g1;} 
>```

 Capacity
<p>1.size() – Returns the number of elements in the vector.</p>
<p>2.max_size() – Returns the maximum number of elements that the vector can hold.</p>
<p>3.capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of elements.</p>
<p>4.resize(n) – Resizes the container so that it contains ‘n’ elements.</p>
<p>5.empty() – Returns whether the container is empty.</p>
<p>6.shrink_to_fit() – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.</p>
<p>7.reserve() – Requests that the vector capacity be at least enough to contain n elements.</p>

Modifiers: 

<p>assign() – It assigns new value to the vector elements by replacing old ones.</p>
<p>push_back() – It push the elements into a vector from the back.</p>
<p>pop_back() – It is used to pop or remove elements from a vector from the back.</p>
<p>insert() – It inserts new elements before the element at the specified position.</p>
<p>erase() – It is used to remove elements from a container from the specified position or range.</p>
<p>swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.</p>
<p>clear() – It is used to remove all the elements of the vector container.</p>\

<p>The most important part:</p>
<p>The time complexity for doing various operations on vectors is-</p>

<p>Random access – constant O(1)</p>
<p>Insertion or removal of elements at the end – constant O(1)</p>
<p>Insertion or removal of elements – linear in the distance to the end of the vector O(N)</p>
<p>Knowing the size – constant O(1)</p>
<p>Resizing the vector- Linear O(N)</p>
  
  
  
  
