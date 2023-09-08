#include <iostream>
#include <vector>
// Part of Cosmos by OpenGenus Foundation
using namespace std;
int rodCutting(int rod_length, vector<int> prices){
    if (rod_length <= 0){
        return 0;
    }
    int maximum_price = INT8_MIN;
    for (int i = 0; i < rod_length; i++){
        maximum_price = max(maximum_price, prices[i] + rodCutting(rod_length-i-1, prices));
    }
    return maximum_price;
}
int main() {
    cout << rodCutting(8, {1,5,8,9,10,17,17,20}) << endl; // should be 22 (one length 2, another length 6)
    return 0;
}
