/* Part of Cosmos by OpenGenus Foundation */
//C implementation of morse code generator
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void 
encrypt(char* msg)
{
    int size = strlen(msg);
    char * morse_code = (char*) malloc(size * 5);

    // Morse Code for the numbers [0-10]
    char* num[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
    // Morse Code for the alphabet
    char* letters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                      "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    int i;
    for (i = 0;i < size; i++)
        if (msg[i] != ' ')
            if (msg[i] >= '0' && msg[i] <= '9')
                strcat(morse_code, num[msg[i] - 48]);
            else
                strcat(morse_code, letters[msg[i] - 65]);

        else
            strcat(morse_code, " ");

    printf("%s\n", morse_code);

    free(morse_code);
}

int 
main()
{
    char* msg = "CONVERT THIS MORSE CODE";
    encrypt(msg);

    return (0);
}
