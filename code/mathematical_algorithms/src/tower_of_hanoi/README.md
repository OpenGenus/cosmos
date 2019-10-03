# cosmos
Your personal library of every algorithm and data structure code that you will ever encounter

Collaborative effort by [OpenGenus](https://github.com/opengenus)

This problem is done using recurssive approach.
Moving n disks from rod L to rod R using rod C, can be recurssively defined as:
1.) Moving n-1 disks from rod L to rod C.
2.) Moving nth disk from rod L to rod R.
3.) Moving n-1 disks from rod C to rod R.

The recussion stops when n becomes 1 which is just moving a particular disk.

Source : Wikipedia
Disk positions may be determined more directly from the binary (base-2)
representation of the move number (the initial state being move #0, with all
digits 0, and the final state being with all digits 1), using the following
rules:

    There is one binary digit (bit) for each disk.
    The most significant (leftmost) bit represents the largest disk. A value of
0 indicates that the largest disk is on the initial peg, while a 1 indicates
that it's on the final peg (right peg if number of disks is odd and middle peg
otherwise).
    The bitstring is read from left to right, and each bit can be used to
determine the location of the corresponding disk.
    A bit with the same value as the previous one means that the corresponding
disk is stacked on top the previous disk on the same peg.

        (That is to say: a straight sequence of 1s or 0s means that the
corresponding disks are all on the same peg).

    A bit with a different value to the previous one means that the
corresponding disk is one position to the left or right of the previous one.
Whether it is left or right is determined by this rule:
        Assume that the initial peg is on the left.
        Also assume "wrapping" – so the right peg counts as one peg "left" of
the left peg, and vice versa.
        Let n be the number of greater disks that are located on the same peg as
their first greater disk and add 1 if the largest disk is on the left peg. If n
is even, the disk is located one peg to the right, if n is odd, the disk located
one peg to the left (in case of even number of disks and vice versa otherwise).

For example, in an 8-disk Hanoi:

    Move 0 = 00000000.
        The largest disk is 0, so it is on the left (initial) peg.
        All other disks are 0 as well, so they are stacked on top of it. Hence
all disks are on the initial peg.
    Move 28 − 1 = 11111111.
        The largest disk is 1, so it is on the middle (final) peg.
        All other disks are 1 as well, so they are stacked on top of it. Hence
all disks are on the final peg and the puzzle is complete.
    Move 21610 = 11011000.
        The largest disk is 1, so it is on the middle (final) peg.
        Disk two is also 1, so it is stacked on top of it, on the middle peg.
        Disk three is 0, so it is on another peg. Since n is odd (n = 1), it is
one peg to the left, i.e. on the left peg.
        Disk four is 1, so it is on another peg. Since n is odd (n = 1), it is
one peg to the left, i.e. on the right peg.
        Disk five is also 1, so it is stacked on top of it, on the right peg.
        Disk six is 0, so it is on another peg. Since n is even (n = 2), the
disk is one peg to the right, i.e. on the left peg.
        Disks seven and eight are also 0, so they are stacked on top of it, on
the left peg.

The source and destination pegs for the mth move can also be found elegantly
from the binary representation of m using bitwise operations. To use the syntax
of the C programming language, move m is from peg (m & m - 1) % 3 to peg 
((m | m - 1) + 1) % 3, where the disks begin on peg 0 and finish on peg 1 or 2 according
as whether the number of disks is even or odd. Another formulation is from peg
(m - (m & -m)) % 3 to peg (m + (m & -m)) % 3.

Furthermore, the disk to be moved is determined by the number of times the move
count (m) can be divided by 2 (i.e. the number of zero bits at the right),
counting the first move as 1 and identifying the disks by the numbers 0, 1, 2
etc. in order of increasing size. This permits a very fast non-recursive
computer implementation to find the positions of the disks after m moves without
reference to any previous move or distribution of disks.

The operation, which counts the number of consecutive zeros at the end of a
binary number, gives a simple solution to the problem: the disks are numbered
from zero, and at move m, disk number count trailing zeros is moved the minimal
possible distance to the right (circling back around to the left as needed).

