#include <iostream>   

int main()
{
    int students;
    int grade;
    std::cin >> students;
    for (int i = 1; i <= students; i++) 
    {
        int state = 0;
        std::cin >> grade;
        if (grade > 85)
                state = 1;
        else if (grade < 85 && grade > 55)
                state = 2;
        else
               state = 3;
        
        switch (state) {
        case 1:
            std::cout << "Great job!!\n";
            break;
        case 2:
            std::cout << "Good job\n";
            break;
        case 3:
            std::cout << "Average\n";
        }   
    
     }
    return 0;
}
