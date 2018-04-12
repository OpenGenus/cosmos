#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll size_t
using namespace std;

struct ranking
{
    ll index;
    ll first;
    ll second;
};

bool comp(ranking a, ranking b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

vector<ll> build_suffix_array(string s)
{
    const ll n = s.length();
    const ll lgn = ceil(log2(n));

    // vector to hold final suffix array result
    vector<ll> sa(n);

    // P[i][j] holds the ranking of the j-th suffix
    // after comparing the first 2^i characters
    // of that suffix
    ll P[lgn][n];

    // vector to store ranking tuples of suffixes
    vector<ranking> ranks(n);

    ll i, j, step = 1;
    for (j = 0; j < n; j++)
        P[0][j] = s[j] - 'a';

    for (i = 1; i <= lgn; i++, step++)
    {
        for (j = 0; j < n; j++)
        {
            ranks[j].index = j;
            ranks[j].first = P[i - 1][j];
            ranks[j].second = (j + std::pow(2, i - 1) < n) ? P[i - 1][j + (ll)(pow(2, i - 1))] : -1;
        }

        std::sort(ranks.begin(), ranks.end(), comp);

        for (j = 0; j < n; j++)
            P[i][ranks[j].index] =
                (j > 0 && ranks[j].first == ranks[j - 1].first &&
                 ranks[j].second == ranks[j - 1].second) ? P[i][ranks[j - 1].index] : j;
    }

    step -= 1;

    for (i = 0; i < n; i++)
        sa[P[step][i]] = i;

    return sa;
}

int main()
{
    string s;
    cin >> s;
    vector<ll> sa = build_suffix_array(s);
    for (ll i = 0; i < s.length(); i++)
        cout << i << " : " << sa[i] << endl;
    return 0;
}
