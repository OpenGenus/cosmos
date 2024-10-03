#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct suffix {
	int index;
	char *suf;
};

int compare(struct suffix x, struct suffix y) {
	return strcmp(x.suf,y.suf) < 0? 1:0;
}

int *suffixArray(char *txt, int n) {
	struct suffix suffixes[n];
	for (int i = 0; i < n; i++) {
		suffixes[i].index = i;
		suffixes[i].suf = (txt+i);
	}
	sort(suffixes, suffixes + n, compare);
	int *suffixArr = new int[n];
	for (int i = 0; i < n; i++) {
		suffixArr[i] = suffixes[i].index;
	}
	return suffixArr;
}

void printArr(int arr[], int n)
{
    for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
  
// Main program
int main()
{
	char txt[100];
	cout << "Enter string" << endl;
	cin >> txt;
    int n = strlen(txt);
    int *suffixArr = suffixArray(txt,n);
    cout << "The following is the suffix array for " << txt << endl;
    printArr(suffixArr,n);
    return 0;
}
