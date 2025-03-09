// Part of Cosmos by OpenGenus Foundation

#include <stdio.h>
#include <string.h>
#include <locale.h>

void cod (char pword[30], int pkeyA, int pkeyB);
void decod (char pword[30], int pkeyA, int pkeyB);

int main (){
	char word[30], character;
	int keyA, keyB;
	printf("Write \"E\" to Encrypt or \"D\" to Decrypt: ");
	scanf("%c", &character);
	while(character == 'E' || character =='e' || character == 'D' || character =='d'){
		if (character == 'E' || character == 'e'){
			printf("Enter a word to be encrypted: ");
			fflush(stdin);
			gets(word);
			printf("Enter key A: ");
			fflush(stdin);
			scanf("%d", &keyA);
			printf("Enter key B: ");
			fflush(stdin);
			scanf("%d", &keyB);
			cod (word, keyA, keyB);
			printf("\n\n");	
			printf("Write \"C\" to Encrypt or \"D\" to Decrypt: ");
			fflush(stdin);
			scanf("%c", &character);
		}
		else{
			if (character == 'D' || character == 'd'){
			printf("Enter a word to be decrypted: ");
			fflush(stdin);
			gets(word);
			printf("Enter key A: ");
			fflush(stdin);
			scanf("%d", &keyA);
			printf("Enter key B: ");
			fflush(stdin);
			scanf("%d", &keyB);
			decod (word, keyA, keyB);
			printf("\n\n");		
			printf("Write \"C\" to Encrypt or \"D\" to Decrypt: ");
			fflush(stdin);
			scanf("%c", &character);
			}
		}
	}
	return 0;
}

void cod (char pword[30], int pkeyA, int pkeyB){
	int j, i, cont = 0;
	char alfa[27];
	int c[30];
	
	if (cont == 0){
	printf("The encrypted word is: ");
	}
	for (i = 0; i < 26; i++){
		alfa[i] = i + 97;
	}
	for (i = 0; i < 30; i++){
		c[i] = ' ';
	}
	for (j = 0; j < 30; j++){
		for (i = 0; i < 26; i++){
			if (pword[j] == alfa[i]){
				c[j] = (pkeyA*i+pkeyB) % 26;
				cont = 1;
			}
		}
	}	
	for (j = 0; j < 30; j++){
		for (i = 0; i < 26; i++){
			if (c[j] == i){
				printf("%c", alfa[i]);
			}	
		}
	}
}

void decod (char pword[30], int pkeyA, int pkeyB){
	int j, i, cont = 0, cont2 = 0, k;
	char alfa[27];
	int c[30];
	float inv;
	
	if (cont == 0){
	printf("The decrypted word is: ");
	}
	for (i = 0; i < 26; i++){
		alfa[i] = i + 97;
	}
	for (i = 0; i < 30; i++){
		c[i] = ' ';
	}
	for (j = 0; j < 30; j++){
		for (i = 0; i < 26; i++){
			if (pword[j] == alfa[i]){
				for (k = 0; k < 30; k++){
					if (cont2 == 0){
						inv = (float)((k*26) + 1) / pkeyA;
					}
					if (inv == (int)inv){
						c[j] = (int)inv*(i - pkeyB) % 26;
						cont = 1;
						cont2 = 1;
						if (c[j] < 0){
							c[j] = c[j] + 26;
						}					
					}
				}
			}
		}
	}	
	for (j = 0; j < 30; j++){
		for (i = 0; i < 26; i++){
			if (c[j] == i){
				printf("%c", alfa[i]);
			}	
		}
	}

}
