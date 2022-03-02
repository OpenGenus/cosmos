template<typename type>
type bitwise_multiply(type a, type b)
{
    type product {0}; // where the product will be enumerated
    type a_reset {a}; // to reset 'a' after each while loop.
    if (b < 0)
    {
        for (type i = b; i < 0; i++) // if b < 0, start at negative number and increment up to 0, each time adding 'a' to product
        {
            while(a != 0) {
                type carry = product & a; // Variable carry keeps track of bits that carry over
                product = product ^ a; // This adds up the individual bits
                a = carry << 1; // Shift carry over bits so they can be added next iteration
            }
            a = a | a_reset; // reset 'a' for next iteration
        }
        product ^= -1; // since 'b' is negative, the product will need to be inverted
        type one {1}; // see below for annotations of lines 18-23
        while(one != 0){
            type carry = product & one;
            product = product ^ one;
            one = carry << 1;
        }
        return product;
    }
    for (type i = b; i > 0; i--)
        {
            while(a != 0) {
                type carry = product & a;
                product = product ^ a;
                a = carry << 1;
            }
            a = a | a_reset;
        }
    return product;
}

/*  
    LINES 18 - 23

    If product were always odd, we could just do 'product |= 1' because 'product ^= -1' gives 
    us the absolute value of product minus 1 (even number). Thus, we could just add the one to the end
    using |= 
    
    However, with even numbers, the addition of 1 requires more than one iteration, so we will use
    a variable to hold 1 and then do bitwise addition. 

    EXAMPLE: 

    2 * -4 gives us the product of 8, or 00000000000000000000000000001000, but we need -8

    product ^= -1 :

        00000000000000000000000000001000 (8)
    ^   11111111111111111111111111111111 (-1)
    ________________________________________
    =   11111111111111111111111111110111 (-9)

    enter while loop:

        11111111111111111111111111110111 (-9)
    ^   00000000000000000000000000000001 (1)
    ________________________________________
    =   11111111111111111111111111110110 (-10)

        11111111111111111111111111110110 (-10)
    ^   00000000000000000000000000000010 (2)
    ________________________________________
        11111111111111111111111111110100 (-12)

        11111111111111111111111111110100 (-12)
    ^   00000000000000000000000000000100 (4)
    ________________________________________
        11111111111111111111111111110000 (-16)

        11111111111111111111111111110000 (-16)
    ^   00000000000000000000000000001000 (8)
    ________________________________________
        11111111111111111111111111111000 (-8)

    return -8
*/