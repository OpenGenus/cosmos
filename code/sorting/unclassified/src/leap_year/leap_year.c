#include <stdio.h>

bool checkLeapYear(int year)
{
    if (year % 400 == 0)
        return true;

    if (year % 100 == 0)
        return false;

    if (year % 4 == 0)
        return true;
    return false;
}

int main()
{
    int year1 , year2;
    printf("Enter the first year: ");
    scanf("%d",&year1);
    printf("Enter the second year year: ");
    scanf("%d",&year2);
    printf("The leap years between %d and %d are : \n",year1,year2);
    for(int i=year1 ; i<=year2 ; i++)
    {
        if(checkLeapYear(i))
        {
            printf("%d\n",i);
        }
    }
    return 0;
}
