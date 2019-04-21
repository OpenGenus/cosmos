#include<stdio.h>

void stat(void);

int main(){
int i;
for(i=1; i<=3 ; i++)
stat();}
void stat(void) {
static int x = 0;
x = x+1;
printf("x = %d/n", x); }
}
