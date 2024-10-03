/* Part of Cosmos by OpenGenus Foundation */
#include<iostream>

int main(void){
    unsigned int n,r,a;
    std::cin>>n>>r;
    for(int i=0;i<n;i++){
        std::cin>>a;
        if(a<r)
            std::cout<<"Bad boi"<<"\n";
        else
            std::cout<<"Good boi"<<"\n";
    }
}
