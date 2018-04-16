#include <iostream>
#include <cmath>
using namespace std;

// Part of Cosmos by OpenGenus Foundation
int main()
{
    int initialNumber;
    int number;
    cout << "Enter a three digit number: ";
    cin >> initialNumber;
    number = initialNumber;

    int lastDigitCubed = pow(number % 10, 3);
    number /= 10;
    int middleDigitCubed = pow(number % 10, 3);
    number /= 10;
    int firstDigitCubed = pow(number % 10, 3);

    bool isArmstrongNumber = (firstDigitCubed + middleDigitCubed + lastDigitCubed) == initialNumber;
    cout << initialNumber << " is " << (isArmstrongNumber ? "" : "not ") <<
        "an Armstrong number." << endl;
}
