// dfs.cpp

#include <iostream>
#include <vector>

using namespace std;

vector <int> g[10000]; // граф

bool used[10000]; // посещенные вершины

void dfs (int v) {
	used[v] = true;
		for (int i = 0; i < g[v].size(); i++)
			if (!used[g[v][i]])
				dfs(g[v][i]);
}


int main() {
	int n; // число вершин
	int m; // число ребер
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v1, v2; // вершины, между которыми есть ребро
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	dfs(1);
	// Print all the visited nodes:
	for (int i = 1; i <= n; i++) {
		if (used[i] == 1) {
			cout << i << " ";
		}
	}
	return 0;
}
