#include <iostream>
using namespace std;

void InputArray(int arr[],int size){
    //input of integers in the array
    for(int i=0;i<size;++i){
        cin>>arr[i];
    }
}
int SumArray(int arr[],int size){
    int sum=0;
    //calculates the sum of all the integers in the array
    for(int i=0;i<size;++i){
        sum+=arr[i];
    }
    //returns the sum
    return sum;
}
int main(){
    //size of the array
    int size;
    cin>>size; 
    int *arr= new int[size];  
    InputArray(arr,size);
    //Average of array of numbers
    cout<<SumArray(arr,size)/size;
    delete [] arr;
    return 0;
}