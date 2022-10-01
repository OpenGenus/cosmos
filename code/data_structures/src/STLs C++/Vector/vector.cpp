//The files contains the example of the STLs used.
#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    vector<int> g1; //normal declaration
 
    for (int i = 1; i <= 5; i++)
        g1.push_back(i); //Insertion of values in the vector through push back
 
    cout << "Output of begin and end: ";
    for (auto i = g1.begin(); i != g1.end(); ++i)
        cout << *i << " "; //Output of the vectors
 
     cout << "Size : " << g1.size();
    cout << "\nCapacity : " << g1.capacity();
    cout << "\nMax_Size : " << g1.max_size();
 
    // resizes the vector size to 4
    g1.resize(4);
 
    // prints the vector size after resize()
    cout << "\nSize : " << g1.size();
 
    // checks if the vector is empty or not
    if (g1.empty() == false)
        cout << "\nVector is not empty";
    else
        cout << "\nVector is empty";
 
    // Shrinks the vector
    g1.shrink_to_fit();
    cout << "\nVector elements are: ";
    for (auto it = g1.begin(); it != g1.end(); it++)
        cout << *it << " ";
   
  // inserts 15 to the last position
    g1.push_back(15);
    int n = g1.size();
    cout << "\nThe last element is: " << g1[n - 1];
 
    // removes last element
    g1.pop_back();
  //deletes all elements
  g1.clear();


}
