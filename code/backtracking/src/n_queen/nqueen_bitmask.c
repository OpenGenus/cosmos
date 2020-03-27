#include <stdio.h>

int ans = 0;
void solve(int rowMask, int ld, int rd, int done) {
    if (rowMask == done) {
        ++ans;
        return;
    }
    int safe = done & (~(rowMask | ld | rd));
    while (safe) {
        int p = safe & (-safe);
        safe -= p;
        solve(rowMask | p, (ld | p) << 1, (rd | p) >> 1, done);
    }
}

int main() {
    int n,done;
    scanf("%d", &n);
    done = (1 << n) - 1;
    solve(0, 0, 0, done);
    printf("%d", ans);
}
