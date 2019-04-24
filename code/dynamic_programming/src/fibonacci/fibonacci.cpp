/* Part of Cosmos by OpenGenus Foundation */

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int dynamic_programming(int num);

int main(){

  int number;

  cout << "Please enter an integer: ";
  cin >> number;

  int dyn_prog = dynamic_programming(number);

  cout << "Fibonacci number is: " << dyn_prog << endl;

  return 0;
}

int dynamic_programming(int num){

  int fibarray[num+1];

  //Fibonacci first two number are always 0 and 1
  fibarray[0] = 0;
  fibarray[1] = 1;

  //Stores the values of the Fibnonacci numbers inside the array
  for ( int i = 2; i <= num; i++){
    fibarray[i] = fibarray[i-1] + fibarray[i-2];
  }

  //Get the number at the postion passed in
  int fibnum = fibarray[num];

  return fibnum;
}
