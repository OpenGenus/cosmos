#include <bits/stdc++.h>
using namespace std;
#define size 100005
int w[size]; /* node weights */
int l[size], r[size]; /* left and right children */
int d[size]; /* depth */
int q[size]; /* working region */
int v[size]; /* number of node in working region */
int t; /* current size of working region */
int m; /* current node */

/*Phase 1 : Function builds a rooted binary tree having the values
 as leaves but possibly in the wrong order*/
void combine(int k) {
	int j, d, x;
	m++;
	l[m] = v[k - 1];
	r[m] = v[k];
	w[m] = x = q[k - 1] + q[k];
	t--;
	for (j = k; j <= t; j++)
		q[j] = q[j + 1], v[j] = v[j + 1];
	for (j = k - 2; q[j] < x; j--)
		q[j + 1] = q[j], v[j + 1] = v[j];
	q[j + 1] = x;
	v[j + 1] = m;
	while (j > 0 && q[j - 1] <= x) {
		d = t - j;
		combine(j);
		j = t - d;
	}
}

/*Phase 2 : Function finds the depth of the each node and
stores it in the depth array */
void mark(int k, int p) {
	d[k] = p;
	if (l[k] >= 0)
		mark(l[k], p + 1);
	if (r[k] >= 0)
		mark(r[k], p + 1);
}

/*Phase 3: Function reorders the leaf nodes
in the same order as of the original sequence given*/
void build(int b) {
	int j = m;
	if (d[t] == b)	l[j] = t++;
	else {
		m--;
		l[j] = m;
		build(b + 1);
	}
	if (d[t] == b)	r[j] = t++;
	else {
		m--;
		r[j] = m;
		build(b + 1);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	//freopen("Input.txt", "r", stdin);
	//freopen("Output.txt", "w", stdout);
#endif
	int i, j, k, n;
	cin >> n;
	/*taking the input as sequnece of n + 1 integers and
	assinging their left and right chid as -1 represents they are leaf nodes*/
	for (j = 0; j <= n; j++) {
		cin >> w[j];
		l[j] = r[j] = -1;
	}
	m = n;
	t = 1;
	q[0] = 1000000000; /* infinity */
	q[1] = w[0];
	v[1] = 0;
	for (k = 1; k <= n; k++) {
		while (q[t - 1] <= w[k])
			combine(t);
		t++;
		q[t] = w[k];
		v[t] = k;
	}
	while (t > 1)
		combine(t);
	mark(v[1], 0);
	t = 0;
	m = 2 * n;
	build(1); /*the order of the leaf nodes becomes same as intial sequence order*/
	/*Extra processing for finding the correct weights  and depths of the n internal nodes*/
	for (int i = 0 ; i <= 2 * n; i++) {
		int ans = 0;
		if (l[i] != -1) ans += w[l[i]];
		else ans = w[i];
		if (r[i] != -1) ans += w[r[i]];
		else ans = w[i];
		w[i] = ans;
	}
	for (int i = 2 * n ; i >= 0 ; i--) {
		/*if the right chid is available*/
		if (r[i] != -1) {
			d[r[i]] = d[i] + 1;
		}
		/*if the left chid is available*/
		if (l[i] != -1) {
			d[l[i]] = d[i] + 1;
		}
	}
	/*program outputs 	index of the node ,
						index of left chid ,
						index of right child ,
						weight of the node and
						the depth of the node
	*/
	cout << "N\tLC\tRC\tWg\tHt" << endl;
	for (int i = 0; i <= 2 * n ; i++) cout << i << "\t"  << (l[i] == -1 ? -1 : l[i]) << "\t" << (r[i] == -1 ? -1 : r[i]) << "\t" << w[i]  << "\t" << d[i] << endl;
}

