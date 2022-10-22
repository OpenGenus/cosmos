#include <bits/stdc++.h>
using namespace std;
int main() {
map<string,int> mp1;
mp1["Shivani"] = 500;
mp1["Kumari"] = 100;
mp1["Hacktoberfest"] = 400;

vector<pair<string,int>> vec1;

for(auto i : mp1)   //inserting map values into vector
{
    vec1.push_back(make_pair(i.first,i.second));
}

for(auto j : vec1)
cout<<j.first<<" : "<<j.second<<endl;

return 0;
}
