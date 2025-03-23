#include <iostream>

bool isLeapYear(int year)
{
    if (year % 400 == 0)
        return true;

    if (year % 100 == 0)
        return false;

    return year % 4 == 0;
}

void findLeapYears(int a, int b)
{
    std::cout << "The leap years between " << a << " and " << b << " are : \n";
    for (int i = a; i <= b; i++)
        if (isLeapYear(i))
            std::cout << i << "\n";
}

int main()
{
    using namespace std;
    int year1, year2;
    cout << "Enter the first year: ";
    cin >> year1;
    cout << "Enter the second year year: ";
    cin >> year2;
    if (year1 > year2)
        findLeapYears(year2, year1);
    else
        findLeapYears(year1, year2);

    return 0;
}
