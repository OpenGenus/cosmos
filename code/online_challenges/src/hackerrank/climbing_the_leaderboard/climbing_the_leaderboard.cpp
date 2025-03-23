#include <iostream>
#include <stack> 

int main() 
{
    unsigned long scr, tmp;
    std::cin >> scr;
    
    std::stack<unsigned long> scores;
    
    for (int i = 0; i < scr; ++i) 
    {
        std::cin >> tmp;
        if (scores.empty() || scores.top() != tmp)
            scores.push(tmp);
    }

    unsigned long scor;
    
    std::cin >> scor;

    for (int i = 0; i < scor; ++i) 
    {
        std::cin >> tmp;
        while (!scores.empty() && tmp >= scores.top()) 
            scores.pop();
        std::cout << (scores.size() + 1) << "\n";
    }

    return 0;

}
