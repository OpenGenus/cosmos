#include<bits/stdc++.h>
using namespace std;
// O(logn)
class Solution {
public:
    int mySqrt(int x) {
       double start=0,end=x;

       for(int i=0;i<100;++i){
           double mid = start + (end - start) / 2;
            if(mid*mid<=x){
                start = mid;
            }else{
                end = mid;
            }
       }
       return start;
    }
};

int main(){

    cout<< Solution().mySqrt(8) << "\n";

    return 0;
}
