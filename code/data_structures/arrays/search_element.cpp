#include<iostream>
using namespace std;
int main(){
    int arr[100],i,j,k,l,n,temp,flag=0;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    cout<<"Enter the elements"<<endl;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"Sorted array is"<<endl;
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"enter the element you want to search"<<endl;
    cin>>l;
    int a=0,b=n,mid;
    while(a<=b){
        mid=(a+b)/2;
        if(arr[mid]==l){
            cout<<"Element found at index "<<mid<<endl;
            flag=1;
            break;
        }
        else if(arr[mid]>l)
            b=mid-1;
        else
            a=mid+1;

    }
    if(flag==0)
        cout<<"Element you are searching for is not in the array"<<endl;


}
