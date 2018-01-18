# cosmos
Your personal library of every algorithm and data structure code that you will ever encounter

## Xor Swap
In computer programming, the XOR swap is an algorithm that uses the XOR 
bitwise operation to swap values of distinct 
variables having the same data type without using a temporary variable.

## Proof of correctness
Let's say we have two distinct registers R1 and R2 as in the table below, 
with initial values A and B respectively.

|   Step	|   Operation	|   R1	|   R2	|
|---	|---	|---	|---	|
|   0	|   Initial	|   A	|   B	|
|   1	|   R1 := R1 ^ R2	|   A ^ B	|   B	|
|   2	|   R2 := R1 ^ R2	|   A ^ B	|  (A ^ B) ^ B => A 	|
|   3	|   R1 := R1 ^ R2	|   (A ^ B) ^ A => B	|   A	|
