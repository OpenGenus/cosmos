// Sample problem for using this algorithm - UVA 11060 Beverages
#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define ll long long
#define inp(a) scanf("%d", &a)
#define out(a) printf("%d\n", a)
#define inp2(a) scanf("%lld", &a)
#define out2(a) printf("%lld\n", a)
#define arrinput(a, n) for (int i = 0; i < n; i++) scanf("%d", &a[i]);
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
#define vi vector<int>
#define rep(i, start, n) for (size_t i = start; i < static_cast<size_t>(n); i++)
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define vb vector<bool>
#define testcases() int test; scanf("%d", &test); while (test--)
#define priorityqueue priority_queue<int, vector<int>, greater<int>>
#define minheappop(a) pop_heap(a.begin(), a.end(), compare); a.pop_back();
#define maxheappop(a) pop_heap(a.begin(), a.end()); a.pop_back();
#define minheappush(a, b) a.push_back(b); push_heap(a.begin(), a.end(), compare);
#define maxheappush(a, b) a.push_back(b); push_heap(a.begin(), a.end());
const int mod = 1000000007;
using namespace std;
map<string, vector<string>> graph;
map<string, int> inDegree;
vector<string> alcohols;
int n, m;
string u, v;
void kahnalgo()
{
    set< pair<int, string >> q;
    rep(i, 0, alcohols.size()) {
        if (inDegree[alcohols[i]] == 0)
        {
            q.insert(mp(i, alcohols[i]));
            inDegree[alcohols[i]] = -1;

        }
    }
    while (q.size())
    {
        pair<int, string> cc = *q.begin();
        string c = cc.S;
        cout << " " << c;
        q.erase(q.begin());
        rep(i, 0, graph[c].size()) {
            inDegree[graph[c][i]] -= 1;
        }
        rep(i, 0, alcohols.size()) {
            if (inDegree[alcohols[i]] == 0)
            {
                q.insert(mp(i, alcohols[i]));
                inDegree[alcohols[i]] = -1;
            }
        }
    }
}
int main()
{
    int cases = 0;
    while (inp(n) != EOF)
    {
        cases += 1;
        inDegree.clear();
        graph.clear();
        alcohols.clear();
        rep(i, 0, n) {
            cin >> u;
            alcohols.pb(u);
            graph[u] = vector<string>();
        }
        inp(m);
        rep(i, 0, m) {
            cin >> u >> v;
            inDegree[v] += 1;
            graph[u].pb(v);
        }
        printf("Case #%d: Dilbert should drink beverages in this order:", cases);
        kahnalgo();
        printf(".\n\n");
        getchar();
    }
    return 0;
}
