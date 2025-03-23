
#include<iostream>
using namespace std;
void insert_an_element(int a[],int n){
    int pos,no;
    cout<<"enter a number which you want to insert";
    cin>>no;
    cout<<"enter the position where insertion should take place:";
    cin>>pos;
    for(int i=n;i>=pos;i--){
        a[i]=a[i-1];
    }
    a[pos]=no;
    cout<<"Number inserted succesfully"<<endl;

}
void delete_an_element(int a[],int n){
    int pos,no;
    char option;
    cout<<"press p if you want to delete no by pos else press n";
    cin>>option;
    if(option=='p'){
        cout<<"enter the position where deletion should take place:";
        cin>>pos;
        for(int i=pos;i<n;i++){
            a[i-1]=a[i];
        }

    cout<<"Number deleted succesfully"<<endl;

    }
    else if(option=='n'){
        cout<<"enter a number which you want to delete";
        cin>>no;
        for(int i=0;i<n;i++){
            if(a[i]==no){
                for(int j=i;j<n;j++){
                    a[j-1]=a[j];
                }
                cout<<"Number deleted succesfully"<<endl;
                break;
            }
        }
    }
}
void find_an_element(int a[],int n){
    int pos,no,flag=0;
    cout<<"enter a number which you want to find";
    cin>>no;
    for(int i=0;i<n;i++){
        if(a[i]==no){
            flag=1;
            cout<<"Number found successfully at position "<<i<<endl;
            break;
        }
    }
    if(flag==0){
        cout<<"Number not in the array"<<endl;
    }
}
void display_the_array(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}
int main(){
    int j,n,m,l,k;
    int a[100];

    cout<<"enter the size of linear array: ";
    cin>>n;
    cout<<"enter the elements of the array:";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"To insert a new element press 1"<<endl;
    cout<<"Delete an element press 2"<<endl;
    cout<<"To find the location press 3"<<endl;
    cout<<"To display the elements press 4"<<endl;
    cin>>m;
    //switch case based on your input value for m;
    switch(m){
    case 1:
        insert_an_element(a,n);
        break;
    case 2:
        delete_an_element(a,n);
        break;
    case 3:
        find_an_element(a,n);
        break;
    case 4:
        display_the_array(a,n);
        break;
    default:
        cout<<"you pressed wrong input";
        break;
    }
    return 0;


}
