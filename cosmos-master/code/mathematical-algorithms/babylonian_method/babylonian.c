	
#include<stdio.h>
 
double squareRoot(double num) {
    double error = 0.0000001;
    double x = num;
 
    while ((x - num / x) > error) {
 
        x = (x + num / x) / 2;
    }
    return x;
 
}
 
int main() {
 
    double num = 0;
    printf("Enter number for finding square root:");
    scanf("%lf", &num);
    printf("Square root of %lf is %lf\n", num, squareRoot(num));
    return 0;
}
