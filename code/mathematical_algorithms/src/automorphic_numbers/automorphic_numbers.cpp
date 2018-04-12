#include <iostream>
#include <string>
#include <algorithm> // For std::equal

using namespace std;

/*
 * In mathematics an automorphic number (sometimes referred to as a circular number) is a number
 * whose square "ends" in the same digits as the number itself.
 * For example, 5^2 = 25, 6^2 = 36, 76^2 = 5776, 376^2 = 141376,and 890625^2 = 793212890625,
 * so 5, 6, 76 and 890625
 */

// Part of Cosmos by OpenGenus Foundation
int main()
{
    long long int number; // May have to deal with large numbers
    cout << "Enter a number: ";
    cin >> number;

    unsigned long long int numberSquared = number * number; // Squares can get really big

    string numberString = to_string(number);
    string numberSquaredString = to_string(numberSquared);

    bool isAutomorphic = std::equal(numberString.rbegin(),
                                    numberString.rend(), numberSquaredString.rbegin());                        // Checks if the number is at the end of the number squared

    cout << number << " is " << (isAutomorphic ? "" : "not ") << "an automorphic number." << endl;
}
