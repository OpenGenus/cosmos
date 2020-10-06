Deletion of an array means that we need to deallocate the memory that was allocated to the array so that it can be used for other purposes.
Arrays occupy a lot of our memory space. Hence, to free up the memory at the end of the program, we must remove/deallocate the memory bytes used by the array to prevent wastage of memory.

If the array is declared statically, then we do not need to delete an array since it gets deleted by the end of the program/block in which it was declared.

But if the array is declared dynamically, i.e. using malloc/calloc, then we need to free up the memory space used up by them by the end of the program for the program to not crash down. It can be done by calling the free method and passing the array.
When we allocate memory dynamically, some part of information is stored before or after the allocated block. free uses this information to know how memory was allocated and then frees up the whole block of memory.

However, if we allocate memory for each array element, then we need to free each element before deleting the array.

Link to the article: https://iq.opengenus.org/delete-vs-free-in-cpp/
