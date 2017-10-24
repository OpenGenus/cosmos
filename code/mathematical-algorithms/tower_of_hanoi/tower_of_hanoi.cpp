/* Part of Cosmos by OpenGenus Foundation */
#include <bits/stdc++.h>

// A recursive function to solve tower of hanoi puzzle
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        cout<<"\n"<<"Move disk 1 from rod"<<from_rod<<"to rod"<<to_rod;
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    cout<<"\n"<<"Move disk "<<n<<"from rod"<<from_rod<<"to rod"<<to_rod;
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n;// Number of disks
    cin>>n;
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods
    return 0;
}