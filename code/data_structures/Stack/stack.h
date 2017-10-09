
#ifndef __stdio_h
#include <stdio.h>
#endif
#ifndef __stdbool_h
#include <stdbool.h>
#endif
#ifndef __stdib_h
#include <stdlib.h>
#endif
#ifndef __unistd_h
#include <unistd.h>
#endif

typedef struct nodeType{
	int info;
	struct nodeType *next;
} node;

bool is_empty(node *);



int menu(void);

void PUSH(node **, int);

int POP(node **);

void createEmptyList(node ** ); 

void refresh();
