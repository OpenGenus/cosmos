/* Part of Cosmos by OpenGenus Foundation */
#include<iostream>

int main(void){
    int t, n;
    int flag;
    std::cin>>t;
    while(t--){
        std::cin>>n;
        int a[n],b,c;
        for(int i=0;i<n;i++)
        std::cin>>a[i];
        for(int i =0;i<n-1;i++)
            for(int j =i+1;j<n;j++){
                if(a[i]!=a[j]){
                    b = a[i]-1;
                    c = a[j]-1;
                        if(a[b] == a[c]){
                            std::cout<<"Truly Happy";
                            flag = 1;
                            goto jump;
                        }
                }
            }
        jump:
        if(flag == 0)
        std::cout<<"Poor Chef";
        std::cout<<"\n";
        flag =0;
    }
}

