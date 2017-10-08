#include <iostream>
#include <string>
#include <algorithm> // For std::equal

using namespace std;

// Part of Cosmos by OpenGenus Foundation
int main()
{
    long long int number; // May have to deal with large numbers
    cout << "Enter a number: ";
    cin >> number;
    
    unsigned long long int numberSquared = number * number; // Squares can get really big
    
    string numberString = to_string(number);
    string numberSquaredString = to_string(numberSquared);
    
    bool isAutomorphic = std::equal(numberString.rbegin(), numberString.rend(), numberSquaredString.rbegin()); // Checks if the number is at the end of the number squared
    
    cout << number << " is " << (isAutomorphic ? "" : "not ") << "an automorphic number." << endl;
}