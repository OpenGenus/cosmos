#include <stdio.h>

long long int n, ans = 0, DONE;
void solve(long long int rowMask, long long int ld, long long int rd) 
{
  if (rowMask == DONE) 
  {
    ans++;
    return;
  }
  long long int safe = DONE & (~(rowMask | ld | rd));
  while (safe) 
  {
    long long int p = safe & (-safe);
    safe = safe - p;
    solve(rowMask | p, (ld | p) << 1, (rd | p) >> 1);
  }
}
int main() 
{
  scanf("%lld", &n);
  DONE = (1 << n) - 1;
  solve(0, 0, 0);
  printf("%lld", ans);
}
