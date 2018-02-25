#include<iostream>
#include<math.h>

int main()
{
    int divisorCount=0;
    int triangleNumberIndex = 0, triangleNumber = 0;
    
    while (divisorCount < 500)
    { 
        divisorCount = 0;
        ++triangleNumberIndex;
        triangleNumber += j;
        for(int i = 1; i <= pow(triangleNumber,0.5); ++i)
        {
            if (triangleNumber % i ==  0)
                {
                    if (i*i == triangleNumber)
                        divisorCount += 1;
                    else
                        divisorCount += 2;
                }
        }
        
    }

    std::cout<< n <<"\n";
    return 0;
}