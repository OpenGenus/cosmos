#include <iostream>
// Part of Cosmos by OpenGenus Foundation
#include <stack>
using namespace std;


// Stack[0]     -> Source Stack
// Stack[1]     -> Auxilliary Stack
// Stack[2]     -> Destination Stack
// For visualisation, we are also going to store the disk number along with its size.
// So,the data type for the stack is pair<int,int>
// The pair will correspond to  < disk size,disk number >

stack<pair<int, int>> Stack[3];




// Tower of Hanoi Function
// Parameters are (A,B,C,N)
// A   -> Source Stack Number
// B   -> Auxilliary Stack Number
// C   -> Destination Stack Number
// N   -> Number of disks to be transferred from the Source Stack to the Destination Stack

void Tower_of_Hanoi(int A, int B, int C, int N)
{
    if (N == 0)
        return;

    Tower_of_Hanoi(A, C, B, N - 1);         // Transferring N-1 disks from stack A to B via C

    pair<int, int> curr_disk = Stack[A].top();     // Nth Disk , still present in the Source stack
    int sz = curr_disk.first;                           // Size of the Nth Disk
    int number = curr_disk.second;              // Disk Number of the Nth Disk
    Stack[A].pop();                                                             // Poppped the Nth Disk from the Source stack
    Stack[C].push(curr_disk);
    cout << "Transferred Disk : Size " << sz << " and Number " << number << " from Stack " << A <<
        " to " << C << endl;
    Tower_of_Hanoi(B, A, C, N - 1);

}

int main()
{
    // N is the number of disks int source stack
    int N;

    // Taking the input for these parameters

    cout << "Enter the number of disks \n";
    cin >> N;
    cout << "Enter the size of the disks \n";
    cout << "Note they must be in descending order \n \n";
    for (int i = N; i >= 1; i--)
    {
        int sz;
        cin >> sz;
        Stack[0].push(make_pair(sz, i));
        cout << "Disk : Size " << sz << " and Number " << i << " pushed into the Source Stack \n";
    }

    //Executing the Tower of Hanoi Function

    cout << " \n    Tower of Hanoi    \n";
    cout << " ----------------------------- \n \n";
    Tower_of_Hanoi(0, 1, 2, N);

    return 0;
}
