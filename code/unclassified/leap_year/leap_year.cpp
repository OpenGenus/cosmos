// part of cosmos by opengenus foundation

// THIS PROGRAM TAKES AN INPUT FOR YEAR AND RETURNS TRUE IF YEAR IS A LEAP YEAR


#include <iostream>
using namespace std;

bool is_leap(int year)
{
   return (year%4 == 0 && year%100 != 0) || year%400 == 0; 
}

int main()
{
   int year = 2000, year_2 = 3000;
   cout<<"Leap years from "<<year<<" to "<<year_2<<endl;

   while(year <= year_2)
   {
      if(is_leap(year))
      {
         cout<<year<<endl;
      }

      year++;
   }

   return 0;
}
