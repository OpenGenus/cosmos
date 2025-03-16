#include<stdio.h>

void insertion(int arr[5] , int index , int element){
    for (int i = 5; i >= index; i--)
    {
        arr[i+1] = arr[i]; 
        
    }
    arr[index] = element;
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n" , arr[i]);
    }
    


}


int main(){
    int arr[5] = {1,2,4,5,6} , index = 2 , element = 3 ;
    insertion(arr , index , element);

    return 0;

}