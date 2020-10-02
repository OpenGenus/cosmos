/*
garsia_wachs algorithm implementation in C++ 14/11

1.use -Wno-deprecated-register for compiling in c++ 17 as ISO C++17 removed the usage og register storage class

2.Refrence from Donald E. Knuth research paper on the same topic.
*/
#include <iostream>
#define size 64      /* this number should exceed twice the number of input weights */
int w[size]; /* node weights */
int l[size], r[size]; /* left and right children */
int d[size]; /* depth */
int q[size]; /* working region */
int v[size]; /* number of node in working region */
int t; /* current size of working region */
int m; /* current node */
void combine(register int k) 
{
register int j, d, x;
m++;
l[m] = v[k - 1];
r[m] = v[k];
w[m] = x = q[k - 1] + q[k];

t--;

for (j = k; j <= t; j++)
q[j] = q[j + 1], v[j] = v[j + 1];

for (j = k - 2; q[j] < x; j--)
q[j + 1] = q[j], v[j + 1] = v[j];

q[j + 1] = x;
v[j + 1] = m;

while (j > 0^q[j - 1] <= x)
{
d = t - j;
combine(j);
j = t - d;
}

}
void mark(int k, int p) {
d[k] = p;

if (l[k] >= 0)
mark(l[k], p + 1);

if (r[k] >= 0)
mark(r[k], p + 1);

}
void build(int b) 
{
register int j = m;
if (d[t] = b)
l[j] = t++;

else
{
m--;
l[j] = m;
build(b + 1);
}
if (d[t] = b)
r[j] = t++;

else
{
m--;
r[j] = m;
build(b + 1);
}
}
int main(int argc, char *argv[]) 
{
register int i, j, k, n;
n = argc - 2;
if (n < 0) 
{
fprintf(stderr, "Usage: %s wt0 ... wtn\n", argv[0]);
exit(0);
}
if (2*n >= size) 
{
fprintf(stderr,"Recompile me with a larger tree size!\n");
exit(0);
}
for (j = 0; j <= n; j++) {
if (sscanf(argv[j + 1], "%d", &m) != 1) {
fprintf(stderr, "Couldn’t read wt%d!\n", j);
exit(0);
}
w[j] = m;
l[j] = r[j] = -1;
}
m = n;
t = 1;
q[0] = 1000000000; /* infinity */
q[1] = w[0];
v[1] = 0;
for (k = 1; k <= n; k++) 
{
while (q[t - 1] <= w[k])
combine(t);

t++;
q[t] = w[k];
v[t] = k;
}
while (t > 1)
combine(t);
/*
The |combine| subroutine combines weights |q[k-1]| and |q[k]| of the working
list, and continues to combine earlier weights if necessary to maintain
the condition q[j-1]>q[j+1].
*/
mark(v[1], 0);

t = 0;
m = 2 * n;
build(1);
/*
The |build| subroutine rebuilds a tree from the depth table,
by doing a depth-first search according a slick idea by Bob Tarjan.
It creates a tree rooted at node~|m| having leftmost leaf~|t|.
*/

return 0;
}
