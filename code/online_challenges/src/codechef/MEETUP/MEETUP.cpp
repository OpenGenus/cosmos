#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) 
	{
	    return *this;
        }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end)
{
    for (auto i = begin; i != end; i++)
    {
		cerr << (*i) << " ";
    }
    cerr << "\n";
}

char buf[100];

int ka, kb;
map<string, int > mm1;
map<string, int > mm2;
int cc1, cc2;
set<int> eds1[1200];
set<int> eds2[1200];
string s1[1200];
string s2[1200];

int rd1()
{
	scanf(" %s", buf);
	if (mm1.count(buf))
		return mm1[buf];
	else
	{
		s1[cc1] = buf;
		return mm1[buf] = cc1++;
	}
}

int rd2()
{
	scanf(" %s", buf);
	if (mm2.count(buf))
		return mm2[buf];
	else
	{
		s2[cc2] = buf;
		return mm2[buf] = cc2++;
	}
}


void del1(int v)
{
	for (int i: eds1[v])
	{
		eds1[i].erase(v);
	}
	eds1[v].clear();
}

void del2(int v)
{
	for (int i: eds2[v])
	{
		eds2[i].erase(v);
	}
	eds2[v].clear();
}

int ask1(int v)
{
	cout << "A " << s1[v] << "\n";
	cout.flush();
	return rd2();
}

int ask2(int v)
{
	cout << "B " << s2[v] << "\n";
	cout.flush();
	return rd1();
}

void solve(vector<int> av1, vector<int> av2)
{
	set<int> ss;
	for (int i: av1)
		if (i < ka)
			ss.insert(eds1[i].size());
	int bst = -1;
	for (int i: av2)
	{
		if (i < kb)
		{
			if (ss.count(eds2[i].size()))
			{
				bst = eds2[i].size();
				break;
			}
		}
	}
	if (bst == -1)
	{
		cout << "C No\n";
		cout.flush();
		exit(0);
	}
	int n = av1.size();
	int c1 = bst;
	int c2 = n - 1 - bst;
	if (c1 < c2)
	{
		int a = -1;
		for (int i: av1)
		{
			if (eds1[i].size() == bst && i < ka)
			{
				a = i;
				break;
			}
		}
		int b = ask1(a);
		if (b < kb) {
			cout << "C Yes\n";
			cout.flush();
			exit(0);
		}
		vector<int> avi;
		vector<int> avii;
		for (int i: av1)
			if (i != a && eds1[a].count(i) == 1)
			{
				avi.push_back(i);
			}
			else if (i != a)
			{
				del1(i);
			}
		del1(a);
		for (int i: av2)
			if (i != b && eds2[b].count(i) == 1)
			{
				avii.push_back(i);
			}
			else if (i != b)
			{
				del2(i);
			}
		del2(b);
		solve(avi, avii);
	}
	else
	{
		int b = -1;
		for (int i: av2)
		{
			if (eds2[i].size() == bst && i < kb)
			{
				b = i;
				break;
			}
		}
		int a = ask2(b);
		if (a < ka) {
			cout << "C Yes\n";
			cout.flush();
			exit(0);
		}
		vector<int> avi;
		vector<int> avii;
		for (int i: av1)
			if (i != a && eds1[a].count(i) == 0)
			{
				avi.push_back(i);
			}
			else if (i != a)
			{
				del1(i);
			}
		del1(a);
		for (int i: av2)
			if (i != b && eds2[b].count(i) == 0)
			{
				avii.push_back(i);
			}
			else if (i != b)
			{
				del2(i);
			}
		del2(b);
		solve(avi, avii);
	}
}
int n, m;

int main()
{
	scanf("%d%d%d%d", &n, &m, &ka, &kb);
	for (int i = 0; i < n; ++i)
		assert(rd1() == i);
	for (int j = 0; j < m; ++j)
	{
		int a = rd1();
		int b = rd1();
		eds1[a].insert(b);
		eds1[b].insert(a);
	}
	for (int i = 0; i < n; ++i)
		assert(rd2() == i);
	for (int j = 0; j < m; ++j)
	{
		int a = rd2();
		int b = rd2();
		eds2[a].insert(b);
		eds2[b].insert(a);
	}
	vector<int> av1;
	for (int i = 0; i < n; ++i)
		av1.push_back(i);
	vector<int> av2;
	for (int i = 0; i < n; ++i)
		av2.push_back(i);
	solve(av1, av2);
	return 0;
}
