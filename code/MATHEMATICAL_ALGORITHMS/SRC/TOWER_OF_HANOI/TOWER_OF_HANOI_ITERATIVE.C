#include <stdio.h>
#include <math.h>

void 
toh (int n) {
    int steps, start, end, i;
    steps = pow (2, n);    // Minimum number of moves required
    for (i = 1; i < steps; i ++) {
    start = (i & (i-1)) % 3;
    end = (1 + (i | (i-1))) % 3;
    printf ("Disc %d shifted from %d to %d\n", i, start + 1, end + 1);
    }
}

int
main() {
    int n;
    printf ("Enter the number of discs : ");
    scanf ("%d", &n);
    toh(n);
    return (0);
}
