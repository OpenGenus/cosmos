#include <iostream>

int main(){
    int t;
    std::cin >> t;
    for(int i = 0; i < t; ++i){
        int n, k;
        std::cin >> n >> k;
        
        int temp = k;
        
        if(k == 0){
            for(int j = 1; j <= n; ++j)
                std::cout << j << " ";
        }
        
        else if(n % (2 * k) == 0){
            for(int j = 1; j <= n; ++j){
                std::cout << j + temp << " ";
                if(j % k == 0)
                    temp = temp*-1;
            }
        }
        else
            std::cout << "-1";
        std::cout << std::endl; 
    }
    return 0;
}
