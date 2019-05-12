#include <iostream>
#include <vector>

int main() {

   // create a vector to store int
   vector<int> vec; 
   int i;

   // display the original size of vec
   std::cout << "vector size = " << vec.size() << endl;

   // push 5 values into the vector
   for(i = 0; i < 5; i++) 
   {
      vec.push_back(i);
   }

   // display extended size of vec
   std::cout << "extended vector size = " << vec.size() << endl;

   // access 5 values from the vector
   for(i = 0; i < 5; i++)
    {
      std::cout << "value of vec [" << i << "] = " << vec[i] << endl;
    }

   // use iterator to access the values
    vector<int>::iterator v = vec.begin();
    while( v != vec.end())
    {
      std::cout << "value of v = " << *v << endl;
      v++;
    }

   return 0;
}
