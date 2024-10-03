#include <stdio.h>
/*
 * Part of Cosmos by OpenGenus Foundation
*/

/*
 * Input: an integer array with size in index 0, the element to be searched
 * Output: if found, returns the index of the element else -1
*/
int search(int arr[], int x)
{
	int i=0, size= arr[0];
	for (i=0; i<size; i++)
		if (arr[i] == x)
		return i;
	return -1;
}


int main() 
{
    int arr[] = {-1,2,3,1,5}; // Index 0 stores the size of the array (initially 0)
    arr[0] = sizeof(arr)/sizeof(arr[0])-1;
    int find = 1;
    printf("Position of %d is %d\n", find, search(arr,find));
    return 0;
}
