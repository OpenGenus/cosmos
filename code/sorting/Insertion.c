#include <stdio.h>
#define MAX 5

int main() {
  int i, j, now;
  int vet[MAX];

  for(i=0; i<MAX; i++) scanf("%d", &vet[i]);

  for(i=1; i<MAX; i++){
    now = vet[i];
    j = i-1;

    while((j>=0) && (now < vet[j])){
      vet[j+1] = vet[j];
      j = j-1;
      
    }
  vet[j+1] = now; 
  }

  for(i=0; i<MAX; i++) printf("%d ", vet[i]);
}
