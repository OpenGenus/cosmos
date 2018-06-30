#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    
    int t;         //t is the number of test case
    cin >> t;
    
    while(t--)
    {
        int n;               //size of metrix n * n
        cin >> n;
        vector <int> a(n);
        vector <int> b(n);
        
        for(int i = 0; i < n; i++)
        {
            int sum = 0;
            
            for(int j = 0; j < n; j++)
            {
                int temp;
                cin >> temp;
                a[j] = a[j] + temp;
                
                sum = sum + temp;
            }    
            b[i] = sum;
        }
        
        sort(a.begin(), a.end());       //used Sort function of C++ STL
        sort(b.begin(), b.end());
        
        int flag = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(a[i] != b[i])
            {
                flag++;
                break;
            }
        }
        
        if(flag == 0)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
                                      // Complexity =  O(T*(N^2))*/   
    return 0;
}
