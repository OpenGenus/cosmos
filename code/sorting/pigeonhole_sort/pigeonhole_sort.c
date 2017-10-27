#include <stdio.h>
#include <stdlib.h>
// Part of Cosmos by OpenGenus Foundation
int main(){
    printf("enter the size of array to be sorted:\n");
    int n; scanf("%d", &n);
    int pigeon[n];
    
    printf("now enter the elements of the array:\n");
    for(int i=0;i<n;++i){
        scanf("%d", &pigeon[i]);
    }

    int max, min;
    max = pigeon[0]; min = pigeon[0];
    for(int i=0;i<n;++i){
        if(min > pigeon[i]) min = pigeon[i];

        if(max < pigeon[i]) max = pigeon[i];
    }
    //printf("%d\n %d\n",max, min );

    int range = max  +1;
    int hole[range+1];
    for(int i=0;i<range+1;++i){
        hole[i] = 0;
    }

    for(int i=0;i<n;++i){
        hole[pigeon[i]]++;
    }

    //for(int i=0;i<range+1;++i){
      // printf("%d ",hole[i] );
    //}
    printf("\n");
    for(int i=0;i<range+1;++i){
        while(hole[i] > 0){
            printf("%d ", i);
            hole[i]--;
        }
    }
}
