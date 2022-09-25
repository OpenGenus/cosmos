#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct suffix {
	int index;
	char *suff;
};

int compare(struct suffix x, struct suffix y) {
	return strcmp(x.suff,y.suff) < 0? 1:0;
}

int *suffixArray(char *txt, int n) {
	struct suffix suffixes[n];
	for (int i = 0; i < n; i++) {
		suffixes[i].index = i;
		suffixes[i].suff = (txt+i);
	}
	sort(suffixes, suffixes + n, compare);
	int *suffixArr = new int[n];
	for (int i = 0; i < n; i++) {
		suffixArr[i] = suffixes[i].index;
	}
	return suffixArr;
}
