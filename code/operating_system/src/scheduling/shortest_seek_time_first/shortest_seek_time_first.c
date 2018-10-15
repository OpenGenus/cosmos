// C program for implementing Shortest Seek Time First
// Disk Scheduling

#include<stdio.h>
#include<stdlib.h> // has inbuilt quick sort, abs for ints

// For Ascending Order Sort
int compare (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


int main() {

    // Initialization
    int noOfRequests, headAt;
    int requests[20];
    int headMovement = 0;
    int left = 0 , right = 0 ;


    // Read input
    printf("Enter no. of requests ... ");
    scanf("%d", &noOfRequests);
  
    printf("Enter no. of requests ... \n");
    for ( int i = 0 ; i < noOfRequests; i ++)
        scanf("%d", &requests[i]);
    
    printf("Enter the starting position for head ... ");
    scanf("%d", &headAt);
    
    /*============ SSTF ================= */
    
    // quick sort
    qsort(requests, noOfRequests, sizeof(int), compare);
    
    // initializing left and right counters	
    while ( requests[right] < headAt){
	left = right;
	right ++;
    } 
	
    
    // Until head reaches extreme left 0 or extreme right 199
    while ( left != -1 && right != noOfRequests){
	
	// Left request is near to head
	if ( abs( headAt - requests[left]) < abs (headAt - requests[right]) ){
	    headMovement += abs( headAt - requests[left]);
	    headAt = requests[left];	   
	    left --;
	    
	}
	// Right request is near to head
	else{
	    headMovement += abs( headAt - requests[right]);
	    headAt = requests[right];	   
	    right ++;
	}
	
    } 

    
    // When we have requests only to the left of the head 
    while( left != -1){
	headMovement += abs( headAt - requests[left]);
	headAt = requests[left];
	left --;
	
    }
	
    // When we have requests only to the right of the head
    while( right != noOfRequests ){
	headMovement += abs( headAt - requests[right]);
	headAt = requests[right];
	right ++;
	
    }

    /* ================== SSTF ENDS ================ */

    printf("Total head movement is %d\n", headMovement);
   
}


/*

Example form Operating System Concepts 7th edition by Silberschatz, Galvin, Gagne
Page no. 459
 
OUTPUT: 
Enter no. of requests ... 8
Enter no. of requests ... 
98 183 37 122 14 124 65 67
Enter the starting position for head ... 53
Total head movement is 236

*/
