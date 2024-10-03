The differences between delete,delete[] and free are as follows:

1. free is a library function whereas delete and delete[] are both operator.
2. free does not call any destructor while delete calls a destructor, if present whereas delete[] calls all the destructors that are present, according to the array size.
3. free deallocates any block of memory created using malloc, calloc or realloc while delete deallocates a non-array object that has been created with new.whereas delete[] deallocates an array that has been created with new[].
4. Freeing or deleting a null pointer with free, delete or delete[] causes no harm.
5. free() uses C run time heap while delete and delete[] may be overloaded on class basis to use private heap.

We cannot allocate an object with malloc() and free it using delete or allocate with new and delete with free() or use realloc() on an array allocated by new.The C++ operators new and delete guarantee proper construction and destruction; where constructors or destructors need to be invoked, they are. The C-style functions malloc(), calloc(), free(), and realloc() don’t ensure that. Furthermore, there is no guarantee that the mechanism used by new and delete to acquire and release raw memory is compatible with malloc() and free()

Link to the article: https://iq.opengenus.org/delete-vs-free-in-cpp/
