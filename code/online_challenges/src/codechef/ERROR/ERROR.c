#include <stdio.h>

int main(void) 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        char feedback[100000];
        scanf("%s", feedback);
        int i, d = 0;
        for (i = 2; feedback[i] != '\0'; ++i) 
        {
            if ((feedback[i] == '0' && feedback[i - 1] == '1' && feedback[i - 2] == '0') || (feedback[i] == '1' && feedback[i - 1] == '0' && feedback[i - 2] == '1')) 
            {
                d = 1;
                break;
            }
        }
        if (d == 0)
            printf("Bad\n");
        else
            printf("Good\n");
    }
    return 0;
}
