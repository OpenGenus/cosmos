#include <stdio.h>
// Part of Cosmos by OpenGenus Foundation
int main() {
    int count;
    unsigned int to_flip;
    unsigned int flipped;
    printf("How many flips? ");
    scanf("%d", &count);

    while(count--) {
        printf("To flip: ");
        scanf("%d", &to_flip);
        flipped = ~to_flip;
        printf("Flipped: %d\n", flipped);
    }
}
