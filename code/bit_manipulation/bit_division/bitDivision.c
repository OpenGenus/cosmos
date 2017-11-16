#include <stdio.h>
// Part of Cosmos by OpenGenus Foundation
unsigned bitDivision(unsigned numerator, unsigned denominator) {

    unsigned current = 1;
    unsigned answer=0;

    if ( denominator > numerator)
        return 0;

    else if ( denominator == numerator)
        return 1;

    while (denominator < numerator) {
        denominator <<= 1;
        current <<= 1;
    }

    denominator >>= 1;
    current >>= 1;

    while (current!=0) {
        if ( numerator >= denominator) {
            numerator -= denominator;
            answer |= current;
        }
        current >>= 1;
        denominator >>= 1;
    }
    return answer;
}

void test(){
    int numerator = 23, denominator = 5;
    printf("%d\n", bitDivision(numerator,denominator));
}

int main() {
    test();
    return 0;
}
