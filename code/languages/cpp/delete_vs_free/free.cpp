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
