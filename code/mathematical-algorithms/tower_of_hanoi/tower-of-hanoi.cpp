#include<iostream>
// Part of Cosmos by OpenGenus Foundation
#include<stack>
using namespace std;


// Stack[0] 	-> Source Stack
// Stack[1]    	-> Auxilliary Stack
// Stack[2]   	-> Destination Stack
// For visualisation, we are also going to store the disk number along with its size.
// So,the data type for the stack is pair<int,int>
// The pair will correspond to  < disk size,disk number >

stack<pair<int,int> > Stack[3];




// Tower of Hanoi Function 
// Parameters are (A,B,C,N)
// A   -> Source Stack Number
// B   -> Auxilliary Stack Number
// C   -> Destination Stack Number
// N   -> Number of disks to be transferred from the Source Stack to the Destination Stack

void Tower_of_Hanoi(int  A ,int B,int  C,int N)
{	
	if(N==0)
		return;

	Tower_of_Hanoi(A,C,B,N-1);          // Transferring N-1 disks from stack A to B via C

	pair<int,int> curr_disk = Stack[A].top();  // Nth Disk , still present in the Source stack
	int sz=curr_disk.first;				// Size of the Nth Disk
	int number=curr_disk.second;		// Disk Number of the Nth Disk
	Stack[A].pop(); 							// Poppped the Nth Disk from the Source stack
	Stack[C].push(curr_disk);
	cout<<"Transferred Disk : Size "<<sz<<" and Number "<<number<<" from Stack "<<A<<" to "<<C<<endl;
	Tower_of_Hanoi(B,A,C,N-1);

}

