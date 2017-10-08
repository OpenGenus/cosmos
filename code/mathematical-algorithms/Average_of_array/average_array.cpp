//  Contibuted by Riya Pannu on 07/10/17.
// Part of Cosmos by OpenGenus Foundation
#include <iostream>
using namespace std;

int main() {
    int arr[1000], n, sum=0;
    double average;
    cout<<"Enter size of the array \n";
    cin>>n;
    cout<<"Enter elements of the array \n";
    for (int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    average=double(sum)/n;
    cout<<"The average of the array is "<<average;
}
