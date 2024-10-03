// Factorial using Stirling's approximation in c language

float stirling_approximation(int n) {
    int fact;
    float stirling, ans;
    fact = factorial(n);
    stirling = sqrt(2.0*3.1416*n) * pow(n / 2.71828, n);
    ans = fact / stirling;
    return ans;
}

int factorial(int input) {
    int i;
    int ans = 1;
    for (i = 2; i <= input; i++)
        ans *= i;
    return ans;
}

int main(void) {
    int n;
    printf(" n\t Ratio\n");
    for (n = 1; n <= 12; n++) {
        printf("n: %2d\t %f\n", n, stirling_approximation(n));
    }
    return 0;
}
