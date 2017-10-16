// Part of cosmos from OpenGenus Foundation

// including header files and liberaries
#include <iostream>
#include <algorithm>
using namespace std;

/*
  Function that will check if string is lapindrome or not
*/
bool is_lapindrome(string str)
{
  // calculating length
  int len = str.length();

  // getting mid element
  int mid = len/2;

  // getting delimiter
  int delim = len%2==0 ? mid : mid + 1;  // for odd number of characters we have to ignore the middle most element

  // slicing
  string left = str.substr(0,mid);
  string right = str.substr(delim, len);

  // sorting two strings
  sort(left.begin(), left.end());
  sort(right.begin(), right.end());

  // equating and returning
  if(left==right)
    return true;
  else
    return false;
}

/*
  Main Function
*/
int main()
{
  // case 1
  if(is_lapindrome("aabaa"))
    cout<<"lapindrome"<<endl;
  else
    cout<<"not lapindrome"<<endl;

  // case 2
  if(is_lapindrome("aabab"))
    cout<<"lapindrome"<<endl;
  else
    cout<<"not lapindrome"<<endl;

    return 0;

}
