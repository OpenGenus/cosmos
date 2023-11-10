#include <stdio.h>

int main() {
    int m[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int t;
    scanf("%d", &t);
    while (t--) {
        long long int a, b, sum = 0;
        scanf("%lld%lld", &a, &b);
        a += b;
        while (a > 0) {
        sum += m[a % 10];
        a /= 10;
        }
        printf("%lld\n", sum);
    }
}
