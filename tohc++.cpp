#include<iostream>

using namespace std;

    int toh1(int n,string s,string h,string d)
    {
    if(n==0){
        return 0;
    }
    toh1(n-1,s,d,h);
    cout<<"move "<<n<< " disk from "<<s<<" to "<<d<<endl;
    
    toh1(n-1,h,s,d);

    }

    int main(){
    int n=0;
    cin>>n;
    
    toh1(n,"source","helper","destination");
    
    return 0 ;
    }



