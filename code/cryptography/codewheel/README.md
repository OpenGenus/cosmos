Assuming that indexes start with 0, find the letter to be encoded on the
`(char pos in text % (num wheels - 1))`th wheel.

Follow letter down the column to the final wheel and output letter.
After every letter encoded, rotate the wheel as described.

Add wheels as necessary, increasing the rotation for each one to be the next prime number.

Reverse process to decrypt, find letter on final wheel, look up the decoded letter on the `(char pos in encrypted text % (num wheels - 1))`th wheel.

A minimum of 2 wheels are necessary for this cipher.

Wheel setup:

> wheel #1: a b c d e f  (rotates left by 2) (shift, push)  
> wheel #2: d e f a b c  (starts and rotates right by 3) (pop, unshift)  
> wheel #3: f a b c d e  (starts and rotates left by 5)  
> wheel #4: f a b c d e  (starts and rotates right by 7)  
> ...

Using the above 4 wheels, the letter 'd' would be output as 'c'.

Using the full letter range for each wheel:

> using 2 wheels, the message `RUN NOW!` becomes `U][2ekxG`  
> using 3 wheels, the message `RUN NOW!` becomes `MEC_=~@@`  
> using 4 wheels, the message `RUN NOW!` becomes `Y]rBb85A`  

Only supports up to 100 wheels. To support more, add more prime numbers to the rotate_amount sub.

