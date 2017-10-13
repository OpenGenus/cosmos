# cosmos
Your personal library of every algorithm and data structure code that you will ever encounter

## Package: Convert number to binary
Programs in this folder are about converting numbers from `base 10`(decimal) to `base 2`(binary)

### Examples:

----------------
| Decimal | Binary |
| :---: | :---: |
| 0 | 0 |
| 1 | 1 |
| 2 | 10 |
| 3 | 11 |
| 4 | 100 |
| 16 | 10000 |
----------------

### Main idea:
Binary numbers have `2` permissible digits `0` **and** `1`.

### How to convert?
Let `n` be a decimal number.

Let `k` denote the `k` number of bits in the binary number `b`.

`mod` is the modulus function, divides the left operand with right operand and provides just the remainder.


`quot` is the quotient function, divides left operand by right operand and provides just the quotient.

* step 1

    n `mod` 2 = b<sub>k - 1</sub>

    n `quot` 2 = n<sub>1</sub>

* step 2

    n<sub>1</sub> `mod` 2 = b<sub>k-2</sub>

    n<sub>1</sub> `quot` 2 = n<sub>2</sub>

... (continue till final step)

* final step

    n<sub>k - 1</sub> `mod` 2 = b<sub>0</sub>

    n<sub>k - 1</sub> `quot` 2 = 0


Lets walk with example of converting number `5` into a `8-bit` binary number:

n = 5, k = 8

---

5 `mod` 2 = 1 -- b<sub>7</sub>

5 `quot` 2 = 2

---

2 `mod` 2 = 0 -- b<sub>6</sub>

2 `quot` 2 = 1

---

1 `mod` 2 = 1 -- b<sub>5</sub>

1 `quot` 2 = 0 -- calc ends(end), all 0s after this point

---

0 `mod` 2 = 0 -- b<sub>4</sub>

0 `quot` 2 = 0

---

0 `mod` 2 = 0 -- b<sub>3</sub>

0 `quot` 2 = 0

---

0 `mod` 2 = 0 -- b<sub>2</sub>

0 `quot` 2 = 0

---

0 `mod` 2 = 0 -- b<sub>1</sub>

0 `quot` 2 = 0

---

0 `mod` 2 = 0 -- b<sub>0</sub>

0 `quot` 2 = 0

---

b = [0, 0, 0, 0, 0, 1, 0, 1] -- "00000101"

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
