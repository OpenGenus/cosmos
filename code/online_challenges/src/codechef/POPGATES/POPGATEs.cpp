// Part of Cosmos by OpenGenus
#include<iostream>
#include<vector>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k, count = 0;
        char e;
        cin >> n >> k;
        vector<char>v;
        for(int i = 0; i < n; i++)
        {
            cin >> e;
            v.push_back(e);
        }
        while(k--)
        {
            if(v.back() == 'H')
            {
                v.pop_back();
                for(int i = 0; i < v.size(); i++)
                {
                    if(v[i] == 'H')
                    {
                        v[i] = 'T';
                    }
                    else if(v[i] == 'T')
                    {
                        v[i] = 'H';
                    }
                }
            }
            else
            {
                v.pop_back();
            }
        }
        for(int i = 0; i < v.size(); i++)
        {
            if(v.at(i) == 'H')
            {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}

