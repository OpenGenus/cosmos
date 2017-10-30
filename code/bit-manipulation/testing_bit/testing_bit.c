#include <stdio.h>
 
void main()
{
    unsigned int number;
    int result, position;
 
    printf("Enter the unsigned integer:\n");
    scanf("%d", &number);
    printf("enter position to be searched\n");
    scanf("%d", &position);
    result = (number >> (position));
    if (result & 1)
        printf("TRUE\n");
    else
        printf("FALSE\n");    
}