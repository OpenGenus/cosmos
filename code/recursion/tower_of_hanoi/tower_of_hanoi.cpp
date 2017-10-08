#include<iostream>
using namespace std;

void hanoi(char source, char helper, char destination, int no_of_discs)
{
    //Base Case
    if (no_of_discs == 1) {
        cout << "Move disc "<< no_of_discs << " from " << source << " to " << destination << endl;
        return;
    }
    
    hanoi(source, destination, helper, no_of_discs - 1);
    cout << "Move disc " << no_of_discs << " from " << source << " to " << destination << endl;
    hanoi(helper, source, destination, no_of_discs - 1);
}

int main()
{
    int number_of_discs; 
    cin >> number_of_discs;

    // The discs are named A, B, C for instance
    hanoi('A', 'B', 'C', number_of_discs); 
    
    return 0;
}
