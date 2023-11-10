//Part of OpenGenus Cosmos

#include <iostream>
#include <vector> 
#include<cstring> 
using namespace std;

int houses, pipes;

// this array  stores the
// ending vertex of pipe
int rd[1100];

// this array stores the value
// of diameters between two pipes
int wt[1100];

// this array stores the
// starting end of pipe
int cd[1100];

// these vectors are used
// to store the resulting output
vector<int> a(10);
vector<int> b(10);
vector<int> c(10);

int ans;

int dfs(int w)
{
	if (cd[w] == 0)
		return w;
	if (wt[w] < ans)
		ans = wt[w];
	return dfs(cd[w]);
}

// this function performs calculations
void solve(int arr[][3])
{
	int i = 0;

	while (i < pipes) {
		
		int q = arr[i][0], h = arr[i][1],
			t = arr[i][2];
		
		cd[q] = h;
		wt[q] = t;
		rd[h] = q;
		i++;
	}
	
	a.clear();
	b.clear();
	c.clear();
	
	for (int j = 1; j <= houses; ++j)
	
		/* 
		 If a pipe has no ending vertex but has 
		 starting vertex i.e is an outgoing pipe 
		 then we need to start DFS 
		 with that vertex 
		*/
		if (rd[j] == 0 && cd[j]) {
			ans = 1000000000;
			int w = dfs(j);
			
			// now,we fill the details of component
			// in final resulting array
			a.push_back(j);
			b.push_back(w);
			c.push_back(ans);
		}
		
	cout << a.size() << endl;
	for (int j = 0; j < a.size(); ++j)
		cout << a[j] << " " << b[j] << " " << c[j] << endl;
}

int main()
{
	houses = 9, pipes = 6;

	memset(rd, 0, sizeof(rd));
	memset(cd, 0, sizeof(cd));
	memset(wt, 0, sizeof(wt));

	int arr[][3] = { { 7, 4, 98 },
					{ 5, 9, 72 },
					{ 4, 6, 10 },
					{ 2, 8, 22 },
					{ 9, 7, 17 },
					{ 3, 1, 66 } };

	solve(arr);
	return 0;
}