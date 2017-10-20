#include<stdio.h>
int main(){
    int i,j;
    //outer loop.
    for (i=1;i<=2000;i++){
        int d1=1;
        int sum1=0;
        while(d1<i){
            if(i%d1==0){
                sum1+=d1; //sum of divisors of i
                d1++;
            }else
                d1++;
        }
        //inner loop
        for(j=i+1;j<=2000;j++){
            int d2=1;
            int sum2=0;
            while(d2<j){
                if(j%d2==0){
                    sum2+=d2;//sum of divisors of j
                    d2++;
                }else
                    d2++;
            }

            if(sum1==j && sum2==i)
                //printing amicalbe pair.
                printf("(%d , %d) \n",i,j);
        }

    }

    return 0;
}
