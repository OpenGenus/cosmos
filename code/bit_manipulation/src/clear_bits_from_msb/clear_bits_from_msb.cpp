// Part of Cosmos (OpenGenus)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int clearAllBits(int n, int i){
    int mask = (1 << i) - 1;
    n = n & mask;

    return n;
}

int main() {
	int n, i;
	cin >> n >> i;
	cout<< clearAllBits(n, i) <<endl;

	return 0;
}

