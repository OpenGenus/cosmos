#include <iostream>

int main(){
    int t;
    std::cin >> t;
    for(int a0 = 0; a0 < t; ++a0){
        int n, k;
        std::cin >> n >> k;
        
        int temp = k;
        
        if(k == 0){
            for(int i = 1; i <= n; ++i)
                std::cout << i << " ";
        }
        
        else if(n % (2 * k) == 0){
            for(int i = 1; i <= n; i++){
                std::cout << i + temp << " ";
                if(i % k == 0)
                    temp = temp*-1;
            }
        }
        else
            std::cout << "-1";
        std::cout << std::endl; 
    }
    return 0;
}