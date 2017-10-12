// header files and standard libs
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


// is_lapindrome function defined which will return true if string is lapindrome
bool is_lapindrome(string val)
{
  // a flag strue
  bool flag = true;
	int len = val.length();

  // checking if length is even or odd
  if(len%2 == 0)
  {
    // this is for even
  string first,second;  // declaring two string
  first.assign(val.substr(0,len/2));  // slicing from 0 - 1/2 of the length
  second.assign(val.substr(len/2,len));  // slicing from 1/2 of the length - actual length

  // traversing from 0 - len/2 , the complete length for
  for(int i=0;i<len/2;i++)
  {
    // main algo goes here
    int a = count(first.begin(), first.end(), first[0]);   // counting occurances a letter from first slice
    int b = count(second.begin(), second.end(), first[0]); // counting occurances of same letterfrom first slice
    if(a!=b)
    {
      flag = false; // make flag =  false if occurances are not same and break
      break;
    }
      // if any one occurances of ore is not equal then quit travering  -> mainly added to make algo faster
  }

  return flag;  // returning flag

}
else
{
  // for odd length
  // actually every thing is same but diff is at slicing
  // the difference is commented
  string first,second;
  first.assign(val.substr(0,len/2));
  second.assign(val.substr(len/2 + 1,len)); // ignoring the middle element of string

  for(int i=0;i<len/2;i++)
  {
    int a = count(first.begin(), first.end(), first[0]);
    int b = count(second.begin(), second.end(), first[0]);
    if(a!=b)
    {
      flag = false;
      break;
    }

  }
  return flag;
}
}

/*

    MAIN FUNCTION

*/
int main()
{
  // declaring a string variable
	string str;

  // prompting for user input
  cout<<"enter a value ";

  // getting user input
  getline(cin,str);

  // checking from function
  if(is_lapindrome(str))
    cout<<"\""<<str<<"\" is a lapindrome"<<endl;
  else
    cout<<"\""<<str<<"\" is not a lapindrome"<<endl;

	return 0;
}
