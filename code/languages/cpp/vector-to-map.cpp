#include <vector>
#include <map>
#include <iostream>
using namespace std;
int main() {
    map<string,int> mp1;
    mp1["Shivani"] = 500;
    mp1["Kumari"] = 100;
    mp1["Hacktoberfest"] = 400;

    vector<pair<string,int>> vec1(mp1.begin(), mp1.end());

    for (const auto& [name, value] : vec1) {
        cout << name << ": " << value << endl;
    }

    return 0;
}
