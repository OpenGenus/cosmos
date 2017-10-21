
/* A simple C progr
am to cre
ate Jacca
rd’s indice
s adjusted for dif
fer
ence
s in species ric
hness
acr
oss site (for de
tails see Patten and Smith-Patten 2008, 
J. Biogeogr.
 35:407–416). */
#include
<time.h>
#include
<math.h>
#include
<stdlib.h>
#include
<stdio.h>
#include
<conio.h>
#include
<floa
t.h>
#define
R
524
#define
C
46
#define
 MAX
100
void main()
{
time_t
toc;
int
M[R
][
C]
, B[R]
[C
], S
[C
];
int
i,j,k, in, un, b;
float
J
acc
ard[C]
[C
], q;
FI
L
E
*fpi, *fpo;
time(&
toc);
/* random number se
ed */
srand(
(int)toc);
/* ge
nera
te pseudora
ndom number */
fpi = fope
n("
Afric
a.txt
", "
r"
);
/* open input file (may
 be alter
ed) */
fpo = f
open("
foo.tx
t", "
w"
);
/* standard output file (ditto) */
for (
i = 0; i < R; i++)
/* rea
d prese
nce–a
bsence
 data */
for (
j = 0; j < C; ++j)
fsca
nf(f
pi, "%
d", &
M[i
][
j]
);
for (
b = 0; b < MAX
; ++b)
 {
/* initi
alize J
acc
ard ma
trix
 to zero */
for (
j = 0; j < C; ++j) S[j]
 = 0;
for (
i = 0; i < C; ++i)
for (
j = 0; j < C; ++j) Jacca
rd[i]
[j
] = 0.0;
i = 0;
for (
i = 0; i < R ; ++i) {
/* obtain species da
ta from input */
k = (int)(
(float)
(ra
nd()/32767.0*(R-1)
));
for (
j = 0; j < C; ++j)
B[i]
[j
] = M[
k][
j]
;
}
for (
j = 0; j < C; ++j)
/* sum species */
for (
i = 0; i < R; ++i)
S[
j]
 += B
[i
][
j]
;
for (
k = 0; k < C-1; ++
k)
/* calcula
ted J
acc
ard’
s index
 */
for (
j = k+1; j < C; ++
j) {
in = un = 0;
for (
i = 0; i < R; ++i) {
un += (
B[i]
[k]
 |
|
 B[i]
[j
]);
in += (
B[i]
[k]
 &&
 B[i]
[j
]);
}
q = S[k]
<S[j
] ?
 (float)
S[
j]
/S[
k] :
 (float)
S[
k]/
S[
j]
;
/* adjust index
 . . . */
J
acc
ard[k][
j]
 = (f
loat)in/un*q*100.0;
/* by
 diff. ric
hness */
}
for (
j = 1; j < C; ++j) {
/* output adjusted J
acc
ard’
s */
fprintf(f
po, "\
n")
;
for (
k = 0; k < j; ++
k)
fprintf(f
po, "%
.1f "
, 100.0-Jaccar
d[k]
[j
]);
}
}}
