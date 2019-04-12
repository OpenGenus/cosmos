#include <string>
#include <iostream>

int main() 
{
    long int n;
    
    std::cin >> n;
    
    std::__cxx11::string ar[n];
    
    for (long int i = 0; i < n/2; ++i)
    {
        int x;
        std::cin >> x;
        
        std::__cxx11::string s;
        std::cin >> s;
        
        ar[x] = ar[x] + "-" + " ";
        
    }

    for (long int i = n/2; i < n; ++i)
    {
        int x;
        std::cin >> x;
        
        std::__cxx11::string s;
        std::cin >> s;

        ar[x] = ar[x] + s + " ";
        
    }
    
    
    for (int i = 0; i < n; ++i)
        std::cout << ar[i];

    std::cout << "\n";

    return 0;
}