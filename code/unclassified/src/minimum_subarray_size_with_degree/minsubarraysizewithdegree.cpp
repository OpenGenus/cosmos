#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

/* Part of Cosmos by OpenGenus Foundation */

using namespace std;

int minSubArraySizeWithDegree(const vector<int> nums)
{
    unordered_map <int, int> m;
    priority_queue<int> pq;
    int best_degree = 1,
        curr_best_degree = nums[0],
        i,
        j,
        s = nums.size();

    for (int x = 0; x < s; x++)
    {
        m[nums[x]]++;
        if (m[nums[x]] > best_degree)
            best_degree = m[nums[x]];
    }

    m.clear();

    i = 0; j = 0;
    int n;
    m[nums[0]]++;
    while (i < s && j < s)
    {
        n = nums[j];

        if (m[n] >= m[curr_best_degree])
            curr_best_degree = n;

        if (m[curr_best_degree] < best_degree)
        {
            j++;
            m[nums[j]]++;
        }
        else
        {
            pq.push(-(j - i + 1));
            m[nums[i]]--;
            i++;
        }
    }

    return -pq.top();
}

#define pb push_back

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    srand(time(NULL));

    vector<int> v;

    for (int i = 0; i < 20; i++)
    {
        v.pb(rand() % 10);
        cout << v[i] << " ";
    }
    cout << endl;

    cout << minSubArraySizeWithDegree(v) << endl;


    return 0;
}
