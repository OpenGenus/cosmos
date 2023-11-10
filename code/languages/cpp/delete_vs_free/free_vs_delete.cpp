//Example of free() function using malloc and realloc:
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
	char *ptr;
	ptr = (char*) malloc(10*sizeof(char));             //Allocating memory to thr character pointer
        
    strcpy(ptr,"Hello C++");
	cout << "Before reallocating: " << ptr << endl;    
 
 	ptr = (char*) realloc(ptr,20);                     //Reallocating memory
	strcpy(ptr,"Hello, Welcome to C++");
	cout << "After reallocating: " <<ptr << endl;

	free(ptr);                                         //Freeing the character pointer
    cout << endl << "Garbage Value: " << ptr;

	return 0;
}

// Example of deleting a single object:
#include<iostream>
using namespace std;

int main()
{
int *d = new int(10);                     //Integer object created
cout<< "The value at the address pointed by the pointer variable : " << *d << "\n";
cout<< "The memory address allocated to the pointer variable : " << d << "\n";

delete d;                                //Single integer object deleted

cout<< "The value at the address pointed by pointer variable : " << *d << "\n";
cout<< "The memory address allocated to the pointer variable : " << d;
}

//Example of deleting multiple objects:
#include<iostream>
using namespace std;

int main()
{
int *d = new int[100];                    //creation of multiple objects
delete [] d;                              //deletion of multiple objects
}
