// including headers and std liberaries
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

// main function

int main()
{
  // the mid value for slicinng puspose
  int mid;
  string s,sl,sr;  // s - main string , sl -  left string slice and sr - right string slice

  getline(cin,s);  // getting user input

  int n = s.length(); // finding length of complete string
  mid=n/2;     // divinding the string

  int iter=mid; //even

  if(n%2) //odd
  {
    iter++;
  }

  // splicing string
  sl=s.substr(0,mid);
  sr=s.substr(iter,mid);

  // sorting to make easy
  sort(sl.begin(),sl.end());
  sort(sr.begin(),sr.end());

  // after sorting equating the strings
  if(sl==sr)
  cout<<"LAPINDROME STRING"<<endl;  // this says its lapindrome
  else
  cout<<"NOT A LAPINDROME STRING"<<endl;  // this says not a lapindrome

  // return 0 for successful exit to OS
  return 0;
}
