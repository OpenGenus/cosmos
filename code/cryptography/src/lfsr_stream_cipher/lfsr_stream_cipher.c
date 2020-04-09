#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 128

char m[MAX_SIZE];
unsigned lfsr_state;

unsigned primitive_polynomial = 4194311;

unsigned evaluate_polynomial()
{
    unsigned result = 0;
    result = lfsr_state & primitive_polynomial;
    result = (result >> 16 & 0xFFFF) ^ (result & 0xFFFF);
    result = (result >> 8 & 0x00FF) ^ (result & 0x00FF);
    result = (result >> 4 & 0x000F) ^ (result & 0x000F);
    result = (result >> 2 & 0x0003) ^ (result & 0x0003);
    result = (result >> 1 & 0x0001) ^ (result & 0x0001);
    return result;
}

void set_seed(unsigned seed)
{
    lfsr_state = seed;
}

char get_pseudorandom_byte()
{
    for (int i = 0; i < 8; ++i)
    {
        unsigned new_bit = evaluate_polynomial();
        lfsr_state = (lfsr_state >> 1 ) | (new_bit << 31);
    }
    return (char) (lfsr_state & 0xFF);
}


void encrypt_decrypt(unsigned seed)
{
    set_seed(seed);
    for (unsigned i = 0; i < strlen(m); ++i)
    {
        m[i] ^= get_pseudorandom_byte();
    }
}

int main()
{
    printf("-----------------------------\n");
    printf("Introduce a string to be encrypted\n");
    fgets(m, MAX_SIZE, stdin); 
    unsigned seed;
    printf("-----------------------------\n");
    printf("Introduce a non-zero seed for the LFSR\n");
    scanf("%u", &seed);
    encrypt_decrypt(seed);
    printf("-----------------------------\n");
    printf("Encrypted text:\n%s", m);
    encrypt_decrypt(seed);
    printf("\n-----------------------------\n");
    printf("Decrypted text:\n%s", m);
    return 0;
}