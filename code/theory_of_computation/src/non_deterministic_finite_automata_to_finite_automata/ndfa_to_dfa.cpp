#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=109;
int n, m;
vector<int> nt[N][N]; 
int dt[N][N];
vector<int> ds[N]; 
int tot; 

void print_dfa() {
		cout << "\n DFA Table:\n";
		cout << "================\n";
		cout << "Q\t";
		for(int j=0; j<m; j++) {
			cout << j << "\t";
		}
		cout << endl;
		for(int i=0; i<tot; i++) {
			cout << "[";
			for(int k=0; k < ds[i].size(); k++) cout << ds[i][k]; cout << "]\t";
			for(int j=0; j<m; j++) {
				cout << "[";
				for(int k=0; k<ds[dt[i][j]].size(); k++) {
					cout << ds[dt[i][j]][k];
				}
				cout << "]\t";
			}
			cout << endl;
		}
	 cout << endl;
}


int main() {
   	n = 4, m = 2;
   	for(int i=0; i<n; i++) {
   		for(int j=0; j<m; j++) {
   			int sz; cin >> sz;
   			nt[i][j].resize(sz);
   		}
   	}
   	for(int i=0; i<n; i++) {
   		for(int j=0; j<m; j++) {
   			for(int k=0; k < nt[i][j].size(); k++) {
   				cin >> nt[i][j][k];
   			}
   		}
   	}
   	
   	queue<int> q;
   	vector<int> v; v.pb(0); q.push(0);
   	ds[tot++] = v;
   	while(!q.empty()) {

   		int top = q.front(); q.pop();

   		for(int j=0; j<m; j++) {
   			vector<int> cur;
	   		for(int i=0; i < ds[top].size(); i++) {
   				for(int k=0; k < nt[ds[top][i]][j].size(); k++) {
   					cur.pb(nt[ds[top][i]][j][k]);
   				}
   			}

   			sort(cur.begin(), cur.end());
   			cur.resize(unique(cur.begin(), cur.end()) - cur.begin());
            int prev = -1;
   			for(int i=0; i<tot; i++) {
   				if(ds[i] == cur) {
   					prev = i;
   					break;
   				}
   			}
   			if(prev == -1) {
   				ds[tot] = cur;
   				q.push(tot);
	   			dt[top][j] = tot;
	   			tot++; 
   			} else {
   				dt[top][j] = prev;
   			}
   			
   		}
   	}

   	print_dfa();
 
    return 0; 
} 
