//Algorithm : 
//1.Take the required inputs.
//2.Create an array of frequency of each number.
//3.If frequency is 2 then present twice and if a number is not present then print the respective values.
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases;
    cin >> testCases;
    while (testCases--) 
    {
        
        int size = 0;
        cin >> size;
        
        std::vector<int> arr(size + 1, 0);
        
        int t = size;
        
        while (t--) 
        {
            int temp = 0;
            cin >> temp;
            arr[temp] ++;
        }
        
        int notPresent;
        int twicePresent;
        
        for (int i = size; i > 0; --i)
        {
            auto temp = arr[i];
            if (temp == 2)
            {
                twicePresent = i;
            }
            else if (temp == 0)
            {
                notPresent = i;
            }
        }
        
        cout << twicePresent << " " << notPresent << endl;
	
	}
	return 0;
}
