# Tuple

Tuple is a collection of Python objects much like a list. The sequence of values stored in a tuple can be of any type, and they are indexed by integers. The important difference between a list and a tuple is that tuples are immutable. 

Tuples are immutable, and usually, they contain a sequence of heterogeneous elements that are accessed via unpacking or indexing (or even by attribute in the case of named tuples). Lists are mutable, and their elements are usually homogeneous and are accessed by iterating over the list.

### Defining and Using Tuples

* Tuples are identical to lists in all respects, except for the following properties:

* Tuples are defined by enclosing the elements in parentheses (()) instead of square brackets ([]).
* Tuples are immutable.

Here is a short example showing a tuple definition, indexing, and slicing:
```Python
>>> t = ('foo', 'bar', 'baz', 'aux', 'quux', 'corge')
>>> t
('foo', 'bar', 'baz', 'aux', 'quux', 'corge')

>>> t[0]
'foo'
>>> t[-1]
'corge'
>>> t[1::2]
('bar', 'aux', 'corge')
```

string and list reversal mechanism works for tuples as well:

```python
>>> t[::-1]
('corge', 'quux', 'aux', 'baz', 'bar', 'foo')
```

### Why use a tuple instead of a list?

* Program execution is faster when manipulating a tuple than it is for the equivalent list. (This is probably not going to be noticeable when the list or tuple is small.)

* Sometimes you don’t want data to be modified. If the values in the collection are meant to remain constant for the life of the program, using a tuple instead of a list guards against accidental modification.

* There is another Python data type that you will encounter shortly called a dictionary, which requires as one of its components a value that is of an immutable type. A tuple can be used for this purpose, whereas a list can’t be.

