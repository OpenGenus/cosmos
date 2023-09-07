/*Algorithm of tower of Hanoi
START
 Hanoi(disk_no, source, dest, aux)
  IF disk == 1, THEN
     move disk from source to dest             
  ELSE
Hanoi(disk_no - 1, source, aux, dest)   : Step 1
     move disk from source to dest           : Step 2
     Hanoi(disk_no - 1, aux, dest, source)   :  Step 3
  END IF   
END Procedure
STOP*/

#include<iostream>

using namespace std;

void TowerOfHanoi(int n, char from_rod, char to_rod, char aux_rod);

int main()
{
    int n;
    char source,destination,auxi;
    cout<<"Enter no. of disk:";
    cin>>n;
    cout<<"Enter source rode name:";
    cin>>source;
    cout<<"Enter Destination rode name:";
    cin>>destination;
    cout<<"Enter Auxi. rode name:";
    cin>>auxi;
    TowerOfHanoi (n, source, destination, auxi);
    return 0;
}

void TowerOfHanoi (int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
	cout<<"Move disk 1 from rod "<<from_rod<<" to rod " <<to_rod<<endl;
	return;
    }
    TowerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    cout<<"Move disk "<<n<< " from rod "<<from_rod<<" to rod "<<to_rod<<endl;
    TowerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}
