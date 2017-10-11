#include <stdio.h>
#include <stdlib.h>

int max (int *v, int i){
    return v[i+1] > v[i+2] ? i+1:i+2;
}

void down(int *v, int position, int n){
   int aux,swap;

   if (position*2 <= n-2){

        if (position*2 == n-2){//If there's only 1 child, get that child
            aux = n-1;
        } else aux = max(v,position*2); //Else, get the highest child

        if (v[position] < v[aux]){//If father is lower than his maxChild, swap them and call the function to the new father's position.
            swap = v[position];
            v[position] = v[aux];
            v[aux] = swap;
            down(v,aux,n);
        }
   }
}


void buildHeap(int *v, int n){
    int i;

    for (i=(n/2)-1;i>=0;i--){
        down(v,i,n);
    }
}

void heapSort(int *v, int n){
    int i;
    int aux;

    for (i=n-1;i>0;i--){
        aux = v[i];
        v[i] = v[0];
        v[0] = aux;

        down(v,0,i);
    }
}


int main () {
    int v[] = {2,3,5,8,6,4,7,1,9,0}; //Example of vector to be sorted
    int i;


    buildHeap(v,10); //Transform the vector into a heap

    heapSort(v,10); //Sort the heap

    for (i=0;i<10;i++){
        printf ("%d\t",v[i]);
    }


    return (0);
}
