#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m > (int)bloomDay.size() / k){
            return -1;
        }

        int start=1,end=*max_element(bloomDay.begin(), bloomDay.end()),res=-1;

        while(start<=end){
            int mid=start+(end-start)/2;

            if(possible(bloomDay,m,k,mid)){
                end=mid-1;
                res=mid;
            }else{
                start=mid+1;
            }
        }
        return res;
    }
    bool possible(vector<int>& bloomDay, int m, int k, int waiting_days){
        int adj_flowers=0, bouquets=0;

        for(int i=0;i<(int)bloomDay.size();++i){
            if(bloomDay[i]<=waiting_days){
                ++adj_flowers;

                if(adj_flowers >= k){
                    adj_flowers=0;
                    ++bouquets;
                }

                if(bouquets==m){
                    return true;
                }
            }else{
                adj_flowers=0;
            }
        }
        return false;
    }
};

int main(){
    vector<int>bloomDay {1,10,3,10,2};
    int m=3;
    int k=1;

    cout<< Solution().minDays(bloomDay, m ,k) << "\n";

    return 0;
}
