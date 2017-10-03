#include <iostream>
// Part of Cosmos by OpenGenus Foundation
using namespace std;

int moves=0;
void hanoi(int disks, char a, char b, char c);

int main(){
  int discs;
  cout<<"Enter the number of discs: "<<endl;
  cin>>discs;
  hanoi(discs,'A','B','C');
  cout <<"It took "<<moves<<" moves."<< endl;
return 0;
}

void hanoi(int disks, char a, char b, char c){
  moves++;
  if(disks == 1){
    cout <<"Move disc "<<disks<<" from "<<a<<" to "<<c<<endl;
  }
  else{
    hanoi(disks-1, a,c,b);
    cout<<"Move disc "<<disks<<" from "<<a<<" to "<<c<< endl;
    hanoi(disks-1, b,a,c);
  }
}
