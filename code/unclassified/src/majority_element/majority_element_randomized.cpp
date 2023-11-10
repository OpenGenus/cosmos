#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;

// Randomized algorithm with expected runtime: O(n), and Space: O(1)
int majorityElement(vector<int>& nums) {
    int pos = 0, n = nums.size(), freq;
    while(1) {
        freq = 0;
        for(int x : nums)if(x == nums[pos])++freq;
        if(freq > n / 2)
            return nums[pos];
        pos = rand() % n;
    }        
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    cout << "The majority element is: " << majorityElement(v);
    return 0;
}
