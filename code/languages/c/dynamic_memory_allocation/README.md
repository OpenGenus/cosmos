## Dynamic memory allocation

The C programming language manages memory statically, automatically, or dynamically. Static-duration variables are allocated in main memory, usually along with the executable code of the program, and persist for the lifetime of the program; automatic-duration variables are allocated on the stack and come and go as functions are called and return. For static-duration and automatic-duration variables, the size of the allocation must be compile-time constant (except for the case of variable-length automatic arrays[5]). If the required size is not known until run-time (for example, if data of arbitrary size is being read from the user or from a disk file), then using fixed-size data objects is inadequate.

The lifetime of allocated memory can also cause concern. Neither static- nor automatic-duration memory is adequate for all situations. Automatic-allocated data cannot persist across multiple function calls, while static data persists for the life of the program whether it is needed or not. In many situations the programmer requires greater flexibility in managing the lifetime of allocated memory.

These limitations are avoided by using dynamic memory allocation in which ```memory``` is more explicitly (but more flexibly) managed, typically, by allocating it from the free store (informally called the "heap"), an area of memory structured for this purpose. In C, the library function malloc is used to allocate a block of memory on the heap. The program accesses this block of memory via a pointer that malloc returns. When the memory is no longer needed, the pointer is passed to ```free``` which deallocates the memory so that it can be used for other purposes.

### Types of Functions

* malloc	allocates the specified number of bytes
* realloc	increases or decreases the size of the specified block of memory, moving it if necessary
* calloc	allocates the specified number of bytes and initializes them to zero
* free		releases the specified block of memory back to the system

### Function Prototype
* **malloc**
Syntax
ptr = (cast-type*) malloc(byte-size); 

For Example:
ptr = (int*) malloc(100 * sizeof(int));
* **calloc**
Syntax:
ptr = (cast-type*)calloc(n, element-size);

For Example:
ptr = (float*) calloc(25, sizeof(float));
* **realloc**
Syntax:
ptr = realloc(ptr, newSize);

where ptr is reallocated with new size 'newSize'.

* **free**
Syntax:
free(ptr);


### Sample code for malloc 
``` C
void foo(int n, int m) {
    int i, *p;
  
    /* Allocate a block of n ints */
    p = (int *) malloc(n * sizeof(int));
    if (p == NULL) {
        perror("malloc");
        exit(0);
    }
  
    /* Initialize allocated block */
    for (i=0; i<n; i++) 
        p[i] = i;

  
    /* Return p to the heap */
    free(p); 
}
```
### Sample code for realloc
```C
#include <stdio.h> 
#include <stdlib.h> 
int main() 
{ 
int arr[2], i; 
int *ptr = arr; 
int *ptr_new; 
	
arr[0] = 10; 
arr[1] = 20;	 
	
// incorrect use of new_ptr: undefined behaviour 
ptr_new = (int *)realloc(ptr, sizeof(int)*3); 
*(ptr_new + 2) = 30; 
	
for(i = 0; i < 3; i++) 
	printf("%d ", *(ptr_new + i)); 

getchar(); 
return 0; 
} 
```
### Sample code for calloc
``` C
#include <stdio.h>
#include <stdlib.h>

int main () {
   int i, n;
   int *a;

   printf("Number of elements to be entered:");
   scanf("%d",&n);

   a = (int*)calloc(n, sizeof(int));
   printf("Enter %d numbers:\n",n);
   for( i=0 ; i < n ; i++ ) {
      scanf("%d",&a[i]);
   }

   printf("The numbers entered are: ");
   for( i=0 ; i < n ; i++ ) {
      printf("%d ",a[i]);
   }
   free( a );
   
   return(0);
}
```
