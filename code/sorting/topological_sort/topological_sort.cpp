#include <bits/stdc++.h>

// Part of Cosmos by OpenGenus Foundation

using namespace std;

int n;

vector <int> vertex[100];
vector <int> ans;

bool used[100];

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < vertex[v].size(); i++) {
		int to = vertex[v][i];
		if (!used[to]) {
			dfs(to);
		}
	}
	ans.push_back(v);
}

void topological_sort() {
	for (int i = 0; i < n; i++)
		used[i] = false;
	ans.clear();
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i);
		}
	}
	reverse(ans.begin(), ans.end());
	cout << "The topological order is:" << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}

int main() {
	cout << "Enter the no of vertices:\n";
	cin >> n;
	cout << "Enter the adjacency matrix:\n";
	for (int i = 0; i < n; i++) {
		printf("Enter row %d\n", i + 1);
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (x == 1)
				vertex[i].push_back(j);
		}
	}
	void topological_sort();
	return 0;
}
