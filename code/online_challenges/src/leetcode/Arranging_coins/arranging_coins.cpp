#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possibol(int n, long long row){
        long sum = (row*(row+1))/2;
        return n>=sum;
    }
    int arrangeCoins(int n) {
        int start=0,end=n,answer=0;

        while(start<=end){
            int mid=start+(end-start)/2;

            if(possibol(n,mid)){
                start=mid+1;
                answer=mid;
            }else{
                end=mid-1;
            }
        }
        return answer;
    }
};

int main(){

    cout<< Solution().arrangeCoins(5) << "\n";

    return 0;
}
