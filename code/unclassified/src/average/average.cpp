/// Part of Cosmos by OpenGenus Foundation
/// Find of average of numbers in an array
/// Contributed by: Pranav Gupta (foobar98)
/// Modified by: Arnav Borborah (arnavb)

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    vector<int> elements;

    cout << "Enter the numbers you want to find the average of: ";
    int sum = 0;
    string input;
    getline(cin, input);
    istringstream is(input);
    for (int element; is >> element;)     // Read numbers until the user enters a newline
    {
        elements.push_back(element);
        sum += element;
    }
    double avg = static_cast<double>(sum) / elements.size();
    cout << "Average of numbers: " << avg << endl;
}
