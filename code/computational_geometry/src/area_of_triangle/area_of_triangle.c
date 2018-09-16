#include <stdio.h>
#include <stdlib.h>

float 
area(float x1, float x2, float y1, float y2,
	float z1, float z2)
{
	return (fabsf((x1 - y1) * (z2 - y2) - (x2 - y2) * (z1 - y1)) / 2.0);
}

int 
main()
{
	float x1, x2, y1, y2, z1, z2;
	printf("Enter x1 = ");
	scanf("%f", &x1);
	printf("Enter x2 = ");
	scanf("%f", &x2);
	printf("Enter y1 = ");
	scanf("%f", &y1);
	printf("Enter y2 = ");
	scanf("%f", &y2);
	printf("Enter z1 = ");
	scanf("%f", &z1);
	printf("Enter z2 = ");
	scanf("%f", &z2);

	printf("Area of the Triangle = %f \n", area(x1, x2, y1, y2, z1, z2));

	return (0);
}
