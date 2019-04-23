## Dynamic memory allocation

The C programming language manages memory statically, automatically, or dynamically. Static-duration variables are allocated in main memory, usually along with the executable code of the program, and persist for the lifetime of the program; automatic-duration variables are allocated on the stack and come and go as functions are called and return. For static-duration and automatic-duration variables, the size of the allocation must be compile-time constant (except for the case of variable-length automatic arrays[5]). If the required size is not known until run-time (for example, if data of arbitrary size is being read from the user or from a disk file), then using fixed-size data objects is inadequate.

The lifetime of allocated memory can also cause concern. Neither static- nor automatic-duration memory is adequate for all situations. Automatic-allocated data cannot persist across multiple function calls, while static data persists for the life of the program whether it is needed or not. In many situations the programmer requires greater flexibility in managing the lifetime of allocated memory.

These limitations are avoided by using dynamic memory allocation in which ```memory``` is more explicitly (but more flexibly) managed, typically, by allocating it from the free store (informally called the "heap"), an area of memory structured for this purpose. In C, the library function malloc is used to allocate a block of memory on the heap. The program accesses this block of memory via a pointer that malloc returns. When the memory is no longer needed, the pointer is passed to ```free``` which deallocates the memory so that it can be used for other purposes.

### Types of Functions

* malloc	allocates the specified number of bytes
* realloc	increases or decreases the size of the specified block of memory, moving it if necessary
* calloc	allocates the specified number of bytes and initializes them to zero
* free		releases the specified block of memory back to the system

### Sample code

``` C
int array[10];
int * array = malloc(10 * sizeof(*array));
int * array = malloc(10 * sizeof(*array));
if (array == NULL) {
  fprintf(stderr, "malloc failed\n");
  return(-1);
}
free(array);
```

