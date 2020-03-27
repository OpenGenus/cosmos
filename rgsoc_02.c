#include <stdio.h>

int main(void) {
    // Input N and K 
    int n,k;
    scanf("%d %d",&n,&k);
    // Input the weights of n items 
    int weights[n];
    for(int i=0;i<n;i++){
        scanf("%d",&weights[i]);}

    // Sorting the weights array 
    for(int i=0;i<=n-2;i++){
        int min=i;
        for(int j=i+1;j<=n-1;j++){
            if(weights[j]<weights[min])
            min=j;
            }
        int temp;
        temp=weights[i];
        weights[i]=weights[min];
        weights[min]=temp;
    }

    if(k>n/2)
    k=n-k;
    int sum1, sum2;
    sum1 = 0;
    sum2=0;
    // sum of first K numbers 
    for(int i=0;i<k;i++){
       sum1+=weights[i];  }
    // sum of last K numbers 
    for(int i=k;i<n;i++) {
        sum2+=weights[i];
    }
    printf("%d\n",sum2-sum1);
    return 0;
}

