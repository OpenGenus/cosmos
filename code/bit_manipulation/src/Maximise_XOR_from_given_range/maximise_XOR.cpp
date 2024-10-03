#include <iostream>
using namespace std;

int main(){
    int q;
    cin >>q;
    
    bool bits[31];
    
    while(q--)
    {
        int x, l, r;
        cin >>x >>l >>r;
        
        int temp = x;
        for(int i = 0; i < 31 ;i++)
        {
            if(temp & 1) bits[i] = true;
            else bits[i] = false;
            temp /= 2;
        }
        
        int ans = 0;
        for(int i = 30; i >= 0 ;i--)
        {
            temp = 1 << i;
                
            if(bits[i] && (ans + temp - 1) < l) ans += temp;
            
            else if(!bits[i] && (ans + temp) <= r) ans += temp;
        }
        
        cout <<(x ^ ans) <<"\n";
    }
}