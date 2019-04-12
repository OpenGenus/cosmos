#include <iostream>
#include <stack> 

int main() 
{
    unsigned long n, m, i, tmp;
    
    std::cin >> n;
    
    std::stack<unsigned long> scores;
    
    for (i = 0; i < n; ++i) {
        std::cin >> tmp;
        if (scores.empty() || scores.top() != tmp) 
            scores.push(tmp);
    }
    
    std::cin >> m;

    for (i = 0; i < m; ++i) {
        std::cin >> tmp;
        while (!scores.empty() && tmp >= scores.top()) 
            scores.pop();
        std::cout << (scores.size() + 1) << "\n";
    }

    std::cout << "\n";

    return 0;
}