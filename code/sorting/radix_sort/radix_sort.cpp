/* Part of Cosmos by OpenGenus Foundation */
#include<iostream>
#include<vector>

using namespace std;

void radix_sort(vector<int> &data) {
    vector<int> tmp[10]; //store 0~9;
    int max = *(max_element(std::begin(data), std::end(data)));

    int n = 1;
    while (n <= max) {
       for(auto v : data) {
            int lsd = (v/n)%10;
            tmp[lsd].emplace_back(v);
        }

        int k = 0;
        for (auto &v: tmp) { //vector 
            if (v.size() <=0) {
                continue;
            }

            for (auto num: v) {
                data[k++] = num;
            }
            v.clear();
        }
        n*= 10;
    }
}


int main() {
    vector<int> data = {34,12,51,52,612,456,12,31,412,123, 1, 3};

    cout << "before sorting" << endl;
    for (auto v: data) {
        cout << v << " ";
    }
    cout << endl;

    radix_sort(data);
    cout << "after sorting" << endl;
    for (auto v: data) {
        cout << v << " ";
    }
    cout << endl;
}
