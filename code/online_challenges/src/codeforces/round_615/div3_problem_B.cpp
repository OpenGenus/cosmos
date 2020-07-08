#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
        cin >> n;
	int x,y;
	string ans = "";
	ll max = 0;
	vector<vector<int> > arr(1001);
	for(int i=0; i<n;i++)
	{
		cin >> x >> y;
		if(max < x)
			max = x;
		arr[x].push_back(y);
	}
	for(int i=0;i<max+1;i++)
	{
		sort(arr[i].begin(),arr[i].end());
	}
	int counter = 0;
	for(int i=0; i<max+1; i++)
	{
		for(int j=0, j<arr[i].size();j++)
		{
			if(arr[i][j] < counter)
			{
				ans = "NO";
				break;
			}
			for(;counter<arr[i][j];counter++)
			{
				ans+="U";
			}
		}
		if(ans == "NO")
		{
			break;
		}
		ans+="R";		
	}
	if(ans == "NO")
	{
		cout << "NO\n";
		return;
	}
	else
	{
		string ans2= "";
		for(int i=0; i<ans.size()-1; i++)
		{
			ans2+=ans[i];
		}
		cout << "YES\n" <<ans2 << '\n';
	}

}

int main()
{
    int t=1;
    cin >> t;
    while(t--)
    	solve();
    return 0;
}
